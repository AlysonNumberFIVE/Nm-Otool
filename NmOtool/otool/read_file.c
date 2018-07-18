/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:00:31 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 17:44:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int			signature_check_32(unsigned char *content)
{
	if (content[0] == 0xce &&
		content[1] == 0xfa &&
		content[2] == 0xed &&
		content[3] == 0xfe &&
		content[4] == 0x07 &&
		content[5] == 0x00 &&
		content[6] == 0x00 &&
		content[7] == 0x00)
		return (1);
	return (-1);
}

int			cafe_babe(unsigned char *content)
{
	if (content[0] == 0xca &&
		content[1] == 0xfe &&
		content[2] == 0xba &&
		content[3] == 0xbe)
		return (1);
	return (-1);
}

int			is_valid(void *content, char *filename)
{
	if (cafe_babe(content) == 1)
		return (1);
	if (arc_magic(content) == 1)
		return (1);
	if (signature_check(content) == 1)
		return (1);
	if (signature_check_32(content) == 1)
		return (1);
	else
	{
		ft_putstr(filename);
		ft_putstr(" : Invalid file\n");
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
