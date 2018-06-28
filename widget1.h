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

      qint64 totalBytes;  //����ܴ�С��Ϣ

      qint64 bytesReceived;  //���յ����ݵĴ�С

      qint64 fileNameSize;  //�ļ����Ĵ�С��Ϣ

      QString fileName;   //����ļ���

      QFile *localFile;   //�����ļ�

  QByteArray inBlock;   //���ݻ�����

private slots:

    void on_startButton_clicked();

    void start();   //��ʼ����

    void acceptConnection();  //��������

    void updateServerProgress();  //���½���������������

    void displayError(QAbstractSocket::SocketError socketError);

 //��ʾ����
};

#endif // WIDGET1_H
