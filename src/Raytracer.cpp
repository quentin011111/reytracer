/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** Raytracer
*/

#include "Raytracer.hpp"

raytracer::Raytracer::Raytracer()
{
    this->primFactory = std::make_shared<raytracer::PrimitivesFactory>();
    this->prims = std::make_shared<raytracer::PrimitivesComposite>();
    this->lightsFactory = std::make_shared<raytracer::LightsFactory>();
    this->material = std::make_shared<Material>();
    this->graphic = std::make_shared<PpmGraphic>();
}

raytracer::Raytracer::~Raytracer()
{
}

raytracer::PrimitivesFactory *raytracer::Raytracer::getPrimFactory() const
{
    return this->primFactory.get();
}

raytracer::LightsFactory *raytracer::Raytracer::getLightFactory() const
{
    return this->lightsFactory.get();
}

void raytracer::Raytracer::addSphere(const libconfig::Setting& spheres)
{
    double x, y, z, r;

    for (int i = 0; i < spheres.getLength(); i++) {
        spheres[i].lookupValue("x", x);
        spheres[i].lookupValue("y", y);
        spheres[i].lookupValue("z", z);
        spheres[i].lookupValue("r", r);
        if (spheres[i].exists("translation")) {
            double xx, yy, zz;
            spheres[i]["translation"].lookupValue("x", xx);
            spheres[i]["translation"].lookupValue("y", yy);
            spheres[i]["translation"].lookupValue("z", zz);
            x += xx;
            y += yy;
            z += zz;
        }
        raytracer::prim_info_t primInfo = raytracer::Tools::createPrimInfo(x, y, z, r, 0, 0, 0, 0, raytracer::Tools::createColorCnf(spheres[i]["color"]));
        this->prims->addChild(std::shared_ptr<IPrimitives>(this->getPrimFactory()->createPrim(raytracer::PrimType::SPHERE, primInfo)));
    }
}

void raytracer::Raytracer::addPlane(const libconfig::Setting& planes)
{
    double rx, ry, rz, position;

    for (int i = 0; i < planes.getLength(); i++) {
        planes[i].lookupValue("rx", rx);
        planes[i].lookupValue("ry", ry);
        planes[i].lookupValue("rz", rz);
        planes[i].lookupValue("position", position);
        if (planes[i].exists("translation")) {
            double positionBis;
            planes[i]["translation"].lookupValue("position", positionBis);
            position += positionBis;
        }
        if (planes[i].exists("rotation")) {
            double rxx, ryy, rzz;
            planes[i]["rotation"].lookupValue("rx", rxx);
            planes[i]["rotation"].lookupValue("ry", ryy);
            planes[i]["rotation"].lookupValue("rz", rzz);
            rx += rxx;
            ry += ryy;
            rz += rzz;
        }
        raytracer::prim_info_t primInfo = raytracer::Tools::createPrimInfo(position, 0, 0, 0, rx, ry, rz, 0, raytracer::Tools::createColorCnf(planes[i]["color"]));
        this->prims->addChild(std::shared_ptr<IPrimitives>(this->getPrimFactory()->createPrim(raytracer::PrimType::PLANE, primInfo)));
    }
}

void raytracer::Raytracer::addCone(const libconfig::Setting& cones)
{
    for (int i = 0; i < cones.getLength(); i++) {
        double x, y, z, height, radius, rx, ry, rz;

        cones[i].lookupValue("x", x);
        cones[i].lookupValue("y", y);
        cones[i].lookupValue("z", z);
        cones[i].lookupValue("rx", rx);
        cones[i].lookupValue("ry", ry);
        cones[i].lookupValue("rz", rz);
        cones[i].lookupValue("height", height);
        cones[i].lookupValue("r", radius);

        if (cones[i].exists("translation")) {
            double xx, yy, zz;
            cones[i]["translation"].lookupValue("x", xx);
            cones[i]["translation"].lookupValue("y", yy);
            cones[i]["translation"].lookupValue("z", zz);
            x += xx;
            y += yy;
            z += zz;
        }
        if (cones[i].exists("rotation")) {
            double rxx, ryy, rzz;
            cones[i]["rotation"].lookupValue("rx", rxx);
            cones[i]["rotation"].lookupValue("ry", ryy);
            cones[i]["rotation"].lookupValue("rz", rzz);
            rxx += rx;
            ryy += ry;
            ryy += rz;
        }

        raytracer::prim_info_t primInfo = raytracer::Tools::createPrimInfo(x, y, z, radius, height, rx, ry, rz, raytracer::Tools::createColorCnf(cones[i]["color"]));
        this->prims->addChild(std::shared_ptr<IPrimitives>(this->getPrimFactory()->createPrim(raytracer::PrimType::CONE, primInfo)));
    }
}

