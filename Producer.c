/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Producer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:56:48 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/27 15:49:53 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	int	id;
	int	i;
	int	t;

	if (ac == 3)
	{
		id = ft_atoi_base(av[1], 10);
		while (*av[2])
		{
			ft_ursignals(SIGUSR1, SIGUSR2, confirm);
			paket(id, *av[2]++);
		}
		paket(id, '\0');
	}
	else
	{
		ft_putstr(RED);
		ft_putstr("•please respect this format •\t[pid] [msg]");
		ft_putstr(END);
		return (1);
	}
	return (0);
}

void	confirm(int sch)
{
	static int	i;

	if (sch == SIGUSR2)
		i++;
	else if (sch == SIGUSR1)
	{
		ft_putstr(GREEN);
		ft_putnub(i);
		ft_putstr("\tSignal Sent Successfully");
		ft_putstr(END);
		i++;
	}
}

void	paket(pid_t pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		usleep(100);
	}
}

void	ft_ursignals(int usr_1, int usr_2, void (*f)(int))
{
	signal(usr_2, f);
	signal(usr_1, f);
}
