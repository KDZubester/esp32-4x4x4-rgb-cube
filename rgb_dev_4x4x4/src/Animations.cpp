#include "Animations.h"

void Animations::animationController()
{
    switch (_current_animation)
    {
    case UP_DOWN:
        upDown();
        break;
    case LEFT_RIGHT:
        leftRight();
        break;
    case BACK_FRONT:
        backForth();
        break;

    default:
        upDown();
    }

    if (_animation_complete)
    {
        _animation_complete = false;
        _timer = 0;
        _current_animation++;
    }

    if (_current_animation >= NUM_ANIMATIONS)
    {
        _current_animation = 0;
    }

    _cube->renderCube();
}

void Animations::upDownNewColor()
{
    _up_down_color_index++;
    if (_up_down_color_index > _up_down_color.size() - 1)
    {
        _up_down_color_index = 0;
        _animation_complete = true;
    }
}

void Animations::upDown()
{
    _timer++;

    if (_refresh_animation)
    {
        _refresh_animation = false;

        _up_down_layer = 0;
        _up = true;
        _up_down_color_index = 0;
    }

    if (_timer > BASIC_HOLD_TIME)
    {
        _timer = 0;

        // Main animation action: Light Layer
        for (uint16_t i = 0; i < _cube->getYSize(); i++)
        {
            if (i == _up_down_layer)
            {
                _cube->setLayer(i, _up_down_color[_up_down_color_index]);
            }
            else
            {
                _cube->setLayer(i, BLACK);
            }
        }

        // Move animation up or down
        _up ? _up_down_layer++ : _up_down_layer--;

        // Check if animation has reached top of Cube
        if (_up_down_layer >= _cube->getYSize())
        {
            _up_down_layer = _cube->getYSize() - 2;
            _up = false;
        }

        // Check if animation has reached bottom of Cube
        if (_up_down_layer <= -1)
        {
            _up = true;
            _up_down_layer = 1;
            upDownNewColor();
        }
    }
}

void Animations::leftRightNewColor()
{
    _left_right_color_index++;
    if (_left_right_color_index > _left_right_color.size() - 1)
    {
        _left_right_color_index = 0;
        _animation_complete = true;
    }
}

void Animations::leftRight()
{
    _timer++;

    if (_refresh_animation)
    {
        _refresh_animation = false;

        _left_right_layer = 0;
        _right = true;
        _left_right_color_index = 0;
    }

    if (_timer > BASIC_HOLD_TIME)
    {
        _timer = 0;

        // Main animation action: Light Layer
        for (uint16_t i = 0; i < _cube->getXSize(); i++)
        {
            if (i == _left_right_layer)
            {
                _cube->setRow(i, _left_right_color[_left_right_color_index]);
            }
            else
            {
                _cube->setRow(i, BLACK);
            }
        }

        // Move animation up or down
        _right ? _left_right_layer++ : _left_right_layer--;

        // Check if animation has reached top of Cube
        if (_left_right_layer >= _cube->getXSize())
        {
            _left_right_layer = _cube->getXSize() - 2;
            _right = false;
        }

        // Check if animation has reached bottom of Cube
        if (_left_right_layer <= -1)
        {
            _right = true;
            _left_right_layer = 1;
            leftRightNewColor();
        }
    }
}

void Animations::backForthNewColor()
{
    _back_forth_color_index++;
    if (_back_forth_color_index > _back_forth_color.size() - 1)
    {
        _back_forth_color_index = 0;
        _animation_complete = true;
    }
}

void Animations::backForth()
{
    _timer++;

    if (_refresh_animation)
    {
        _refresh_animation = false;

        _back_forth_layer = 0;
        _forth = true;
        _back_forth_color_index = 0;
    }

    if (_timer > BASIC_HOLD_TIME)
    {
        _timer = 0;

        // Main animation action: Light Layer
        for (uint16_t i = 0; i < _cube->getZSize(); i++)
        {
            if (i == _back_forth_layer)
            {
                _cube->setColumn(i, _back_forth_color[_back_forth_color_index]);
            }
            else
            {
                _cube->setColumn(i, BLACK);
            }
        }

        // Move animation up or down
        _forth ? _back_forth_layer++ : _back_forth_layer--;

        // Check if animation has reached top of Cube
        if (_back_forth_layer >= _cube->getZSize())
        {
            _back_forth_layer = _cube->getZSize() - 2;
            _forth = false;
        }

        // Check if animation has reached bottom of Cube
        if (_back_forth_layer <= -1)
        {
            _forth = true;
            _back_forth_layer = 1;
            backForthNewColor();
        }
    }
}