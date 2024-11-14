/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Tools
*/

#include "Tools.hpp"

raytracer::color_t raytracer::Tools::createColorCnf(const libconfig::Setting& color)
{
    raytracer::color_t newColor;
    color.lookupValue("r", newColor.r);
    color.lookupValue("g", newColor.g);
    color.lookupValue("b", newColor.b);
    return newColor;
}

raytracer::color_t raytracer::Tools::createColor(int r, int g, int b)
{
    raytracer::color_t newColor;
    newColor.r = r;
    newColor.g = g;
    newColor.b = b;
    return newColor;
}

raytracer::prim_info_t raytracer::Tools::createPrimInfo(double x, double y,
    double z, double r, double height, double rx, double ry, double rz, raytracer::color_t color)
{
    raytracer::prim_info_t newInfo;
    newInfo.x = x;
    newInfo.y = y;
    newInfo.z = z;
    newInfo.r = r;
    newInfo.rx = rx;
    newInfo.ry = ry;
    newInfo.rz = rz;
    newInfo.height = height;
    newInfo.color = color;
    return newInfo;
}

raytracer::cam_info_t raytracer::Tools::createCamera(int width, int height,
    double pos_x, double pos_y, double pos_z, double rot_x, double rot_y, double rot_z, double viewField)
{
    raytracer::cam_info_t newInfo;
    newInfo.width = width;
    newInfo.height = height;
    newInfo.pos_x = pos_x;
    newInfo.pos_y = pos_y;
    newInfo.pos_z = pos_z;
    newInfo.rot_x = rot_x;
    newInfo.rot_y = rot_y;
    newInfo.rot_z = rot_z;
    newInfo.view_field = viewField;
    return newInfo;
}

raytracer::light_info_t raytracer::Tools::createLightInfo(double ambient, double diffuse,
    double x, double y, double z, double rx, double ry, double rz)
{
    raytracer::light_info_t newInfo;
    newInfo.ambient = ambient;
    newInfo.diffuse = diffuse;
    newInfo.x = x;
    newInfo.y = y;
    newInfo.z = z;
    newInfo.rx = rx;
    newInfo.ry = ry;
    newInfo.rz = rz;
    return newInfo;
}

raytracer::Vector raytracer::Tools::executeVectorRotation(raytracer::Vector &vector, double rot_x, double rot_y, double rot_z)
{
    double xRot = rot_x * M_PI / 180.0;
    double yRot = rot_y * M_PI / 180.0;
    double zRot = rot_z * M_PI / 180.0;

    double Rx[3][3] = {
        {1, 0, 0},
        {0, std::cos(xRot), -std::sin(xRot)},
        {0, std::sin(xRot), std::cos(xRot)}
    };

    double Ry[3][3] = {
        {std::cos(yRot), 0, std::sin(yRot)},
        {0, 1, 0},
        {-std::sin(yRot), 0, std::cos(yRot)}
    };

    double Rz[3][3] = {
        {std::cos(zRot), -std::sin(zRot), 0},
        {std::sin(zRot), std::cos(zRot), 0},
        {0, 0, 1}
    };

    raytracer::Vector newVector = vector;

    double xRx = (Rx[0][0] * vector.direction.x) + (Rx[0][1] * vector.direction.y) + (Rx[0][2] * vector.direction.z);
    double yRx = (Rx[1][0] * vector.direction.x) + (Rx[1][1] * vector.direction.y) + (Rx[1][2] * vector.direction.z);
    double zRx = (Rx[2][0] * vector.direction.x) + (Rx[2][1] * vector.direction.y) + (Rx[2][2] * vector.direction.z);

    double xRy = (Ry[0][0] * xRx) + (Ry[0][1] * yRx) + (Ry[0][2] * zRx);
    double yRy = (Ry[1][0] * xRx) + (Ry[1][1] * yRx) + (Ry[1][2] * zRx);
    double zRy = (Ry[2][0] * xRx) + (Ry[2][1] * yRx) + (Ry[2][2] * zRx);

    double xRz = (Rz[0][0] * xRy) + (Rz[0][1] * yRy) + (Rz[0][2] * zRy);
    double yRz = (Rz[1][0] * xRy) + (Rz[1][1] * yRy) + (Rz[1][2] * zRy);
    double zRz = (Rz[2][0] * xRy) + (Rz[2][1] * yRy) + (Rz[2][2] * zRy);

    newVector.direction.x = xRz;
    newVector.direction.y = yRz;
    newVector.direction.z = zRz;

    return (newVector);
}
