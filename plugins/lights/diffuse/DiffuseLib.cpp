/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** DiffuseLib
*/

#include "DiffuseLib.hpp"

extern "C" raytracer::ILights* createLights(raytracer::light_info_t info)
{
    return new raytracer::Diffuse(info);
}
