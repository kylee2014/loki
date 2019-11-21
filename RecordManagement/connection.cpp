#include "connection.h"
#include "ui_connection.h"
#include "dialog.h"

Connection::Connection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);

    if(!connOpen()) {
        ui->label->setText("Failed to open the database");
    } else {
        ui->label->setText("Connected...");
        connClose();
    }



}

Connection::~Connection()
{
    delete ui;
}

void Connection::on_pushButton_clicked()
{
    Dialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();


}
