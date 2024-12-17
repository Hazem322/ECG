#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo> // Pour la détection des ports série

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stm32Connected(false) // Initialisation de l'état de connexion
{
    ui->setupUi(this);

    // Vérifier l'état de connexion
    checkSTM32Connection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkSTM32Connection()
{
    // Parcourir les ports série disponibles
    stm32Connected = false;
    foreach (const QSerialPortInfo &portInfo, QSerialPortInfo::availablePorts()) {
        if (portInfo.portName() == "COM8") { // Vérifier si COM8 est disponible
            stm32Connected = true;
            break;
        }
    }

    // Mettre à jour le label
    updateConnectionStatusLabel();
}

void MainWindow::updateConnectionStatusLabel()
{
    if (stm32Connected) {
        ui->connectionStatusLabel->setText("Connecté à COM8");
        ui->connectionStatusLabel->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->connectionStatusLabel->setText("Non connecté");
        ui->connectionStatusLabel->setStyleSheet("QLabel { color : red; }");
    }
}
