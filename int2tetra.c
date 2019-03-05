/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:19:36 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/14 05:40:58 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void int2tetra(USI a, char c, t_tet **t)
{
	int		i, j;

	if (a == 0)
		exit(7);
	i = -1;
	while ((a & 0xF000) != 0 && ++i < 4)
	{
		(*t)->t[i][0] = (char)(46 + ((a & 0x8000) != 0) * (c - 46));
		(*t)->t[i][1] = (char)(46 + ((a & 0x4000) != 0) * (c - 46));
		(*t)->t[i][2] = (char)(46 + ((a & 0x2000) != 0) * (c - 46));
		(*t)->t[i][3] = (char)(46 + ((a & 0x1000) != 0) * (c - 46));
		(*t)->t[i][4] = 0;
		a <<= 4;
	}
	(*t)->y = ++i;
	j = -1;
	while(i < 4)
		ft_strcpy((*t)->t[i++],"....");
	ft_memset((*t)->t[i], '\0', 5);
	(*t)->x = 0;
	while (++j < 16)
		if ((*t)->t[j / 4][j % 4] != '.')
			(*t)->x = (*t)->x > j % 4 ? (*t)->x : j % 4;
	(*t)->x++;
}
int tetra_read(int fd, char *buf, USI *t)
{
	short int	i;
	USI			ret, wl;

	ret = (unsigned short int)read(fd, buf, 21);
	if ((ret < 20 && ret > 0) || ret < 0)
		exit(1);
	buf[ret] = 0;
	i = -1;
	t[0] = 0;
	wl = 5;
	while (buf[++i])
		if (((buf[i] == 46 || buf[i] == 35) && i % 5 != 4 && i != 20)
				|| (buf[i] == 10 && (i % 5 == 4 || i == 20)))
			if ((*t = buf[i] == 35 ? (USI)((*t << 1) | 1) : *t) != 0
					&& buf[i] == 35)
				wl = wl < i % 5 ? wl : (USI)(i % 5);
			else
				*t = (buf[i] == '.') ? (*t << 1) : *t;
		else
			exit(2);
	*t <<= wl;
	while ((*t & 0xF000) == 0 && *t)
		*t <<= 4;
	if (*t == 0)
		exit (6);
	return (ret);
}

int	tetra_valid(int fd, USI const tet[], USI inp[])
{
	char	buf[22];
	int		i, j, ret, p;
	USI		t;

	j = 0;
	ret = 22;
	p = 1;
	while (ret > 19)
	{
		ret = tetra_read(fd, buf, &t);
		p = (ret == 20 ? 0 : p);
		i = -1;
		while (tet[++i] && t)
			if (t == tet[i])
				break ;
		if (i > 18)
			exit(4);
		else
			inp[j++] = t;
		if (ret < 21)
			break ;
	}
	if (p == 1)
		exit(5);
	return (j);
}

int		main(int argc, char **argv)
{
 	int		fd, p, se;
	USI		tet[27], inp[27];
	t_tet	*t, *t1;

	ft_bzero(tet, 54);
	ft_bzero(inp, 54);
	ft_memcpy((void *)&tet[0],(void *)STR_TETRA_1, 16);
	ft_memcpy((void *)&tet[8],(void *)STR_TETRA_2, 16);
	ft_memcpy((void *)&tet[16],(void *)STR_TETRA_3, 16);
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 29);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	se = tetra_valid(fd, tet, inp);
	close(fd);
	if ((t = (t_tet *)malloc(sizeof(t_tet))) == NULL)
		exit (800);
	p = -1;
	t1 = t;
	while (++p < se)
	{
		int2tetra(inp[p], (char)('A' + p), &t1);
		t1->p = 0;
		t1->k = 0;
		while (t1->t[0][t1->k] == '.')
			t1->k++;
		if ((t1->next = (t_tet *)malloc(sizeof(t_tet))) == NULL)
			exit (345);
		t1 = t1->next;
	}
	t1->next = NULL;
	fill_it(&t, se);
	exit(0);
}
