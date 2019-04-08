/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:19:11 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/08 14:21:43 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		handle_move(char move, t_arg **curr, t_arg *head)
{
	(*curr)->is_current = 0;
	*curr = (move == RIGHT) ? (*curr)->next : (*curr)->prev;
	(*curr)->is_current = 1;
	print_args(head);
}

static void		handle_select(t_arg *curr, t_arg *head)
{
	curr->is_selected *= -1;
	curr->is_selected += 1;
	print_args(head);
}

void		input_loop(t_arg *head)
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
				handle_move(c, &curr, head);
		}
		else if (c == 32)
			handle_select(curr, head);
		else if (c == 'a')
			break ;
	}
}
