/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:59:23 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/28 16:59:37 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_starts_with(char *to_start, char *str)
{
	int		i;

	i = 0;
	while (to_start[i] && str[i] && (to_start[i] == str[i]))
		i++;
	return (to_start[i] == '\0' ? 1 : 0);
}
