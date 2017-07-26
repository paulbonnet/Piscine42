/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:12:06 by pbonnet           #+#    #+#             */
/*   Updated: 2017/07/23 22:07:12 by pbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int		i;

	i = -1;
	while (s1[++i] && s2[i] && (unsigned int)i < n)
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	if (s2[i] && (unsigned int)i < n)
		return (-s2[i]);
	if (s1[i] && (unsigned int)i < n)
		return (s1[i]);
	return (0);
}
