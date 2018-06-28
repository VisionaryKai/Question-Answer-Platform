#include "focusdetail.h"
#include "ui_focusdetail.h"
#include"define.h"
focusdetail::focusdetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::focusdetail)
{
        int i,j,counter;
        QVector<question>::iterator qu;
        QVector<answer>::iterator a;
        focusquestion.clear();
        focusanswer.clear();
        ui->setupUi(this);
        qu=questions.begin();
        for(i=0;i<questions.size();i++)
        {
              a=qu->answers.begin();
              if(focusname==qu->getuserid())
              {
                 focusquestion.push_back(*qu);
              }
              for(j=0;j<qu->answers.size();j++)
              {
                  if(focusname==a->getuserid())
                  {
                     focusanswer.push_back(*a);
                  }
                  if(a<qu->answers.end()-1)
                  a++;
                  else break;
              }
              if(qu<questions.end()-1)
              qu++;
              else break;
        }
            qu=focusquestion.begin();
            a=focusanswer.begin();
            if(focusquestion.empty())
            {

            }
            else
            {
                for(counter=0;counter<=5;counter++)
            {
                ui->tableWidget->setItem(counter,0,new QTableWidgetItem(qu->gettitle()));
                if(qu!=focusquestion.end()-1)
                qu++;
                else break;
            }
            }
            if(focusanswer.empty())
            {

            }
            else
            {
            for(counter=0;counter<=5;counter++)
            {
                ui->tableWidget->setItem(counter,1,new QTableWidgetItem(a->getcontent()));
                if(a!=focusanswer.end()-1)
                a++;
                else break;
            }
            }

}

focusdetail::~focusdetail()
{
    delete ui;
}

void focusdetail::on_pushButton_2_clicked()
{
    close();
}
