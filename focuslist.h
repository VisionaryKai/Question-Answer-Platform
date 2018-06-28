#ifndef FOCUSLIST_H
#define FOCUSLIST_H

#include <QWidget>
#include <QTableWidgetItem>
namespace Ui {
class focuslist;
}

class focuslist : public QWidget
{
    Q_OBJECT

public:
    explicit focuslist(QWidget *parent = 0);
    ~focuslist();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_activated(const QModelIndex &index);

    void on_tableWidget_clicked(const QModelIndex &index);

    void testSlot(QTableWidgetItem * q);

private:
    Ui::focuslist *ui;
};

#endif // FOCUSLIST_H
