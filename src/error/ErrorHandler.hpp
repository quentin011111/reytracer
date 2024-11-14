/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** ErrorHandler
*/

#ifndef ERRORHANDLER_HPP_
    #define ERRORHANDLER_HPP_

    #include "../RaytracerIncludes.hpp"

    namespace raytracer
    {
        class ErrorHandler {
            public:
                ErrorHandler();
                ~ErrorHandler();

                void setConfigFileName(std::string);
                std::string getConfigFileName() const;

                void checkArguments(int argc, char **argv);

            protected:
            private:
                void checkConfFile();
                void checkCameraParam(const libconfig::Setting&);
                void checkPrimitivesParam(const libconfig::Setting&);
                void checkLightsParam(const libconfig::Setting&);
                void checkSphere(const libconfig::Setting&);
                void checkPlane(const libconfig::Setting&);
                void checkCone(const libconfig::Setting&);
                void checkCylinder(const libconfig::Setting&);
                void checkColor(const libconfig::Setting&);
                void checkLightsPoint(const libconfig::Setting&);
                void checkLightsDirectional(const libconfig::Setting&);
                void checkTranslationParam(const libconfig::Setting&);
                void checkRotationParam(const libconfig::Setting&);
                std::string _fileName = "";
        };
    }

#endif /* !ERRORHANDLER_HPP_ */
