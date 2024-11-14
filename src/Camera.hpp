/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Camera {
            public:
                Camera(raytracer::cam_info_t);
                ~Camera();

                void setCamInfo(raytracer::cam_info_t);
                raytracer::cam_info_t getCameInfo() const;

            protected:
            private:
                raytracer::cam_info_t _info;

        };
    }
#endif /* !CAMERA_HPP_ */
