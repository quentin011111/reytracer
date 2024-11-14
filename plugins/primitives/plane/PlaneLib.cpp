/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PlaneLib
*/

#include "PlaneLib.hpp"

extern "C" raytracer::IPrimitives* createPrim(raytracer::prim_info_t prim)
{
    return new raytracer::Plane(prim);
}


