/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:30:03 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/01 12:14:12 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoinchf(char *str, char c)
{
	char	*new;

	new = ft_strjoinch(str, c);
	if (!new)
		return (NULL);
	free(str);
	str = NULL;
	return (new);
}
