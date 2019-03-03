/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:05:18 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/14 05:41:02 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define USI unsigned short int
# define STR_TETRA_1 "\210\210\0\360\0\314\0\154\0\306\100\214\200\114\0\350"
# define STR_TETRA_2 "\0\56\100\304\0\342\300\210\0\216\300\104\200\310\0\344"
# define STR_TETRA_3 "\0\116\100\114\200\214\0\0\0\0\0\0\0\0"

typedef struct		s_tetra
{
	char			**t;
	size_t	 		x;
	size_t 			y;
	size_t 			k;
	char 			p;
}					t_tet;

void				int2tetra(USI inttet, char lit, t_tet *tetra, char ***c);

int					fillit(t_tet **t, size_t count);

#endif
