#include "ft_printf.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	*ft_itoa_base(long long i, int base, t_option *opt, char *p)
{
	int		j;

	j = 0;
	if ((i == 0 && opt->flag_pre_va) || (i == 0 && !opt->dot))
		p[j++] = '0';
	if (i < 0)
	{
		i *= -1;
		if (opt->dot)
			opt->precision++;
		opt->num_m = 1;
	}
	if (base == 16 && i != 0)
		p = ft_hexa(i, p, *opt);
	else
	{
		while (i)
		{
			p[j++] = i % 10 + '0';
			i /= 10;
		}
		p[j] = 0;
	}
	return (p);
}

char	*ft_arr_num(t_option opt, char *s)
{
	int		size;
	char	*str;

	size = ft_strlen(s);
	str = 0;
	if (opt.precision >= 0)
	{
		if (opt.flag_minus)
			str = ft_right_blank_n(opt, size, s);
		else if (opt.flag_pre_va && opt.flag_zero)
			str = ft_left_zero_n(opt, size, s);
		else
			str = ft_left_blank_n(&opt, size, s);
	}
	else
	{
		if (opt.flag_minus)
			str = ft_right_blank_n(opt, size, s);
		else if (opt.flag_zero && (opt.num_m || opt.flag_pre_va || !opt.dot))
			str = ft_left_zero_n(opt, size, s);
		else
			str = ft_left_blank_n(&opt, size, s);
	}
	return (str);
}

int		ft_num_type(t_option opt, va_list ap)
{
	long long	i;
	char		*s;
	char		*p;

	if (!(p = (char *)malloc(9)))
		return (0);
	if (opt.type == 'd' || opt.type == 'i')
	{
		i = (int)va_arg(ap, int);
		p = ft_itoa_base(i, 10, &opt, p);
	}
	else
	{
		i = (long long)va_arg(ap, unsigned int);
		if (opt.type == 'x' || opt.type == 'X')
			p = ft_itoa_base(i, 16, &opt, p);
		else
			p = ft_itoa_base(i, 10, &opt, p);
	}
	if (!(s = ft_arr_num(opt, p)))
		return (0);
	free(p);
	ft_printstr(s, ft_strlen(s), opt);
	return (1);
}
