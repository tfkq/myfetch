#include <iostream>
#include <fstream>
#include "lib/nlohmann/json.hpp"
#include "TextLine.h"
#include "entities/Title.h"
#include "entities/Module.h"
#include "helper/Color.h"

using json = nlohmann::json;

int main() {

    //* PARSE JSON
    //TODO check differents path, for example in ~/.config/myfetch/myfetch.jsonc
    std::ifstream json_file;
    json_file.open("../myfetch.jsonc");
    if (!json_file.is_open()) {
        std::cerr << "ERR: couldn't open config file" << std::endl;
        return 1;
    }
    json config = json::parse(json_file, nullptr, true, true);
    json_file.close();

    // logo
    std::vector<std::string> logo;
    if (config.contains("logo")) {
        auto l = config["logo"];
        if (l.contains("path")) {
            std::ifstream logo_file;
            logo_file.open("../" + l["path"].get<std::string>()); //TODO multiple paths see above
            if (logo_file.is_open()) {
                std::string line;
                while (std::getline(logo_file, line)) {
                    std::istringstream iss(line);
                    logo.push_back(iss.str());
                }
                logo_file.close();
            } else {
                std::cerr << "ERR: LOGO: no file found" << std::endl;
            }
        } else {
            std::cerr << "ERR: LOGO: no path configured" << std::endl;
        }
    } else {
        std::cerr << "ERR: LOGO: no logo configuration" << std::endl;
    }

    //colors
    Color color_title;
    Color color_key;
    Color color_value;

    if (config.contains("colors")) {
        auto c = config["colors"];
        if (c.contains("title")) {
            color_title = Color(c["title"]);
        }
        if (c.contains("key")) {
            color_key = Color(c["key"]);
        }
        if (c.contains("value")) {
            color_value = Color(c["value"]);
        }
    } else {
        std::cerr << "W: no color information found, using just white" << std::endl;
    }

    // title & modules
    std::vector<TextLine *> text;

    if (config.contains("title")) {
        auto *t = new Title(config["title"]);
        text.push_back(t);
        auto *tu = (TextLine *) t->getUnderline();
        text.push_back(tu);
    }

    if (config.contains("modules")) {
        auto l = config["modules"];
        for (auto &it: l) {
            auto *m = new Module(it);
            text.push_back(m);
        }
    }

    //* PRINT
    int logo_line = 0;
    int text_line = 0;

    while (true) {

        /*
        //commented out until logo is refactored
        if (logo_line < logo.size()) {
            std::cout << logo.at(logo_line);
        }
*/

        if (text_line < text.size()) {
            std::cout << text.at(text_line)->str();
        }

        std::cout << std::endl;

        if (/*logo_line >= logo.size() &&*/ text_line >= text.size()) {
            break;
        }

        logo_line++;
        text_line++;
    }

    for (auto t: text) {
        delete t;
    }

    return 0;
}
