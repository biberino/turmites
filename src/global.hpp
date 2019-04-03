#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include <GL/glut.h> // GLUT
#include <GL/glu.h>  // GLU
#include <GL/gl.h>

#include <mutex>
#include <vector>
#include <cmath>

/**
 * Konstanten
 */
const int WIDTH = 1500;
const int HEIGHT = 1500;

const int pixel_h = 5;
const int pixel_w = 5;

const int pixel_darstellbar_x = WIDTH / pixel_w;
const int pixel_darstellbar_y = HEIGHT / pixel_h;

const int loop_timeout_ms = 20;

const int update_mult = 600;

struct Pos
{
    int x;
    int y;
    Pos(int x_p, int y_p)
    {
        x = x_p;
        y = y_p;
    }
};

struct v2
{
    int x;
    int y;

    v2()
    {
        x = 0;
        y = 0;
    }

    v2(int x_p, int y_p)
    {
        x = x_p;
        y = y_p;
    }

    v2(const v2 &vec)
    {
        x = vec.x;
        y = vec.y;
    }

    v2 operator+(const v2 &vec) const
    {
        return v2(x + vec.x, y + vec.y);
    }

    v2 operator-(const v2 &vec) const
    {
        return v2(x - vec.x, y - vec.y);
    }

    v2 operator*(double d) const
    {
        return v2(x * d, y * d);
    }

    v2 operator*(int d) const
    {
        return v2(x * d, y * d);
    }

    bool operator==(const v2 &vec) const
    {
        return ((x == vec.x) && (y == vec.y));
    }

    v2 &operator=(const v2 &vec)
    {
        x = vec.x;
        y = vec.y;
        return *this;
    }

    double length()
    {
        return std::sqrt((x * x) + (y * y));
    }

    double length_squared()
    {
        return (x * x) + (y * y);
    }

    void normalize()
    {
        double l = length();
        x = x / l;
        y = y / l;
    }

    std::string to_string()
    {
        return std::to_string(x) + " | " + std::to_string(y);
    }

    double dot(const v2 &vec) const
    {

        return (x * vec.x) + (y * vec.y);
    }
};



namespace colors
{
extern std::vector<GLfloat *> colorVec;
extern GLfloat blue[];
extern GLfloat red[];
extern GLfloat green[];
extern GLfloat violet[];
extern GLfloat brown[];
extern GLfloat darkbrown[];
extern GLfloat burlywood[];
extern GLfloat cadetblue[];
extern GLfloat chocolate[];
extern GLfloat cyan[];
extern GLfloat darkblue[];
extern GLfloat darkgray[];
extern GLfloat darkorchid[];
extern GLfloat deepskyblue[];
extern GLfloat himmel1[];
extern GLfloat himmel2[];
extern GLfloat himmel3[];
extern GLfloat himmel4[];
extern GLfloat himmel5[];
extern GLfloat gold[];
extern GLfloat greenyellow[];
extern GLfloat indigo[];
extern GLfloat khaki[];
extern GLfloat lightcoral[];
extern GLfloat lightpink[];
extern GLfloat magenta[];
extern GLfloat mediumspringgreen[];
extern GLfloat goldenrod[];
extern GLfloat white[];
} // namespace colors

/**
 * Global
 *
 */

extern std::mutex vec_mutex;

#endif /* end of include guard: GLOBAL_HPP */
