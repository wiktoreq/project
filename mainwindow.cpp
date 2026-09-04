#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionLog->setStyleSheet("QTextBrowser { font-size: 8pt; }");

    ui->readme->append("<b>README:\n");
    ui->readme->append("W file menu można wybrać plik do wczytania lub zapisać wynik deszyfrowania do pliku \n");
    ui->readme->append("W menu języka można wybrać język dla jakiego przeprowadzane jest deszyfrowanie oraz wyświetlane są statystyki\n");
    ui->readme->append("Z statistics menu można wybrać statystyki liter, digramów oraz trigramów. Dokładne dane na temat występowania ich w danym języku znalazłem na stronie: http://practicalcryptography.com/cryptanalysis/letter-frequencies-various-languages/. Dane są posortowane od najczęściej występujących do najrzadziej \n");
    ui->readme->append("W folderze /examples można znaleźć przykładowe pliki po polsku i angielku, przed i po zaszyfrowaniu do załadowania do programu. Szyfrowanie użyte to szyfr cezara z przesunięciem 7 na stronie: https://cryptii.com/pipes/caesar-cipher/. Do szyfrowania w języku polskim uzyłem również znaków polskich (jak w alfabecie 'polish' w pliku data.h) \n");
    ui->readme->append("Tekst do zdeszyfrowania powinien być naprawdę długi. W języku polskim dla 6000 znaków program uzyskuje ok. 25% poprawnego deszyfrowania - angielski znacznie więcej ze względu na charakterystykę występowania liter w języku polskim\n");
    ui->readme->moveCursor(QTextCursor::Start);
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
    QString out = QString("-> Deciphered text %1 characters long").arg(input.size());
    ui->actionLog->append(out);
    ui->input->moveCursor(QTextCursor::Start);
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
    ui->output->moveCursor(QTextCursor::Start);
}



void MainWindow::on_actionRead_from_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open text file"), "../../../", tr("Text Files (*txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    ui->input->clear();
    QString fileContent = "";

    QByteArray byteLine = file.readAll();;
    QString content = QString(byteLine);
    ui->input->setPlainText(content);

    QString out = QString("-> File opened: %1").arg(fileName);
    ui->actionLog->append(out);
    file.close();
    ui->input->moveCursor(QTextCursor::Start);
}


void MainWindow::on_actionSave_output_to_file_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "../../../", tr("Text Files (*txt)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return;
    }

    QString stringBuffer = ui->output->toPlainText();
    file.write(stringBuffer.toUtf8());
    QString out = QString("-> File saved at: %1").arg(fileName);
    ui->actionLog->append(out);
    file.close();
}


void MainWindow::on_actionEnglish_triggered()
{
    stats.letterStats.updateLang(ENGLISH);
    currLan = ENGLISH;
    ui->actionEnglish->setChecked(true);
    ui->actionPolish->setChecked(false);
    ui->actionLog->append("-> <font color='blue'>Deciphering language changed to english");
}


void MainWindow::on_actionPolish_triggered()
{
    stats.letterStats.updateLang(POLISH);
    currLan = POLISH;
    ui->actionPolish->setChecked(true);
    ui->actionEnglish->setChecked(false);
    ui->actionLog->append("-> <font color='blue'>Deciphering language changed to polish");
}


void MainWindow::on_letterchange_clicked()
{
    if(input == QString(""))
    {
        ui->actionLog->append("-> <font color='red'>No output to change");
        return;
    }
    QString oldStr = ui->oldLetter->text();
    QString newStr = ui->newLetter->text();
    if(oldStr.length() > 1 || oldStr.length() == 0 || newStr.length() > 1 || newStr.length() == 0)
    {
        ui->actionLog->append("-> <font color='red'>Invalid input>");
        return;
    }
    QChar oldC = oldStr[0];
    QChar newC = newStr[0];

    ui->output->clear();
    stats.changeDictionary(oldC, newC);
    decipherInput();
    QString out = QString("-> <font color='magenta'> Letter '%1' changed to '%2' in output").arg(oldC).arg(newC);
    ui->actionLog->append(out);
}


void MainWindow::on_resetToDefault_clicked()
{
    ui->output->clear();
    stats.resetDictionary();
    decipherInput();
    ui->actionLog->append("-> <font color='green'>Deciphering dictionary set to default");
}


void MainWindow::on_action_letters_triggered()
{
    StatsWindow *statsWin = new StatsWindow(this);
    statsWin->setAttribute(Qt::WA_DeleteOnClose);
    statsWin->setWindowTitle("Letter statistics");
    statsWin->show();
    statsWin->raise();
    statsWin->activateWindow();
    statsWin->setContent(stats.letterStats, LETTER);
}


void MainWindow::on_action_digrams_triggered()
{
    StatsWindow *statsWin = new StatsWindow(this);
    statsWin->setAttribute(Qt::WA_DeleteOnClose);
    statsWin->setWindowTitle("Digram statistics");
    statsWin->show();
    statsWin->raise();
    statsWin->activateWindow();
    statsWin->setContent(stats.letterStats, DIGRAM);
}


void MainWindow::on_action_trigrams_triggered()
{
    StatsWindow *statsWin = new StatsWindow(this);
    statsWin->setAttribute(Qt::WA_DeleteOnClose);
    statsWin->setWindowTitle("Trigram statistics");
    statsWin->show();
    statsWin->raise();
    statsWin->activateWindow();
    statsWin->setContent(stats.letterStats, TRIGRAM);
}

