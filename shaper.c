/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:33:30 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/27 15:34:32 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shape_three(void)
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

void	shape_two(void)
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

void	shape_one(void)
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

void	show_me(int pid)
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
