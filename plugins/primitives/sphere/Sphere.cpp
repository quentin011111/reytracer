/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Sphere
*/

#include "Sphere.hpp"

raytracer::Sphere::Sphere(raytracer::prim_info_t prim)
{
    this->setInfo(prim);
    std::cout << "CREATE SPHERE at " << prim.x << ", " << prim.y << ", " << prim.z << " with a radius of " << prim.r << std::endl;
    std::cout << "with that color " << prim.color.r << ", " << prim.color.g << ", " << prim.color.b << std::endl;
}

raytracer::Sphere::~Sphere()
{
    std::cout << "DESTROY SPHERE" << std::endl;
}

raytracer::prim_info_t raytracer::Sphere::getInfo() const
{
    return this->_info;
}

void raytracer::Sphere::setInfo(raytracer::prim_info_t prim)
{
    this->_info = prim;
}

raytracer::hit_info_t  raytracer::Sphere::isHit(raytracer::Vector vector)
// gérer si la distance est negative (ducoup que l'objet touche mais derriere la camera donc hors champ)
{
    raytracer::hit_info_t hitInfo;

    double xA = vector.origin.x;
    double yA = vector.origin.y;
    double zA = vector.origin.z;

    double xB = vector.direction.x;
    double yB = vector.direction.y;
    double zB = vector.direction.z;

    double xC = _info.x;
    double yC = _info.y;
    double zC = _info.z;
    double r = _info.r;

    double a = (std::pow(xB - xA, 2) + std::pow(yB - yA, 2) + std::pow(zB - zA, 2));
    double b = 2 * ((xB - xA) * (xA - xC) + (yB - yA) * (yA - yC) + (zB - zA) * (zA - zC));
    double c = (std::pow(xA - xC, 2) + std::pow(yA - yC, 2) + std::pow(zA - zC, 2) - std::pow(r, 2));

    double delta = std::pow(b, 2) - 4 * a * c;
    double t1 = 0.0;
    double t2 = 0.0;

    if (delta < 0) {
        hitInfo.hit = false;
    } else if (delta == 0) {
        hitInfo.hit = true;
        t1 = -b / (2 * a);
        raytracer::Point hitPoint = {xA + t1 * (xB - xA), yA + t1 * (yB - yA), zA + t1 * (zB - zA)};
        hitInfo.point = hitPoint;
        hitInfo.color = _info.color;
    } else if (delta > 0) {
        hitInfo.hit = true;
        t1 = (-b + std::sqrt(delta)) / (2 * a);
        t2 = (-b - std::sqrt(delta)) / (2 * a);
        raytracer::Point hitPoint1 = {xA + t1 * (xB - xA), yA + t1 * (yB - yA), zA + t1 * (zB - zA)};
        raytracer::Point hitPoint2 = {xA + t2 * (xB - xA), yA + t2 * (yB - yA), zA + t2 * (zB - zA)};
        double distanceOriginP1 = std::sqrt(std::pow(hitPoint1.x - xA, 2) + std::pow(hitPoint1.y - yA, 2) + std::pow(hitPoint1.z - zA, 2));
        double distanceOriginP2 = std::sqrt(std::pow(hitPoint2.x - xA, 2) + std::pow(hitPoint2.y - yA, 2) + std::pow(hitPoint2.z - zA, 2));
        if (distanceOriginP1 < distanceOriginP2) {
            hitInfo.point = hitPoint1;
        } else {
            hitInfo.point = hitPoint2;
        }
        hitInfo.color = _info.color;
    }
    return (hitInfo);
}