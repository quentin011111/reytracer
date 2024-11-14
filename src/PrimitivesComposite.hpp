/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PrimitivesComposite
*/

#ifndef PRIMITIVESCOMPOSITE_HPP_
    #define PRIMITIVESCOMPOSITE_HPP_

    #include "Raytracer.hpp"

    namespace raytracer
    {
        class PrimitivesComposite : public raytracer::IPrimitives {
            public:
                PrimitivesComposite();
                ~PrimitivesComposite();

                raytracer::hit_info_t  isHit(raytracer::Vector) override;

                void addChild(std::shared_ptr<IPrimitives>);



            protected:
            private:
                std::list<std::shared_ptr<IPrimitives>> children;
        };
    }

#endif /* !PRIMITIVESCOMPOSITE_HPP_ */
