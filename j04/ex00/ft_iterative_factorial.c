/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 19:12:41 by pbonnet           #+#    #+#             */
/*   Updated: 2017/07/16 19:30:28 by pbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		value;

	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	i = 1;
	value = 1;
	while (i <= nb)
	{
		value = value * i;
		i++;
	}
	return (value);
}
