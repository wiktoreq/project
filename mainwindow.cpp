#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionLog->setStyleSheet("QTextBrowser { font-size: 6pt; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_decipher_clicked()
{
    input = ui->input->toPlainText();
    input = input.toLower();
    if(!input.isEmpty())
    {
        stats = Stats(currLan);

        ui->output->clear();

        stats.calcFreq(input);

        decipherInput();
    }
    else
    {
        ui->actionLog->append("<font color='red'>Provide an input");
    }
}

void MainWindow::decipherInput()
{
    stats.letterStats.totalLetters = 0;

    stats.letterStats.digrams.clear();
    stats.letterStats.trigrams.clear();
    stats.letterStats.totalDigrams = 0;
    stats.letterStats.totalTrigrams = 0;

    QString buffer = QString(" ");

    for(qsizetype i = 0; i < input.length(); i++)
    {
        QChar curr = input[i];
        buffer.append(curr);

        if(curr.isLetter())
        {
            stats.letterStats.totalLetters++;
        }

        if(curr == QChar(' '))
        {
            stats.calculateDigrams(buffer);
            stats.calculateTrigrams(buffer);
            stats.decipher(buffer);
            ui->output->insertPlainText(buffer);
            buffer.clear();
        }
    }
    stats.calculateDigrams(buffer);
    stats.sortDigrams();
    stats.calculateTrigrams(buffer);
    stats.sortTrigrams();
    stats.decipher(buffer);
    ui->output->insertPlainText(buffer);
}



void MainWindow::on_actionRead_from_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open text file"), "../../../", tr("Text Files (*txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    ui->input->clear();
    while (!file.atEnd())
    {
        QByteArray byteLine = file.readLine();
        QString line = QString(byteLine);
        ui->input->appendPlainText(line);
    }
    QString out = QString("File opened: %1").arg(fileName);
    ui->actionLog->append(out);
    file.close();
}


void MainWindow::on_actionSave_output_to_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "../../../", tr("Text Files (*txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QString stringBuffer = ui->output->toPlainText();
    file.write(stringBuffer.toUtf8());
    QString out = QString("File saved at: %1").arg(fileName);
    ui->actionLog->append(out);
    file.close();
}

void MainWindow::on_actionEnglish_triggered()
{
    stats.letterStats.updateLang(ENGLISH);
    currLan = ENGLISH;
}


void MainWindow::on_actionPolish_triggered()
{
    stats.letterStats.updateLang(POLISH);
    currLan = POLISH;
}


void MainWindow::on_letterchange_clicked()
{
    if(input == "")
    {
        ui->actionLog->append("<font color='red'>No output to change");
        return;
    }
    QString oldStr = ui->oldLetter->text();
    QString newStr = ui->newLetter->text();
    if(oldStr.length() > 1 || oldStr.length() == 0 || newStr.length() > 1 || newStr.length() == 0)
    {
        ui->actionLog->append("<font color='red'>Invalid input>");
        return;
    }
    QChar oldC = oldStr[0];
    QChar newC = newStr[0];

    ui->output->clear();
    stats.changeDictionary(oldC, newC);
    decipherInput();
}


void MainWindow::on_resetToDefault_clicked()
{
    ui->output->clear();
    stats.resetDictionary();
    decipherInput();
}


void MainWindow::on_action_letters_triggered()
{
    StatsWindow *statsWin = new StatsWindow(this);
    statsWin->setAttribute(Qt::WA_DeleteOnClose);
    statsWin->show();
    statsWin->raise();
    statsWin->activateWindow();
    statsWin->setContent(stats.letterStats, LETTER);
}


void MainWindow::on_action_digrams_triggered()
{
    StatsWindow *statsWin = new StatsWindow(this);
    statsWin->setAttribute(Qt::WA_DeleteOnClose);
    statsWin->show();
    statsWin->raise();
    statsWin->activateWindow();
    statsWin->setContent(stats.letterStats, DIGRAM);
}


void MainWindow::on_action_trigrams_triggered()
{
    StatsWindow *statsWin = new StatsWindow(this);
    statsWin->setAttribute(Qt::WA_DeleteOnClose);
    statsWin->show();
    statsWin->raise();
    statsWin->activateWindow();
    statsWin->setContent(stats.letterStats, TRIGRAM);
}

