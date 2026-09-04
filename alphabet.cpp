#include <alphabet.h>


Alphabet::Alphabet(Language lang)
{
    currLang = lang;
    (currLang) ? len = ENLEN : len = PLLEN;
    alphabet.resize(len);
    digrams.resize(0);
    trigrams.resize(0);
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

