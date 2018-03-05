
#include "ft.h"

int        is_type_flag(const char c)
{
    if (c == 's' || c == 'S' || c == 'p' || c == 'D' || c == 'i' || c == 'o'
            || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
            || c == 'c' || c == 'C')
        return (1);
    else
        return (0);
}

int     get_num(const char *format, t_data data)
{
  int n;
  
  n = 0;
  while (format[data->i] >= '0' && format[data->i] <= '9')
  {
      n *= 10;
      n += format[data->i];
      (data->i)++;
  }
  return (n);
}

void    get_modifier(const char *format, t_data data)
{ 
    data->flags->modifier[0] = format[data->i];
    data->flags->modifier[1] = 0;
    if (format[data->i] == 'h' && format[data->i + 1] == 'h')
            || (format[data->i] == 'l' && format[data->i + 1] == 'l'))
        data->flags->modifier[1] = format[(data->i)++];
    (data->i)++;
}

void	bs_case(const char *format, t_data data)
{
	(data->i)++;
	if (format[data->i] == 'n')
	else if (format[data->i] == 'r')
	else if (format[data->i] == 'b')
	else if (format[data->i] == 'v')
	else if (format[data->i] == '\')
	else if (format[data->i] == 'x')
	else if (format[data->i] == 'X')
	else if (format[data->i] >= '0' && format[data->i] <= '7')
}

char    *ft_get_flags(const char *format, va_list ap, t_data data)
{
    int		i;
	
	i = data->i;
    while (format[data->i])
    {
		if (format[data->i] == '\')
			bs_case(data, format);
        else if (format[data->i] == '#')
            data->flags->options[0] = 1;
        else if (format[data->i] == '-')
            data->flags->options[1] = 1;
        else if (format[data->i] == '+')
            data->flags->options[2] = 1;
        else if (format[data->i] == ' ' && !data->flags->options[2])
            data->flags->options[2] = 2;
        else if (format[data->i] == '0' && !data->flags->options[1])
            data->flags->options[1] = 2;
        else if (format[data->i] >= '1' && format[data->i] <= '9')
            data->flags->options[3] = get_num(format, data);
        else if (format[data->i] == '.')
		{
			(data->i)++;
        	data->flags->options[4] = get_num(format, data);
		}
		else if (format[data->i] == 'h' || format[data->i] == 'l'
                || format[data->i] == 'j' || format[data->i] == 'z')
            get_modifier(data, format);
        else if (is_type_flag(format[data->i]))
            return (ft_print_controller(format[data->i], ap, data));
        else
            return (ft_strsub(format, i, data->i));
        (data->i)++;
    }
    return (ft_strsub(format, i, data->i));
}
