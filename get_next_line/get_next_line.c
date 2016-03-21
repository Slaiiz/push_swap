/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:29:03 by vchesnea          #+#    #+#             */
/*   Updated: 2015/11/27 13:29:03 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	load_next_chunk(t_linebuffer *buff)
{
	char	*data;
	char	*new;
	size_t	size;

	if ((new = malloc(sizeof(char) * (buff->size + BUFF_SIZE))) == NULL)
		return (-1);
	data = buff->data;
	buff->data = new;
	if (data != NULL)
	{
		size = buff->size;
		while (size--)
			new[size] = data[size];
		free(data);
	}
	if ((size = read(buff->fd, new + buff->size, BUFF_SIZE)) != (size_t)-1)
		buff->size += size;
	return (size);
}

static int	trim_buffer(t_linebuffer *buff, size_t offset)
{
	char	*data;
	char	*new;
	size_t	size;

	if (offset >= buff->size)
	{
		free(buff->data);
		buff->data = NULL;
		buff->size = 0;
		return (1);
	}
	size = buff->size - offset;
	buff->size = size;
	if ((new = malloc(sizeof(char) * size)) == NULL)
		return (-1);
	data = buff->data + offset;
	while (size--)
		new[size] = data[size];
	free(buff->data);
	buff->data = new;
	return (1);
}

static int	retrieve_line(t_linebuffer *buff, char **out, size_t size)
{
	char	*data;
	char	*new;
	size_t	trim;

	if (buff->size < 1)
		return (0);
	data = buff->data;
	if (size < 1)
	{
		while (size < buff->size && data[size] != '\n')
			size++;
		if (size == buff->size)
			return (0);
	}
	if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	*out = new;
	trim = size + 1;
	while (size--)
		*new++ = *data++;
	*new = '\0';
	return (trim_buffer(buff, trim));
}

static int	get_linebuffer(const int fd, t_linebuffer *entry, t_linebuffer **out)
{
	t_linebuffer	*new;

	while (entry->next != NULL)
	{
		if (entry->fd == fd && entry->data != NULL)
			break ;
		entry = entry->next;
	}
	new = entry;
	if (entry->fd != fd)
	{
		if (entry->fd != 0 || entry->data != NULL)
		{
			if ((new = malloc(sizeof(t_linebuffer))) == NULL)
				return (0);
			entry->next = new;
			new->next = NULL;
			new->data = NULL;
			new->size = 0;
		}
		new->fd = fd;
	}
	*out = new;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				error;
	t_linebuffer		*buff;
	static t_linebuffer	entry;

	if (fd < 0 || line == NULL || !get_linebuffer(fd, &entry, &buff))
		return (-1);
	*line = NULL;
	while (!(error = retrieve_line(buff, line, 0)))
		if ((error = load_next_chunk(buff)) < 1)
			break ;
	if (error == 0)
		return (retrieve_line(buff, line, buff->size));
	return (error);
}
