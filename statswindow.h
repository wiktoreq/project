#pragma once
#ifndef STATSWINDOW_H
#define STATSWINDOW_H

#include <QDialog>
#include "alphabet.h"

enum WhichStats
{
    LETTER = 0,
    DIGRAM = 1,
    TRIGRAM = 2
};

namespace Ui {
class StatsWindow;
}

class StatsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatsWindow(QWidget *parent = nullptr);
    ~StatsWindow();

    void setContent(Alphabet& letterStats, WhichStats whichStats);

private:
    void setLetterStats(Alphabet& letterStats);
    void setDigramStats(Alphabet& letterStats);
    void setTrigramStats(Alphabet& letterStats);
    Ui::StatsWindow *ui;
};

#endif // STATSWINDOW_H
