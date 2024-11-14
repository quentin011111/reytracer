/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Camera
*/

#include "Camera.hpp"

raytracer::Camera::Camera(raytracer::cam_info_t info)
{
    this->setCamInfo(info);
    std::cout << "CAM CREATED WITH " << info.width << " width, " << info.height << " height at " << info.pos_x << " x, " << info.pos_y << " y, " << info.pos_z << " z, ";
    std::cout << " with that rotation " << info.rot_x << ", " << info.rot_y << ", " << info.rot_z << " with this field of view " << info.view_field << " degres" << std::endl;
}

raytracer::Camera::~Camera()
{
    std::cout << "CAMERA DESTROYED" << std::endl;
}

void raytracer::Camera::setCamInfo(raytracer::cam_info_t info)
{
    this->_info = info;
}

raytracer::cam_info_t raytracer::Camera::getCameInfo() const
{
    return this->_info;
}