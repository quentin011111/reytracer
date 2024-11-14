/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

raytracer::Cylinder::Cylinder(raytracer::prim_info_t prim)
{
    this->setInfo(prim);
    std::cout << "CREATE CYLINDER at " << prim.x << ", " << prim.y << ", " << prim.z << " with a radius of " << prim.r << " and height of " << prim.height << std::endl;
    std::cout << "rotation of " << prim.rx << ", " << prim.ry << ", " << prim.rz << std::endl;
    std::cout << "with that color " << prim.color.r << ", " << prim.color.g << ", " << prim.color.b << std::endl;
}

raytracer::Cylinder::~Cylinder()
{
    std::cout << "DESTROY CYLINDER" << std::endl;
}

raytracer::prim_info_t raytracer::Cylinder::getInfo() const
{
    return this->_info;
}

void raytracer::Cylinder::setInfo(raytracer::prim_info_t prim)
{
    this->_info = prim;
}

raytracer::hit_info_t  raytracer::Cylinder::isHit(raytracer::Vector vector)
{
    (void)vector;
    raytracer::hit_info_t hitInfo;
    hitInfo.hit = false;
    return (hitInfo);
}