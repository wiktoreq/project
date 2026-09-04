#include "statswindow.h"
#include "ui_statswindow.h"

StatsWindow::StatsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatsWindow)
{
    ui->setupUi(this);

    ui->text_1->setStyleSheet("QTextBrowser { font-size: 8pt; }");
    ui->text_2->setStyleSheet("QTextBrowser { font-size: 8pt; }");
}

StatsWindow::~StatsWindow()
{
    delete ui;
}

void StatsWindow::setContent(Alphabet& letterStats, WhichStats whichStats)
{

    if(whichStats == LETTER)
    {
        setLetterStats(letterStats);
    }
    else if(whichStats == DIGRAM)
    {
        setDigramStats(letterStats);
    }
    else
    {
        setTrigramStats(letterStats);
    }
}

void StatsWindow::setLetterStats(Alphabet& letterStats)
{
    QString out;

    size_t alphabetSize = letterStats.alphabet.size();

    ui->text_1->append("<b>Letter statistics for input text [letter : count : propability]");

    out = QString("<b>Letter statistics for %1 language[letter : propability]")
              .arg((letterStats.currLang) ? "english" : "polish");
    ui->text_2->append(out);

    for(size_t i = 0; i < alphabetSize; i++)
    {
        out = QString("%1 : %2 : %3%")
        .arg(letterStats.alphabet[i].c)
            .arg(letterStats.alphabet[i].freq)
            .arg(letterStats.alphabet[i].freq*100.0/(letterStats.totalLetters));
        ui->text_1->append(out);
        if(!letterStats.currLang)
        {
            out = QString("%1 : %2%")
            .arg(POLISH_LETTER_STATS[i].c)
                .arg(POLISH_LETTER_STATS[i].freq/100.0);
        } else
        {
            out = QString("%1 : %2%")
            .arg(ENGLISH_LETTER_STATS[i].c)
                .arg(ENGLISH_LETTER_STATS[i].freq/100.0);
        }
        ui->text_2->append(out);

    }
}

void StatsWindow::setDigramStats(Alphabet& letterStats)
{
    QString out;
    ui->text_1->append("<b>Digram statistics for input [digram : count : propability]");
    out = QString("<b>Digram statistics for %1 language[digram : propability]")
              .arg((letterStats.currLang) ? "english" : "polish");
    ui->text_2->append(out);

    for(size_t i = 0; i < letterStats.digrams.size(); i++)
    {
        out = QString("%1 : %2 : %3%")
        .arg(letterStats.digrams[i].digram)
            .arg(letterStats.digrams[i].freq)
            .arg(letterStats.digrams[i].freq*100.0/letterStats.totalDigrams);
        ui->text_1->append(out);
    }

    for(int i = 0; i < 30; i++)
    {
        if(!letterStats.currLang)
        {
            out = QString("%1 : %2%")
            .arg(POLISH_DIGRAM_STATS[i].digram)
                .arg(POLISH_DIGRAM_STATS[i].freq/100.0);
        } else
        {
            out = QString("%1 : %2%")
            .arg(ENGLISH_DIGRAM_STATS[i].digram)
                .arg(ENGLISH_DIGRAM_STATS[i].freq/100.0);
        }
        ui->text_2->append(out);
    }
}

void StatsWindow::setTrigramStats(Alphabet& letterStats)
{
    QString out;
    ui->text_1->append("<b>Trigram statistics for input [trigram : count : propability]");
    out = QString("<b>Trigram statistics for %1 language[trigram : propability]")
              .arg((letterStats.currLang) ? "english" : "polish");
    ui->text_2->append(out);

    for(size_t i = 0; i < letterStats.trigrams.size(); i++)
    {
        out = QString("%1 : %2 : %3%")
        .arg(letterStats.trigrams[i].trigram)
            .arg(letterStats.trigrams[i].freq)
            .arg(letterStats.trigrams[i].freq*100.0/letterStats.totalTrigrams);
        ui->text_1->append(out);
    }

    for(int i = 0; i < 30; i++)
    {
        if(!letterStats.currLang)
        {
            out = QString("%1 : %2%")
            .arg(POLISH_TRIGRAM_STATS[i].trigram)
                .arg(POLISH_TRIGRAM_STATS[i].freq/100.0);
        } else
        {
            out = QString("%1 : %2%")
            .arg(ENGLISH_TRIGRAM_STATS[i].trigram)
                .arg(ENGLISH_TRIGRAM_STATS[i].freq/100.0);
        }
        ui->text_2->append(out);
    }
}