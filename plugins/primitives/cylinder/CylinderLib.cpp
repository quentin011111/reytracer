/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** CylinderLib
*/

#include "CylinderLib.hpp"

extern "C" raytracer::IPrimitives* createPrim(raytracer::prim_info_t prim)
{
    return new raytracer::Cylinder(prim);
}


