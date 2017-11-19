/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:34 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/19 13:42:03 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isinmap(char **map, t_pos posmap, int sizemap)
{
	if (posmap.iref < sizemap && posmap.iref >= 0)
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
	int		htag;

	htag = 0;
	postetri = (t_pos){.i = 0, .j = 0};
	posmap = (t_pos){.i = (pos % sizemap), .j = (pos / sizemap)};
	while (tab[postetri.j][postetri.i++] == '.')
		(postetri.i == 4 && postetri.j++ >= 0) ? postetri.i = 0 : 42;
	postetri.iref = --postetri.i;
	while (postetri.j != 4 && htag < 4)
	{
		posmap.iref = posmap.i + postetri.i - postetri.iref;
		if (tab[postetri.j][postetri.i] != '.' && htag++ < 5)
		{
			if (!(ft_isinmap(map, posmap, sizemap)))
				return (0);
			map[posmap.j][posmap.iref] = tab[postetri.j][postetri.i];
		}
		if (postetri.i == 3 && postetri.j++ < 5 && (posmap.j++) >= 0)
			postetri.i = -1;
		postetri.i++;
	}
	return (1);
}

int		ft_posmap(char **map, t_map tmap)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < tmap.sizemap && map[j][i] != '.')
	{
		if (i++ == tmap.sizemap)
		{
			i = 0;
			j++;
		}
	}
	return (j * tmap.sizemap + i);
}

int		ft_solved(t_map *tmap, char ***tab, char **map, int pos)
{
	char	**mapsav;

	if (tmap->notetri == tmap->nbtetri)
		return (1);
	if (!(mapsav = ft_savemap(map, tmap->sizemap)))
		return (0);
	while (pos < (tmap->sizemap * tmap->sizemap))
	{
		if ((ft_placetetri(tab[tmap->notetri], map, pos, tmap->sizemap)))
		{
			tmap->notetri++;
			if ((ft_solved(tmap, tab, map, ft_posmap(map, *tmap))))
			{
				ft_freemap(mapsav, tmap->sizemap);
				return (1);
			}
			tmap->notetri--;
		}
		ft_remap(map, mapsav, tmap->sizemap);
		pos++;
	}
	ft_freemap(mapsav, tmap->sizemap);
	return (0);
}

int		ft_solver(char ***tab, t_map *tmap)
{
	char	**map;

	tmap->sizemap = ft_mapsize(tmap->nbtetri);
	if (!(map = ft_createmap(tmap->sizemap)))
		return (0);
	while (!(ft_solved(tmap, tab, map, 0)) && tmap->sizemap < 100)
	{
		ft_freemap(map, tmap->sizemap);
		tmap->sizemap++;
		if (!(map = ft_createmap(tmap->sizemap)))
			return (0);
	}
	ft_printmap(map, tmap->sizemap);
	ft_freemap(map, tmap->sizemap);
	ft_freetab(tab, tmap->nbtetri);
	return (1);
}
