#include "ft_printf.h"

const char	*ft_set_width(const char *start, t_option *opt, va_list ap)
{
	const char *ptr;

	ptr = start;
	if (*ptr == '*')
	{
		opt->width = va_arg(ap, int);
		if (opt->width < 0)
		{
			opt->width *= -1;
			opt->flag_minus = 1;
		}
		ptr++;
	}
	else
	{
		while (*ptr >= '0' && *ptr <= '9')
		{
			opt->width *= 10;
			opt->width += *ptr - '0';
			ptr++;
		}
	}
	return (ptr);
}

const char	*ft_set_precision(const char *start, t_option *opt, va_list ap)
{
	const char	*ptr;
	int			num;

	opt->dot = 1;
	num = 0;
	ptr = start + 1;
	if (*ptr == '*')
	{
		opt->precision = va_arg(ap, int);
		if (opt->precision < 0)
			opt->flag_pre_va = 1;
		ptr++;
	}
	else
	{
		while ((*ptr >= '0' && *ptr <= '9') &&
				(opt->type != 'c' && opt->type != '%'))
		{
			num *= 10;
			num += *ptr - '0';
			ptr++;
			opt->precision = num;
		}
	}
	return (ptr);
}

int			ft_apply_opt(t_option opt, va_list ap)
{
	char	c;
	int		i;

	c = opt.type;
	i = 0;
	if (c == '%')
		i = ft_percent_type(opt);
	else if (c == 'c')
		i = ft_char_type(opt, ap);
	else if (c == 's')
		i = ft_str_type(opt, ap);
	else if (c == 'p')
		i = ft_ptr_type(opt, ap);
	else
		i = ft_num_type(opt, ap);
	return (i);
}

const char	*ft_format(const char *start, va_list ap)
{
	const char	*ptr;
	t_option	opt;

	ptr = start;
	ft_initialize(&opt);
	while (*ptr == '-' || *ptr == '0')
	{
		if (*ptr == '-')
			opt.flag_minus = 1;
		else
			opt.flag_zero = 1;
		ptr++;
	}
	ptr = ft_set_width(ptr, &opt, ap);
	if (*ptr == '.')
		ptr = ft_set_precision(ptr, &opt, ap);
	if (!ft_is_type(*ptr))
		return (NULL);
	opt.type = *ptr;
	if (!ft_apply_opt(opt, ap))
		return (NULL);
	return (ptr);
}
