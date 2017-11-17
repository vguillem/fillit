#include "fillit.h"

char	***ft_create_tetri(char ***tab, char *buf, int pos, int notetri)
{
	int		line;
	int		i;

		line = 0;
		while (line++ < 4)
		{
			if (!(tab[notetri][line] = (char *)ft_memalloc(sizeof(char) * 5)))
				return (NULL);
			i = 0;
			while (i < 4)
			{
				if (buf[pos++] == '#')
					tab[notetri][line][i++] = 'A' + notetri;
				else
					tab[notetri][line][i++] = '.';
			}
			pos++;
		}
	return (tab);
}

char	***ft_create_tetris(char ***tab, char *buf, int nbtetri)
{
	int		pos;
	int		notetri;

	notetri = 0;
	pos = 0;
	while (notetri < nbtetri)
	{
		if(!(tab[notetri] = (char **)ft_memalloc(sizeof(char *) * 5)))
			return (NULL);
		if (!(ft_create_tetri(tab, buf, pos, notetri)))
			return (NULL);
		pos += 21;
		notetri++;
	}
	return (tab);
}
