#ifndef QUESTIONLIST2_H
#define QUESTIONLIST2_H
#include<QTableWidgetItem>
#include<QTableWidget>
#include <QWidget>
namespace Ui {
class questionlist2;
}

class questionlist2 : public QWidget
{
    Q_OBJECT

public:
    explicit questionlist2(QWidget *parent = 0);
    ~questionlist2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::questionlist2 *ui;
};

#endif // QUESTIONLIST2_H
