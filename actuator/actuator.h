#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QUdpSocket>
#include <protobufs/grSim_Packet.pb.h>

class Actuator
{
public:
    Actuator(QString actuatorAddress, quint16 actuatorPort);
    //De modo geral, é possível controlar os robôs vss de 3 formas:
    //Velocidade do eixo x
    //Velocidade do eixo y
    //Velocidade angular (w)
    // como os  robôs são omnidirecionais, é possível passar essas 3 informações de uma vez e ele obedecerá!
    //Também é importante declarar qual time receberá o comando e o id do robô.
    void sendCommand(bool isYellow, int id, float vx, float vy, float vw, float vkx, float vkz, bool spinner);

private:
    QUdpSocket *_actuatorSocket;
    QString _actuatorAddress;
    quint16 _actuatorPort;

    void connectToNetwork();

};

#endif // ACTUATOR_H
