/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Main
*/

#include "Raytracer.hpp"

void printUsage(void)
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

int main(int argc, char **argv)
{
    // raytracer::SFMLGraphics graphics;
    raytracer::ErrorHandler error;
    raytracer::Raytracer ray;

    try {
        error.checkArguments(argc, argv);
    } catch (std::exception &e) {
        printUsage();
        std::cerr << std::endl << e.what() << std::endl;
        exit(84);
    }
    ray.initConfFile(error.getConfigFileName());
    ray.calculate();
    return 0;
}
