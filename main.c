#include "fillit.h"

int		main(int ac, char **av)
{
	int		nbtetri;
	char	***tab;
	/*int		i;
	int		j;

	i = 0;
	j = 0;*/
	nbtetri = 0;
	if (!(tab = ft_check_fillit(ac, av, &nbtetri)))
	{
		ft_putstr("error\n");
		return (0);
	}
	/*while (i < nbtetri)
	{
		while (j < 4)
		{
			ft_putstr(tab[i][j]);
			ft_putchar('\n');
			j++;
		}
		j = 0;
		i++;
	}*/
	ft_solver(tab, nbtetri);
}
