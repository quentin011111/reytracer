/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Diffuse
*/

#include "Diffuse.hpp"

raytracer::Diffuse::Diffuse(raytracer::light_info_t info)
{
    std::cout << "[LOG] CREATE Diffuse LIGHT" << std::endl;
    std::cout << "Diffuse " << info.diffuse << "; " << info.x << ", " << info.y << ", " << info.z << std::endl;
    this->setInfo(info);
}

raytracer::Diffuse::~Diffuse()
{
    std::cout << "[LOG] DESTROY Diffuse LIGHT" << std::endl;
}

void raytracer::Diffuse::setInfo(raytracer::light_info_t info)
{
    this->_info = info;
}

raytracer::light_info_t raytracer::Diffuse::getInfo() const
{
    return this->_info;
}
