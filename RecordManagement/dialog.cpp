#include "dialog.h"
#include "ui_dialog.h"
#include "connection.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/ADMIN/Documents/Qt Projects/RecordManagement/Records.db");

    Connection connn;

    if(!connn.connOpen()) {
        ui->labelSec->setText("Failed to open the database");
    } else {
        ui->labelSec->setText("Connected...");
    }



}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    Connection connn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    connn.connOpen();

    QSqlQuery* qry= new QSqlQuery(connn.mydb);

    qry->prepare("select * from RecordInfo");
    qry->exec();
    modal->setQuery(*qry);

    ui->tableView->setModel(modal);

    connn.connClose();
    qDebug()<<(modal ->rowCount());

}
