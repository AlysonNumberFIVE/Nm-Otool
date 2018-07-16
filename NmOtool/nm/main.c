/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:33:30 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:41:36 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int				signature_check(unsigned char *content)
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

size_t			func_name(unsigned char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		ft_putchar(content[i]);
		i++;
	}
	ft_putstr("):\n");
	return (i);
}

unsigned char	*find_signature(unsigned char *content)
{
	size_t	i;

	i = 0;
	while (42)
	{
		if (signature_check(&content[i]) == 1)
			break ;
		i++;
	}
	return (&content[i]);
}

void			last_word(unsigned char *content, size_t size)
{
	size_t i;

	i = size - 8;
	while (i > 0)
	{
		if (content[i] == 0x0a && content[i - 1] == 0x60 &&
			content[i - 2] == 0x20)
			break ;
		i--;
	}
	i++;
	i += func_name(&content[i]);
	content = find_signature(&content[i]);
	symbols(content);
}

int				main(int argc, char **argv)
{
	char	*filename;
	void	*content;
	size_t	size;

	if (argc == 1)
		filename = ft_strdup("a.out");
	else
		filename = ft_strdup(argv[1]);
	read_file(&content, &size, filename);
	if (arc_magic(content) == 1)
	{
		arc_nm(content, size, filename);
		return (1);
	}
	content = find_start((unsigned char *)content, size);
	symbols(content);
	free(filename);
}
