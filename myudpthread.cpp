#include "myudpthread.h"


MyUdpThread::MyUdpThread(QObject *parent)
    : QThread{parent}
{
    m_sctSocket = nullptr;
}

MyUdpThread::~MyUdpThread()
{

}

bool MyUdpThread::Init()
{
    if(m_sctSocket == nullptr)
    {
        m_sctSocket = new QUdpSocket();

        if(m_sctSocket != nullptr)
        {
            return m_sctSocket->bind(QHostAddress(QHostAddress::Any), 20101);
        }
        else
        {
            return false;
        }
    }

    return true;
}

void MyUdpThread::run()
{
    while(!isInterruptionRequested())
    {
        if(m_sctSocket->hasPendingDatagrams())
        {
            quint16 iFromPort = 0;
            QHostAddress hstaddr;
            QByteArray arData, arFromAddr;

            arData.resize(static_cast<int>(m_sctSocket->pendingDatagramSize()));

            m_sctSocket->readDatagram(arData.data(), arData.size(), &hstaddr, &iFromPort);

            int ip4 = hstaddr.toIPv4Address();

            arFromAddr.append(((ip4 & 0xFF000000) >> 24) & 0xFF);
            arFromAddr.append(((ip4 & 0x00FF0000) >> 16) & 0xFF);
            arFromAddr.append(((ip4 & 0x0000FF00) >> 8) & 0xFF);
            arFromAddr.append((ip4  & 0x000000FF)  & 0xFF);

            //UDPRecvPack pack(m_mapRecvSocket.key(socket), iPort, arAddr, data);

            //addUDPRecvPack(pack);

            arData.clear();
            arFromAddr.clear();
        }

        msleep(1);
    }
}
