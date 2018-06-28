#ifndef WIDGET1_H
#define WIDGET1_H

#include <QWidget>
#include <QtNetwork>
namespace Ui {
class widget1;
}

class widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit widget1(QWidget *parent = 0);
    ~widget1();

private:
    Ui::widget1 *ui;

    QTcpServer tcpServer;

      QTcpSocket *tcpServerConnection;

      qint64 totalBytes;  //存放总大小信息

      qint64 bytesReceived;  //已收到数据的大小

      qint64 fileNameSize;  //文件名的大小信息

      QString fileName;   //存放文件名

      QFile *localFile;   //本地文件

  QByteArray inBlock;   //数据缓冲区

private slots:

    void on_startButton_clicked();

    void start();   //开始监听

    void acceptConnection();  //建立连接

    void updateServerProgress();  //更新进度条，接收数据

    void displayError(QAbstractSocket::SocketError socketError);

 //显示错误
};

#endif // WIDGET1_H
