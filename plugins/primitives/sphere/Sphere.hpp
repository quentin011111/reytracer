/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Sphere : public raytracer::IPrimitives {
            public:
                Sphere(raytracer::prim_info_t);
                ~Sphere();

                raytracer::hit_info_t  isHit(raytracer::Vector vector) override;

                prim_info_t getInfo() const;
                void setInfo(prim_info_t);

            protected:
            private:
                prim_info_t _info;
        };
    }


#endif /* !SPHERE_HPP_ */
