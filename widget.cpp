#include "widget.h"
#include "ui_widget.h"
#include<define.h>
#include"registerwig.h"
#include"central.h"
#include <QMessageBox>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<QString>
#include<string>
#include<QTextStream>
#include<QIODevice>
#include<QDebug>
#include<widget1.h>
using namespace std;

QTextStream & operator>>(QTextStream &in,user *u)
{
    int j;
    QString s;
    in>>s;
    u->setid(s);
    in>>s;
    u->setpassword(s);
    in>>u->focusnum;
    for(j=0;j<u->focusnum;j++)
    {
        in>>u->foclist[j];
    }
    qDebug()<<u->getid();
}
QTextStream & operator>>(QTextStream &in,question *qs)
{

    //QVector<answer>::iterator an;
    int i,j;
    QString s;
    QTime t;
    in>>s;
    qs->settitle(s);
    in>>s;
    qs->setcontent(s);
    in>>s;
    qs->setuserid(s);
    in>>s;
    t=QTime::fromString(s);
    qs->settime(t);
    in>>i;
    qs->totalanswer=i;
    answer *a=new answer;
    qDebug()<<qs->totalanswer;
    for(j=0;j<qs->totalanswer;j++)
    {
        in>>i;
        a->setpraisenum(i);
        qDebug()<<"no problem!";
        in>>s;
        a->setcontent(s);
        in>>s;
        a->setuserid(s);
        in>>s;
        t=QTime::fromString(s);
        a->settime(t);
        for(i=0;i<a->getpraisenum();i++)
        {
            in>>s;
            a->praiseusers[i]=s;
        }
        qs->answers.push_back(*a);
    }

}
QTextStream & operator<<(QTextStream &out,user *u)
{

    int j;
    QString s;
    s=u->getid();
    out<<s<<" ";
    s=u->getpassword();
    out<<s<<" ";
    j=u->focusnum;
    out<<j<<" ";
    for(j=0;j<u->focusnum;j++)
    {
        if(u->foclist[j]!=NULL)
        {
            s=u->foclist[j];
            out<<s<<" ";
        }
    }
    out<<"\r\n";
}
QTextStream & operator<<(QTextStream &out,question *qs)
{
    QVector<answer>::iterator an;
    int i,j;
    QString s;
    s=qs->gettitle();
    out<<s<<" ";
    s=qs->getcontent();
    out<<s<<" ";
    s=qs->getuserid();
    out<<s<<" ";
    s=qs->gettime().toString();
    out<<s<<" ";
    out<<qs->totalanswer<<" ";
    an=qs->answers.begin();
    for(j=0;j<qs->totalanswer;j++)
    {
        out<<an->getpraisenum()<<" ";
        s=an->getcontent();
        out<<s<<" ";
        s=an->getuserid();
        out<<s<<" ";
        s=an->gettime().toString();
        out<<s<<" ";
        for(i=0;i<an->getpraisenum();i++)
        {
            out<<an->praiseusers[i]<<" ";
        }
        if(an!=qs->answers.end()-1)
        an++;
        else break;
    }
    out<<"\r\n";
}
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    user * u;
    QString str1=ui->lineEdit->text();
    QString str2=ui->lineEdit_2->text();
    int i=0;
    qDebug()<<users.size();
    for(;i<users.size();i++)
    {
        u=users.value(i);
        qDebug()<<users.value(i)->getid();
        if((u->getid()==str1)&&(u->getpassword()==str2))
        {
            curuser=u;
            central *c=new central;
            c->show();
            break;
        }
    }

    /*if(u==users.end())
    {
         QMessageBox::about(this,tr("warning"),tr("wrong name or password!"));
    }
*/
}

void Widget::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(QString(" "));
    ui->lineEdit_2->setText(QString(" "));
}

void Widget::on_pushButton_3_clicked()
{
    registerwig *r=new registerwig;
    r->show();
}

void Widget::on_pushButton_4_clicked()
{
    int k;
    QTextStream in;
    QFile qf("1.txt");
    if(qf.open(QIODevice::ReadOnly))
    {
        qDebug()<<"jhkjhkjhjk";
        QTextStream in(& qf);
        in>>totaluser;
        qDebug()<<"okk";

    for(k=0;k<totaluser;k++)
    {
        user *u=new user;
        in>>u;
        users.push_back(u);
        qDebug()<<"okkk";
    }
    in>>totalquestion;
    question *q=new question;
    for(k=0;k<totalquestion;k++)
    {
        qDebug()<<"okkkkk";
        in>>q;
        questions.push_back(*q);

    }
    qf.close();
    }
}

void Widget::on_pushButton_5_clicked()
{
    int k,i;
    string filename;
    user * u;
    QVector<question>::iterator q;
    QFile f("1.txt");
    u=users.value(0);
    q=questions.begin();
    i=0;
    try{
    if(!f.open(QIODevice::WriteOnly))
    throw QString("open failed!");
    //if(f.open(QIODevice::WriteOnly))
    //{
        qDebug()<<"jhkjhkjhjk";
        QTextStream out(&f);
        out<<totaluser;
        out<<"\r\n";
        for(k=0;k<totaluser;k++)
    {
        out<<u;
        if(i!=users.size()-1)
       { i++;
        u=users.value(i);
        }
        else break;
    }
        out<<totalquestion;
        out<<"\r\n";
    for(k=0;k<totalquestion;k++)
    {
        out<<q;
        if(q!=questions.end()-1)
        q++;
        else break;
    }
    f.close();
    //}
}
catch(QString message)
{
   QMessageBox *mes=new QMessageBox;
   mes->setText(message);
   mes->exec();
}
}

void Widget::on_pushButton_6_clicked()
{
    widget1 *w=new widget1;
    w->show();
}
