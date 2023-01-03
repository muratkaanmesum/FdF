#include "fdf.h"
int	hex_to_decimal(const char *hex)
{
	int	decimal;

	decimal = 0;
	int i, len, val;
	len = ft_strlen(hex);
	for (i = 0; i < len; i++)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			val = hex[i] - '0';
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			val = hex[i] - 'a' + 10;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			val = hex[i] - 'A' + 10;
		}
		decimal = decimal * 16 + val;
	}
	return (decimal);
}
