#include "ft_printf.h"

extern int		g_total_count;

char	ft_is_type(char c)
{
	char *str;

	str = TYPE;
	while (*str)
	{
		if (c == *str)
			return (c);
		str++;
	}
	return (0);
}

void	ft_initialize(t_option *opt)
{
	opt->flag_minus = 0;
	opt->flag_zero = 0;
	opt->width = 0;
	opt->dot = 0;
	opt->flag_pre_va = 0;
	opt->precision = -1;
	opt->num_m = 0;
	opt->type = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	g_total_count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			g_total_count++;
		}
		else
		{
			if (!(format = ft_format(format + 1, ap)))
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (g_total_count);
}
