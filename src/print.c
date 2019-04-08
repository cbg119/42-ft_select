/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:37:25 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/08 13:59:25 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void		clear_screen(void)
{
	char	*clear;

	clear = tgetstr("cl", NULL);
	ft_printf(clear);
	//free(clear);
}

static void		print_selected(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_printf(tgetstr("so", &underline));
	ft_printf(str);
	ft_printf(tgetstr("se", &underline));
	ft_putchar('\n');
}

static void		print_current(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_printf(tgetstr("us", &underline));
	ft_printf(str);
	ft_printf(tgetstr("ue", &underline));
	ft_putchar('\n');
}

static void		print_curr_and_selected(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_printf(tgetstr("so", &underline));
	ft_printf(tgetstr("us", &underline));
	ft_printf(str);
	ft_printf(tgetstr("se", &underline));
	ft_printf(tgetstr("ue", &underline));
	ft_putchar('\n');
}

void			print_args(t_arg *head)
{
	t_arg	*curr;

	clear_screen();
	curr = head;
	while (curr)
	{
		if (curr->is_current && !curr->is_selected)
			print_current(curr->name);
		else if (curr->is_selected && !curr->is_current)
			print_selected(curr->name);
		else if (curr->is_selected && curr->is_current)
			print_curr_and_selected(curr->name);
		else
			ft_printf("%s\n", curr->name);
		if (curr->is_last)
			break ;
		curr = curr->next;
	}
}
