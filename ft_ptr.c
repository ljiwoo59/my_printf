#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_hexa(long long num, char *p, t_option opt)
{
	int	i;

	i = 0;
	if (opt.type == 'p' && num == 0 && opt.dot == 0)
		p[i++] = '0';
	while (num)
	{
		if ((num % 16) < 10)
			p[i++] = (num % 16) + '0';
		else
			p[i++] = (num % 16) - 10 + 'a';
		num /= 16;
	}
	if (opt.type == 'p')
	{
		p[i++] = 'x';
		p[i++] = '0';
	}
	p[i] = 0;
	return (p);
}

char	*ft_arr_ptr(t_option opt, int size, char *p)
{
	char	*s;

	if (!opt.flag_minus)
		s = ft_left_blank_s(opt, size, p);
	else
		s = ft_right_blank_s(opt, size, p);
	return (s);
}

int		ft_ptr_type(t_option opt, va_list ap)
{
	char		*p;
	char		*s;
	int			size;
	long long	num;

	if (!(p = (char *)malloc(15)))
		return (0);
	num = va_arg(ap, long long);
	p = ft_hexa(num, p, opt);
	size = ft_strlen(p);
	if (size == 0)
	{
		if (opt.precision == 0)
			return (0);
	}
	else
	{
		if (!(s = ft_arr_ptr(opt, size, p)))
			return (0);
		ft_printstr(s, ft_strlen(s), opt);
	}
	free(p);
	return (1);
}
