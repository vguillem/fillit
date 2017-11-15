#include "fillit.h"

int		ft_check_form(char *buf, int pos, int i)
{
	if (i + 5 < 20 && buf[pos + 5] == '#')
		return (0);
	if (i + 1 < 20 && buf[pos + 1] == '#')
		return (0);
	if (i != 0 && buf[pos - 1] == '#')
		return (0);
	if (i > 4 && buf[pos - 5] == '#')
		return (0);
	return (1);
}

int		ft_check_one_tetri(char *buf, int pos, int i, int tetri)
{
	int		htag;

	htag = 0;
	while (i < 21)
	{
		if (buf[pos] && buf[pos] != '.' && buf[pos] != '#' && buf[pos] != '\n')
		{
			ft_putstr("le caractere est :");
			return (0);
		}
		if (buf[pos] == '#')
		{
			if (ft_check_form(buf, pos, i))
			{
				ft_putstr("form\n");
				return (0);
			}
			htag++;
		}
		if (buf[pos] && ((pos - tetri + 1) % 5 == 0 || (pos + 1)  % 21 == 0))
		{
			if (buf[pos] != '\n')
			{
				ft_putstr("N\n");
				return (0);
			}
		}
		pos++;
		i++;
	}
	return (htag);
}

int		ft_check_tetri(char *buf, int nbtetri)
{
	int		tetri;
	int		i;
	int		pos;

	pos = 0;
	tetri = 0;
	while (tetri < nbtetri)
	{
		i = 0;
		if (ft_check_one_tetri(buf, pos, i, tetri) != 4)
		{
			ft_putstr("HTAG\n");
			return (0);
		}
		tetri++;
		pos = pos + 21; 
	}
	return (1);
}



char	***ft_check_fillit(int ac, char **av, int *nbtetri)
{
	int		fd;
	int		ret;
	char	buf[548];
	char	***tab;

	if (ac != 2)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error LECTURE");
		return (NULL);
	}
	ret = read(fd, buf, 547);
	buf[ret] = '\0';
	if (ret == 547 || (ret + 1) % 21 != 0)
	{
		ft_putstr("Error longueur fichier");
		return (NULL);
	}
	*nbtetri = (ret + 1) / 21;
	if (!(tab = ft_memalloc(sizeof(char *) * (*nbtetri + 1))))
	{
		ft_putstr("Error malloc");
		return (NULL);
	}
	if (!(ft_check_tetri(buf, *nbtetri)))
	{
		ft_putstr("Error fichier non conforme");
		return (NULL);
	}
	if (!(tab = ft_create_tetri(tab, buf)))
		return (NULL);
	return (tab);
}