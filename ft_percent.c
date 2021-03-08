#include "ft_printf.h"

char	*ft_arr_percent(t_option opt, int size)
{
	char	*s;
	char	c;

	c = '%';
	if (!opt.flag_minus && !opt.flag_zero)
		s = ft_left_blank(opt, size, &c);
	else if (!opt.flag_minus && opt.flag_zero)
		s = ft_left_zero(size, &c);
	else
		s = ft_right_blank(opt, size, &c);
	return (s);
}

int		ft_percent_type(t_option opt)
{
	char	*s;
	int		size;

	size = 0;
	if (opt.width == 0)
	{
		write(1, "%", 1);
		g_total_count++;
	}
	else
	{
		size += opt.width;
		if (!(s = ft_arr_percent(opt, size)))
			return (0);
		ft_printstr(s, ft_strlen(s), opt);
	}
	return (1);
}
