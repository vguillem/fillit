/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:34 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 21:02:59 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isinmap(char **map, t_pos posmap, int sizemap)
{
	if ((posmap.iref) < sizemap && (posmap.iref) >= 0)
	{
		if (posmap.j >= 0 && posmap.j < sizemap)
		{
			if (map[posmap.j][posmap.iref] == '.')
				return (1);
		}
	}
	return (0);
}

int		ft_placetetri(char **tab, char **map, int pos, int sizemap)
{
	t_pos	postetri;
	t_pos	posmap;

	postetri.i = 0;
	postetri.j = 0;
	posmap.i = pos % sizemap;
	posmap.j = pos / sizemap;
	while (tab[postetri.j][postetri.i] == '.')
	{
		if (postetri.i == 3 && postetri.j++ >= 0)
			postetri.i = -1;
		postetri.i++;
	}
	postetri.iref = postetri.i;
	while (postetri.j != 4)
	{
		posmap.iref = posmap.i + postetri.i - postetri.iref;
		if (tab[postetri.j][postetri.i] != '.')
		{
			if (ft_isinmap(map, posmap, sizemap))
				map[posmap.j][posmap.iref] = tab[postetri.j][postetri.i];
			else
				return (0);
		}
		if (postetri.i == 3 && postetri.j++ < 5 && (posmap.j++) >= 0)
			postetri.i = -1;
		postetri.i++;
	}
	return (1);
}

int		ft_solved(int notetri, int nbtetri, char ***tab, char **map)
{
	char	**mapsav;
	int		pos;
	int		sizemap;

	pos = 0;
	if (notetri == nbtetri)
		return (1);
	sizemap = ft_strlen(map[0]);
	if (!(mapsav = ft_savemap(map, sizemap)))
		return (0);
	while (pos < (sizemap * sizemap))
	{
		if ((ft_placetetri(tab[notetri], map, pos, sizemap)))
		{
			if ((ft_solved(notetri + 1, nbtetri, tab, map)))
			{
				ft_freemap(mapsav, sizemap);
				return (1);
			}
		}
		ft_remap(map, mapsav, sizemap);
		pos++;
	}
	ft_freemap(mapsav, sizemap);
	return (0);
}

int		ft_solver(char ***tab, int nbtetri)
{
	char	**map;
	int		sizemap;

	sizemap = ft_mapsize(nbtetri);
	if (!(map = ft_createmap(sizemap)))
		return (0);
	while (!(ft_solved(0, nbtetri, tab, map)) && sizemap < 100)
	{
		ft_freemap(map, sizemap);
		sizemap++;
		if (!(map = ft_createmap(sizemap)))
			return (0);
	}
	ft_printmap(map, sizemap);
	ft_freemap(map, sizemap);
	return (1);
}
