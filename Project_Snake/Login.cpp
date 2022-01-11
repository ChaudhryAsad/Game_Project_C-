#include "Login.h"
#include "ui_Login.h"
#include <QMessageBox>

#include <QImage> /* 37 : QT class*/
#include <QPixmap>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//Hier wordt foto toegoeved in login scherm

    QPixmap pix(":/images/logo.png");
    ui->label_pic ->setPixmap(pix.scaled(330,280,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();


    if(username == "Snake" && password == "Snake"){
        QMessageBox::information(this, "Login","Username and password is correct");
        hide();
        game_screen = new class game_screen(this);
        game_screen->show();
    }
    else if(username != "Snake" && password == "Snake")
    {
        QMessageBox::information(this, "Login","Username is uncorrect Please try again!");
    }
    else if(username == "Snake" && password != "Snake")
    {
        QMessageBox::information(this, "Login","Password is uncorrect Please try again!");
    }
    else{
        QMessageBox::warning(this,"Login","Username and password is uncorrect");
    }

}


