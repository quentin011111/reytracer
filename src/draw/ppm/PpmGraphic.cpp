/*
** EPITECH PROJECT, 2024
** saved
** File description:
** PpmGraphic
*/

#include "PpmGraphic.hpp"

raytracer::PpmGraphic::PpmGraphic()
{
}

raytracer::PpmGraphic::~PpmGraphic()
{
}

void raytracer::PpmGraphic::setFileName(std::string fileName)
{
    this->_filename = fileName;
}

std::string raytracer::PpmGraphic::getFileName()
{
    return this->_filename;
}

void raytracer::PpmGraphic::assignFile(std::string fileName)
{
    std::string oldName;
    std::string newName;
    std::string finalName = "ppm/";
    size_t lastSeparator = fileName.find_last_of("/\\");

    if (lastSeparator != std::string::npos) {
        newName = fileName.substr(lastSeparator + 1);
    } else {
        newName = fileName;
    }
    oldName = newName.substr(0, newName.length() - 5);
    newName.append(".ppm");
    finalName.append(newName);
    this->setFileName(finalName);
}

void raytracer::PpmGraphic::writeHeader(int width, int height)
{
    std::ofstream file(this->getFileName());

    if (file.is_open()) {
        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << "255" << std::endl;
    }
    file.close();
}

void raytracer::PpmGraphic::createPPMFile(int width, int height)
{
    std::ofstream file(this->getFileName(), std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }
    file.close();
    this->writeHeader(width, height);
}

void raytracer::PpmGraphic::draw(std::string image)
{
    std::ofstream file(this->getFileName(), std::ios::app);

    if (file.is_open()) {
        file << image;
    }
    file.close();
}