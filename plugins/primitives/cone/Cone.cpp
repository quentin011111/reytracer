/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Cone
*/

#include "Cone.hpp"

raytracer::Cone::Cone(raytracer::prim_info_t prim)
{
    this->setInfo(prim);
    std::cout << "CREATE CONE at " << prim.x << ", " << prim.y << ", " << prim.z << " with a radius of " << prim.r << std::endl;
    std::cout << "with that color " << prim.color.r << ", " << prim.color.g << ", " << prim.color.b << std::endl;
}

raytracer::Cone::~Cone()
{
    std::cout << "DESTROY CONE" << std::endl;
}

raytracer::prim_info_t raytracer::Cone::getInfo() const
{
    return this->_info;
}

void raytracer::Cone::setInfo(raytracer::prim_info_t prim)
{
    this->_info = prim;
}

raytracer::hit_info_t  raytracer::Cone::isHit(raytracer::Vector vector)
{
    (void)vector;
    raytracer::hit_info_t hitInfo;
    hitInfo.hit = false;
    return (hitInfo);
}