void raytracer::Raytracer::addCylinder(const libconfig::Setting& cylinders)
{
    for (int i = 0; i < cylinders.getLength(); i++) {
        double x, y, z, height, radius, rx, ry, rz;

        cylinders[i].lookupValue("x", x);
        cylinders[i].lookupValue("y", y);
        cylinders[i].lookupValue("z", z);
        cylinders[i].lookupValue("rx", rx);
        cylinders[i].lookupValue("ry", ry);
        cylinders[i].lookupValue("rz", rz);
        cylinders[i].lookupValue("height", height);
        cylinders[i].lookupValue("r", radius);

        if (cylinders[i].exists("translation")) {
            double xx, yy, zz;
            cylinders[i]["translation"].lookupValue("x", xx);
            cylinders[i]["translation"].lookupValue("y", yy);
            cylinders[i]["translation"].lookupValue("z", zz);
            x += xx;
            y += yy;
            z += zz;
        }
        if (cylinders[i].exists("rotation")) {
            double rxx, ryy, rzz;
            cylinders[i]["rotation"].lookupValue("rx", rxx);
            cylinders[i]["rotation"].lookupValue("ry", ryy);
            cylinders[i]["rotation"].lookupValue("rz", rzz);
            rxx += rx;
            ryy += ry;
            ryy += rz;
        }

        raytracer::prim_info_t primInfo = raytracer::Tools::createPrimInfo(x, y, z, radius, height, rx, ry, rz, raytracer::Tools::createColorCnf(cylinders[i]["color"]));
        this->prims->addChild(std::shared_ptr<IPrimitives>(this->getPrimFactory()->createPrim(raytracer::PrimType::CYLINDER, primInfo)));
    }
}

void raytracer::Raytracer::initPrim(const libconfig::Setting& prim)
{
    if (prim.exists("spheres"))
        this->addSphere(prim["spheres"]);
    if (prim.exists("planes"))
        this->addPlane(prim["planes"]);
    if (prim.exists("cylinders"))
        this->addCylinder(prim["cylinders"]);
    if (prim.exists("cones"))
        this->addCone(prim["cones"]);
}

void raytracer::Raytracer::initCamera(const libconfig::Setting& camera)
{
    int width, height;
    double viewField, pos_x, pos_y, pos_z, rot_x, rot_y, rot_z;

    camera.lookupValue("width", width);
    camera.lookupValue("height", height);
    camera.lookupValue("position_x", pos_x);
    camera.lookupValue("position_y", pos_y);
    camera.lookupValue("position_z", pos_z);
    camera.lookupValue("rotation_x", rot_x);
    camera.lookupValue("rotation_y", rot_y);
    camera.lookupValue("rotation_z", rot_z);
    camera.lookupValue("fieldOfView", viewField);

    this->camera = std::shared_ptr<Camera>(new Camera(raytracer::Tools::createCamera(width, height, pos_x, pos_y, pos_z, rot_x, rot_y, rot_z, viewField)));
}

void raytracer::Raytracer::addAmbient(const libconfig::Setting& ambient)
{
    double amb;

    ambient.lookupValue("ambient", amb);
    this->lights.push_back(std::shared_ptr<ILights>(this->getLightFactory()->createLight(raytracer::LightType::AMBIENT, raytracer::Tools::createLightInfo(amb))));
}

void raytracer::Raytracer::addLightPoint(const libconfig::Setting& point, double diffuse)
{
    double x;
    double y;
    double z;

    for (int i = 0; i < point.getLength(); i++) {
        point[i].lookupValue("x", x);
        point[i].lookupValue("y", y);
        point[i].lookupValue("z", z);
        this->lights.push_back(std::shared_ptr<ILights>(this->getLightFactory()->createLight(raytracer::LightType::DIFFUSE, raytracer::Tools::createLightInfo(0, diffuse, x, y, z))));
    }
}

void raytracer::Raytracer::addDirectional(const libconfig::Setting& directional, double diffuse)
{
    double rx;
    double ry;
    double rz;

    for (int i = 0; i < directional.getLength(); i++) {
        directional[i].lookupValue("rx", rx);
        directional[i].lookupValue("ry", ry);
        directional[i].lookupValue("rz", rz);
        this->lights.push_back(std::shared_ptr<ILights>(this->getLightFactory()->createLight(raytracer::LightType::DIRECTIONAL, raytracer::Tools::createLightInfo(0, diffuse, 0, 0, 0, rx, ry, rz))));
    }
}

