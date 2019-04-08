/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:46:46 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/01 14:47:45 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_pathjoin(char *s1, char *s2)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(s1, "/");
	result = ft_strjoin(temp, s2);
	free(temp);
	return (result);
}
