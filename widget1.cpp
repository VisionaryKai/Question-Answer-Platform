#include "widget1.h"
#include "ui_widget1.h"

widget1::widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget1)
{

    ui->setupUi(this);
    totalBytes = 0;

    bytesReceived = 0;

    fileNameSize = 0;

    connect(&tcpServer,SIGNAL(newConnection()),this,

    SLOT(acceptConnection()));

    //������������ʱ����newConnection()�ź�
}

void widget1::start() //��ʼ����

{

    ui->startButton->setEnabled(false);

    bytesReceived =0;

    if(!tcpServer.listen(QHostAddress::LocalHost,6666))

    {

        qDebug() << tcpServer.errorString();

        close();

        return;

    }

    ui->serverStatusLabel->setText(tr("listening"));

}

void widget1::acceptConnection()  //��������

{

    tcpServerConnection = tcpServer.nextPendingConnection();

connect(tcpServerConnection,SIGNAL(readyRead()),this,

SLOT(updateServerProgress()));

    connect(tcpServerConnection,

SIGNAL(error(QAbstractSocket::SocketError)),this,

            SLOT(displayError(QAbstractSocket::SocketError)));

    ui->serverStatusLabel->setText("accecpt");

    tcpServer.close();

}

void widget1::updateServerProgress()  //���½���������������

{

   QDataStream in(tcpServerConnection);

   in.setVersion(QDataStream::Qt_4_6);

   if(bytesReceived <= sizeof(qint64)*2)

   { //������յ�������С��16���ֽڣ���ô�Ǹտ�ʼ�������ݣ����Ǳ��浽//����ͷ�ļ���Ϣ

        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2)

            && (fileNameSize == 0))

        { //���������ܴ�С��Ϣ���ļ�����С��Ϣ

            in >> totalBytes >> fileNameSize;

            bytesReceived += sizeof(qint64) * 2;

        }

        if((tcpServerConnection->bytesAvailable() >= fileNameSize)

            && (fileNameSize != 0))

        {  //�����ļ������������ļ�

            in >> fileName;

            ui->serverStatusLabel->setText(tr("receiving...").arg(fileName));

            bytesReceived += fileNameSize;

            localFile = new QFile(fileName);

            if(!localFile->open(QFile::WriteOnly))

            {

                qDebug() << "open file error!";

                return;

            }

        }

        else return;

   }

   if(bytesReceived < totalBytes)

   {  //������յ�����С�������ݣ���ôд���ļ�

       bytesReceived += tcpServerConnection->bytesAvailable();

       inBlock = tcpServerConnection->readAll();

       localFile->write(inBlock);

       inBlock.resize(0);

   }

   ui->serverProgressBar->setMaximum(totalBytes);

   ui->serverProgressBar->setValue(bytesReceived);

   //���½�����

   if(bytesReceived == totalBytes)

   { //�����������ʱ

    tcpServerConnection->close();

    localFile->close();

    ui->startButton->setEnabled(true);

    ui->serverStatusLabel->setText(tr("receive success��").arg(fileName));

   }

}
void widget1::displayError(QAbstractSocket::SocketError) //������

{

    qDebug() << tcpServerConnection->errorString();

    tcpServerConnection->close();

    ui->serverProgressBar->reset();

    ui->serverStatusLabel->setText("server ready");

    ui->startButton->setEnabled(true);

}


widget1::~widget1()
{
    delete ui;
}

void widget1::on_startButton_clicked()
{
    start();
}
