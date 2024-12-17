#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo> // Pour gérer les informations sur les ports série

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool stm32Connected;

    void checkSTM32Connection();       // Vérifie la connexion au STM32
    void updateConnectionStatusLabel(); // Met à jour le label de statut
};

#endif // MAINWINDOW_H
