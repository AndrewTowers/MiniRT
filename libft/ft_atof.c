double	ft_atof(const char *nptr)
{
	int	    i;
	double	n;
    double  decimal;
	int	    s;

	i = 0;
	n = 0.0;
	decimal = 0.1;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10.0 + (nptr[i] - '0');
        decimal *= 10.0;
		i++;
	}
	return (n * s) / decimal;
}
