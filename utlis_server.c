/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:38:44 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/27 16:36:32 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_mssg(int sig, siginfo_t *sig_infos, void *nothing)
{
	static int		msg;
	static int		id_clt;
	static char		key;
	static int		id_cur;
	static int		i;

	(void)nothing;
	pid_handler(&id_clt, &id_cur, sig_infos);
	if (id_clt != id_cur)
	{
		id_clt = sig_infos->si_pid;
		key = 0;
		i = 0;
		msg = 0;
	}
	exchange(sig, &i, &key);
	i++;
	msg++;
	if (i == 8)
	{
		ft_write (key);
		binding(id_clt, &key, &msg, &i);
	}
	usleep(100);
	kill(id_clt, SIGUSR2);
}

void	ft_sigactions(int usr_1, int usr_2, struct sigaction *sig)
{
	sigaction(usr_1, sig, 0x0);
	sigaction(usr_2, sig, 0x0);
}

void	ft_sigactions_set(struct sigaction *obj)
{
	obj->sa_flags = 0x0040;
	obj->sa_sigaction = recieve_mssg;
	sigemptyset(&obj->sa_mask);
}
