/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:55:13 by acadiou           #+#    #+#             */
/*   Updated: 2017/07/16 21:17:44 by acadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_available_line(char *line, char chiffre);
int		is_available_column(char **sudoku, int x, char chiffre);
int		is_available_block(int x, int y, char **sudoku, char chiffre);

int		backtrack(char **argv, int x, int y)
{
	int cmp;

	if (x == 9)
	{
		x = 0;
		y = y + 1;
	}
	if (y == 10)
		return (1);
	if (argv[y][x] != '.')
		return (backtrack(argv, x + 1, y));
	cmp = 0;
	while (++cmp <= 9)
	{
		if (is_available_line(argv[y], cmp + '0') &&
		is_available_column(argv, x, cmp + '0') &&
		is_available_block(x, y, argv, cmp + '0'))
		{
			argv[y][x] = cmp + '0';
			if (backtrack(argv, x + 1, y))
				return (1);
		}
	}
	argv[y][x] = '.';
	return (0);
}

int		backtrack_reverse(char **argv, int x, int y)
{
	int cmp;

	if (x == -1)
	{
		x = 8;
		y = y - 1;
	}
	if (y == 0)
		return (1);
	if (argv[y][x] != '.')
		return (backtrack_reverse(argv, x - 1, y));
	cmp = 0;
	while (++cmp <= 9)
	{
		if (is_available_line(argv[y], cmp + '0') &&
		is_available_column(argv, x, cmp + '0') &&
		is_available_block(x, y, argv, cmp + '0'))
		{
			argv[y][x] = cmp + '0';
			if (backtrack_reverse(argv, x - 1, y))
				return (1);
		}
	}
	argv[y][x] = '.';
	return (0);
}

int		different(char **tab1, char **tab2)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (tab1[i][j] != tab2[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	duplicate(char **tab1, char **tab2)
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			tab2[i][j] = tab1[i][j];
			j++;
		}
		i++;
	}
}

void	initialize_tab(char **tab)
{
	int i;

	i = 0;
	while (i < 10)
	{
		tab[i] = (char *)malloc(sizeof(char) * 10);
		i++;
	}
}
