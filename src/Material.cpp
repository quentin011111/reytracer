/*
** EPITECH PROJECT, 2024
** saved
** File description:
** Material
*/

#include "Material.hpp"

raytracer::Material::Material()
{
    std::cout << "CREATE MATERIAL" << std::endl;
}

raytracer::Material::~Material()
{
    std::cout << "DESTROY MATERIAL" << std::endl;
}

raytracer::color_t raytracer::Material::applyMaterial(raytracer::color_t color)
{
    return color;
}