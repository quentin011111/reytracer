/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** LightsFactory
*/

#ifndef LIGHTSFACTORY_HPP_
    #define LIGHTSFACTORY_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class LightsFactory {
            public:
                LightsFactory();
                ~LightsFactory();

                raytracer::ILights *createLight(raytracer::LightType, raytracer::light_info_t);

            protected:
            private:
                std::unique_ptr<LightsLibHandler> _ambient;
                std::unique_ptr<LightsLibHandler> _diffuse;
                std::unique_ptr<LightsLibHandler> _directional;
                std::unique_ptr<LightsLibHandler> _dropshadow;
        };
    }

#endif /* !LIGHTSFACTORY_HPP_ */
