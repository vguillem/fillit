#include "fillit.h"

void	ft_printmap(char **map, int sizemap)
{
	int		i;

	i = 0;
	while (i++ < sizemap)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
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
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * (sizemap + 1))))
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
