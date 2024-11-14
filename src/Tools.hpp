/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Tools
*/

#ifndef TOOLS_HPP_
    #define TOOLS_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        struct Vector;

        class Tools {
            public:
                static raytracer::color_t createColorCnf(const libconfig::Setting&);

                static raytracer::color_t createColor(int r = 0, int g = 0, int b = 0);

                static raytracer::prim_info_t createPrimInfo(double x = 0, double y = 0, double z = 0,
                    double r = 0, double height = 0, double rx = 0, double zy = 0, double rz = 0, raytracer::color_t color = createColor());

                static raytracer::cam_info_t createCamera(int width = 1920, int height = 1080,
                    double pos_x = 0, double pos_y = 0, double pos_z = 0, double rot_x = 0,
                    double rot_y = 0, double rot_z = 0, double viewField = 70.0);

                static raytracer::light_info_t createLightInfo(double ambient = 0.5, double diffuse = 0.5,
                    double x = 0, double y = 0, double z = 0, double rx = 0, double ry = 0, double rz = 0);

                static raytracer::Vector executeVectorRotation(raytracer::Vector &vector, double rot_x, double rot_y, double rot_z);

            protected:
            private:
        };
    }


#endif /* !TOOLS_HPP_ */
