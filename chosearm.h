#ifndef CHOSEARM_H
#define CHOSEARM_H
#include<QMessageBox>

#include <QDialog>

namespace Ui {
class ChoseARM;
}

class ChoseARM : public QDialog
{
    Q_OBJECT

public:
    explicit ChoseARM(QWidget *parent = 0);
    ~ChoseARM();
signals:
    void choseModel( ) ;

private slots:
    sendMODEL();

    void on_cancle_BTN_clicked();

private:
    Ui::ChoseARM *ui;
    QMessageBox messg;
};

#endif // CHOSEARM_H
