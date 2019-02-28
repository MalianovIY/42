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

# define STRING_TETRA_1 "\0\314\0\0\0\360\0\0\210\210\0\0\0\154\0\0\100\214\0\0"
# define STRING_TETRA_2 "\0\306\0\0\200\114\0\0\0\350\0\0\100\304\0\0\0\56\0\0"


char	**int2tetra(int tetra, char litera);

void	fillit(char ***tetramines, int count);

#endif
