#include "fillit.h"

int		ft_placetetri(char **tab, char **map, int i, int j)
{
	int		itetri;
	int		jtetri;
	int		iconst;

	itetri = 0;
	jtetri = 0;
	while (tab[jtetri][itetri] == '.')
	{
		if (itetri++ == 3 && jtetri++ < 4)
			itetri = 0;
	}
	iconst = itetri;
	while (itetri < 4 && jtetri < 4)
	{
		if (tab[jtetri][itetri] != '.')
			{
				if (map[j][i + itetri - iconst] == '.')
					map[j][i + itetri - iconst] = tab[jtetri][itetri];
				else
					return (0);
			}
		if (itetri++ == 3 && jtetri++ < 4 && j++ >= 0)
			itetri = 0;
	}
		return (1);
}

char	**ft_createmap(int	sizemap)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * sizemap)))
		return (NULL);
	while (i < sizemap)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char *) * (sizemap + 1))))
			return (NULL);
		ft_memset(map[i], '.', sizemap);
		i++;
	}
	return (map);
}

int		ft_mapsize(int nbtetri)
{
	int		i;

	i = 0;
	while (i * i < nbtetri * 4)
		i++;
	return (i);
}

char	**ft_savemap(char **map, int sizemap)
{
	char	**mapsav;
	int		i;

	i = 0;
	if (!(mapsav = (char **)ft_memalloc(sizeof(char *) * sizemap)))
		return (NULL);
	while (i < sizemap)
	{
		if (!(mapsav[i] = ft_strdup(map[i])))
			return (NULL);
		i++;
	}
	return (mapsav);
}

char	**ft_solver(char ***tab, int nbtetri, int notetri)
{
	char	**map;
	int		sizemap;

	sizemap = ft_mapsize(nbtetri);
	if (!(map = ft_createmap(sizemap)))
		return (NULL);
	if (notetri == nbtetri)
		return (map);
	while 
}
