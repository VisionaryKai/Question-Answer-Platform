#include "focuslist2.h"
#include "ui_focuslist2.h"
#include"define.h"
#include"focusdetail.h"
focuslist2::focuslist2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::focuslist2)
{
    int i;
    ui->setupUi(this);
    for(i=0;i<=5;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(curuser->foclist[i+6]));
    }
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(testSlot(QTableWidgetItem *)));
}

focuslist2::~focuslist2()
{
    delete ui;
}

void focuslist2::on_pushButton_clicked()
{
    close();
}
void focuslist2::testSlot(QTableWidgetItem * q)
{
    focusname=curuser->foclist[q->row()+6];
    focusdetail * f=new focusdetail;
    f->show();
}
