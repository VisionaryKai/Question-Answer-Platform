#include "giveanswer.h"
#include "ui_giveanswer.h"
#include"define.h"
#include"qmessagebox.h"
giveanswer::giveanswer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giveanswer)
{
    ui->setupUi(this);
}

giveanswer::~giveanswer()
{
    delete ui;
}

void giveanswer::on_pushButton_clicked()
{
    QString q;
    q=ui->textEdit->toPlainText();
    answer *a=new answer(q);
    a->create(curuser->getid());
    QVector<question>::iterator qu;
    qu=questions.end()-(questionnum+1);
    qu->answers.push_back(*a);
    qu->totalanswer++;
    QMessageBox::about(this,tr("warning"),tr("answer added!"));
    close();
}

void giveanswer::on_pushButton_2_clicked()
{
    close();
}
