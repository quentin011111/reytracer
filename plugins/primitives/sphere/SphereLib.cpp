/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** SphereLib
*/

#include "SphereLib.hpp"

extern "C" raytracer::IPrimitives* createPrim(raytracer::prim_info_t prim)
{
    return new raytracer::Sphere(prim);
}


