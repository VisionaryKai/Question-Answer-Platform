#ifndef REPLACELIST_H
#define REPLACELIST_H
#include<QTableWidgetItem>
#include <QWidget>

namespace Ui {
class replacelist;
}

class replacelist : public QWidget
{
    Q_OBJECT

public:
    explicit replacelist(QWidget *parent = 0);
    ~replacelist();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::replacelist *ui;
};

#endif // REPLACELIST_H
