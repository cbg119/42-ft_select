/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:52:24 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/08 13:43:03 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
**	INCLUDES
*/

# include <termcap.h>
# include <termios.h>
# include "../libft/includes/libft.h"

/*
**	MACROS
*/

# define UP 65
# define DOWN 66
# define LEFT 68
# define RIGHT 67

/*
**	STRUCTS
*/

typedef struct		s_arg
{
	struct s_arg	*prev;
	char			*name;
	int				is_current;
	int				is_selected;
	int				is_last;
	struct s_arg	*next;
}					t_arg;

/*
**	ARGS
*/

t_arg				*init_args(int argc, char *argv[]);

/*
**	MISC PROTOTYPES
*/

void				print_args(t_arg *head);
void				input_loop(t_arg *arg);

#endif
