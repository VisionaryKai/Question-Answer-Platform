#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H
#include<QTableWidgetItem>
#include<QTableWidget>
#include <QWidget>

namespace Ui {
class questionlist;
}

class questionlist : public QWidget
{
    Q_OBJECT

public:
    explicit questionlist(QWidget *parent = 0);
    ~questionlist();

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_tableWidget_activated(const QModelIndex &index);

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void testSlot(QTableWidgetItem * q);

private:
    Ui::questionlist *ui;
};

#endif // QUESTIONLIST_H
