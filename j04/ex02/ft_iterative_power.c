/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 12:17:33 by pbonnet           #+#    #+#             */
/*   Updated: 2017/07/23 14:42:59 by pbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	i;
	int	value;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = 1;
	value = 1;
	while (i <= power)
	{
		value = value * nb;
		i++;
	}
	return (value);
}