void raytracer::Raytracer::initLights(const libconfig::Setting& lights)
{
    double diffuse;

    if (lights.exists("ambient"))
        this->addAmbient(lights);
    if (lights.exists("diffuse")) {
        lights.lookupValue("diffuse", diffuse);
    } else {
        return;
    }
    if (lights.exists("point"))
        this->addLightPoint(lights["point"], diffuse);
    if (lights.exists("directional"))
        this->addDirectional(lights["directional"], diffuse);
}

void raytracer::Raytracer::initConfFile(std::string confFile)
{
    libconfig::Config cfg;

    this->graphic->assignFile(confFile);

    cfg.readFile(confFile);
    const libconfig::Setting& camera = cfg.lookup("camera");
    const libconfig::Setting& primitives = cfg.lookup("primitives");
    const libconfig::Setting& lights = cfg.lookup("lights");

    this->initPrim(primitives);
    this->initCamera(camera);
    this->initLights(lights);
}

raytracer::Point raytracer::Raytracer::calculateRayDirection(double u, double v, const raytracer::cam_info_t& info)
{
    double aspectRatio = static_cast<double>(info.width) / info.height;
    double fov = info.view_field;

    double xNorm = (2.0f * static_cast<double>(u) / info.width - 1.0f) * aspectRatio;
    double yNorm = 1.0f - 2.0f * static_cast<double>(v) / info.height;

    double dirX_cam = xNorm * std::tan(fov * 0.5f * (M_PI / 180.0f));
    double dirY_cam = yNorm * std::tan(fov * 0.5f * (M_PI / 180.0f));
    double dirZ_cam = -1.0f; // Direction along the negative z-axis

    double yaw = info.rot_x * (M_PI / 180.0f);
    double pitch = info.rot_y * (M_PI / 180.0f);
    double roll = info.rot_z * (M_PI / 180.0f);

    double rotMatrix[9] = {
        std::cos(yaw) * std::cos(pitch),
        std::cos(yaw) * std::sin(pitch) * std::sin(roll) - std::sin(yaw) * std::cos(roll),
        std::cos(yaw) * std::sin(pitch) * std::cos(roll) + std::sin(yaw) * std::sin(roll),
        std::sin(yaw) * std::cos(pitch),
        std::sin(yaw) * std::sin(pitch) * std::sin(roll) + std::cos(yaw) * std::cos(roll),
        std::sin(yaw) * std::sin(pitch) * std::cos(roll) - std::cos(yaw) * std::sin(roll),
        -std::sin(pitch),
        std::cos(pitch) * std::sin(roll),
        std::cos(pitch) * std::cos(roll)
    };
    raytracer::Point rayDirection;
    rayDirection.x = rotMatrix[0] * dirX_cam + rotMatrix[1] * dirY_cam + rotMatrix[2] * dirZ_cam;
    rayDirection.y = rotMatrix[3] * dirX_cam + rotMatrix[4] * dirY_cam + rotMatrix[5] * dirZ_cam;
    rayDirection.z = rotMatrix[6] * dirX_cam + rotMatrix[7] * dirY_cam + rotMatrix[8] * dirZ_cam;

    rayDirection.x += info.pos_x;
    rayDirection.y += info.pos_y;
    rayDirection.z += info.pos_z;

    return (rayDirection);
}

void raytracer::Raytracer::calculate()
{
    raytracer::cam_info_t info = this->camera->getCameInfo();
    raytracer::Point origin = {info.pos_x, info.pos_y, info.pos_z};
    this->graphic->createPPMFile(info.width, info.height);
    std::string testImage;
    testImage.clear();
    std::stringstream currentpixel;

    for (int u = 0; u < info.height; u++) {
        for (int v = 0; v < info.width; v++) {
                raytracer::Point rayDirection = this->calculateRayDirection(v, u, info);
                raytracer::Vector rayVector = {origin, rayDirection};
                raytracer::hit_info_t infoImage = this->prims->isHit(rayVector);
                currentpixel << infoImage.color.r << " " << infoImage.color.g << " " << infoImage.color.b << std::endl;
                testImage.append(currentpixel.str());
                currentpixel.str("");
        }
    }
    this->graphic->draw(testImage);
}