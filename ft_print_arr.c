#include "ft_printf.h"

void	ft_printstr(char *s, int size, t_option opt)
{
	int		i;
	char	c;

	i = 0;
	if (opt.type == 'X')
	{
		while (s[i])
		{
			c = ft_toupper(s[i++]);
			write(1, &c, 1);
			g_total_count++;
		}
	}
	else
	{
		while (i < size)
		{
			write(1, &s[i++], 1);
			g_total_count++;
		}
	}
	free(s);
}
