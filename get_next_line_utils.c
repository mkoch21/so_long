/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoch <mkoch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:52:26 by mkoch             #+#    #+#             */
/*   Updated: 2022/02/25 16:19:19 by mkoch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_n(char *s1, int plus_n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(*s1) * (ft_strlen_gnl(s1) + 1 + plus_n));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	if (plus_n == 1)
	{
		ptr[i++] = '\n';
		free(s1);
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + \
	ft_strlen_gnl(s2) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	unsigned char	*ptr;
	unsigned char	cc;

	ptr = (unsigned char *)s;
	cc = (unsigned char )c;
	while (*ptr != '\0')
	{
		if (*ptr == cc)
			return ((char *)ptr);
		ptr++;
	}
	if (cc == '\0')
		return ((char *)ptr);
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
