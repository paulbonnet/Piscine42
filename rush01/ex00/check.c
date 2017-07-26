/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:44:48 by acadiou           #+#    #+#             */
/*   Updated: 2017/07/16 16:38:42 by acadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_initializer(int *var, int axe, int init)
{
	if (axe >= init && axe <= init + 2)
		*var = init;
	if (axe >= init + 3 && axe <= init + 5)
		*var = init + 3;
	if (axe >= init + 6 && axe <= init + 8)
		*var = init + 6;
}

int		is_available_line(char *line, char chiffre)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] == chiffre)
			return (0);
		x++;
	}
	return (1);
}

int		is_available_column(char **sudoku, int x, char chiffre)
{
	int y;

	y = 1;
	while (y < 10)
	{
		if (sudoku[y][x] == chiffre)
			return (0);
		y++;
	}
	return (1);
}

int		is_available_block(int x, int y, char **sudoku, char chiffre)
{
	int i;
	int j;
	int save1;
	int save2;

	ft_initializer(&j, y, 1);
	save1 = j + 2;
	while (j <= save1)
	{
		ft_initializer(&i, x, 0);
		save2 = i + 2;
		while (i <= save2)
		{
			if (sudoku[j][i] == chiffre)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
