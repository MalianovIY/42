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

void	puttetra(char ***map, char ****t, int p)
{
	int	i, j;

	i = 0;
	while (map[0][i])
	{
		j = 0;
		while(map[0][i][j] != '.' && map[0][i][j])
			j++;
		if (map[0][i][j] == '.')

	}

}

void	removetetra();

char	**createmap(size_t size)
{
	char **map;
	int i;

	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(6);
	map[size] = NULL;
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			exit(7);
		ft_memset(map[i], '.', size);
		map[i][size] = 0;
	}
	return (map);
}

void 	backtracking(char ***map, char ****tet)
{
	int		i, j, p;
	char	***t;

	i = -1;
	t = *tet;
	while (t[++i] != NULL)
	{
		p = 1;
		j = 0;
		while (t[i][j])
			if (t[i][j][0] != '.' || t[i][j][1] != '.' || t[i][j][2] != '.' ||
					t[i][j][3] != '.')
				p = 0;
		if (p)
		{
			puttetra(map, tet, i);
			backtracking(map, tet);
			removetetra(map, tet, i);
		}
	}
}

void	fillit(char ***t, int n)
{
	char **map;
	map = createmap((size_t)2 * n);
	backtracking(&map, &t);
}
