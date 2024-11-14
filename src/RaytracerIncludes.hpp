/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Raytracer
*/

#ifndef RAYTRACERINCLUDES_HPP_
    #define RAYTRACERINCLUDES_HPP_

    // CPP LIB INCLUDES

    #include <iostream>
    #include <fstream>
    #include <memory>
    #include <dlfcn.h>
    #include <filesystem>
    #include <list>
    #include <libconfig.h++>
    #include <SFML/Graphics.hpp>
    #include <cmath>
    #include <sstream>
    #include <limits>

    // FILES INCLUDES

    #include "RaytracerStructuresAndEnum.hpp"
    #include "Material.hpp"
    #include "Tools.hpp"
    #include "error/exceptions/RaytracerExceptions.hpp"
    #include "error/ErrorHandler.hpp"
    #include "IPrimitives.hpp"
    #include "ILights.hpp"
    #include "PrimitivesComposite.hpp"
    #include "PrimitivesLibHandler.hpp"
    #include "LightsLibHandler.hpp"
    #include "Camera.hpp"
    #include "PrimitivesFactory.hpp"
    #include "LightsFactory.hpp"
    #include "draw/ppm/PpmGraphic.hpp"
    #include "draw/SFML/graphics.hpp"

#endif /* !RAYTRACERINCLUDES_HPP_ */
