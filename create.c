#include "fillit.h"

char	***ft_create_tetri(char ***tab, char *buf)
{
	int		pos;
	int		notetri;
	int		i;
	int		line;

	notetri = 0;
	pos = 0;
	while (buf[pos])
	{
		tab[notetri] = (char **)ft_memalloc(sizeof(char *) * 5);
		line = 0;
		while (line < 4)
		{
			tab[notetri][line] = (char *)ft_memalloc(sizeof(char) * 5);
			i = 0;
			while (i < 4)
				tab[notetri][line][i++] = buf [pos++];
			pos++;
			tab[notetri][line++][i] = '\0';
		}
		tab[notetri][line] = '\0';
		pos++;
		notetri++;
	}
	return (tab);
}
