/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:07:47 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:26:52 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

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

void	*first_obj_name(unsigned char *content, size_t *size)
{
	size_t		i;

	i = 17;
	while (i < *size)
	{
		if (content[i] == 0x23 &&
				content[i + 1] == 0x31 &&
				content[i + 2] == 0x2f &&
				content[i + 3] == 0x32)
			return ((void*)&content[i]);
		i++;
	}
	return ((void*)content);
}

int		end_of_functions(unsigned char *content)
{
	if (content[0] == 0x23 &&
			content[1] == 0x31 &&
			content[2] == 0x2f)
		return (1);
	return (-1);
}

int		grab_labels(unsigned char *content, size_t size)
{
	size_t		i;
	int			count;

	count = 0;
	i = 1;
	while (i < size)
	{
		if (end_of_functions(&content[i]) == 1)
			break ;
		if (content[i] == 0x00)
		{
			ft_putchar('\n');
			count++;
		}
		else
			ft_putchar(content[i]);
		i++;
	}
	return (count);
}

int		find_begin(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x5f)
			break ;
		i++;
	}
	return (grab_labels(&content[i], size));
}
