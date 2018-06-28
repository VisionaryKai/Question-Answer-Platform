#include "usersearch1.h"
#include "ui_usersearch1.h"
#include "define.h"
#include "qmessagebox.h"
#include "searchresult.h"
usersearch1::usersearch1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usersearch1)
{
    ui->setupUi(this);
}

usersearch1::~usersearch1()
{
    delete ui;
}

void usersearch1::on_pushButton_clicked()
{
    searchtime=ui->textEdit->toPlainText();
    contentortime=1;
    qsearchtime=QTime::fromString(searchtime);
    searchquestions.clear();
    QMessageBox::about(this,tr("warning"),tr("search succeed!"));
    searchresult *s=new searchresult;
    s->show();
}

void usersearch1::on_pushButton_2_clicked()
{
    close();
}
