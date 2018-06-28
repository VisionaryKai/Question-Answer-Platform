#ifndef FOCUSLIST2_H
#define FOCUSLIST2_H

#include <QWidget>
#include <QTableWidgetItem>
namespace Ui {
class focuslist2;
}

class focuslist2 : public QWidget
{
    Q_OBJECT

public:
    explicit focuslist2(QWidget *parent = 0);
    ~focuslist2();

private slots:
    void on_pushButton_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::focuslist2 *ui;
};

#endif // FOCUSLIST2_H
