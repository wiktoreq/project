#include "stats.h"
#include <QStringView>
#include "quicksort.h"

Stats::Stats(Language lang)
{
    letterStats = Alphabet(lang);
}

void Stats::calcFreq(QString input)
{
    for(qsizetype i = 0; i < input.length(); i++)
    {
        for(int j = 0; j < letterStats.len; j++)
        {
            if(!letterStats.currLang)
            {
                if(polish[j] == input[i])
                {
                    letterStats.alphabet[j].freq++;
                }
            } else
            {
                if(english[j] == input[i])
                {
                    letterStats.alphabet[j].freq++;
                }
            }
        }
    }
    QuickSort::quickSort(letterStats.alphabet, 0, letterStats.len - 1);
    translate(letterStats.alphabet);
}

void Stats::decipher(QString& input)
{
    for(qsizetype i = 0; i < input.length(); i++)
    {
        for(int j = 0; j < letterStats.len; j++)
        {
            if(input[i] == letterStats.dictionary[j].c)
            {
                input[i] = letterStats.dictionary[j].tc;
                break;
            }
        }
    }
}

void Stats::translate(std::vector<letter> alphabet)
{
    letterStats.dictionary.resize(letterStats.len);
    for(int i = 0; i < letterStats.len; i++) {
        if(!letterStats.currLang)
        {
            letterStats.dictionary[i].c = alphabet[i].c;
            letterStats.dictionary[i].tc = POLISH_LETTER_STATS[i].c;
        } else
        {
            letterStats.dictionary[i].c = alphabet[i].c;
            letterStats.dictionary[i].tc = ENGLISH_LETTER_STATS[i].c;
        }
    }
    originalDictionary = letterStats.dictionary;
}

void Stats::changeDictionary(QChar oldC, QChar newC)
{
    int buffer = -1;
    for(int i = 0; i < letterStats.len; i++)
    {
        if(letterStats.dictionary[i].tc == oldC)
        {
            buffer = i;
            letterStats.dictionary[i].tc = newC;
            break;
        }
    }
    for(int i = 0; i < letterStats.len; i++)
    {
        if(letterStats.dictionary[i].tc == newC && buffer != i)
        {
            letterStats.dictionary[i].tc = oldC;
        }
    }
}

void Stats::resetDictionary()
{
    letterStats.dictionary = originalDictionary;
}

void Stats::calculateDigrams(QString buffer)
{
    QString input = buffer;

    for (qsizetype i = input.length() - 1; i >= 0; --i)
    {
        if (!input[i].isLetter())
        {
            input.remove(i, 1);
        }
    }

    if(input.length() < 2)
    {
        return;
    }

    for(qsizetype j = 0; j < input.length() - 1; j++)
    {
        QString currentDigram = input.mid(j, 2);
        bool found = false;

        for(size_t i = 0; i < letterStats.digrams.size(); i++)
        {
            if(currentDigram == letterStats.digrams[i].digram)
            {
                letterStats.digrams[i].freq++;
                found = true;
                break;
            }
        }

        if(!found)
        {
            letterStats.digrams.push_back({currentDigram, 1});
        }

        letterStats.totalDigrams++;
    }
}

void Stats::calculateTrigrams(QString buffer)
{
    QString input = buffer;

    for (qsizetype i = input.length() - 1; i >= 0; --i)
    {
        if (!input[i].isLetter())
        {
            input.remove(i, 1);
        }
    }

    if(input.length() < 3)
    {
        return;
    }

    for(qsizetype j = 0; j < input.length() - 2; j++)
    {
        QString currentTrigram = input.mid(j, 3);
        bool found = false;

        for(size_t i = 0; i < letterStats.trigrams.size(); i++)
        {
            if(currentTrigram == letterStats.trigrams[i].trigram)
            {
                letterStats.trigrams[i].freq++;
                found = true;
                break;
            }
        }

        if(!found)
        {
            letterStats.trigrams.push_back({currentTrigram, 1});
        }

        letterStats.totalTrigrams++;
    }
}

void Stats::sortDigrams()
{
    if(letterStats.digrams.size() < 2)
    {
        return;
    }
    QuickSort::quickSortDigrams(letterStats.digrams, 0, letterStats.digrams.size() - 1);
}

void Stats::sortTrigrams()
{
    if(letterStats.trigrams.size() < 2)
    {
        return;
    }
    QuickSort::quickSortTrigrams(letterStats.trigrams, 0, letterStats.trigrams.size() - 1);
}




