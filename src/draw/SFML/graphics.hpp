/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PrimitivesFactory
*/

#ifndef GRAPHICS_HPP_
    #define GRAPHICS_HPP_

    #include "./../../RaytracerIncludes.hpp"

    namespace raytracer
    {
        class SFMLGraphics {
            public:
                SFMLGraphics();
                ~SFMLGraphics();
                void drawSphere(double radius, int numMeridians, int numParallels);
                void draw();


            protected:
            private:
                sf::RenderWindow window;
        };
    }


#endif /* GRAPHICS_HPP_ */

