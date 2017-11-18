#include "fillit.h"

int		ft_placetetri(char **tab, char **map, int pos, int sizemap)
{
	int		itetri;
	int		jtetri;
	int		iconst;
	int		i;

	itetri = 0;
	jtetri = 0;
	i = pos % sizemap;
	while (tab[jtetri][itetri] == '.')
	{
		if (itetri == 3)
		{
			itetri = -1;
			jtetri++;
		}
		itetri++;
	}
	iconst = itetri;
	while (jtetri != 4)
	{
		if (tab[jtetri][itetri] != '.')
			{
				if ((i + itetri - iconst) < sizemap && (i + itetri - iconst) >= 0 && (pos / sizemap) >= 0 && (pos / sizemap) < sizemap && map[pos / (sizemap)][i + itetri - iconst] == '.')
					map[pos / (sizemap)][i + itetri - iconst] = tab[jtetri][itetri];
				else
				{
					return (0);
				}
			}
		if (itetri++ == 3 && jtetri++ < 5 && (pos += sizemap) >= 0)
			itetri = 0;
	}
	return (1);
}

char	**ft_solved(int notetri, int nbtetri, char ***tab, char **map)
{
	char	**mapsav;
	int		pos;
	int		sizemap;

	pos = 0;
	if (notetri == nbtetri)
		return (map);
	sizemap = ft_mapsize(nbtetri);
	if (!(mapsav = ft_savemap(map, sizemap)))
		return (NULL);
	while (pos < (sizemap * sizemap))
	{
		if ((ft_placetetri(tab[notetri], map, pos, sizemap)))
		{
			if ((map = ft_solved(notetri + 1, nbtetri, tab, map)))
				return (map);
		}
		map = mapsav;
		pos++;
	}
	return (NULL);
}

char	**ft_solver(char ***tab, int nbtetri)
{
	char	**map;
	int		sizemap;

	sizemap = ft_mapsize(nbtetri);
	if (!(map = ft_createmap(sizemap)))
		return (NULL);
	while (!(map = ft_solved(0, nbtetri, tab, map)) && sizemap < 100)
	{
		//freemap
		sizemap++;
		if (!(map = ft_createmap(sizemap)))
			return (NULL);
	}
	ft_printmap(map, sizemap);
	return (map);
}
