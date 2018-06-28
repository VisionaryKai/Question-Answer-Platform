#include "usersearch.h"
#include "ui_usersearch.h"
#include "define.h"
#include "searchresult.h"
#include "qmessagebox.h"
usersearch::usersearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usersearch)
{
    ui->setupUi(this);
}

usersearch::~usersearch()
{
    delete ui;
}

void usersearch::on_pushButton_2_clicked()
{
    close();
}

void usersearch::on_pushButton_clicked()
{
    searchcontent=ui->textEdit->toPlainText();
    contentortime=0;
    searchquestions.clear();
    QMessageBox::about(this,tr("warning"),tr("search succeed!"));
    searchresult *s=new searchresult;
    s->show();
}
