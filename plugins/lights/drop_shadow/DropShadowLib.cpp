/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** DropShadowLib
*/

#include "DropShadowLib.hpp"

extern "C" raytracer::ILights* createLights(raytracer::light_info_t info)
{
    return new raytracer::DropShadow(info);
}
