#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <QWidget>

namespace Ui {
class usersearch;
}

class usersearch : public QWidget
{
    Q_OBJECT

public:
    explicit usersearch(QWidget *parent = 0);
    ~usersearch();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::usersearch *ui;
};

#endif // USERSEARCH_H
