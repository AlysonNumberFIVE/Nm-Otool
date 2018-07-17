



#include "otool.h"

size_t			g_int = 0;

unsigned char	*print_obj_name(unsigned char *content, size_t size)
{
	size_t		i;

	ft_putchar('(');
	i = 0;	
	while (content[i] != 0x20)
	{
		if (g_int >= size) 
			exit(1);
		ft_putchar(content[i]);
		i++;
		g_int++;
	}
	ft_putstr("):\n");
	return (&content[i]);
}

unsigned char	*find_first_label_seg(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (g_int >= size)
			exit(1);
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00)
			break ;
		i++;
		g_int++;
	}
	i += 2;
	g_int += 2;
	return (&content[i]);
}

unsigned char	*exit_header(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (42)
	{
		if (g_int >= size)
			break ;
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00 &&
			content[i + 2] == 0x5f)
			break ;
		i++;
		g_int++;
	}
	i += 2;
	g_int += 2;
	return (find_first_label_seg(&content[i], size));
}

unsigned char	*leave_header(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (42)
	{
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00 &&
			content[i + 2] == 0x00 &&
			content[i + 3] == 0x00)
			break ;
		i++;
		g_int++;
	}
	i += 4;
	content = exit_header(&content[i], size);
	return (content);
}

int				start_frame(unsigned char *content, size_t size)
{
	if (g_int + 8 >= size)
		exit(1);
	if (content[0] == 0xcf && 
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

unsigned char	*find_stack_frame(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (g_int < size)
	{
		if (start_frame(&content[i], size) == 1)
			break ;
		i++;
		g_int++;
	}
	return (&content[i]);
}

unsigned char	*reverse_to_next_frame(unsigned char *content)
{
	size_t			i;

	i = 0;
	while (content[i] != 0x00)
	{
		i--;
		g_int--;
	}
	return (&content[i]);
}

unsigned char	*next_frame(unsigned char *content, size_t size)
{
	size_t			i;

	i = 0;
	while (g_int < size)
	{
		if (content[i] == 0x20 &&
			content[i + 1] == 0x20 &&
			content[i + 2] == 0x20)
			break ;
		i++;
		g_int++;
	}
	return (reverse_to_next_frame(&content[i]));
}

unsigned char	*name_space(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x5f)
			break;
		i++;
	}
	i += 2;
	return (&content[i]);
}

unsigned char	*print_labels(unsigned char *content, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00 &&
			content[i + 2] == 0x00 &&
			content[i + 3] == 0x00)
			break ;
		i++;
	}
	return (name_space(&content[i], size));
}

unsigned char	*print_names(unsigned char *content, char *filepath)
{
	size_t		i;

	ft_putstr(filepath);
	ft_putstr("(");
	i = 0;
	while (content[i])
	{
		ft_putchar(content[i]);
		i++;
	}
	ft_putstr("):\n");
	i++;
	return (&content[i]);
}

void			nm_so(unsigned char *content, size_t size, 
				void (*symbols)(void *, int flag), char *filepath)
{
	unsigned char	*file;
	size_t			i;
	unsigned char	*names;

	file = leave_header(content, size);
	if (endswith(filepath, ".so") == -1)
		names = print_labels(content, size);
	else
		names = NULL;
//	file = leave_header(content, size);
	i = 0;
	while (g_int < size)
	{
		if (endswith(filepath, ".so") == -1)
			names = print_names(names, filepath);
		else
		{
			ft_putstr(filepath);
			file = print_obj_name(file, size);
		}
		file = find_stack_frame(file, size);
		symbols(file, 1);
		file = next_frame(file, size);
		ft_putchar('\n');
	}
}



