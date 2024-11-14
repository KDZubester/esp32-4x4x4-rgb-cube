#ifndef _ANIMATIONS_H
#define _ANIMATIONS_H

#include <Arduino.h>
#include <vector>

#include "Cube.h"
#include "globals.h"

#define BASIC_HOLD_TIME 50

// All Animations
#define UP_DOWN 0
#define LEFT_RIGHT 1
#define BACK_FRONT 2
#define NUM_ANIMATIONS 3

class Animations
{
public:
    Animations(Cube *cube) : _cube(cube),
                             _timer(0),
                             _refresh_animation(true),
                             _animation_complete(false),
                             _current_animation(0),

                             ///////////////////////////////////
                             // UP-DOWN Variable Definitions  //
                             ///////////////////////////////////
                             _up_down_layer(0),
                             _up(true),
                             _up_down_color{{RED, GREEN, BLUE}},
                             _up_down_color_index(0),

                             //////////////////////////////////////
                             // LEFT-RIGHT Variable Definitions  //
                             //////////////////////////////////////
                             _left_right_layer(0),
                             _right(true),
                             _left_right_color{{YELLOW, MAGENTA, CYAN}},
                             _left_right_color_index(0),

                             //////////////////////////////////////
                             // LEFT-RIGHT Variable Definitions  //
                             //////////////////////////////////////
                             _back_forth_layer(0),
                             _forth(true),
                             _back_forth_color{{RED, WHITE, BLUE}},
                             _back_forth_color_index(0)
    {
    }
    ~Animations() {};

    void animationController();
    void pickNewAnimation();

    ///////////////////////////////////
    // UP-DOWN Functions             //
    ///////////////////////////////////
    void upDownNewColor();
    void upDown();

    ///////////////////////////////////
    // LEFT-RIGHT Functions          //
    ///////////////////////////////////
    void leftRightNewColor();
    void leftRight();

    ///////////////////////////////////
    // BACK-FORTH Functions          //
    ///////////////////////////////////
    void backForthNewColor();
    void backForth();

private:
    Cube *_cube;
    int _timer;
    bool _refresh_animation;
    bool _animation_complete;
    int _current_animation;

    ///////////////////////////////////
    // UP-DOWN Variable Declarations //
    ///////////////////////////////////
    int _up_down_layer;
    bool _up;
    std::array<Color, 3> _up_down_color;
    int _up_down_color_index;

    //////////////////////////////////////
    // LEFT-RIGHT Variable Declarations //
    //////////////////////////////////////
    int _left_right_layer;
    bool _right;
    std::array<Color, 3> _left_right_color;
    int _left_right_color_index;

    //////////////////////////////////////
    // BACK-FORTH Variable Declarations //
    //////////////////////////////////////
    int _back_forth_layer;
    bool _forth;
    std::array<Color, 3> _back_forth_color;
    int _back_forth_color_index;
};

#endif