#include "ft_printf.h"

char	*ft_arr_char(t_option opt, int size, char c)
{
	char	*s;

	if (!opt.flag_minus)
		s = ft_left_blank(opt, size, &c);
	else
		s = ft_right_blank(opt, size, &c);
	return (s);
}

int		ft_char_type(t_option opt, va_list ap)
{
	char	*s;
	char	c;
	int		size;

	size = 0;
	c = va_arg(ap, int);
	if (opt.precision != -1)
		return (0);
	if (opt.flag_zero)
		return (0);
	if (opt.width == 0)
	{
		g_total_count++;
		write(1, &c, 1);
	}
	else
	{
		size += opt.width;
		if (!(s = ft_arr_char(opt, size, c)))
			return (0);
		ft_printstr(s, size, opt);
	}
	return (1);
}
