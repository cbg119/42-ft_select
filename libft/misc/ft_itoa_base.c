/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:43:32 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/05 13:00:09 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa_base(int number, int base)
{
	int				len;
	int				negative;
	char			*result;
	unsigned int	num;
	static char		*hex_base = "0123456789ABCDEF";

	len = 0;
	if (!number || (number < 0 && base != 10))
		return (ft_strdup("0"));
	num = (number < 0 && base == 10) ? -number : number;
	negative = (number < 0 && base == 10) ? 1 : 0;
	while (number)
	{
		len++;
		number /= base;
	}
	result = ft_strnew(len + negative);
	while (len - negative - 1 >= 0)
	{
		result[len - 1] = hex_base[num % base];
		num /= base;
		len--;
	}
	result[0] = (negative) ? '-' : result[0];
	return (result);
}
