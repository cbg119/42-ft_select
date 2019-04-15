/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:05:42 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/13 19:29:44 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
**	Not going to lie, I think the ioctl solution in suspend_signal is pretty
**	weird. Anyway, I use it to mark an EOF that way a new prompt is put back
**	out. The second signal, e.g. signal(SIGTSTP, SIG_DFL) is used to start
**	the default behavior of CTRL-Z
*/

static void		resize_signal(int signo)
{
	if (signo == SIGWINCH)
	{
		clear_screen();
		get_screen_size();
		print_args(g_args);
	}
}

static void		suspend_signal(int signo)
{
	char	*to_print;
	char	buf[30];

	to_print = buf;
	if (signo == SIGTSTP)
	{
		reset_term();
		clear_screen();
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
}

static void		resume_signal(int signo)
{
	if (signo == SIGCONT)
	{
		setup_term();
		clear_screen();
		print_args(g_args);
	}
}

static void		die_signal(int signo)
{
	(void)signo;
	reset_term();
	exit(0);
}

void			handle_sigs(void)
{
	signal(SIGWINCH, resize_signal);
	signal(SIGTSTP, suspend_signal);
	signal(SIGCONT, resume_signal);
	signal(SIGINT, die_signal);
	signal(SIGABRT, die_signal);
	signal(SIGFPE, die_signal);
	signal(SIGILL, die_signal);
	signal(SIGINT, die_signal);
	signal(SIGSEGV, die_signal);
	signal(SIGTERM, die_signal);
}
