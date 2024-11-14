/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** DirectionalLib
*/

#include "DirectionalLib.hpp"

extern "C" raytracer::ILights* createLights(raytracer::light_info_t info)
{
    return new raytracer::Directional(info);
}
