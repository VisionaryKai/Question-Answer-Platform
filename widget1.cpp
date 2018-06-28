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

    //当发现新连接时发出newConnection()信号
}

void widget1::start() //开始监听

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

void widget1::acceptConnection()  //接受连接

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

void widget1::updateServerProgress()  //更新进度条，接收数据

{

   QDataStream in(tcpServerConnection);

   in.setVersion(QDataStream::Qt_4_6);

   if(bytesReceived <= sizeof(qint64)*2)

   { //如果接收到的数据小于16个字节，那么是刚开始接收数据，我们保存到//来的头文件信息

        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2)

            && (fileNameSize == 0))

        { //接收数据总大小信息和文件名大小信息

            in >> totalBytes >> fileNameSize;

            bytesReceived += sizeof(qint64) * 2;

        }

        if((tcpServerConnection->bytesAvailable() >= fileNameSize)

            && (fileNameSize != 0))

        {  //接收文件名，并建立文件

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

   {  //如果接收的数据小于总数据，那么写入文件

       bytesReceived += tcpServerConnection->bytesAvailable();

       inBlock = tcpServerConnection->readAll();

       localFile->write(inBlock);

       inBlock.resize(0);

   }

   ui->serverProgressBar->setMaximum(totalBytes);

   ui->serverProgressBar->setValue(bytesReceived);

   //更新进度条

   if(bytesReceived == totalBytes)

   { //接收数据完成时

    tcpServerConnection->close();

    localFile->close();

    ui->startButton->setEnabled(true);

    ui->serverStatusLabel->setText(tr("receive success！").arg(fileName));

   }

}
void widget1::displayError(QAbstractSocket::SocketError) //错误处理

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
