/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:28:22 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 15:58:53 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int			is_valid(void *content, char *filename)
{
	if (arc_magic(content) == 1)
	{
		return (1);
	}
	if (signature_check(content) == 1)
		return (1);
	else
	{
		ft_putstr(filename);
		ft_putstr(" : The file was not recognized as a valid object filen");
	}
	return (-1);
}

int			read_file(void **content,
		size_t *size, char *filename)
{
	int			fd;
	struct stat	info;

	fd = open(filename, O_RDONLY);
	fstat(fd, &info);
	*size = info.st_size;
	*content = mmap(0, *size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*content == MAP_FAILED)
	{
		ft_putstr(filename);
		ft_putstr(" : No such file or directory\n");
		return (-1);
	}
	if (is_valid(*content, filename) == -1)
		return (-1);
	return (1);
}
