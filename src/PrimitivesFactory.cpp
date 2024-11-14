/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PrimitivesFactory
*/

#include "PrimitivesFactory.hpp"

raytracer::PrimitivesFactory::PrimitivesFactory()
{
    std::cout << "[LOG] FACTORY PRIM CREATED"  << std::endl;
    this->_sphere = std::make_unique<PrimitivesLibHandler>("./plugins/primitives/libsphere.so");
    this->_cone = std::make_unique<PrimitivesLibHandler>("./plugins/primitives/libcone.so");
    this->_plane = std::make_unique<PrimitivesLibHandler>("./plugins/primitives/libplane.so");
    this->_cylinder = std::make_unique<PrimitivesLibHandler>("./plugins/primitives/libcylinder.so");
}

raytracer::PrimitivesFactory::~PrimitivesFactory()
{
    std::cout << "[LOG] FACTORY PRIM DESTROYED" << std::endl;
}

raytracer::IPrimitives *raytracer::PrimitivesFactory::createPrim(raytracer::PrimType type, raytracer::prim_info_t primInfo)
{
    switch (type)
    {
    case raytracer::PrimType::SPHERE:
        return this->_sphere->createInstance(primInfo);
    case raytracer::PrimType::PLANE:
        return this->_plane->createInstance(primInfo);
    case raytracer::PrimType::CONE:
        return this->_cone->createInstance(primInfo);
    case raytracer::PrimType::CYLINDER:
        return this->_cylinder->createInstance(primInfo);
    default:
        return nullptr; // IMPOSSIBLE CASE
    }
}