#include "questionlist2.h"
#include "ui_questionlist2.h"
#include"define.h"
#include"questionlist3.h"
#include"questiondetail.h"
questionlist2::questionlist2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questionlist2)
{
    int i;
    ui->setupUi(this);
    if(questions.size()<=4)
    {

    }
    else
    {
        QVector<question>::iterator q;
        q=questions.end()-5;
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

questionlist2::~questionlist2()
{
    delete ui;
}

void questionlist2::on_pushButton_clicked()
{
    close();
}

void questionlist2::on_pushButton_2_clicked()
{
    questionlist3 *q=new questionlist3;
    q->show();
}
void questionlist2::testSlot(QTableWidgetItem * q)
{
    flag=0;
    questionnum=q->row()+4;
    questiondetail *qd=new questiondetail();
    qd->show();
}
