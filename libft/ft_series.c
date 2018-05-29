#include <libft.h>

double	ft_series_harmonic(int n)
{
	double	sum;
	int	i;

	if (n < 1)
		return (0);
	sum = 1;
	i = 1;
	while (++i <= n)
		sum += 1.0 / i;
	return (sum);
}
