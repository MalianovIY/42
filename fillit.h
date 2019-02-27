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
#define STRING_TETRA_1 "\314\0\360\0\210\210\154\0\214\100\306\0\114\200\350\0"
#define STRING_TETRA_2 "\304\100\56\0\210\300\342\0\104\300\216\0\310\200\344\0"
#define STRING_TETRA_3 "\114\100\116\0\214\200\0\0"


char	**int2tetra(int tetra, char litera);

void	fillit(char ***tetramines, int count);

#endif
