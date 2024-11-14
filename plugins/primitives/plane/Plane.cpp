/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Plane
*/

#include "Plane.hpp"

raytracer::Plane::Plane(raytracer::prim_info_t prim)
{
    this->setInfo(prim);
    std::cout << "CREATE PLANE at " << prim.x << ", " << prim.y << ", " << prim.z << " with " << prim.rx << ", " << prim.ry << ", " << prim.rz << std::endl;
    std::cout << "with that color " << prim.color.r << ", " << prim.color.g << ", " << prim.color.b << std::endl;
}

raytracer::Plane::~Plane()
{
    std::cout << "DESTROY PLANE" << std::endl;
}

raytracer::prim_info_t raytracer::Plane::getInfo() const
{
    return this->_info;
}

void raytracer::Plane::setInfo(raytracer::prim_info_t prim)
{
    this->_info = prim;
    raytracer::Point originPoint = {prim.x, prim.y, prim.z};
    raytracer::Point destinationPoint = {prim.x, prim.y, prim.z + 1.0};
    raytracer::Vector vector = {originPoint, destinationPoint};
    this->_info.vector = raytracer::Tools::executeVectorRotation(vector, prim.rx, prim.ry, prim.rz);
}

raytracer::hit_info_t  raytracer::Plane::isHit(raytracer::Vector vector)
// equation of form ax + by + cz + d = 0
{
    raytracer::hit_info_t hitInfo;

    double a = _info.vector.direction.x - _info.vector.origin.x;
    double b = _info.vector.direction.y - _info.vector.origin.y;
    double c = _info.vector.direction.z - _info.vector.origin.z;
    double d = a * (- _info.x) + b * (- _info.y) + c * (- _info.z);

    double vx = vector.direction.x - vector.origin.x;
    double vy = vector.direction.y - vector.origin.y;
    double vz = vector.direction.z - vector.origin.z;

    double denominator = a * vx + b * vy + c * vz;
    if (std::abs(denominator) < 1e-6) {
        hitInfo.hit = false;
        return (hitInfo);
    }

    double t = -(a * vector.origin.x + b * vector.origin.y + c * vector.origin.z + d) / denominator;

    if (t < 0) {
        hitInfo.hit = false;
        return (hitInfo);
    }

    raytracer::Point hitPoint = {vector.origin.x + t * vx, vector.origin.y + t * vy, vector.origin.z + t * vz};
    hitInfo.hit = true;
    hitInfo.point = hitPoint;
    hitInfo.color = _info.color;

    return (hitInfo);
}
