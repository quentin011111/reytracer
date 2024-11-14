/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** DropShadow
*/

#include "DropShadow.hpp"

raytracer::DropShadow::DropShadow(raytracer::light_info_t info)
{
    std::cout << "[LOG] CREATE DROPSHADOW LIGHT" << std::endl;
    std::cout << "DropShadow no info yet" << std::endl;
    this->setInfo(info);
}

raytracer::DropShadow::~DropShadow()
{
    std::cout << "[LOG] DESTROY DROPSHADOW LIGHT" << std::endl;
}

void raytracer::DropShadow::setInfo(raytracer::light_info_t info)
{
    this->_info = info;
}

raytracer::light_info_t raytracer::DropShadow::getInfo() const
{
    return this->_info;
}