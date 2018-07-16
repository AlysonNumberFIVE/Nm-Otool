/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraydup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:37:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:37:03 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char	**arraydup(char **arr)
{
	char	**new;
	int		i;

	new = (char**)malloc(sizeof(char*) * arraylen(arr) + 1);
	i = 0;
	while (arr[i])
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
