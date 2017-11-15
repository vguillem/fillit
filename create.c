#include "fillit.h"

char	***ft_create_tetri(char ***tab, char *buf, int nbtetri)
{
	int		pos;
	int		notetriminos;
	int		i;
	int		line;

	notetriminos = 0;
	pos = 0;
	while (buf[pos])
	{
		tab[notetriminos] = (char **)ft_memalloc(sizeof(char *) * 5);
		line = 0;
		while (line < 4)
		{
			tab[notetriminos][line] = (char *)ft_memalloc(sizeof(char) * 5);
			i = 0;
			while (i < 4)
				tab[notetriminos][line][i++] = buf [pos++];
			pos++;
			tab[notetriminos][line++][i] = '\0';
		}
		tab[notetriminos][line] = '\0';
		pos++;
		notetriminos++;
	}
}
