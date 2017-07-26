/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 11:43:13 by acadiou           #+#    #+#             */
/*   Updated: 2017/07/16 21:45:42 by acadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_available_line(char *line, char chiffre);
int		is_available_column(char **sudoku, int x, char chiffre);
int		is_available_block(int x, int y, char **sudoku, char chiffre);
int		backtrack(char **argv, int x, int y);
int		backtrack_reverse(char **argv, int x, int y);
int		different(char **tab1, char **tab2);
void	initialize_tab(char **tab);
void	duplicate(char **tab1, char **tab2);

int		check(char **argv, int argc)
{
	int i;
	int j;

	if (argc != 10)
		return (0);
	i = 1;
	while (i < 10)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '.')
				j++;
			else
				return (0);
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

void	display(char **str)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (j != 0)
				write(1, " ", 1);
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		final(char **argv)
{
	int		y;
	int		x;
	char	save;

	y = 1;
	while (y < 10)
	{
		x = 0;
		while (x < 9)
		{
			save = argv[y][x];
			argv[y][x] = '.';
			if (!is_available_line(argv[y], save) &&
			!is_available_column(argv, x, save) &&
			!is_available_block(x, y, argv, save))
				return (0);
			argv[y][x] = save;
			x++;
		}
		y++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	**cpy;

	cpy = (char **)malloc(sizeof(char *) * 10);
	if (!check(argv, argc))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	initialize_tab(cpy);
	duplicate(argv, cpy);
	backtrack_reverse(cpy, 8, 9);
	if (!backtrack(argv, 0, 1) || different(argv, cpy) || !final(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	display(argv);
	return (0);
}
