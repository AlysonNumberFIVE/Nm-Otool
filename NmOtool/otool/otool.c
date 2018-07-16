/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:44:25 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 12:21:07 by angonyam         ###   ########.fr       */
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

void		*dynamic_lib_read(void *content, size_t size)
{
	size_t			i;
	unsigned char	*file;

	file = (unsigned char *)content;
	i = 0;
	while (i < size)
	{
		if (find_magic_number(&file[i]) == 1)
			break ;
		i++;
	}
	return ((void*)&file[i]);
}

void		usage(void)
{
	ft_putstr("Usage : ./ft_otool [file to examine]");
	return ;
}

int			main(int argc, char **argv)
{
	char	*filename;
	void	*content;
	size_t	size;
	int		i;

	if (argc == 1)
	{
		usage();
		return (0);
	}
	i = 1;
//	filename = argv[1];
	while (i < argc)
	{
		filename = argv[i];
		read_file(&content, &size, filename);
		if (is_dynamic_lib((unsigned char *)content) == 1)
		{
			ft_putstr("Archive files not handled. [Coming soon]\n");
			return (1);
		}
		otool(content, filename);
		i++;
	}
	return (0);
}









