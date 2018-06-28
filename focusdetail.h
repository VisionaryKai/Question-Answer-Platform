#ifndef FOCUSDETAIL_H
#define FOCUSDETAIL_H

#include <QWidget>

namespace Ui {
class focusdetail;
}

class focusdetail : public QWidget
{
    Q_OBJECT

public:
    explicit focusdetail(QWidget *parent = 0);
    ~focusdetail();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::focusdetail *ui;
};

#endif // FOCUSDETAIL_H
