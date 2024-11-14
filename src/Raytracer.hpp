/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Raytracer
*/

#ifndef RAYTRACER_HPP_
    #define RAYTRACER_HPP_

    #include "RaytracerIncludes.hpp"

    namespace raytracer
    {
        class IPrimitives;

        class ILights;

        class Camera;

        class PrimitivesFactory;

        class PrimitivesComposite;

        class LightsFactory;

        class Material;

        class PpmGraphic;

        class Raytracer {
            public:
                Raytracer();
                ~Raytracer();

                PrimitivesFactory *getPrimFactory() const;
                LightsFactory *getLightFactory() const;
                void initConfFile(std::string);

                void initPrim(const libconfig::Setting&);
                void initCamera(const libconfig::Setting&);
                void initLights(const libconfig::Setting&);

                void calculate();

            protected:
            private:
                void addSphere(const libconfig::Setting&);
                void addPlane(const libconfig::Setting&);
                void addCone(const libconfig::Setting&);
                void addCylinder(const libconfig::Setting&);
                void addAmbient(const libconfig::Setting&);
                void addLightPoint(const libconfig::Setting&, double);
                void addDirectional(const libconfig::Setting&, double);
                raytracer::Point calculateRayDirection(double u, double v, const raytracer::cam_info_t &info);
                std::shared_ptr<PrimitivesFactory> primFactory;
                std::shared_ptr<PrimitivesComposite> prims;
                std::shared_ptr<LightsFactory> lightsFactory;
                std::list<std::shared_ptr<ILights>> lights;
                std::shared_ptr<Camera> camera;
                std::shared_ptr<Material> material;
                std::shared_ptr<PpmGraphic> graphic;
        };
    }


#endif /* !RAYTRACER_HPP_ */
