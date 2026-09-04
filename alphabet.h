#ifndef LETTER_H
#define LETTER_H

#define PLLEN 35
#define ENLEN 26

#include "data.h"

enum Language
{
    POLISH = 0,
    ENGLISH = 1
};

struct dict
{
    QChar c;
    QChar tc;
};

class Alphabet
{
    private:

    public:
        std::vector<letter> alphabet;
        std::vector<digram> digrams;
        std::vector<trigram> trigrams;
        std::vector<dict> dictionary;
        int totalDigrams = 0;
        int totalTrigrams = 0;
        Language currLang;
        int len;

        Alphabet() = default;
        Alphabet(Language lang);

};
#endif // LETTER_H
