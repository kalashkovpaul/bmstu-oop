#ifndef DIRECTION_HPP_

#define DIRECTION_HPP_

enum Direction {
    down = -1,
    stay = 0,
    up = 1
};

Direction dir(int target, int floor);

#endif