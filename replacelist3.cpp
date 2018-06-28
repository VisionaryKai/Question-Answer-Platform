#include "replacelist3.h"
#include "ui_replacelist3.h"
#include "define.h"
#include"questiondetail.h"
replacelist3::replacelist3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replacelist3)
{
    int i;
    ui->setupUi(this);
    if(questionsreplace.size()<=8)
    {

    }
    else
    {
        QVector<question>::iterator q;
        q=questionsreplace.end()-9;
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

replacelist3::~replacelist3()
{
    delete ui;
}

void replacelist3::on_pushButton_clicked()
{
    close();
}
void replacelist3::testSlot(QTableWidgetItem * q)
{
    flag=1;
    questionnum=q->row()+8;
    questiondetail *qd=new questiondetail();
    qd->show();
}
