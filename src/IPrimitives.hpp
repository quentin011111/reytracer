/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** IPrimitives
*/

#ifndef IPRIMITIVES_HPP_
    #define IPRIMITIVES_HPP_

    namespace raytracer
    {
        class IPrimitives {
            public:
                virtual ~IPrimitives() = default;

                virtual raytracer::hit_info_t  isHit(raytracer::Vector vector) = 0; // TO MODIFIE AFTER

            protected:
            private:
        };
    }

#endif /* !IPRIMITIVES_HPP_ */
