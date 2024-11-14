/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** LightsFactory
*/

#include "LightsFactory.hpp"

raytracer::LightsFactory::LightsFactory()
{
    std::cout << "[LOG] FACTORY LIGHTS CREATED"  << std::endl;
    this->_ambient = std::make_unique<LightsLibHandler>("./plugins/lights/libambient.so");
    this->_diffuse = std::make_unique<LightsLibHandler>("./plugins/lights/libdiffuse.so");
    this->_directional = std::make_unique<LightsLibHandler>("./plugins/lights/libdirectional.so");
    this->_dropshadow = std::make_unique<LightsLibHandler>("./plugins/lights/libdropshadow.so");
}

raytracer::LightsFactory::~LightsFactory()
{
    std::cout << "[LOG] FACTORY LIGHTS DESTROYED" << std::endl;
}

raytracer::ILights *raytracer::LightsFactory::createLight(raytracer::LightType type, raytracer::light_info_t info)
{
    switch (type)
    {
    case raytracer::LightType::AMBIENT:
        return this->_ambient->createInstance(info);
    case raytracer::LightType::DIFFUSE:
        return this->_diffuse->createInstance(info);
    case raytracer::LightType::DIRECTIONAL:
        return this->_directional->createInstance(info);
    case raytracer::LightType::DROPSHADOW:
        return this->_dropshadow->createInstance(info);
    default:
        return nullptr; // IMPOSSIBLE CASE
    }
}
