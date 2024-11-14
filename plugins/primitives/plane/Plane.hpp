/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Plane
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Plane : public raytracer::IPrimitives {
            public:
                Plane(raytracer::prim_info_t);
                ~Plane();

                raytracer::hit_info_t  isHit(raytracer::Vector vector) override;

                prim_info_t getInfo() const;
                void setInfo(prim_info_t);

            protected:
            private:
                raytracer::prim_info_t _info;
        };
    }


#endif /* !PLANE_HPP_ */
