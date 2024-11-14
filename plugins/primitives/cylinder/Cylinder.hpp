/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Cylinder : public raytracer::IPrimitives {
            public:
                Cylinder(raytracer::prim_info_t);
                ~Cylinder();

                raytracer::hit_info_t  isHit(raytracer::Vector vector) override;

                prim_info_t getInfo() const;
                void setInfo(prim_info_t);

            protected:
            private:
                raytracer::prim_info_t _info;
        };
    }


#endif /* !CYLINDER_HPP_ */
