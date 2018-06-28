#ifndef CENTRAL_H
#define CENTRAL_H

#include <QWidget>

namespace Ui {
class central;
}

class central : public QWidget
{
    Q_OBJECT

public:
    explicit central(QWidget *parent = 0);
    ~central();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::central *ui;
};

#endif // CENTRAL_H
