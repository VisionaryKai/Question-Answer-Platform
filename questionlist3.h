#ifndef QUESTIONLIST3_H
#define QUESTIONLIST3_H
#include<QTableWidgetItem>
#include<QTableWidget>
#include <QWidget>

namespace Ui {
class questionlist3;
}

class questionlist3 : public QWidget
{
    Q_OBJECT

public:
    explicit questionlist3(QWidget *parent = 0);
    ~questionlist3();

private slots:
    void on_pushButton_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::questionlist3 *ui;
};

#endif // QUESTIONLIST3_H
