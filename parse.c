/* ************************************************************************** */
/*  parse.c — entrada do subject                                              */
/*                                                                            */
/*  A string deve produzir exatamente 16 dígitos entre '1' e '4', em ordem:   */
/*  [0..3]   topo das colunas 1..4                                            */
/*  [4..7]   base das colunas 1..4                                            */
/*  [8..11]  esquerda das linhas 1..4                                         */
/*  [12..15] direita das linhas 1..4                                          */
/*                                                                            */
/*  Espaços (e outros brancos) são ignorados; qualquer outro caractere erro.  */
/* ************************************************************************** */

#include "rush01.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	parse_input(char *str, int clues[16])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
		{
			i++;
			continue ;
		}
		if (str[i] < '1' || str[i] > '4')
			return (-1);
		if (n >= 16)
			return (-1);
		clues[n++] = str[i] - '0';
		i++;
	}
	if (n != 16)
		return (-1);
	return (0);
}