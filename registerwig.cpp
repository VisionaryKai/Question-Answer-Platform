#include"define.h"
#include"widget.h"
#include"registerwig.h"
#include "ui_registerwig.h"
#include<QMessageBox>
registerwig::registerwig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerwig)
{
    ui->setupUi(this);
}

registerwig::~registerwig()
{
    delete ui;
}

void registerwig::on_pushButton_2_clicked()
{
    close();
}

void registerwig::on_pushButton_clicked()
{
    QString str1=ui->lineEdit->text();
    QString str2=ui->lineEdit_2->text();
    if(str1!=NULL&&str2!=NULL)
    {
        user *u=new user(str1,str2);
        users.push_back( u);
        totaluser++;
        QMessageBox::about(this,tr("warning"),tr("register success!"));
    }
    else
    QMessageBox::about(this,tr("warning"),tr("register failed!"));
    close();

}
