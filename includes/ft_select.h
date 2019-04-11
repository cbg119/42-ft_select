/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:52:24 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/11 15:27:34 by cbagdon          ###   ########.fr       */
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

# define SPACE 0x20
# define ENTER 0xA
# define ESCAPE 0x1B
# define LEFT 0x445B1B
# define RIGHT 0x435B1B
# define DELETE 0x7F
# define DELETE2 0x7E335B1B

/*
**	STRUCTS
*/

typedef struct		s_arg
{
	struct s_arg	*prev;
	char			*name;
	int				hidden;
	int				is_current;
	int				is_selected;
	int				is_last;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_screensize
{
	int		length;
	int		width;
}					t_screensize;

/*
**	ARGS
*/

t_arg				*init_args(int argc, char *argv[]);

/*
**	MISC PROTOTYPES
*/

void				print_args(t_arg *head);
void				input_loop(int argc, t_arg *arg, int *clean_exit);

/*
**	PRINT_UTILS
*/

void				get_screen_size(void);
void				clear_screen(void);
void				print_selected(char *str);
void				print_current(char *str);
void				print_curr_and_selected(char *str);

/*
**	GLOBALS
*/

t_screensize		g_screen;

#endif
