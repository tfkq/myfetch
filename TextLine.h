//
// Created by tfkq on 03.12.24.
//

#ifndef MYFETCH_TEXTLINE_H
#define MYFETCH_TEXTLINE_H


#include <string>

class TextLine {

public:

    virtual ~TextLine() = default;

    virtual std::string str() = 0;

};


#endif //MYFETCH_TEXTLINE_H
