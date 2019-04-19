/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:01:34 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/15 15:49:48 by cbagdon          ###   ########.fr       */
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

/*
**	FOR WINDOW RESIZING: To print things out properly, I'm thinking I need to
**	first get the window dimensions. Then, I find the largest line length.
**	I compare that to the length of the window. If I can't fit at least the
**	length of the longest word + 1 space, then I display an error message.
**	If I CAN fit it, I'm going to print out each word + 1 space one by one.
**	While printing, I'll keep a counter for each word length + 1 (for space).
**	Once I hit <= length, I print out a new line then keep printing and
**	printing. Should be easy enough. Right?
*/

static int		term_check(void)
{
	char	*term;
	char	buf[2048];

	term = getenv("TERM");
	if (!term)
		ft_putstr_fd("ft_select: error: $TERM variable not found!\n",
		STDERR_FILENO);
	else if (!tgetent(buf, term))
		ft_putstr_fd("ft_select: error: terminfo not found!\n",
		STDERR_FILENO);
	else
		return (1);
	return (0);
}

void			setup_term(void)
{
	char				*to_print;
	char				buf[30];

	to_print = buf;
	tcgetattr(STDERR_FILENO, &g_terminals.old_terminal);
	tcgetattr(STDERR_FILENO, &g_terminals.new_terminal);
	g_terminals.new_terminal.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDERR_FILENO, TCSANOW, &g_terminals.new_terminal);
	ft_putstr_fd(tgetstr("vi", &to_print), STDERR_FILENO);
	ft_putstr_fd(tgetstr("ti", &to_print), STDERR_FILENO);
	g_terminals.row = 1;
}

void			reset_term(void)
{
	char	*to_print;
	char	buf[30];

	to_print = buf;
	tcsetattr(STDERR_FILENO, TCSANOW, &g_terminals.old_terminal);
	ft_putstr_fd(tgetstr("ve", &to_print), STDERR_FILENO);
	ft_putstr_fd(tgetstr("te", &to_print), STDERR_FILENO);
}

static void		final_print(t_arg *head)
{
	while (head)
	{
		if (!head->hidden && head->is_selected)
			ft_printf("%s ", head->name);
		if (head && head->is_last)
			break ;
		head = head->next;
	}
	ft_putchar('\n');
}

int				main(int argc, char *argv[])
{
	int					clean_exit;
    t_arg               *head;

	if (argc < 2 || !term_check())
	{
		if (argc < 2)
			ft_putstr_fd("ft_select: error: no arguments found\n",
			STDERR_FILENO);
		return (1);
	}
	setup_term();
	get_screen_size();
	g_args = init_args(argc, argv);
	head = g_args;
	print_args(g_args);
	input_loop(argc, g_args, &clean_exit);
	reset_term();
	if (clean_exit)
		final_print(head);
	return (0);
}
