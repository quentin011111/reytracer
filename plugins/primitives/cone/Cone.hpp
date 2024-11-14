/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include "../../../src/RaytracerIncludes.hpp"

    namespace raytracer
    {
        class Cone : public raytracer::IPrimitives {
            public:
                Cone(raytracer::prim_info_t);
                ~Cone();

                raytracer::hit_info_t isHit(raytracer::Vector vector) override;

                prim_info_t getInfo() const;
                void setInfo(prim_info_t);

            protected:
            private:
                raytracer::prim_info_t _info;
        };
    }


#endif /* !CONE_HPP_ */
