/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Directional
*/

#ifndef DIRECTIONAL_HPP_
    #define DIRECTIONAL_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Directional : public raytracer::ILights {
            public:
                Directional(raytracer::light_info_t);
                ~Directional();

                void setInfo(raytracer::light_info_t);
                raytracer::light_info_t getInfo() const;

            protected:
            private:
                raytracer::light_info_t _info;
        };
    }

#endif /* !DIRECTIONAL_HPP_ */
