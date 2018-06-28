#include "ask.h"
#include "ui_ask.h"
#include"define.h"
#include"widget.h"
#include<QMessageBox>
ask::ask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ask)
{
    ui->setupUi(this);
}

ask::~ask()
{
    delete ui;
}

void ask::on_pushButton_clicked()
{
    QString t,c;
    t=ui->lineEdit->text();
    c=ui->textEdit->toPlainText();
    question *q=new question(t,c);
    q->create(curuser->getid());
    questions.push_back(*q);
    totalquestion++;
    QMessageBox::about(this,tr("warning"),tr("question added!"));
    close();
}

void ask::on_pushButton_2_clicked()
{
    close();
}
