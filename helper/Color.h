//
// Created by tfkq on 03.12.24.
//

#ifndef MYFETCH_COLOR_H
#define MYFETCH_COLOR_H


#include <string>
#include "../lib/nlohmann/json.hpp"
#include "../entities/Title.h"


class Color {

    int r;
    int b;
    int g;

public:

    Color();

    Color(json config);

};


#endif //MYFETCH_COLOR_H
