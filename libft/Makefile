# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 16:50:18 by cbagdon           #+#    #+#              #
#    Updated: 2019/04/05 12:58:40 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
L_GREEN = \033[1;32m
BLUE = \033[0;34m
L_BLUE = \033[0;34m
WHITE = \033[1;37m

NAME = libft.a

MISC_SRCS = ft_atoi.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_getwordcount.c \
	   ft_intlen.c \
	   ft_itoa.c \
	   get_next_line.c \
	   ft_itoa_base.c

LST_SRCS = ft_lstadd.c \
		   ft_lstdelone.c \
		   ft_lstmap.c \
		   ft_lstpush.c \
		   ft_lstdel.c \
		   ft_lstiter.c \
		   ft_lstnew.c

STR_SRCS = ft_strcat.c \
			ft_strccpy.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strmove.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_stroverlap.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_starts_with.c \
			ft_strjoinch.c \
			ft_strjoinchf.c \
			ft_strjoinf.c \
			ft_pathjoin.c \
			ft_freestrarray.c

IS_SRCS = ft_isalpha.c \
			ft_isdigit.c \
			ft_isupper.c \
			ft_islower.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c

PUT_SRCS = ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

MEM_SRCS = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memalloc.c \
			ft_memdel.c \

PRINTF_SRCS = decision.c \
			  dispatch_array.c \
			  ft_printf.c \
			  options.c \
			  utils.c

PRINTF_CONVERSIONS = convert_c.c \
					 convert_f.c \
					 convert_i.c \
					 convert_o.c \
					 convert_p.c \
					 convert_percent.c \
					 convert_s.c \
					 convert_u.c \
					 convert_x.c \
					 convert_xl.c

PRINTF_EXTRAS = ft_imsorry.c \
				ft_intmove.c \
				ft_numlen.c \
				ft_pad.c \
				pf_putfloat.c

OBJECTS = $(patsubst %.c,%.o,$(MISC_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(LST_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(STR_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(IS_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(PUT_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(MEM_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(PRINTF_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(PRINTF_CONVERSIONS))
OBJECTS += $(patsubst %.c,%.o,$(PRINTF_EXTRAS))

INCLUDES = includes/

all:	$(NAME)

$(NAME):
	@mkdir build
	@echo "$(L_BLUE)Making ft_printf...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix ft_printf/src/,$(PRINTF_SRCS)) $(addprefix ft_printf/conversions/,$(PRINTF_CONVERSIONS)) $(addprefix ft_printf/extras/,$(PRINTF_EXTRAS))
	@echo "$(L_BLUE)Making PUT_SRCS...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix put/,$(PUT_SRCS))
	@echo "$(L_BLUE)Making STR_SRCS...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix str/,$(STR_SRCS))
	@echo "$(L_BLUE)Making MEM_SRCS...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix mem/,$(MEM_SRCS))
	@echo "$(L_BLUE)Making LST_SRCS...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix lst/,$(LST_SRCS))
	@echo "$(L_BLUE)Making IS_SRCS...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix is/,$(IS_SRCS))
	@echo "$(L_BLUE)Making MISC_SRCS...$(WHITE)"
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(addprefix misc/,$(MISC_SRCS))
	@mv $(OBJECTS) build/
	@echo "$(L_GREEN)Objects made!$(WHITE)"
	@echo "$(L_BLUE)Making library...$(WHITE)"
	@ar -rcs $(NAME) $(addprefix build/,$(OBJECTS))
	@echo "$(L_GREEN)Library made!$(WHITE)"

clean:
	@echo "$(L_BLUE)Deleting objects...$(WHITE)"
	@rm -rf build
	@echo "$(RED)Objects deleted!$(WHITE)"

fclean: clean
	@echo "$(L_BLUE)Cleaning up...$(WHITE)"
	@rm -rf $(NAME)
	@echo "$(RED)Objects and library deleted$(WHITE)"

re: fclean all
