/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:37:25 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/13 16:32:40 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void			color_decision(char *path)
{
	struct stat		info;

	if (lstat(path, &info) == -1)
		ft_printf(C_WHITE);
	else if (S_ISDIR(info.st_mode))
		ft_printf(C_BLUE);
	else if (S_ISLNK(info.st_mode))
		ft_printf(C_MAGENTA);
	else if (info.st_mode & S_IXUSR)
		ft_printf(C_RED);
}

static void			print_decision(t_arg *curr)
{
	if (curr->is_current && !curr->is_selected)
		print_current(curr->name);
	else if (curr->is_selected && !curr->is_current)
		print_selected(curr->name);
	else if (curr->is_selected && curr->is_current)
		print_curr_and_selected(curr->name);
	else
		ft_printf("%s ", curr->name);
}

static void			print_handler(t_arg *head)
{
	int		i;
	t_arg	*curr;

	i = 0;
	clear_screen();
	curr = head;
	while (curr)
	{
		if (curr->hidden == 0)
		{
			i += ft_strlen(curr->name) + 1;
			if (i > g_ws.ws_col)
			{
				i = ft_strlen(curr->name) + 1;
				ft_putchar('\n');
			}
			color_decision(curr->name);
			print_decision(curr);
			ft_printf(C_WHITE);
		}
		if (curr->is_last)
			break ;
		curr = curr->next;
	}
}

void				print_args(t_arg *head)
{
	int			arg_max;
	t_arg		*curr;

	arg_max = 0;
	curr = head;
	while (curr)
	{
		if (!curr->hidden && (int)ft_strlen(curr->name) > arg_max)
			arg_max = ft_strlen(curr->name);
		if (curr->is_last)
			break ;
		curr = curr->next;
	}
	if (arg_max + 1 > g_ws.ws_col)
	{
		clear_screen();
		ft_printf("Please resize the screen!\n");
	}
	else
		print_handler(head);
}
