/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WinRender.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:28:38 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/20 00:32:42 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/BSDL.hpp"

void Win::drawPixel(u_int32_t y, u_int32_t x, u_int32_t color)
{
    if (y >= this->h || x >= this->w)
        return ;
    this->colorBuffer[y * this->w + x] = color;
}

void           Win::clear_color_buffer(u_int32_t color)
{
    for (u_int32_t i = 0; i < this->n_pixel; i++)
        this->colorBuffer[i] = color;
}

void Win::draw_grid(void)
{
    for (u_int32_t i = 0; i < this->h; i++)
        for (uint32_t j = 0; j < this->w; j++)
            if (!(i % 10) || !(j % 10))
                drawPixel(i, j, 0x101010);
}

void Win::drawRecrangle(u_int32_t posX, u_int32_t posY, u_int32_t w, u_int32_t h, u_int32_t color)
{
    for (u_int32_t i = 0; i < h; i++)
        for (uint32_t j = 0; j < w; j++)
            drawPixel(i + posY, j + posX, color);
}