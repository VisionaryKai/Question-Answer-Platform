#ifndef REPLACELIST2_H
#define REPLACELIST2_H
#include<QTableWidgetItem>
#include <QWidget>

namespace Ui {
class replacelist2;
}

class replacelist2 : public QWidget
{
    Q_OBJECT

public:
    explicit replacelist2(QWidget *parent = 0);
    ~replacelist2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::replacelist2 *ui;
};

#endif // REPLACELIST2_H
