/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:24:42 by pbonnet           #+#    #+#             */
/*   Updated: 2017/07/26 10:38:55 by pbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		find_len;
	
	if (to_find == 0 || str == 0)
				return (0);
	i = 0;
	while (to_find[i])
		i++;
	if (i == 0)
		return (str);
	find_len = i;
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j == find_len - 1)
				return (str + i);
			j++;
		}
	}
	return (0);
}
