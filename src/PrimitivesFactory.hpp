/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PrimitivesFactory
*/

#ifndef PRIMITIVESFACTORY_HPP_
    #define PRIMITIVESFACTORY_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class PrimitivesFactory {
            public:
                PrimitivesFactory();
                ~PrimitivesFactory();

                raytracer::IPrimitives *createPrim(raytracer::PrimType, raytracer::prim_info_t);

            protected:
            private:
                std::unique_ptr<PrimitivesLibHandler> _sphere;
                std::unique_ptr<PrimitivesLibHandler> _plane;
                std::unique_ptr<PrimitivesLibHandler> _cone;
                std::unique_ptr<PrimitivesLibHandler> _cylinder;
        };
    }


#endif /* !PRIMITIVESFACTORY_HPP_ */
