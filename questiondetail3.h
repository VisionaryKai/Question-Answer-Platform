#ifndef QUESTIONDETAIL3_H
#define QUESTIONDETAIL3_H
#include<QTableWidgetItem>
#include<QTableWidget>
#include <QWidget>


namespace Ui {
class questiondetail3;
}

class questiondetail3 : public QWidget
{
    Q_OBJECT

public:
    explicit questiondetail3(QWidget *parent = 0);
    ~questiondetail3();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void testSlot(QTableWidgetItem * q);

    void on_pushButton_3_clicked();

private:
    Ui::questiondetail3 *ui;
};

#endif // QUESTIONDETAIL3_H
