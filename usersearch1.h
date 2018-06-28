#ifndef USERSEARCH1_H
#define USERSEARCH1_H

#include <QWidget>

namespace Ui {
class usersearch1;
}

class usersearch1 : public QWidget
{
    Q_OBJECT

public:
    explicit usersearch1(QWidget *parent = 0);
    ~usersearch1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::usersearch1 *ui;
};

#endif // USERSEARCH1_H
