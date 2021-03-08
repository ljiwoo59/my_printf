#include "ft_printf.h"

char	*ft_strcpy(char *dest, char *src, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_arr_str(t_option *opt, va_list ap)
{
	char	*s;
	char	*dst;
	int		size;

	if (!(s = va_arg(ap, char *)))
		s = NULLSTR;
	size = ft_strlen(s);
	if (!(dst = (char *)malloc(size)))
		return (NULL);
	if (opt->flag_pre_va)
		opt->precision = size;
	if (opt->precision < size && opt->precision > 0)
	{
		s = ft_strcpy(dst, s, opt->precision);
		size = ft_strlen(s);
	}
	if (opt->width > size)
		size = opt->width;
	if (opt->flag_minus)
		s = ft_right_blank(*opt, size, s);
	else if (!opt->flag_minus)
		s = ft_left_blank(*opt, size, s);
	free(dst);
	return (s);
}

int		ft_str_type(t_option opt, va_list ap)
{
	char	*s;
	int		size;

	if (opt.flag_zero)
		return (0);
	if ((opt.dot && opt.precision == -1 && opt.flag_pre_va == 0) ||
			opt.precision == 0)
	{
		size = opt.width;
		va_arg(ap, char *);
		while (size--)
		{
			write(1, " ", 1);
			g_total_count++;
		}
		return (1);
	}
	if (!(s = ft_arr_str(&opt, ap)))
		return (0);
	ft_printstr(s, ft_strlen(s), opt);
	return (1);
}
