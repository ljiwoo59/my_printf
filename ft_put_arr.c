#include "ft_printf.h"

char	*ft_left_blank(t_option opt, int size, char *c)
{
	char	*s;
	int		i;

	i = 0;
	if (opt.type == '%' || opt.type == 'c')
	{
		if (!(s = (char *)malloc(size + 1)))
			return (NULL);
		while (i < size - 1)
			s[i++] = ' ';
		s[i++] = *c;
		s[i] = 0;
	}
	else
	{
		if (!(s = (char *)malloc(size + 1)))
			return (NULL);
		while (i < opt.width - ft_strlen(c))
			s[i++] = ' ';
		while (*c)
			s[i++] = *(c++);
		s[i] = 0;
	}
	return (s);
}

char	*ft_left_zero(int size, char *c)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size - 1)
		s[i++] = '0';
	s[i++] = *c;
	s[i] = 0;
	return (s);
}

char	*ft_right_blank(t_option opt, int size, char *c)
{
	char	*s;
	int		i;

	i = 0;
	if (opt.type == '%' || opt.type == 'c')
	{
		if (!(s = (char *)malloc(size + 1)))
			return (NULL);
		s[i++] = *c;
		while (i < size)
			s[i++] = ' ';
		s[i] = 0;
	}
	else
	{
		if (!(s = (char *)malloc(size + 1)))
			return (NULL);
		while (*c)
			s[i++] = *(c++);
		while (i < size)
			s[i++] = ' ';
		s[i] = 0;
	}
	return (s);
}
