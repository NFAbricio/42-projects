/* ************************************************************************** */
/*  rush01.h — visão geral do projeto                                         */
/*                                                                            */
/*  Módulos:                                                                  */
/*  • parse.c  — lê a string de entrada e preenche clues[16]                  */
/*  • solver.c — regras do puzzle + busca em profundidade (backtracking)      */
/*  • io.c     — saída só com write (norma 42): números e "Error\n"           */
/*  • main.c   — encadeia: validar → parse → resolver → imprimir               */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		parse_input(char *str, int clues[16]);
int		solve_grid(int grid[4][4], int clues[16], int pos);
void	print_grid(int grid[4][4]);

#endif