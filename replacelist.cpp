#include "replacelist.h"
#include "ui_replacelist.h"
#include"replacelist2.h"
#include "define.h"
#include"questiondetail.h"
replacelist::replacelist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replacelist)
{
    int i;
    QVector<question>::iterator q;
    ui->setupUi(this);
    if(questionsreplace.empty())
    {

    }
    else
    {
        q=questionsreplace.end()-1;
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

replacelist::~replacelist()
{
    delete ui;
}

void replacelist::on_pushButton_2_clicked()
{
    close();
}

void replacelist::on_pushButton_clicked()
{
    replacelist2 *r=new replacelist2();
    r->show();
}
void replacelist::testSlot(QTableWidgetItem * q)
{
    flag=1;
    questionnum=q->row();
    questiondetail *qd=new questiondetail();
    qd->show();
}
