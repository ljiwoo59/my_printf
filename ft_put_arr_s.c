#include "ft_printf.h"

char	*ft_left_blank_s(t_option opt, int size, char *p)
{
	char	*s;
	int		i;
	int		total;

	i = 0;
	total = size;
	if (opt.width > total)
		total = opt.width;
	if (!(s = (char *)malloc(total + 1)))
		return (NULL);
	while (i < total - size)
		s[i++] = ' ';
	while (i < total && p[size - 1])
		s[i++] = p[--size];
	s[i] = 0;
	return (s);
}

char	*ft_right_blank_s(t_option opt, int size, char *p)
{
	char	*s;
	int		i;
	int		total;

	i = 0;
	total = size;
	if (opt.width > size)
		total = opt.width;
	if (!(s = (char *)malloc(total + 1)))
		return (NULL);
	while (i < size && p[size - i - 1])
	{
		s[i] = p[size - i - 1];
		i++;
	}
	while (i < total)
		s[i++] = ' ';
	s[i] = 0;
	return (s);
}
