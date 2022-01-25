/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:33:32 by rkaufman          #+#    #+#             */
/*   Updated: 2022/01/23 21:09:48 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s) + 1;
	while (i < s_len)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_cpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		size--;
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_realloc(char *dst, char *src, int free_dst, int free_src)
{
	char	*output;
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	output = (char *) malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!output)
		return (NULL);
	i = ft_cpy(output, dst, 0);
	ft_cpy(&output[i], src, 0);
	if (free_dst)
		free(dst);
	if (free_src)
		free(src);
	return (output);
}
