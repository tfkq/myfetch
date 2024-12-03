//
// Created by tfkq on 03.12.24.
//

#include <format>
#include <chrono>
#include <iostream>
#include "Title.h"

Title::Title() {

}

Title::Title(json config) {
    if (config.contains("name")) {
        name = config["name"].get<std::string>();
    }
    if (config.contains("pronouns")) {
        pronouns = config["pronouns"].get<std::string>();
    }
    if (config.contains("year-of-birth")) {
        year_of_birth = config["year-of-birth"].get<int>();
        if (year_of_birth == 0) {
            std::cerr << "ERR: You're not Jesus" << std::endl;
        }
    }
}

Title::~Title() {

}

std::string Title::str() {

    if (name.empty()) {
        return "myfetch - neofetch for humans";
    } else {
        std::string ret;
        ret += name;
        if (!pronouns.empty()) {
            ret += " (" + pronouns + ")";
        }
        if (year_of_birth != -1) {
            const auto now = std::chrono::system_clock::now();
            int year = std::stoi(std::format("{:%Y}", now));
            ret += ", " + std::to_string(year - year_of_birth) + " years old";
        }

        underline.set_length(ret.length());
        return ret;
    }
}

const std::string &Title::getName() const {
    return name;
}

void Title::setName(const std::string &name) {
    Title::name = name;
}

const std::string &Title::getPronouns() const {
    return pronouns;
}

void Title::setPronouns(const std::string &pronouns) {
    Title::pronouns = pronouns;
}

int Title::getYearOfBirth() const {
    return year_of_birth;
}

void Title::setYearOfBirth(int yearOfBirth) {
    year_of_birth = yearOfBirth;
}

const Title::TitleUnderline *Title::getUnderline() const {
    return &underline;
}

std::string Title::TitleUnderline::str() {
    std::string ret;
    for (int i = 0; i < length; i++) {
        ret += "-";
    }
    return ret;
}

void Title::TitleUnderline::set_length(int _length) {
    length = _length;
}
