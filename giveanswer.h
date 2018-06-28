#ifndef GIVEANSWER_H
#define GIVEANSWER_H

#include <QWidget>

namespace Ui {
class giveanswer;
}

class giveanswer : public QWidget
{
    Q_OBJECT

public:
    explicit giveanswer(QWidget *parent = 0);
    ~giveanswer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::giveanswer *ui;
};

#endif // GIVEANSWER_H
