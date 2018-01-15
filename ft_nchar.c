char	*ft_nchar (char c, size_t n)
{
	char	str[n + 1];
	size_t	i;
	
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[n] = 0;
	return (str);
}
