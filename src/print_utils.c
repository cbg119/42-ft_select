/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:53:12 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/15 15:47:12 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		clear_screen(void)
{
	char	*clear;

	clear = tgetstr("cl", NULL);
	ft_putstr_fd(clear, STDERR_FILENO);
}

void		print_selected(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_putstr_fd(tgetstr("so", &underline), STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(tgetstr("se", &underline), STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
}

void		print_current(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_putstr_fd(tgetstr("us", &underline), STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(tgetstr("ue", &underline), STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
}

void		print_curr_and_selected(char *str)
{
	char	*underline;
	char	buf[2048];

	underline = buf;
	ft_putstr_fd(tgetstr("so", &underline), STDERR_FILENO);
	ft_putstr_fd(tgetstr("us", &underline), STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(tgetstr("se", &underline), STDERR_FILENO);
	ft_putstr_fd(tgetstr("ue", &underline), STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
}
