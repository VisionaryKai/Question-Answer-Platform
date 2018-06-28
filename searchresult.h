#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include<QTableWidgetItem>
#include <QWidget>

namespace Ui {
class searchresult;
}

class searchresult : public QWidget
{
    Q_OBJECT

public:
    explicit searchresult(QWidget *parent = 0);
    ~searchresult();

private slots:
    void on_pushButton_2_clicked();
    void testSlot(QTableWidgetItem * q);
private:
    Ui::searchresult *ui;
};

#endif // SEARCHRESULT_H
