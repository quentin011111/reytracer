/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Ambient
*/

#include "Ambient.hpp"

raytracer::Ambient::Ambient(raytracer::light_info_t info)
{
    std::cout << "[LOG] CREATE AMBIANT LIGHT" << std::endl;
    std::cout << "Ambient " << info.ambient << std::endl;
    this->setInfo(info);
}

raytracer::Ambient::~Ambient()
{
    std::cout << "[LOG] DESTROY AMBIANT LIGHT" << std::endl;
}

void raytracer::Ambient::setInfo(raytracer::light_info_t info)
{
    this->_info = info;
}

raytracer::light_info_t raytracer::Ambient::getInfo() const
{
    return this->_info;
}
