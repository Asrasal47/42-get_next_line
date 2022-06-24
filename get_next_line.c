/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:50:52 by arasal            #+#    #+#             */
/*   Updated: 2022/05/15 19:51:07 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	f;

	init_rest(&f);
	f.number = BUFFER_SIZE;
	while (f.number && f.number % BUFFER_SIZE == 0
		&& (!(ft_strchr(f.line, '\n'))))
	{
		f.number = read(fd, f.buff, BUFFER_SIZE);
		if ((f.number == 0 && (!*f.line)) || f.number == -1)
		{
			if (f.line || f.number == -1)
				free(f.line);
			return (NULL);
		}
		f.buff[f.number] = '\0';
		f.line = ft_strjoin(f.line, f.buff);
	}
	ft_saverest(&f);
	ft_returnline(&f);
	return (f.line);
}

void	ft_saverest(t_list *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (f->line == NULL)
		return ;
	while (f->line[j] != '\0')
		j++;
	while (f->line[i] != '\n' && f->line[i] != '\0')
		i++;
	if (i != j)
		f->rest = ft_substr(f->line, i + 1, j - (i + 1));
	else
		f->rest = ft_strdup("");
}

void	init_rest(t_list *f)
{
	if (f->rest)
	{
		f->line = ft_strdup(f->rest);
		free (f->rest);
	}
	else
		f->line = ft_strdup("");
}

void	ft_returnline(t_list *f)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (f->line == NULL)
		return ;
	while (f->line[j] != '\0')
		j++;
	while (f->line[i] != '\n' && f->line[i] != '\0')
		i++;
	if (i != j)
	{
		ret = ft_substr(f->line, 0, i + 1);
		free (f->line);
		f->line = ft_strdup(ret);
		free (ret);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	else
	{
		while (i++ < dstsize)
			dst[i] = src[i];
	}
	return (j);
}
