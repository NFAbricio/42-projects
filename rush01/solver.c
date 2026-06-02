/* ************************************************************************** */
/*  solver.c — ideia matemática e algoritmo                                   */
/*                                                                            */
/*  CONCEITO                                                                  */
/*  • Grade 4×4: em cada linha e cada coluna, os números 1,2,3,4 aparecem    */
/*    exatamente uma vez (isso é um “quadrado latino” de ordem 4).            */
/*                                                                            */
/*  • Nas bordas há dicas: quantas “torres” você enxerga olhando daquele      */
/*    lado. Uma torre só conta como visível se for mais alta que todas as     */
/*    que estão entre ela e você (mais perto da borda).                       */
/*    Ex.: na linha [3,1,4,2], da esquerda vê-se 3 torres (3, depois 4; 1 e 2 */
/*    ficam cobertas por alturas maiores à frente).                           */
/*                                                                            */
/*  PASSO A PASSO DA RESOLUÇÃO                                                 */
/*  1) Numeramos as casas de 0 a 15, linha a linha (pos = linha*4 + col).     */
/*  2) Para cada pos, tentamos colocar 1, depois 2, … até 4.                  */
/*  3) Antes de aceitar um valor, checamos se ele já existe na mesma linha    */
/*    ou coluna nas casas já preenchidas (count_conflict).                     */
/*  4) Depois de colocar, se a linha atual está completa (última coluna),      */
/*    verificamos as dicas esquerda/direita daquela linha.                    */
/*     Se a coluna atual está completa (última linha), verificamos topo/base.  */
/*     Só então faz sentido contar torres visíveis na linha/coluna inteira.   */
/*  5) Se as dicas baterem, avançamos (recursão) para pos+1. Se não houver    */
/*    valor que funcione, voltamos atrás (backtracking): limpamos a célula  */
/*    e o nível anterior tenta outro número.                                  */
/*                                                                            */
/*  Por fim, pos==16 significa que todas as casas foram preenchidas com       */
/*  sucesso — encontramos uma solução válida.                                  */
/* ************************************************************************** */

#include "rush01.h"

/*
** Verifica se "num" já aparece na mesma coluna (linhas acima) ou na mesma
** linha (colunas à esquerda). Só olhamos para trás porque à frente ainda
** está vazio ou será preenchido depois.
*/
static int	count_conflict(int grid[4][4], int pos, int num)
{
	int	r;
	int	c;
	int	i;

	r = pos / 4;
	c = pos % 4;
	i = 0;
	while (i < r)
	{
		if (grid[i][c] == num)
			return (1);
		i++;
	}
	i = 0;
	while (i < c)
	{
		if (grid[r][i] == num)
			return (1);
		i++;
	}
	return (0);
}

/*
** Conta torres visíveis ao percorrer a linha da esquerda para a direita.
** Só incrementamos "seen" quando encontramos uma altura maior que qualquer
** uma vista até agora (variável max_h).
*/
static int	visible_left(int row, int grid[4][4])
{
	int	i;
	int	max_h;
	int	seen;

	max_h = 0;
	seen = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max_h)
		{
			max_h = grid[row][i];
			seen++;
		}
		i++;
	}
	return (seen);
}

/* Mesma ideia, olhando da direita para a esquerda. */
static int	visible_right(int row, int grid[4][4])
{
	int	i;
	int	max_h;
	int	seen;

	max_h = 0;
	seen = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max_h)
		{
			max_h = grid[row][i];
			seen++;
		}
		i--;
	}
	return (seen);
}

/* De cima para baixo na coluna "col". */
static int	visible_top(int col, int grid[4][4])
{
	int	i;
	int	max_h;
	int	seen;

	max_h = 0;
	seen = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_h)
		{
			max_h = grid[i][col];
			seen++;
		}
		i++;
	}
	return (seen);
}

/* De baixo para cima na coluna "col". */
static int	visible_bottom(int col, int grid[4][4])
{
	int	i;
	int	max_h;
	int	seen;

	max_h = 0;
	seen = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_h)
		{
			max_h = grid[i][col];
			seen++;
		}
		i--;
	}
	return (seen);
}

/*
** Depois de preencher "pos", aplicamos só as restrições que já podem ser
** testadas com a informação atual:
** - Linha completa quando pos % 4 == 3 (última coluna da linha).
** - Coluna completa quando pos / 4 == 3 (última linha da coluna).
** Retorna 1 se violar alguma dica (entrada inválida para esse ramo).
*/
static int	check_constraints(int grid[4][4], int pos, int clues[16])
{
	int	row;
	int	col;

	row = pos / 4;
	col = pos % 4;
	if (pos % 4 == 3)
	{
		if (visible_left(row, grid) != clues[8 + row])
			return (1);
		if (visible_right(row, grid) != clues[12 + row])
			return (1);
	}
	if (pos / 4 == 3)
	{
		if (visible_top(col, grid) != clues[col])
			return (1);
		if (visible_bottom(col, grid) != clues[4 + col])
			return (1);
	}
	return (0);
}

/*
** Busca em profundidade: tenta valores na casa "pos"; se chegar a 16, achou
** solução. Se nenhum valor funcionar neste ramo, devolve 0 para o chamador
** desfazer a escolha anterior (backtracking).
*/
int	solve_grid(int grid[4][4], int clues[16], int pos)
{
	int	n;

	if (pos == 16)
		return (1);
	n = 1;
	while (n <= 4)
	{
		if (!count_conflict(grid, pos, n))
		{
			grid[pos / 4][pos % 4] = n;
			if (!check_constraints(grid, pos, clues))
			{
				if (solve_grid(grid, clues, pos + 1))
					return (1);
			}
			grid[pos / 4][pos % 4] = 0;
		}
		n++;
	}
	return (0);
}