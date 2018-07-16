/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:33:30 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 11:34:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		signature_check(unsigned char *content)
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

void	*find_start(unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (signature_check(&content[i]) == 1)
			return ((void*)&content[i]);
		i++;
	}
	return ((void*)content);
}

int		main(int argc, char **argv)
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
		ft_putstr("archive files not handled. [Coming Soon]\n");
		return (1);
	}
	content = find_start((unsigned char *)content, size);
	symbols(content);
	free(filename);
}
