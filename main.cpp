#include "widget.h"
#include <QApplication>
#include<define.h>
#include"widget.h"
#include"registerwig.h"
#include <QTextCodec>
QVector<user *>users;
QVector<question>questions;
QVector<question>searchquestions;
QVector<question>questionsreplace;
QVector<question>focusquestion;
QVector<answer>focusanswer;
QString searchcontent;
QString searchtime;
QString focusname;
QTime qsearchtime;
user * curuser;
int flag;
int questionnum;
int currentfocus;
int contentortime;
int totaluser;
int totalquestion;

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    totaluser=0;
    totalquestion=0;
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
