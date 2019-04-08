/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:44:11 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/05 12:38:51 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}
