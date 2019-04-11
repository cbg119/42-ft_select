/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:19:11 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/10 17:36:52 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

/*
**	I pass head to each argument so I can actually print them correctly
*/

static void		handle_move(int argc, char move, t_arg **curr, t_arg *head)
{
	int		i = 1;

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

void			input_loop(int argc, t_arg *head)
{
	char		c;
	t_arg		*curr;

	curr = head;
	while (1)
	{
		read(0, &c, 1);
		if (c == '\033')
		{
			read(0, &c, 1);
			read(0, &c, 1);
			if (c == RIGHT || c == LEFT)
				handle_move(argc, c, &curr, head);
		}
		else if (c == 32)
			handle_select(curr, head);
		else if (c == 'a')
			break ;
		else if (c == 8 || c == 127)
			handle_delete(argc, &curr, head);
	}
}
