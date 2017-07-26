/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 20:00:24 by acadiou           #+#    #+#             */
/*   Updated: 2017/07/16 21:18:24 by acadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_ok_line(char **sudoku, char chiffre)
{
	int x;
	int y;
	int cmpt;

	y = 1;
	while (y < 10)
	{
		cmpt = 0;
		x = 0;
		while (x < 9)
		{
			if (sudoku[y][x] == chiffre)
				cmpt++;
			x++;
		}
		if (cmpt > 1)
			return (0);
		y++;
	}
	return (1);
}

int		is_ok_column(char **sudoku, char chiffre)
{
	int x;
	int y;
	int cmpt;

	x = 0;
	while (x < 9)
	{
		cmpt = 0;
		y = 1;
		while (y < 10)
		{
			if (sudoku[y][x] == chiffre)
				cmpt++;
			y++;
		}
		if (cmpt > 1)
			return (0);
		x++;
	}
	return (1);
}

int		last_verif(char **argv)
{
	int		chiffre;

	chiffre = '0';
	while (chiffre <= '9')
	{
		if (!is_ok_line(argv, chiffre) || !is_ok_column(argv, chiffre))
			return (0);
		chiffre++;
	}
	return (1);
}
