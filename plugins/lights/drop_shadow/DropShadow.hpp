/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** DropShadow
*/

#ifndef DROPSHADOW_HPP_
    #define DROPSHADOW_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class DropShadow : public raytracer::ILights {
            public:
                DropShadow(raytracer::light_info_t);
                ~DropShadow();

                void setInfo(raytracer::light_info_t);
                raytracer::light_info_t getInfo() const;

            protected:
            private:
                raytracer::light_info_t _info;
        };
    }

#endif /* !DROPSHADOW_HPP_ */
