/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** LightsLibHandler
*/

#ifndef LIGHTSLIBHANDLER_HPP_
    #define LIGHTSLIBHANDLER_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class LightsLibHandler
        {
            private:
                using CreateLightsType = raytracer::ILights* (*)(raytracer::light_info_t);

                CreateLightsType createFunction;
                void *handle = nullptr;

            public:
                LightsLibHandler(const char* libPath) {
                    std::cout << "[LOG] CREATE LIB HANDLER LIGHTS" << std::endl;
                    this->handle = dlopen(libPath, RTLD_LAZY);
                    if (!this->handle) {
                        throw raytracer::exceptions::CantOpenLIbException();
                    }
                    this->createFunction = reinterpret_cast<CreateLightsType>(dlsym(this->handle, "createLights"));
                    if (!this->createFunction) {
                        std::cerr << "Erreur lors de la récupération du symbole 'createLights' : " << dlerror() << std::endl;
                        this->closeLib();
                        return;
                    }
                }

                ~LightsLibHandler() {
                    std::cout << "[LOG] DESTROY LIB HANDLER LIGHTS" << std::endl;
                    this->closeLib();
                }

                void closeLib()
                {
                    if (this->handle != nullptr) {
                        dlclose(this->handle);
                        this->handle = nullptr;
                    }
                }

                ILights *createInstance(raytracer::light_info_t info)
                {
                    return this->createFunction(info);
                }
        };
    }

#endif /* !LIGHTSLIBHANDLER_HPP_ */
