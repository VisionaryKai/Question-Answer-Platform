#include "questionlist.h"
#include "ui_questionlist.h"
#include"define.h"
#include"questionlist2.h"
#include"questionlist3.h"
#include"questiondetail.h"

questionlist::questionlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questionlist)
{
    int i;
    QVector<question>::iterator q;
    ui->setupUi(this);
    if(questions.empty())
    {

    }
    else
    {
        q=questions.end()-1;
        for(i=0;i<=3;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(q->gettitle()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q->getuserid()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q->gettime().toString()));
            if(q!=questions.begin())
            q--;
            else break;
        }
        connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(testSlot(QTableWidgetItem *)));
    }

}

questionlist::~questionlist()
{
    delete ui;
}



void questionlist::on_tableWidget_clicked(const QModelIndex &index)
{



}

void questionlist::on_tableWidget_activated(const QModelIndex &index)
{

}

void questionlist::on_tableWidget_itemClicked(QTableWidgetItem *item)
{

}

void questionlist::on_tableWidget_cellClicked(int row, int column)
{

}

void questionlist::on_pushButton_2_clicked()
{
    close();
}

void questionlist::on_pushButton_clicked()
{
    questionlist2 *q=new questionlist2;
    q->show();
}
void questionlist::testSlot(QTableWidgetItem * q)
{
    flag=0;
    questionnum=q->row();
    questiondetail *qd=new questiondetail();
    qd->show();
}
