/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:21:01 by pbonnet           #+#    #+#             */
/*   Updated: 2017/07/16 18:14:00 by pbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	int		var;

	var = '0';
	while (var <= '9')
	{
		ft_putchar(var);
		var++;
	}
}
