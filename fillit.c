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

void	puttetra(tetra_t *map, tetra_t **t, int p)
{
	int	i, j, k, f;

	i = -1;
	while (map[0].t[++i])
	{
		j = 0;
		while(map[0].t[i][j] != '.' && map[0].t[i][j])
			j++;
		if (map[0].t[i][j] == '.')
		{
			if ((t[0][p]).x + i >= map[0].x || (t[0][p]).y + j >= map[0].x)
				continue ;
			k = (int)t[0][p].k;
			while (k / 4 < 4)
				if (t[0][p].t[k / 4][k % 4] - '.')
					if (map[0].t[i + k / 4][j + k % 4 - (int)t[0][p].k] == '.')
						;
		}
	}

}

void	removetetra(tetra_t *map, tetra_t **t, int p);

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

void 	backtracking(tetra_t *map, tetra_t **tet)
{
	int		i, j, p;
	tetra_t	*t;

	i = -1;
	t = *tet;
	while ((t[++i]).t != NULL)
	{
		p = 1;
		j = 0;
		while (((t[i]).t)[j])
			if (((t[i]).t)[j][0] - '.' || ((t[i]).t)[j][1] - '.'
					|| ((t[i]).t)[j][2] - '.' || ((t[i]).t)[j][3] - '.')
				p = 0;
		if (p)
		{
			puttetra(map, tet, i);
			backtracking(map, tet);
			removetetra(map, tet, i);
		}
	}
}

void	fillit(tetra_t **t, size_t n)
{
	tetra_t map;
	map.x = 2 * n;
	map.t = createmap(map.x);
	backtracking(&map, t);
}
