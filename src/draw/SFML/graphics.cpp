/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-raytracer-noe.pereira
** File description:
** graphics.cpp
*/

#include "graphics.hpp"
#include <cmath>

using namespace raytracer;

const double PI = 3.14159265f;

// Fonction pour convertir les degrés en radians
double toRadians(double degrees) {
    return degrees * (PI / 180.0f);
}

SFMLGraphics::SFMLGraphics()
{
    window.create(sf::VideoMode(800, 600), "Affichage de page SFML");
}

SFMLGraphics::~SFMLGraphics()
{
}

void SFMLGraphics::drawSphere(double radius, int numMeridians, int numParallels)
{
    (void)radius;
    (void)numMeridians;
    (void)numParallels;
    // double theta, phi;
    // double dTheta = 360.0f / numMeridians;
    // double dPhi = 180.0f / numParallels;

    // sf::CircleShape sphereSlice(radius);

    // sphereSlice.setFillColor(sf::Color(255, 64, 64));

    // for (phi = 0; phi <= 180 - dPhi; phi += dPhi)
    // {
    //     for (theta = 0; theta <= 360 - dTheta; theta += dTheta)
    //     {
    //         double x = radius * std::sin(toRadians(phi)) * std::cos(toRadians(theta));
    //         double y = radius * std::sin(toRadians(phi)) * std::sin(toRadians(theta));

    //         sphereSlice.setPosition(x + window.getSize().x / 2, y + window.getSize().y / 2);

    //         window.draw(sphereSlice);
    //         sphereSlice.rotate(dTheta);

    //     }
    //     sphereSlice.rotate(-360);
    //     sphereSlice.rotate(dPhi);
    // }
}

void SFMLGraphics::draw()
{
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();

    //     drawSphere(100, 36, 18);

    //     window.display();
    // }
}



// int main()
// {
//     raytracer::SFMMGraphics graphics;
//     graphics.draw();

//     return 0;
// }
