/*
** EPITECH PROJECT, 2024
** Object-Oriented
** File description:
** RaytracerStructuresAndEnum
*/

#ifndef RAYTRACERSTRUCTURESANDENUM_HPP_
    #define RAYTRACERSTRUCTURESANDENUM_HPP_

    namespace raytracer
    {
        enum PrimType {
            NOTYPE,
            SPHERE,
            PLANE,
            CONE,
            CYLINDER
        };

        enum LightType {
            AMBIENT,
            DIFFUSE,
            DIRECTIONAL,
            DROPSHADOW
        };

        typedef struct Point
        {
            double x;
            double y;
            double z;
        } Point_t;

        typedef struct Vector
        {
            Point_t origin;
            Point_t direction;
        } vector_t;

        typedef struct Colors
        {
            int r;
            int g;
            int b;
        } color_t;

        typedef struct PrimInfo
        {
            double x;
            double y;
            double z;
            double r; // for circle
            double height;
            double rx;
            double ry;
            double rz;
            color_t color;
            Vector vector; // for plan
        } prim_info_t;

        typedef struct CameraInfo
        {
            int width;
            int height;
            double pos_x;
            double pos_y;
            double pos_z;
            double rot_x;
            double rot_y;
            double rot_z;
            double view_field;
        } cam_info_t;

        typedef struct LigthsInfo
        {
            double ambient;
            double diffuse;
            double x;
            double y;
            double z;
            double rx;
            double ry;
            double rz;
        } light_info_t;

        typedef struct HitInfo
        {
            bool hit;
            Colors color;
            Point point;
        } hit_info_t;
    }

#endif /* !RAYTRACERSTRUCTURESANDENUM_HPP_ */
