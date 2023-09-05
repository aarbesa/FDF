/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:54 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:55 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/fdf.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && i < 13)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (i == 13 || (i == 1 && sign == -1))
		return (write(2, "Bad values but proceeding.\n", 28), -1);
	return (result * sign);
}

void	ft_fdf_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		y;

	if (s2 == NULL)
		return (s1);
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	str = malloc(len1 + len2 + 1);
	if (str == 0)
		return (perror("Malloc"), exit(EXIT_FAILURE), NULL);
	i = -1;
	while (s1 && s1[++i])
		str[i] = s1[i];
	y = -1;
	while (s2 && s2[++y])
		str[i + y] = s2[y];
	str[i + y] = '\0';
	return (str);
}
