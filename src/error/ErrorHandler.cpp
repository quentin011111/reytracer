/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** ErrorHandler
*/

#include "ErrorHandler.hpp"

raytracer::ErrorHandler::ErrorHandler()
{
}

raytracer::ErrorHandler::~ErrorHandler()
{
}

void raytracer::ErrorHandler::setConfigFileName(std::string filename)
{
    this->_fileName = filename;
}

std::string raytracer::ErrorHandler::getConfigFileName() const
{
    return this->_fileName;
}

void raytracer::ErrorHandler::checkColor(const libconfig::Setting& sphere)
{
    if (!sphere.exists("r") || !sphere.exists("g") || !sphere.exists("b")) {
        throw raytracer::exceptions::IncorrectColorParamException();
    }
}

void raytracer::ErrorHandler::checkTranslationParam(const libconfig::Setting& translation)
{
    if (!translation.exists("x") || !translation.exists("y") || !translation.exists("z")) {
        throw raytracer::exceptions::InvalidParamTranslationException();
    }
}

void raytracer::ErrorHandler::checkRotationParam(const libconfig::Setting& rotation)
{
    if (!rotation.exists("rx") || !rotation.exists("ry") || !rotation.exists("rz")) {
        throw raytracer::exceptions::InvalidParamRotationException();
    }
}

void raytracer::ErrorHandler::checkSphere(const libconfig::Setting& settings)
{
    for (int i = 0; i < settings.getLength(); i++) {
        if (!settings[i].exists("x") || !settings[i].exists("y") || !settings[i].exists("z") ||
            !settings[i].exists("r") || !settings[i].exists("color")) {
                throw raytracer::exceptions::IncorrectPrimitivesParamException();
        }
        if (settings[i].exists("translation")) {
            this->checkTranslationParam(settings[i]["translation"]);
        }
        this->checkColor(settings[i]["color"]);
    }
}

void raytracer::ErrorHandler::checkPlane(const libconfig::Setting& settings)
{
    for (int i = 0; i < settings.getLength(); i++) {
        if (!settings[i].exists("axis") || !settings[i].exists("position") || !settings[i].exists("color")) {
                throw raytracer::exceptions::IncorrectPrimitivesParamException();
        }
        if (settings[i].exists("translation")) {
            if (!settings[i]["translation"].exists("position"))
                throw raytracer::exceptions::InvalidParamTranslationException();
        }
        if (settings[i].exists("rotation")) {
            this->checkTranslationParam(settings[i]["rotation"]);
        }
        this->checkColor(settings[i]["color"]);
    }
}

void raytracer::ErrorHandler::checkCone(const libconfig::Setting& settings)
{
    (void)settings;
}

void raytracer::ErrorHandler::checkCylinder(const libconfig::Setting& settings)
{
    (void)settings;
}

void raytracer::ErrorHandler::checkCameraParam(const libconfig::Setting& settings)
{
    const char* keys[] = {"width", "height", "position_x", "position_y", "position_z",
        "rotation_x", "rotation_y", "rotation_z", "fieldOfView"};
    if (settings.getLength() != 9)
        throw raytracer::exceptions::MoreThanOneCameraException();
    for (const auto& key : keys) {
        if (!settings.exists(key)) {
            throw raytracer::exceptions::IncorrectCameraParamException();
        }
    }
}

void raytracer::ErrorHandler::checkPrimitivesParam(const libconfig::Setting& settings)
{
    if (settings.exists("spheres")) {
        this->checkSphere(settings["spheres"]);
    } else if (settings.exists("planes") == 0) {
        this->checkPlane(settings["planes"]);
    } else if (settings.exists("cylinders") == 0) {
        this->checkCylinder(settings["cylinders"]);
    } else if (settings.exists("cones") == 0) {
        this->checkCone(settings["cones"]);
    } else {
        throw raytracer::exceptions::PrimitivesNoFoundException();
    }
}

void raytracer::ErrorHandler::checkLightsPoint(const libconfig::Setting& settings)
{
    for (int i = 0; i < settings.getLength(); i++) {
        if (!settings[i].exists("x") || !settings[i].exists("y") || !settings[i].exists("z")) {
                throw raytracer::exceptions::IncorrectLightsParamException();
        }
    }
}

void raytracer::ErrorHandler::checkLightsDirectional(const libconfig::Setting& settings)
{
    // TO DO
    // CHECK DIRECTIONAL LIGHT PARAM
    (void)settings;
}

void raytracer::ErrorHandler::checkLightsParam(const libconfig::Setting& settings)
{
    if (!settings.exists("ambient")) {
        throw raytracer::exceptions::IncorrectLightsParamException();
    } else if (!settings.exists("diffuse")) {
        throw raytracer::exceptions::IncorrectLightsParamException();
    } else if (settings.exists("point")) {
        this->checkLightsPoint(settings["point"]);
    } else if (settings.exists("directional")) {
        this->checkLightsDirectional(settings["directional"]);
    } else {
        throw raytracer::exceptions::IncorrectLightsParamException();
    }
}

void raytracer::ErrorHandler::checkConfFile()
{
    libconfig::Config cfg;

    try {
        cfg.readFile(this->getConfigFileName());
    } catch(const libconfig::FileIOException &fioex) {
        throw raytracer::exceptions::CantReadConfFileException();
    } catch(const libconfig::ParseException &pex) {
        throw raytracer::exceptions::SyntaxeErrorConfFileException();
    }
    if (!cfg.exists("camera")) {
        throw raytracer::exceptions::CameraNoFoundException();
    } else if (!cfg.exists("primitives")) {
        throw raytracer::exceptions::PrimitivesNoFoundException();
    } else if (!cfg.exists("lights")) {
        throw raytracer::exceptions::LightsNoFoundException();
    }
    const libconfig::Setting& camera = cfg.lookup("camera");
    const libconfig::Setting& primitives = cfg.lookup("primitives");
    const libconfig::Setting& lights = cfg.lookup("lights");
    this->checkCameraParam(camera);
    this->checkPrimitivesParam(primitives);
    this->checkLightsParam(lights);
    std::cout << "The configuration file : '" << this->getConfigFileName() << "' is correct." << std::endl;
}

void raytracer::ErrorHandler::checkArguments(int argc, char **argv)
{
    std::string filename;

    if (argc != 2)
        throw raytracer::exceptions::WrongNumberOfArgumentsException();

    filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open())
        throw raytracer::exceptions::CantOpenFileException();
    file.close();

    if (filename.length() >= 5) {
        std::string extension = filename.substr(filename.length() - 5);
        if (extension.compare(".conf") != 0)
            throw raytracer::exceptions::WrongFileExtensionException();
    } else {
        throw raytracer::exceptions::WrongFileExtensionException();
    }
    this->setConfigFileName(filename);
    this->checkConfFile();
}
