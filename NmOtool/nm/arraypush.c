/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraypush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:36:45 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:41:54 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "nm.h"

char		**arraypush(char **arr, char *str)
{
	char	**new;
	int		i;

	new = NULL;
	i = 0;
	if (arr == NULL)
	{
		new = (char**)malloc(sizeof(char*) * 2);
		new[0] = ft_strdup(str);
		new[1] = NULL;
	}
	else
	{
		new = (char**)malloc(sizeof(char*) * (arraylen(arr) + 2));
		while (arr[i])
		{
			new[i] = ft_strdup(arr[i]);
			i++;
		}
		new[i] = ft_strdup(str);
		new[++i] = NULL;
	}
	return (new);
}
