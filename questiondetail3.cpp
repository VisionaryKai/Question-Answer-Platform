#include "questiondetail3.h"
#include "ui_questiondetail3.h"
#include"define.h"
#include"giveanswer.h"
#include"qmessagebox.h"
#include"questionlist.h"
questiondetail3::questiondetail3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questiondetail3)
{
    int i;
    QVector<question>::iterator qu;
    QVector<answer>::iterator a;
    ui->setupUi(this);
    if(flag==0)
    qu=questions.end()-(questionnum+1);
    else if(flag==1)
    qu=questionsreplace.end()-(questionnum+1);
    else
    qu=searchquestions.end()-(questionnum+1);
    ui->label->setText(qu->gettitle());
    ui->pushButton_3->setText(qu->getuserid());
    ui->textBrowser->setText(qu->getcontent());
    if(qu->answers.size()<=6)
    {

    }
    else
    {
        a=qu->answers.end()-7;
        for(i=0;i<=2;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(a->getcontent()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(a->getuserid()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(a->getpraisenum())));
            if(a!=(qu->answers.begin()))
            a--;
            else break;
        }
        connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(testSlot(QTableWidgetItem *)));
    }
}


questiondetail3::~questiondetail3()
{
    delete ui;
}

void questiondetail3::on_pushButton_4_clicked()
{
    close();
}

void questiondetail3::on_pushButton_clicked()
{
    giveanswer *g=new giveanswer;
    g->show();
}
void questiondetail3::testSlot(QTableWidgetItem * q)
{
    int i;
    if(q->column()==2)
    {

        QVector<question>::iterator qu;
        QVector<answer>::iterator an;
        qu=questions.end()-(questionnum+1);
        an=qu->answers.end()-1-q->row()-6;
        if(an->getpraisenum()==0)
        {
            an->setpraisenum(1);
            ui->tableWidget->setItem(q->row(),2,new QTableWidgetItem(QString::number(an->getpraisenum())));
            an->praiseusers[0]=curuser->getid();
        }
        else
        for(i=0;i<=an->getpraisenum()-1;i++)
        {
            if(an->praiseusers[i]==curuser->getid())
            break;
        }
        if(i==an->getpraisenum())
        {
            an->setpraisenum(i+1);
            an->praiseusers[i]=curuser->getid();
            QVector<answer>::iterator a;

            ui->tableWidget->setItem(q->row(),2,new QTableWidgetItem(QString::number(an->getpraisenum())));
        }
    }
    else if(q->column()==1)
    {
        QVector<question>::iterator qu;
        QVector<answer>::iterator an;
        qu=questions.end()-(questionnum+1);
        an=qu->answers.end()-q->row()-6;
        if(an->getuserid()!=curuser->getid())
        {
            curuser->Focus(an->getuserid());
            QMessageBox::about(this,tr("warning"),tr("focus success!"));
        }
    }
}
void questiondetail3::on_pushButton_3_clicked()
{
    QVector<question>::iterator qu;
    qu=questions.end()-(questionnum+1);
    if(qu->getuserid()!=curuser->getid())
    {
        curuser->Focus(qu->getuserid());
        QMessageBox::about(this,tr("warning"),tr("focus success!"));
    }
}
