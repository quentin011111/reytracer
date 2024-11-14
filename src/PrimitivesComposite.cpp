/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PrimitivesComposite
*/

#include "PrimitivesComposite.hpp"

raytracer::PrimitivesComposite::PrimitivesComposite()
{
    std::cout << "CREATE PRIM COMPOSITE" << std::endl;
}

raytracer::PrimitivesComposite::~PrimitivesComposite()
{
    std::cout << "DESTROY PRIM COMPOSITE" << std::endl;
}

raytracer::hit_info_t raytracer::PrimitivesComposite::isHit(raytracer::Vector vector)
// renvoie la structure hitInfo la plus proche de l'origine (celle que l'on doit afficher à l'écran).
{
    std::vector<raytracer::hit_info_t> hit_vector;
    raytracer::Colors color = {0, 0, 0};
    raytracer::hit_info_t trueHit;
    trueHit.color = color;
    trueHit.hit = false;

    double distance = __DBL_MAX__;

    double xA = vector.origin.x;
    double yA = vector.origin.y;
    double zA = vector.origin.z;

    for (const auto& prim: this->children) {
        hit_vector.push_back(prim->isHit(vector));
    }

    for (const raytracer::hit_info_t hitInfo : hit_vector) {
        if (hitInfo.hit == true) {
            double currentDistance = std::sqrt(std::pow(hitInfo.point.x - xA, 2) + std::pow(hitInfo.point.y - yA, 2) + std::pow(hitInfo.point.z - zA, 2));
            if (currentDistance < distance) {
                distance = currentDistance;
                trueHit = hitInfo;
            }
        }
    }


    return (trueHit);
}

void raytracer::PrimitivesComposite::addChild(std::shared_ptr<IPrimitives> child)
{
    this->children.push_front(child);
}