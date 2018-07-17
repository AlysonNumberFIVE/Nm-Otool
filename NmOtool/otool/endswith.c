/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endswith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:39:13 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 15:39:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int			endswith(char *str, char *end)
{
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	while (j > -1)
	{
		if (str[i] != end[j])
			return (-1);
		j--;
		i--;
	}
	return (1);
}
