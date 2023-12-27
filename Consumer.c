/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Consumer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:09:00 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/27 14:07:06 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void shape_three()
{

	ft_putstr(" \n\t");
	ft_putstr(MAGENTA);
	ft_putstr("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗");
	ft_putstr(END);
	ft_putstr("\n\t");
	ft_putstr(MAGENTA);
	ft_putstr("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝");
	ft_putstr(END);
	ft_putstr("\n");
	ft_putstr(RED);
}

void shape_two ()
{
	ft_putstr("\n\t");
	ft_putstr(MAGENTA);
	ft_putstr("███╗   ███╗██╗███╗ ██╗██╗████████╗ █████╗ ██╗     ██╗██╗");
	ft_putstr(END);
	ft_putstr("\n\t");
	ft_putstr(MAGENTA);
	ft_putstr("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝");
	ft_putstr(END);
	ft_putstr(" \n\t");
	ft_putstr(MAGENTA);
	ft_putstr("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗");
	ft_putstr(END);
	shape_three();
}

void shape_one()
{
	ft_putstr("\n\t");
	ft_putstr(CYAN);
	ft_putstr("╔══════════════════════════════════════════════════╗");
	ft_putstr(END);
	ft_putstr("\n\t");
	ft_putstr(CYAN);
	ft_putstr("║                yassine nassibi 42                ║");
	ft_putstr(END);
	ft_putstr("\n\t");
	ft_putstr(CYAN);
	ft_putstr("╚══════════════════════════════════════════════════╝");
	ft_putstr(END);
	ft_putstr("\t");
	shape_two();
}


void show_me(int pid)
{

	shape_one();
	ft_putstr("\tPID: ");
	ft_putnub(pid);
	ft_putstr(END);
	ft_putstr("\t\t\t");
	ft_putstr(MAGENTA);
	ft_putstr("By: ynassibi");
	ft_putstr(END);
	ft_putstr("\n\t");
	ft_putstr(MAGENTA);
	ft_putstr("\t");
	ft_putstr("⊱ ───────────── {•_•} ────────────── ⊰");
	ft_putstr(END);
	ft_putstr("\n\n");
}

void    pid_handler( int *id_clt, int *id_cur,siginfo_t *info)
{
    if (*id_clt == 0)
        *id_clt = info->si_pid;
    *id_cur = info->si_pid;
}



void    binding(int id,char *o, int *msg, int *i)
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
void	Exchange(int sig, int *i,char *c)
{
	int n;
	n = 1;
    if (sig == SIGUSR1)
        *c = *c | (!n << *i);
    else if (sig == SIGUSR2)
        *c = *c | (n << *i);
}

void    recieve_mssg(int sig, siginfo_t *sig_infos, void *nothing)
{
    static int                msg;
    static int                id_clt;
    static char    key;
    static int                id_cur;
    static int                i;

    (void)nothing;
    pid_handler( &id_clt, &id_cur,sig_infos);
    if (id_clt != id_cur)
    {
        id_clt = sig_infos->si_pid;
        key = 0;
        i = 0;
        msg = 0;
    }
    Exchange(sig, &i, &key);
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

void ft_sigactions (int usr_1, int usr_2 , struct sigaction *sig)
{
	sigaction(SIGUSR1, sig, 0x0);
		sigaction(SIGUSR2, sig, 0x0);
}
void ft_sigactions_set (struct sigaction *obj)
{
	obj->sa_flags = 0x0040;
	obj->sa_sigaction = recieve_mssg;
	 sigemptyset(&obj->sa_mask);
}

int	main(void)
{
	struct sigaction	sig_obj;
	int		id;
	char life ;
    show_me(getpid());
	 life = 'k';
	ft_sigactions_set (&sig_obj);
	ft_putnub(id);
	ft_sigactions(SIGUSR1,SIGUSR2,&sig_obj);
	while (life)
		pause();
	return (0);
}
