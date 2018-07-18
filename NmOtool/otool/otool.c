/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:44:25 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 16:23:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int			is_dynamic_lib(unsigned char *content)
{
	if (content[0] == 0x21 &&
		content[1] == 0x3c &&
		content[2] == 0x61 &&
		content[3] == 0x72 &&
		content[4] == 0x63 &&
		content[5] == 0x68 &&
		content[6] == 0x3e &&
		content[7] == 0x0a)
		return (1);
	return (-1);
}

int			dymlib_magic(unsigned char *content)
{
	if (content[0] == 0xca &&
			content[1] == 0xfe &&
			content[2] == 0xba &&
			content[3] == 0xbe)
		return (1);
	return (-1);
}

int			find_magic_number(unsigned char *content)
{
	if ((content[0] == 0xcf || content[0] == 0xce) &&
		content[1] == 0xfa &&
		content[2] == 0xed &&
		content[3] == 0xfe &&
		content[4] == 0x07 &&
		content[5] == 0x00 &&
		content[6] == 0x00 &&
		content[7] == 0x01)
		return (1);
	return (-1);
}

void		*dynamic_lib_handler(unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (find_magic_number(&content[i]) == 1)
			break ;
		i++;
	}
	return ((void*)&content[i]);
}

int			main(int argc, char **argv)
{
	char	*filename;
	void	*content;
	size_t	size;
	int		i;
	void	(*otool_ptr)(void *, int);

	otool_ptr = &otool;
	if (argc == 1)
		usage();
	i = 0;
	while (++i < argc && argc > 1)
	{
		filename = argv[i];
		if (read_file(&content, &size, filename) == -1)
			continue ;
		if (is_dynamic_lib(content) == 1)
			nm_so(content, size, otool_ptr, filename);
		else
		{
			if (dymlib_magic(content) == 1)
				content = dynamic_lib_read(content, size);
			line_put(filename);
			otool(content, 0);
		}
	}
}
