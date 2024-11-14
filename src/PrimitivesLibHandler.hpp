/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** PrimitivesLibHandler
*/

#ifndef PRIMITIVESLIBHANDLER_HPP_
    #define PRIMITIVESLIBHANDLER_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class PrimitivesLibHandler
        {
            private:
                using CreatePrimitivesType = raytracer::IPrimitives* (*)(raytracer::prim_info_t);

                CreatePrimitivesType createFunction;
                void *handle = nullptr;

            public:
                PrimitivesLibHandler(const char* libPath) {
                    std::cout << "[LOG] CREATE LIB HANDLER PRIM" << std::endl;
                    this->handle = dlopen(libPath, RTLD_LAZY);
                    if (!this->handle) {
                        throw raytracer::exceptions::CantOpenLIbException();
                    }
                    this->createFunction = reinterpret_cast<CreatePrimitivesType>(dlsym(this->handle, "createPrim"));
                    if (!this->createFunction) {
                        std::cerr << "Erreur lors de la récupération du symbole 'createPrim' : " << dlerror() << std::endl;
                        this->closeLib();
                        return;
                    }
                }

                ~PrimitivesLibHandler() {
                    std::cout << "[LOG] DESTROY LIB HANDLER PRIM" << std::endl;
                    this->closeLib();
                }

                void closeLib()
                {
                    if (this->handle != nullptr) {
                        dlclose(this->handle);
                        this->handle = nullptr;
                    }
                }

                IPrimitives *createInstance(raytracer::prim_info_t prim)
                {
                    return this->createFunction(prim);
                }
        };
    }

#endif /* !PRIMITIVESLIBHANDLER_HPP_ */
