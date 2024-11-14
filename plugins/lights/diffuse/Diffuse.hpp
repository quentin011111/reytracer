/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Diffuse
*/

#ifndef DIFFUSE_HPP_
    #define DIFFUSE_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Diffuse : public raytracer::ILights {
            public:
                Diffuse(raytracer::light_info_t);
                ~Diffuse();

                void setInfo(raytracer::light_info_t);
                raytracer::light_info_t getInfo() const;

            protected:
            private:
                raytracer::light_info_t _info;
        };
    }

#endif /* !DIFFUSE_HPP_ */
