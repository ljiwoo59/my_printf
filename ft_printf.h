#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define NULLSTR "(null)"

int				g_total_count;

typedef struct	s_option
{
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		dot;
	int		precision;
	int		flag_pre_va;
	int		num_m;
	char	type;
}				t_option;

int				ft_printf(const char *format, ...);
char			ft_is_type(char c);
void			ft_initialize(t_option *opt);
const char		*ft_set_width(const char *start, t_option *opt, va_list ap);
const char		*ft_set_precision(const char *start, t_option *opt, va_list ap);
const char		*ft_format(const char *start, va_list ap);
char			*ft_arr_percent(t_option opt, int size);
int				ft_percent_type(t_option opt);
char			*ft_left_blank(t_option opt, int size, char *c);
char			*ft_left_zero(int size, char *c);
char			*ft_right_blank(t_option opt, int size, char *c);
void			ft_printstr(char *s, int size, t_option opt);
char			*ft_arr_char(t_option opt, int size, char c);
int				ft_char_type(t_option opt, va_list ap);
char			*ft_hexa(long long num, char *p, t_option opt);
char			*ft_arr_ptr(t_option opt, int size, char *p);
int				ft_ptr_type(t_option opt, va_list ap);
char			*ft_left_blank_s(t_option opt, int size, char *p);
char			*ft_right_blank_s(t_option opt, int size, char *p);
int				ft_strlen(char *str);
char			*ft_arr_str(t_option *opt, va_list ap);
int				ft_str_type(t_option opt, va_list ap);
char			*ft_strcpy(char *dest, char *src, int len);
char			ft_toupper(char c);
char			*ft_itoa_base(long long i, int base, t_option *opt, char *p);
char			*ft_arr_num(t_option opt, char *s);
int				ft_num_type(t_option opt, va_list ap);
char			*ft_left_blank_n(t_option *opt, int size, char *p);
char			*ft_right_blank_n(t_option opt, int size, char *p);
char			*ft_left_zero_n(t_option opt, int sisze, char *p);
void			ft_total_size(t_option *opt, int *total, int *size);

#endif
