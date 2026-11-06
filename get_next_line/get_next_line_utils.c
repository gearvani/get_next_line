/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:13:58 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/04 17:52:34 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		ch;

	i = 0;
	ch = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

char	*ft_strjoin_buffer(char *old_stash, char *buf)
{
	char	*new_stash;
	int		i;
	int		j;

	if (!old_stash)
		old_stash = ft_strdup("");
	if (!old_stash || !buf)
		return (free(old_stash), NULL);
	new_stash = malloc(ft_strlen(old_stash) + ft_strlen(buf) + 1);
	if (!new_stash)
		return (free(old_stash), NULL);
	i = 0;
	while (old_stash[i])
	{
		new_stash[i] = old_stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		new_stash[i + j] = buf[j];
		j++;
	}
	new_stash[i + j] = '\0';
	return (free(old_stash), new_stash);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
