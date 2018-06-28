#ifndef REPLACELIST3_H
#define REPLACELIST3_H
#include<QTableWidgetItem>
#include <QWidget>

namespace Ui {
class replacelist3;
}

class replacelist3 : public QWidget
{
    Q_OBJECT

public:
    explicit replacelist3(QWidget *parent = 0);
    ~replacelist3();

private slots:
    void on_pushButton_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::replacelist3 *ui;
};

#endif // REPLACELIST3_H
