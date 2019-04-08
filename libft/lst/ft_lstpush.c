/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:52:45 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/24 11:11:12 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstpush(t_list **head, t_list *new)
{
	t_list	*current;

	current = *head;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}
