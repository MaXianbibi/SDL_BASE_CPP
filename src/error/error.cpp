/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:06:02 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/19 22:15:36 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/BSDL.hpp"

void fatal(std::string msg)
{
    perror(msg.c_str());
    // free
    exit( 1 );
}

void fatal_SDL(std::string msg)
{
    std::cerr << msg << std::endl;
    SDL_GetError();
    // free
    exit( 1 );
}