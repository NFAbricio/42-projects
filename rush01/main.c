/* ************************************************************************** */
/*  main.c — orquestração do programa                                         */
/*                                                                            */
/*  Fluxo lógico (depois de entender o puzzle em solver.c):                  */
/*  1) Só aceitamos um único argumento (a string com as 16 dicas).           */
/*  2) parse_input transforma caracteres em 16 inteiros 1..4.                */
/*  3) A grade começa vazia (0); solve_grid preenche com a primeira solução. */
/*  4) Se parse falhar ou não existir solução → "Error\n". Senão → grade.      */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];
	int	i;
	int	j;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (parse_input(argv[1], clues) != 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!solve_grid(grid, clues, 0))
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_grid(grid);
	return (0);
}