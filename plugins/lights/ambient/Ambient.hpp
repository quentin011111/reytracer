/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Ambient
*/

#ifndef AMBIENT_HPP_
    #define AMBIENT_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Ambient : public raytracer::ILights {
            public:
                Ambient(raytracer::light_info_t);
                ~Ambient();

                void setInfo(raytracer::light_info_t);
                raytracer::light_info_t getInfo() const;

            protected:
            private:
                raytracer::light_info_t _info;
        };
    }

#endif /* !AMBIENT_HPP_ */
