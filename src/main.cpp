/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:48:56 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 01:08:23 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Win.hpp"

int doingnothing(Win &win)
{
    win.clear_color_buffer(0);
    win.draw_grid();
    win.drawRecrangle(200, 200, 100, 100, 0xff);
    return (1);    
}

int main ( void )
{
    Win win(720, 480, "BSDL");
    
    win.updateFunc = doingnothing;
    win.loop();
    
}