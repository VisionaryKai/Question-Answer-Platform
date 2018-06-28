#include "questionlist3.h"
#include "ui_questionlist3.h"
#include"define.h"
#include"questiondetail.h"
questionlist3::questionlist3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questionlist3)
{
    int i;
    ui->setupUi(this);
    if(questions.size()<=8)
    {

    }
    else
    {
        QVector<question>::iterator q;
        q=questions.end()-9;
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


questionlist3::~questionlist3()
{
    delete ui;
}

void questionlist3::on_pushButton_clicked()
{
    close();
}
void questionlist3::testSlot(QTableWidgetItem * q)
{
    flag=0;
    questionnum=q->row()+8;
    questiondetail *qd=new questiondetail();
    qd->show();
}
