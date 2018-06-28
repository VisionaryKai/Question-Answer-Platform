#include "focuslist.h"
#include "ui_focuslist.h"
#include"define.h"
#include"focuslist2.h"
#include"focusdetail.h"
focuslist::focuslist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::focuslist)
{
    int i;
    ui->setupUi(this);
    for(i=0;i<=5;i++)
    {
       qDebug()<<curuser->foclist[i];
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(curuser->foclist[i]));
    }
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(testSlot(QTableWidgetItem *)));
}

focuslist::~focuslist()
{
    delete ui;
}

void focuslist::on_pushButton_clicked()
{
    focuslist2 *f=new focuslist2;
    f->show();
}

void focuslist::on_pushButton_2_clicked()
{
    close();
}

void focuslist::on_tableWidget_clicked(const QModelIndex &index)
{

}

void focuslist::testSlot(QTableWidgetItem * q)
{
    int r;
    r=q->row();
    focusname=curuser->foclist[r];
    focusdetail * f=new focusdetail;
    f->show();
}

void focuslist::on_tableWidget_activated(const QModelIndex &index)
{

}
