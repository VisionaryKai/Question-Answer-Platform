#ifndef REGISTERWIG_H
#define REGISTERWIG_H

#include <QWidget>

namespace Ui {
class registerwig;
}

class registerwig : public QWidget
{
    Q_OBJECT

public:
    explicit registerwig(QWidget *parent = 0);
    ~registerwig();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::registerwig *ui;
};

#endif // REGISTERWIG_H
