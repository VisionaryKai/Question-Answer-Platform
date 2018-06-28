
#define DEFINE
#include<iostream>
#include<stdlib.h>
#include<qstring.h>
#include<QTime>
#include<QtGui>
#include<QDebug>
extern int flag;
extern int questionnum;
extern int currentfocus;
extern int contentortime;
extern int totaluser;
extern int totalquestion;
extern QString searchcontent;
extern QString searchtime;
extern QString focusname;
extern QTime qsearchtime;
class BasicInfo
{
    public:
    BasicInfo()
    {

    }
    ~BasicInfo()
    {

    }
    virtual void create(QString)=0;
    protected:
    int textid;
    QString userid;
    QString textcontent;
    QTime time;

}
;
class answer:public BasicInfo
{
private:
    int praiseNum;

public:
     QString praiseusers[99];
    virtual void create(QString uid)
    {
        time = QTime::currentTime();
        userid=uid;
    }
    answer()
    {
    }
    answer(QString content)
    {
        textcontent=content;
        praiseNum=0;
    }
    ~answer()
    {

    }
    void setpraisenum(int n)
    {
        praiseNum=n;
    }
    int getpraisenum()
    {
        return praiseNum;
    }

    QString getuserid()
    {
        return userid;
    }
    void setuserid(QString q)
    {
        userid=q;
    }

    QString getcontent()
    {
        return textcontent;
    }
    void setcontent(QString q)
    {
        textcontent=q;
    }

    QTime gettime()
    {
        return time;
    }
    void settime(QTime t)
    {
        time=t;
    }
};
class question:public BasicInfo
{
private:
    QString title;

public:
    QVector<answer>answers;
    int totalanswer;
    virtual void create(QString uid)
    {
        time = QTime::currentTime();
        userid=uid;
        totalanswer=0;
    }
    question()
    {

    }
    question(QString t,QString content)
    {
        title=t;
        textcontent=content;
    }
    QString getuserid()
    {
        return userid;
    }
    void setuserid(QString q)
    {
        userid=q;
    }

    QString gettitle()
    {
        return title;
    }
    void settitle(QString q)
    {
        title=q;
    }

    QString getcontent()
    {
        return textcontent;
    }
    void setcontent(QString q)
    {
        textcontent=q;
    }

    QTime gettime()
    {
        return time;
    }
    void settime(QTime t)
    {
        time=t;
    }

    int hotlevel()
    {
        int hl,counter;
        QVector<answer>::iterator a;
        hl=answers.size();
        a=answers.begin();
        for(counter=0;counter<answers.size();counter++)
        {
            hl=hl+a->getpraisenum();
            a++;
        }
        return hl;
    }

    ~question()
    {

    }

};
extern QVector<question>questions;
extern QVector<question>questionsreplace;
extern QVector<question>searchquestions;
extern QVector<question>focusquestion;
extern QVector<answer>focusanswer;
class user
{
private:
    QString id;
    QString name;
    QString password;

public:
    int focusnum;
    QString foclist[99];
    user()
    {
        focusnum=0;
    }

    user(QString m_name,QString m_password)
    {
        id=m_name;
        password=m_password;
        focusnum=0;
    }
    ~user()
    {

    }
    QString getid()const
    {
        return this->id;
    }
    void setid(QString i)
    {
        this->id=i;
    }
    void setpassword(QString p)
    {
        this->password=p;
    }

    QString getpassword()const
    {
        return this->password;
    }
    void Focus(QString a)
    {
        int i;
        if(focusnum==0)
        {
            foclist[focusnum]=a;
            focusnum++;

        }
        else
        {
            for(i=0;i<focusnum;i++)
            {
                if(foclist[i]==a)
                {
                    break;
                }
            }
            if(i<focusnum)
            {

            }
            else if(i==focusnum)
            {
                foclist[focusnum]=a;
                focusnum++;
            }
        }
        qDebug()<<focusnum;
        }
}
;
extern user *curuser;
extern QVector<user *>users;

