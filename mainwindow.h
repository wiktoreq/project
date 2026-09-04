#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stats.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override;

    private slots:
        void on_decipher_clicked();

        void on_actionRead_from_file_triggered();

        void on_actionSave_output_to_file_triggered();

        void on_actionEnglish_triggered();

        void on_actionPolish_triggered();

        void on_letterchange_clicked();

        void on_resetToDefault_clicked();

        void on_action_letters_triggered();

        void on_action_digrams_triggered();

        void on_action_trigrams_triggered();

    private:
        Language currLan = POLISH;
        void decipherInput();
        QString input = "";
        Stats stats;
        Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
