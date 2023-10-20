#ifndef MYUDPTHREAD_H
#define MYUDPTHREAD_H

#include <QThread>
#include <QObject>
#include <QtNetwork/QtNetwork>
#include <QMutex>

class QUdpSocket;

// 接收包
struct UDPRecvPack
{
    quint16 m_iLocalPort;         // 本地监听端口
    quint16 m_iRemotePort;        // 发送端端口
    QByteArray m_arAddr;          // 接收: 来源地址   发送: 目的地址
    QByteArray m_arFrame;         // 有线协议帧

    UDPRecvPack()
    {
        init();
    }

    void init()
    {
        m_iLocalPort = 0;
        m_iRemotePort = 0;
        m_arAddr.clear();
        m_arFrame.clear();
    }

    UDPRecvPack(quint16 localport, quint16 remoteport, QByteArray addr, QByteArray frame)
    {
        this->m_iLocalPort = localport;
        this->m_iRemotePort = remoteport;
        this->m_arAddr = addr;
        this->m_arFrame = frame;
    }
};

// 发送包
struct UDPSendPack
{
    quint16 m_iRemotePort;        // 目标端口
    QByteArray m_arAddr;          // 接收: 来源地址   发送: 目的地址
    QByteArray m_arFrame;         // 有线协议帧

    UDPSendPack()
    {
    }

    void init()
    {
        m_iRemotePort = 0;
        m_arAddr.clear();
        m_arFrame.clear();
    }

    UDPSendPack(quint16 remoteport, QByteArray addr, QByteArray frame)
    {
        this->m_iRemotePort = remoteport;
        this->m_arAddr = addr;
        this->m_arFrame = frame;
    }

    QString getAddr()
    {
        QString addr = QString("%1.%2.%3.%4").arg(QString::number((quint8)m_arAddr[0], 10))  \
                           .arg(QString::number((quint8)m_arAddr[1], 10))  \
                           .arg(QString::number((quint8)m_arAddr[2], 10))  \
                           .arg(QString::number((quint8)m_arAddr[3], 10));

        return addr;
    }
};

class MyUdpThread : public QThread
{
    Q_OBJECT
public:
    explicit MyUdpThread(QObject *parent = nullptr);
    ~MyUdpThread();

public:

signals:


protected:

    QUdpSocket *m_sctSocket;

    bool Init();

    // QThread interface
protected:
    virtual void run() override;
};

#endif // MYUDPTHREAD_H
