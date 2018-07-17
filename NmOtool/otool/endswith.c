

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

