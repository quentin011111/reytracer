/*
** EPITECH PROJECT, 2024
** saved
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
    #define MATERIAL_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Material {
            public:
                Material();
                ~Material();

                raytracer::color_t applyMaterial(raytracer::color_t);

            protected:
            private:
        };
    }

#endif /* !MATERIAL_HPP_ */
