/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:19:36 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/14 05:40:58 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	puttetrahlp(t_tet *m, t_tet **t, int i, int p)
{
	int	k[5];


	k[1] = (int)(i / m->x);
	k[2] = (int)(i % m->x);
	k[0] = (int)t[p]->k - 1;
	while (++k[0] < 16)
	{
		k[3] = k[0] / 4;
		k[4] = k[0] % 4;
		if (t[p]->t[k[3]][k[4]] != '.')
			m->t[k[1] + k[3]][k[2] + k[4] - t[p]->k] = (char)(p + 65);
	}
	return (1);
}

int	puttetra(t_tet *m, t_tet **t, int p)
{
	int	i, k;

	i = -1;
	while (++i < m->k)
	{
		while(m->t[i / m->x][i % m->x] != '.' && m->t[i / m->x][i % m->x])
			i++;
		if (m->t[i / m->x][i % m->x] == '.')
		{
			if (t[p]->y + i / m->x >= m->x
					|| t[p]->x + i % m->x - t[p]->k >= m->x
					||  i % m->x - t[p]->k < 0)
				continue ;
			k = (int)t[p]->k - 1;
			while (++k < 16)
				if (t[p]->t[k / 4][k % 4] - '.')
					if (m->t[i / m->x + k / 4][i % m->x + k % 4 - t[p]->k] - 46)
						break ;
			if (k == 16)
				return ((int)(t[p]->p = puttetrahlp(m, t, i, p)));
		}
	}
	return (0);
}

void	removetetra(t_tet *m, t_tet **t, int p)
{
	int i, k;

	t[p]->p = 0;
	p += 'A';
	i = -1;
	while (++i < m->k)
		if (m->t[i / m->x][i % m->x] == p)
			break ;
	k = (int)t[p -= 'A']->k - 1;
	while (++k < 16)
		if (t[p]->t[k / 4][k % 4] - '.')
			m->t[i / m->x + k / 4][i % m->x + k % 4 - t[p]->k] = 46;
}

int		backtracking(t_tet *m, t_tet **t)
{
	int		p;

	p = -1;
	while ((t[++p])->t != NULL)
	{
		if (t[p]->p == 0)
		{
			if (puttetra(m, t, p) == 1)
			{
				ft_putendl(m->t[0]);
				ft_putendl(m->t[1]);
				ft_putendl(m->t[2]);
				ft_putendl(m->t[3]);
			}
			backtracking(m, t);
			removetetra(m, t, p);
		}
	}
	return (1);
}

int	fillit(t_tet **t, size_t n)
{
	t_tet m;

	m.x = n > 3 ? n : n + 1;
	m.k = m.x * m.x;
	m.t = (char **)ft_arrnew(m.x, m.x, 46);
	while (backtracking(&m, t))
	{
		m.x++;
		m.k = m.x * m.x;
		m.t = (char **)ft_arrnew(m.x, m.x, 46);
	}
	return (1);
}
