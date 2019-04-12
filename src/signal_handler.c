/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:05:42 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/11 16:59:28 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	resize_signal(int signo)
{
	if (signo == SIGWINCH)
	{
		clear_screen();
		get_screen_size();
		print_args(g_args);
	}
}
