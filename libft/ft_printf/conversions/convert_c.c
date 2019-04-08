/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:34:58 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/05 12:44:14 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	We decrement width since with %c we will always need to print at least
**	the char. AKA with 1 width we print only the c, with 2 width we print
**	a space AND the c.
*/

int				convert_c(t_opts options, va_list ap)
{
	int		i;
	char	c;
	char	*result;

	i = 0;
	c = va_arg(ap, int);
	result = ft_strnew(1);
	result[0] = c;
	result = ft_pad(result, options.field_width, 1, options.flags.minus);
	if (options.flags.zero)
		while (result[i] == ' ' &&
				(i < (int)ft_strlen(result)))
			result[i++] = '0';
	i = ft_strlen(result);
	ft_putstr(result);
	free(result);
	return (i);
}
