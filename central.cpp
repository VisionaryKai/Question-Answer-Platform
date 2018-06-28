#include "central.h"
#include "ui_central.h"
#include"ask.h"
#include"questionlist.h"
#include "focuslist.h"
#include "replacelist.h"
#include"usersearch.h"
#include"usersearch1.h"
#include "define.h"
central::central(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::central)
{
    ui->setupUi(this);
}

central::~central()
{
    delete ui;
}

void central::on_pushButton_4_clicked()
{
    close();
}

void central::on_pushButton_2_clicked()
{
    ask *a=new ask;
    a->show();
}

void central::on_pushButton_clicked()
{
    focuslist *f=new focuslist;
    f->show();
}

void central::on_pushButton_3_clicked()
{
    questionlist *q=new questionlist;
    q->show();
}

void central::on_pushButton_5_clicked()
{
    int i,j;
    questionsreplace=questions;
    question empquestion;
    for(i=0;i<questionsreplace.size();i++)
    {
        for(j=0;j<questionsreplace.size()-i-1;j++)
        {
            if(questionsreplace[j].hotlevel()>questionsreplace[j+1].hotlevel())
            {
                empquestion=questionsreplace[j];
                questionsreplace[j]=questionsreplace[j+1];
                questionsreplace[j+1]=empquestion;
            }

        }
    }
    replacelist *r=new replacelist;
    r->show();
}

void central::on_pushButton_6_clicked()
{
    usersearch *u=new usersearch;
    u->show();
}

void central::on_pushButton_7_clicked()
{
    usersearch1 *u=new  usersearch1;
    u->show();
}
