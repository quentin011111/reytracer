/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Directional
*/

#include "Directional.hpp"

raytracer::Directional::Directional(raytracer::light_info_t info)
{
    std::cout << "[LOG] CREATE DIRECTIONAL LIGHT" << std::endl;
    std::cout << "Directional " << info.diffuse << "; " << info.rx << ", " << info.ry << ", " << info.rz << std::endl;
    this->setInfo(info);
}

raytracer::Directional::~Directional()
{
    std::cout << "[LOG] DESTROY DIRECTIONAL LIGHT" << std::endl;
}

void raytracer::Directional::setInfo(raytracer::light_info_t info)
{
    this->_info = info;
}

raytracer::light_info_t raytracer::Directional::getInfo() const
{
    return this->_info;
}
