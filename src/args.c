/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:21:22 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/08 13:35:46 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		push_arg(t_arg *head, t_arg *to_add)
{
	t_arg		*curr;

	curr = head;
	while (curr && curr->next && !curr->is_last)
		curr = curr->next;
	curr->is_last = 0;
	curr->next = to_add;
	head->prev = to_add;
	to_add->next = head;
	to_add->prev = curr;
}

static t_arg	*new_arg(char *name)
{
	t_arg		*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	new->prev = NULL;
	new->name = name;
	new->is_current = 0;
	new->is_selected = 0;
	new->is_last = 1;
	new->next = NULL;
	return (new);
}

t_arg			*init_args(int argc, char *argv[])
{
	int		i;
	t_arg	*head;
	t_arg	*to_add;

	i = 1;
	head = new_arg(argv[i++]);
	head->is_current = 1;
	while (i < argc)
	{
		to_add = new_arg(argv[i]);
		push_arg(head, to_add);
		i++;
	}
	return (head);
}
