#ifndef ASK_H
#define ASK_H

#include <QWidget>

namespace Ui {
class ask;
}

class ask : public QWidget
{
    Q_OBJECT

public:
    explicit ask(QWidget *parent = 0);
    ~ask();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ask *ui;
};

#endif // ASK_H
