#include "fillit.h"

int		main(int ac, char **av)
{
	int		nbtetri;
	char	***tab;

	nbtetri = 0;
	if (!(tab = ft_check_fillit(ac, av, &nbtetri)))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_solver(tab, &nbtetri);
}
