/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** ConeLib
*/

#include "ConeLib.hpp"

extern "C" raytracer::IPrimitives* createPrim(raytracer::prim_info_t prim)
{
    return new raytracer::Cone(prim);
}


