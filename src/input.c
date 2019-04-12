/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:19:11 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/12 13:48:42 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
**	I pass head to each argument so I can actually print them correctly
*/

static void		handle_move(int argc, long move, t_arg **curr, t_arg *head)
{
	int		i;

	i = 1;
	(*curr)->is_current = 0;
	*curr = (move == RIGHT) ? (*curr)->next : (*curr)->prev;
	while (i < argc && (*curr)->hidden)
	{
		*curr = (move == RIGHT) ? (*curr)->next : (*curr)->prev;
		i++;
	}
	(*curr)->is_current = 1;
	print_args(head);
}

static void		handle_select(t_arg *curr, t_arg *head)
{
	curr->is_selected *= -1;
	curr->is_selected += 1;
	print_args(head);
}

static void		handle_delete(int argc, t_arg **curr, t_arg *head)
{
	int		i;

	i = 1;
	(*curr)->is_selected = 0;
	(*curr)->hidden = 1;
	*curr = (*curr)->next;
	while (i < argc && (*curr)->hidden)
	{
		*curr = (*curr)->next;
		i++;
	}
	(*curr)->is_current = 1;
	print_args(head);
}

void			input_loop(int argc, t_arg *head, int *clean_exit)
{
	unsigned long		c;
	t_arg				*curr;

	curr = head;
	*clean_exit = 1;
	signal(SIGWINCH, resize_signal);
	while (1)
	{
		c = 0;
		read(STDERR_FILENO, &c, 6);
		if (c == ENTER)
			break ;
		else if (c == ESCAPE)
		{
			*clean_exit = 0;
			break ;
		}
		else if (c == SPACE)
			handle_select(curr, head);
		else if (c == RIGHT || c == LEFT)
			handle_move(argc, c, &curr, head);
		else if (c == DELETE || c == DELETE2)
			handle_delete(argc, &curr, head);
	}
}
