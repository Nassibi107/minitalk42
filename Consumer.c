/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Consumer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:09:00 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/26 19:49:28 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}
void shape_two()
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
void display_banner(int pid)
{

	shape_one();
	shape_two();
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

void    pid_handler(siginfo_t *sig_infos, int *client_pid, int *actual_pid)
{
    if (!(*client_pid))
        *client_pid = sig_infos->si_pid;
    *actual_pid = sig_infos->si_pid;
}

void    bit_handler(int sig_v, int *index,char *carac)
{
    if (sig_v == SIGUSR2)
        *carac |= (0x01 << *index);
    else if (sig_v == SIGUSR1)
        *carac |= (0x0 << *index);
}

void    caracter_handler(int c_pid,char *o, int *s_mssg, int *i)
{
    if (*o == '\0')
    {
        //ft_printf("\n\033[32m%d Signal Recieved Successfully\033[0m\n", *s_mssg);
        *s_mssg = 0x0;
        kill(c_pid, SIGUSR1);
    }
    *o = 0x0;
    *i = 0x0;
}

void    recieve_mssg(int sig, siginfo_t *sig_infos, void *nothing)
{
    static int                msg;
    static int                id_clt;
    static char    received_carac;
    static int                id_cur;
    static int                i;

    (void)nothing;
    pid_handler(sig_infos, &id_clt, &id_cur);
    if (id_clt != id_cur)
    {
        id_clt = sig_infos->si_pid;
        received_carac = 0;
        i = 0;
        msg = 0;
    }
    bit_handler(sig, &i, &received_carac);
    i++;
    msg++;
    if (i == 8)
    {
        ft_write (received_carac);
        caracter_handler(id_clt, &received_carac, &msg, &i);
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
    display_banner(getpid());
	 life = 'k';
	ft_sigactions_set (&sig_obj);
	//ft_printf("My Server's PID : %d\n", pid);
	ft_putnub(id);
	//ft_printf("\033[90mWaiting for a message...\033[0m\n");
	 ft_sigactions(SIGUSR1,SIGUSR2,&sig_obj);
	while (life)
		pause();
	return (0);
}
