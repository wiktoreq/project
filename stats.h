#ifndef STATS_H
#define STATS_H

#include <QFileDialog>
#include "alphabet.h"
#include "quicksort.h"

class Stats
{
    private:
        void translate(std::vector<letter> alphabet);
        std::vector<dict> originalDictionary;

    public:
        Stats() = default;
        Stats(Language lang);

        Alphabet letterStats;

        void calculateDigrams(QString input);
        void calculateTrigrams(QString input);
        void sortDigrams();
        void sortTrigrams();

        void changeDictionary(QChar oldC, QChar newC);
        void resetDictionary();

        int getLength(letter* alphabet);
        void calcFreq(QString input);
        void decipher(QString& input);
        bool processLine(QByteArray line);
};

#endif // STATS_H
