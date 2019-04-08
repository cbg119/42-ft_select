/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:54:29 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/08 14:15:21 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
**	NOTES: It's April 18, 9:59 A.M. So I'm thinking I have a doubly
**	circular linked list.
**	Each node will have its name/argument, whether it is selected, whether it
**	is the current one, and if it's the last. Initially, I'll malloc the first
**	argument as the first node in the list. From there I will add arguments.
**	I will then print it. Then, we set up an input loop. If we receive a valid
**	arrow key, then make the appropriate movement. We then redraw.
*/

static int		term_check()
{
	char	*term;
	char	buf[2048];

	term = getenv("TERM");
	if (!term)
		ft_printf("ft_select: error: $TERM variable not found!\n");
	else if (!tgetent(buf, term))
		ft_printf("ft_select: error: terminfo not foudn!\n");
	else
		return (1);
	return (0);
}

static void		setup_term(struct termios *old_terminal)
{
	char				*to_print;
	char				buf[30];
	struct termios		new_terminal;

	to_print = buf;
	ft_printf(tgetstr("vi", &to_print));
	ft_printf(tgetstr("ti", &to_print));
	tcgetattr(0, old_terminal);
	tcgetattr(0, &new_terminal);
	new_terminal.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new_terminal);
}

static void		reset_term(struct termios old_terminal)
{
	char	*to_print;
	char	buf[30];

	to_print = buf;
	ft_printf(tgetstr("ve", &to_print));
	ft_printf(tgetstr("te", &to_print));
	tcsetattr(0, TCSANOW, &old_terminal);
}

int		main(int argc, char *argv[])
{
	t_arg				*args;
	struct termios		old_terminal;

	if (argc < 2 || !term_check())
	{
		if (argc < 2)
			ft_printf("ft_select: error: no arguments found\n");
		return (1);
	}
	setup_term(&old_terminal);
	args = init_args(argc, argv);
	print_args(args);
	input_loop(args);
	reset_term(old_terminal);
	return (0);
}
