#include "ft_printf.h"

void	ft_total_size(t_option *opt, int *total, int *size)
{
	*total = *size;
	if (opt->precision > *total)
		*total = opt->precision;
	else
		opt->precision = 0;
	if (opt->width > *total)
		*total = opt->width;
	else
		opt->width = 0;
}

char	*ft_left_blank_n(t_option *opt, int size, char *p)
{
	char	*s;
	int		i;
	int		total;

	ft_total_size(opt, &total, &size);
	if (!(s = (char *)malloc(total + opt->num_m + 1)))
		return (NULL);
	i = 0;
	if (opt->precision > size)
		while (i < total - opt->precision)
			s[i++] = ' ';
	else if (opt->width >= size)
	{
		opt->width = size;
		while (i < total - opt->width - opt->precision - opt->num_m)
			s[i++] = ' ';
	}
	if (opt->num_m)
		s[i++] = '-';
	while (i < total - size)
		s[i++] = '0';
	while (size)
		s[i++] = p[--size];
	s[i] = 0;
	return (s);
}

char	*ft_right_blank_n(t_option opt, int size, char *p)
{
	char	*s;
	int		i;
	int		total;

	total = size;
	if (opt.precision > size)
		total = opt.precision;
	else
		opt.precision = 0;
	if (opt.width > total)
		total = opt.width;
	if (!(s = (char *)malloc(total + opt.num_m + 1)))
		return (NULL);
	i = 0;
	if (opt.num_m)
		s[i++] = '-';
	while (i < opt.precision - size)
		s[i++] = '0';
	while (size)
		s[i++] = p[--size];
	while (i < total)
		s[i++] = ' ';
	s[i] = 0;
	return (s);
}

char	*ft_left_zero_n(t_option opt, int size, char *p)
{
	char	*s;
	int		i;
	int		total;

	total = size;
	if (opt.width > total)
		total = opt.width;
	if (!(s = (char *)malloc(total + opt.num_m + 1)))
		return (NULL);
	i = 0;
	if (opt.num_m)
		s[i++] = '-';
	while (i < total - size)
		s[i++] = '0';
	while (size)
		s[i++] = p[--size];
	s[i] = 0;
	return (s);
}
