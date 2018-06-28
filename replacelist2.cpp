#include "replacelist2.h"
#include "ui_replacelist2.h"
#include "replacelist3.h"
#include "define.h"
#include"questiondetail.h"
replacelist2::replacelist2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replacelist2)
{
    int i;
    ui->setupUi(this);
    if(questionsreplace.size()<=4)
    {

    }
    else
    {
        QVector<question>::iterator q;
        q=questionsreplace.end()-5;
        for(i=0;i<=3;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(q->gettitle()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q->getuserid()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(q->gettime().toString()));
            if(q!=questionsreplace.begin())
            q--;
            else break;
        }

        connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(testSlot(QTableWidgetItem *)));
    }
}

replacelist2::~replacelist2()
{
    delete ui;
}

void replacelist2::on_pushButton_clicked()
{
    close();
}

void replacelist2::on_pushButton_2_clicked()
{
    replacelist3 * r=new replacelist3();
    r->show();
}
void replacelist2::testSlot(QTableWidgetItem * q)
{
    flag=1;
    questionnum=q->row()+4;
    questiondetail *qd=new questiondetail();
    qd->show();
}
