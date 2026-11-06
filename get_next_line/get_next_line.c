/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgios-arvanitidis <georgios-arvaniti    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:14:07 by georgios-ar       #+#    #+#             */
/*   Updated: 2026/11/05 20:07:00 by georgios-ar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strrchr(stash, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes] = '\0';
		stash = ft_strjoin_buffer(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new = malloc((ft_strlen(stash) - i) + 1);
	if (!new)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
	{
		new[j] = stash[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (free(stash), new);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    stash = read_file(fd, stash);
    if (!stash)
        return (NULL);
    line = extract_line(stash);
    stash = update_stash(stash);
    return (line);
}

int	main(void)
{
    int        fd;
	int			i;
	char		*str;
	
	i = 0;
	fd = open("lonely_day.txt", O_RDONLY);
	str = get_next_line(fd);
	if(!str)
		return(-1);
	while (str && i != 4)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	get_next_line(-1);
	close(fd);
    return (0);
}
