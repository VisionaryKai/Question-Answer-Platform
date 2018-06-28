#include "searchresult.h"
#include "ui_searchresult.h"
#include "define.h"
#include"questiondetail.h"


void search(QString q)
{
    int i,j,judge;
    QVector<question>::iterator qu;
    qu=questions.begin();
    for(i=0;i<questions.size();i++)
    {
        judge=qu->gettitle().indexOf(searchcontent);
        if(judge!=-1)
        searchquestions.push_back(*qu);
        qu++;
    }
}
void search(QTime a)
{
    int i,j,judge;
    QVector<question>::iterator qu;
    qu=questions.begin();
    for(i=0;i<questions.size();i++)
    {
        if(qu->gettime().toString()==searchtime)
        searchquestions.push_back(*qu);
        qu++;
    }
}

searchresult::searchresult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchresult)
{
    int i;
    QVector<question>::iterator q;
    ui->setupUi(this);
    if(contentortime==0)
    search(searchcontent);
    else
    search(qsearchtime);
    if(searchquestions.empty())
    {

    }
    else
    {
        q=searchquestions.end()-1;
        for(i=0;i<=3;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(q->gettitle()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(q->getuserid()));
            if(q!=searchquestions.begin())
            q--;
            else break;
        }
        connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(testSlot(QTableWidgetItem *)));
    }
}

searchresult::~searchresult()
{
    delete ui;
}

void searchresult::on_pushButton_2_clicked()
{
    close();
}
void searchresult::testSlot(QTableWidgetItem * q)
{
    flag=2;
    questionnum=q->row();
    questiondetail *qd=new questiondetail();
    qd->show();
}
