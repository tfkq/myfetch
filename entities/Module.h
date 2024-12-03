//
// Created by tfkq on 03.12.24.
//

#ifndef MYFETCH_MODULE_H
#define MYFETCH_MODULE_H


#include "../TextLine.h"
#include "../lib/nlohmann/json.hpp"

using json = nlohmann::json;

class Module : public TextLine{

private:
    std::string key;
    std::string value;

public:


    explicit Module(json config);

    ~Module() override;

    std::string str() override;

};


#endif //MYFETCH_MODULE_H
