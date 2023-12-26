/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:28:08 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/26 11:34:01 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_value (char c, int base)
{
	char *a = "0123456789abcdef";
	char *A = "01234567ABCDEF89";
	while (--base >= 0)
	{
		if (c == a[base] || c == a[base])
			return (1);
	}
	return (0);
}

static int	get_number (char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - ('a' - 10));
	else if (c >= 'A' && c <= 'f')
		return (c - ('A' - 10));
	return (-1);
}

int		ft_atoi_base(char *str, int base)
{
	int	i;
	int	rst;
	int	s;

	i = 0;
	rst = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			s*= -1;
		i++;
	}
	while (get_number(str[i]) != -1 && is_value(str[i], base))
	{
		rst = (rst * base) + get_number(str[i]);
		i++;
	}
	return (rst * s);
}
