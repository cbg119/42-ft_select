/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:53:12 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/11 15:23:41 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		clear_screen(void)
{
	char	*clear;

	clear = tgetstr("cl", NULL);
	ft_printf(clear);
}

void		print_selected(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_printf(tgetstr("so", &underline));
	ft_printf(str);
	ft_printf(tgetstr("se", &underline));
	ft_putchar(' ');
}

void		print_current(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_printf(tgetstr("us", &underline));
	ft_printf(str);
	ft_printf(tgetstr("ue", &underline));
	ft_putchar(' ');
}

void		print_curr_and_selected(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_printf(tgetstr("so", &underline));
	ft_printf(tgetstr("us", &underline));
	ft_printf(str);
	ft_printf(tgetstr("se", &underline));
	ft_printf(tgetstr("ue", &underline));
	ft_putchar(' ');
}
