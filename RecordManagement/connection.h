#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Connection;
}

class Connection : public QMainWindow
{
    Q_OBJECT
public:

    QSqlDatabase mydb;
    void connClose() {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }

    bool connOpen() {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/ADMIN/Documents/Qt Projects/RecordManagement/Records.db");

        if(!mydb.open()) {
            qDebug()<<("Failed to open the database");
            return false;
        } else {
            qDebug()<<("Connected...");
            return true;
        }
    }



public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Connection *ui;
};

#endif // CONNECTION_H
