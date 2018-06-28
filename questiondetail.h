#ifndef QUESTIONDETAIL_H
#define QUESTIONDETAIL_H
#include<QTableWidgetItem>
#include<QTableWidget>
#include <QWidget>


namespace Ui {
class questiondetail;
}

class questiondetail : public QWidget
{
    Q_OBJECT

public:
    explicit questiondetail(QWidget *parent = 0);
    ~questiondetail();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void testSlot(QTableWidgetItem * q);

    void on_pushButton_3_clicked();

private:
    Ui::questiondetail *ui;
};

#endif // QUESTIONDETAIL_H
