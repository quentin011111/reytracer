/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** AmbientLib
*/

#include "AmbientLib.hpp"

extern "C" raytracer::ILights* createLights(raytracer::light_info_t info)
{
    return new raytracer::Ambient(info);
}
