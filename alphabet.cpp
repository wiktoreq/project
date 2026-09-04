#include <alphabet.h>


Alphabet::Alphabet(Language lang)
{
    currLang = lang;
    setLang();
}

void Alphabet::updateLang(Language newLang)
{
    currLang = newLang;
    setLang();
}

void Alphabet::setLang()
{
    len = (currLang == POLISH) ? polish.size() : english.size();
    alphabet.clear();
    alphabet.resize(len);

    switch (currLang)
    {
    case POLISH:
        for(int i = 0; i < len; i++)
        {
            alphabet[i].c = polish[i];
            alphabet[i].freq = 0;
        }
        break;
    case ENGLISH:
        for(int i = 0; i < len; i++)
        {
            alphabet[i].c = english[i];
            alphabet[i].freq = 0;
        }
        break;
    }
}

