//
// Created by tfkq on 03.12.24.
//

#ifndef MYFETCH_TITLE_H
#define MYFETCH_TITLE_H


#include "../TextLine.h"
#include "../lib/nlohmann/json.hpp"

using json = nlohmann::json;


class Title : public TextLine{

private:

    std::string name;
    std::string pronouns;
    int year_of_birth = -1;

    class TitleUnderline : public TextLine{
    private:
        int length;
    public:
        std::string str() override;
        void set_length(int _length);
    };

    TitleUnderline underline;

public:

    Title();

    explicit Title(json config);

    ~Title() override;

    std::string str() override;

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPronouns() const;

    void setPronouns(const std::string &pronouns);

    int getYearOfBirth() const;

    void setYearOfBirth(int yearOfBirth);

    const TitleUnderline* getUnderline() const;
};


#endif //MYFETCH_TITLE_H
