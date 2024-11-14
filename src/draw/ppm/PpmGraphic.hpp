/*
** EPITECH PROJECT, 2024
** saved
** File description:
** PpmGraphic
*/

#ifndef PPMGRAPHIC_HPP_
    #define PPMGRAPHIC_HPP_

    #include "../../RaytracerIncludes.hpp"

    namespace raytracer
    {
        class PpmGraphic {
            public:
                PpmGraphic();
                ~PpmGraphic();

                void setFileName(std::string);
                std::string getFileName();

                void assignFile(std::string);
                void createPPMFile(int width, int height);
                void writeHeader(int width, int height);
                void draw(std::string);

            protected:
            private:
                std::string _filename;

        };
    }

#endif /* !PPMGRAPHIC_HPP_ */
