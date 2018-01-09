
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

int     get_num(const char **format, int *i)
{
  int n;
  
  n = 0;
  while ((*format)[*i] >= '0' && (*format)[*i] <= '9')
  {
      n *= 10;
      n += (*format)[*i];
      *i++;
  }
  return (n);
}

void    get_modifier(t_flags *flags, const char **format, int *i)
{ 
    (*flags)->modifier[0] = **format;
    (*flags)->modifier[1] = 0;
    if ((*format)[*i] == 'h' && (*format)[*i + 1] == 'h')
            || ((*format)[*i] == 'l' && (*format)[*i + 1] == 'l'))
        (*flags)->modifier[1] = **format++;
    *i++;
}

char    *ft_get_flags(const char **format, va_list ap, t_flags flags)
{
    int     i;
    char    *str;
    
    i = 0;
    while ((*format)[i])
    {
        if ((*format)[i] == '#')
            flags->options[0] = 1;
        else if ((*format)[i] == '-')
            flags->options[1] = 1;
        else if ((*format)[i] == '+')
            flags->options[2] = 1;
        else if ((*format)[i] == ' ' && !flags->options[2])
            flags->options[2] = 2;
        else if ((*format)[i] == '0' && !flags->options[1])
            flags->options[1] = 2;
        else if ((*format)[i] >= '1' && *format <= '9')
            flags->options[3] = get_num(format, &i);
        else if ((*format)[i] == '.')
            flags->options[4] = get_num(format, &(++i));
        else if ((*format)[i] == 'h' || (*format)[i] == 'l'
                || (*format)[i] == 'j' || (*format)[i] == 'z')
            get_modifier(&flags, format, &i);
        else if ((*format)[i] == '%')
            return (ft_strdup("%"));
        else if (is_type_flag((*format)[i]))
            return ((str = ft_print_controller((*format)[i], ap, flags)));
        else
            return ((str = ft_strndup(*format, i)));
        i++;
    }
    return ((str = ft_strndup(*format, i)));
}
