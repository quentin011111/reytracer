/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** RaytracerExceptions
*/

#ifndef RAYTRACEREXCEPTIONS_HPP_
    #define RAYTRACEREXCEPTIONS_HPP_

    #include "../../RaytracerIncludes.hpp"

    namespace raytracer
    {
        namespace exceptions
        {
            class WrongNumberOfArgumentsException : virtual public std::exception
            {
                public:
                    WrongNumberOfArgumentsException() {}

                    const char *what()const noexcept override {
                        return ("WrongNumberOfArgumentsException : The program must take 1 argument.");
                    };
            };

            class CantOpenFileException : virtual public std::exception
            {
                public:
                    CantOpenFileException() {}

                    const char *what()const noexcept override {
                        return ("CantOpenFileException : Can't open the file given as argument.");
                    };
            };

            class WrongFileExtensionException : virtual public std::exception
            {
                public:
                    WrongFileExtensionException() {}

                    const char *what()const noexcept override {
                        return ("WrongFileExtensionException : Your configuration file must have the '.conf' extension.");
                    };
            };

            class CantReadConfFileException : virtual public std::exception
            {
                public:
                    CantReadConfFileException() {}

                    const char *what()const noexcept override {
                        return ("CantReadConfFileException : Couldn't read your configuration file.");
                    };
            };

            class SyntaxeErrorConfFileException : virtual public std::exception
            {
                public:
                    SyntaxeErrorConfFileException() {}

                    const char *what()const noexcept override {
                        return ("SyntaxeErrorConfFileException : Syntaxe error in your configuration file.");
                    };
            };

            class CameraNoFoundException : virtual public std::exception
            {
                public:
                    CameraNoFoundException() {}

                    const char *what()const noexcept override {
                        return ("CameraNoFoundException : You must give at least one camera.");
                    };
            };

            class MoreThanOneCameraException : virtual public std::exception
            {
                public:
                    MoreThanOneCameraException() {}

                    const char *what()const noexcept override {
                        return ("MoreThanOneCameraException : You must give one and only camera.");
                    };
            };

            class IncorrectCameraParamException : virtual public std::exception
            {
                public:
                    IncorrectCameraParamException() {}

                    const char *what()const noexcept override {
                        return ("IncorrectCameraParamException : Camera param are incorrect.");
                    };
            };

            class PrimitivesNoFoundException : virtual public std::exception
            {
                public:
                    PrimitivesNoFoundException() {}

                    const char *what()const noexcept override {
                        return ("PrimitivesNoFoundException : You must give at least one primitives.");
                    };
            };

            class IncorrectPrimitivesParamException : virtual public std::exception
            {
                public:
                    IncorrectPrimitivesParamException() {}

                    const char *what()const noexcept override {
                        return ("IncorrectPrimitivesParamException : Primitives param are incorrect.");
                    };
            };

            class LightsNoFoundException : virtual public std::exception
            {
                public:
                    LightsNoFoundException() {}

                    const char *what()const noexcept override {
                        return ("LightsNoFoundException : You must give at least one lights.");
                    };
            };

            class IncorrectColorParamException : virtual public std::exception
            {
                public:
                    IncorrectColorParamException() {}

                    const char *what()const noexcept override {
                        return ("IncorrectColorParamException : Incorrect color param.");
                    };
            };

            class IncorrectLightsParamException : virtual public std::exception
            {
                public:
                    IncorrectLightsParamException() {}

                    const char *what()const noexcept override {
                        return ("IncorrectLightsParamException : Incorrect lights param.");
                    };
            };

            class CantOpenLIbException : virtual public std::exception
            {
                public:
                    CantOpenLIbException() {}

                    const char *what()const noexcept override {
                        return ("CantOpenLIbException : Error when trying to open the lib.");
                    };
            };

            class InvalidParamTranslationException : virtual public std::exception
            {
                public:
                    InvalidParamTranslationException() {}

                    const char *what()const noexcept override {
                        return ("InvalidParamTranslationException : Invalid param for a translation.");
                    };
            };

            class InvalidParamRotationException : virtual public std::exception
            {
                public:
                    InvalidParamRotationException() {}

                    const char *what()const noexcept override {
                        return ("InvalidParamTranslationException : Invalid param for a translation.");
                    };
            };
        }
    }

#endif /* !RAYTRACEREXCEPTIONS_HPP_ */
