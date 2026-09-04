#include <alphabet.h>


Alphabet::Alphabet(Language lang)
{
    currLang = lang;
    setLang();
}

void Alphabet::updateLang(Language newLang)
{
    currLang = newLang;
    (currLang == POLISH) ? len = polish.size() : len = english.size();
    setLang();
}

void Alphabet::setLang()
{
    alphabet.clear();
    alphabet.resize(len);

    switch (currLang)
    {
    case POLISH:
        for(int i = 0; i < len; i++)
        {
            alphabet[i].c = polish[i];
        }
        break;
    case ENGLISH:
        for(int i = 0; i < len; i++)
        {
            alphabet[i].c = english[i];
        }
        break;
    }
}

