/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Consumer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:09:00 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/27 16:32:08 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sig_obj;
	int					id;
	char				life ;

	id = 0;
	show_me(getpid());
	life = 'k';
	ft_sigactions_set (&sig_obj);
	ft_putnub(id);
	ft_sigactions(SIGUSR1, SIGUSR2, &sig_obj);
	while (life)
		pause();
	return (0);
}

void	pid_handler( int *id_clt, int *id_cur, siginfo_t *info)
{
	if (*id_clt == 0)
		*id_clt = info->si_pid;
	*id_cur = info->si_pid;
}

void	binding(int id, char *o, int *msg, int *i)
{
	if (!*o)
	{
		ft_putstr(GREEN);
		ft_putstr("\nSignal Recieved Successfully\t{");
		ft_putnub(*msg);
		ft_write('}');
		ft_putstr(END);
		ft_write('\n');
		*msg = 0;
		kill(id, SIGUSR1);
	}
	*i = 0;
	*o = 0;
}

void	exchange(int sig, int *i, char *c)
{
	int	n;

	n = 1;
	if (sig == SIGUSR1)
		*c = *c | (!n << *i);
	else if (sig == SIGUSR2)
		*c = *c | (n << *i);
}
