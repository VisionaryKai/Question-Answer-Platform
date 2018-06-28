#ifndef QUESTIONDETAIL2_H
#define QUESTIONDETAIL2_H

#include<QTableWidgetItem>
#include<QTableWidget>
#include <QWidget>


namespace Ui {
class questiondetail2;
}

class questiondetail2 : public QWidget
{
    Q_OBJECT

public:
    explicit questiondetail2(QWidget *parent = 0);
    ~questiondetail2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void testSlot(QTableWidgetItem * q);

    void on_pushButton_3_clicked();

private:
    Ui::questiondetail2 *ui;
};

#endif // QUESTIONDETAIL2_H
