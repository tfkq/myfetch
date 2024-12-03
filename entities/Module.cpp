//
// Created by tfkq on 03.12.24.
//

#include "Module.h"

Module::Module(json config) {
    if (config.contains("key")) {
        key = config["key"].get<std::string>();
    }
    if (config.contains("value")) {
        value = config["value"].get<std::string>();
    }
}

Module::~Module() {

}

std::string Module::str() {
    return key + ": " + value;
}
