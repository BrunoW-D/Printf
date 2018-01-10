#include "ft.h"

char	*ft_realloc(char *str1, char *str2)
{
	char	*tmp;
	int		i;

	if (!str1 && !str2)
		return (NULL);
	if (!str1 && str2)
		return (str2);
	if (!str2)
		return (str1);
	tmp = ft_strdup(str1);
	if ((str1 = ft_strnew(ft_strlen(str1) + ft_strlen(str2))) == NULL)
		return (NULL);
	str1 = ft_strcpy(str1, tmp);
	str1 = ft_strcat(str1, str2);
	free(tmp);
	free(str2);
	str2 = NULL;
	return (str1);
}
