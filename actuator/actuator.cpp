#include "actuator.h"

Actuator::Actuator(QString actuatorAddress, quint16 actuatorPort)
{
    _actuatorAddress = actuatorAddress;
    _actuatorPort = actuatorPort;
    _actuatorSocket = new QUdpSocket();

    connectToNetwork();
}

void Actuator::connectToNetwork(){
    //Se por algum motivo o socket estiver em uso, fecha antes de conectar.
    if(_actuatorSocket->isOpen()){
        _actuatorSocket->close();
    }
    //Nesse caso, somos clientes e os robôs/simulador são os servidores. Como clientes, somos writeOnly.
    _actuatorSocket->connectToHost(_actuatorAddress, _actuatorPort, QIODevice::WriteOnly, QAbstractSocket::IPv4Protocol);
}

//De modo geral, é possível controlar os robôs vss de 3 formas:
//Velocidade do eixo x
//Velocidade do eixo y
//Velocidade angular (w)
// como os  robôs são omnidirecionais, é possível passar essas 3 informações de uma vez e ele obedecerá!
//Também é importante declarar qual time receberá o comando e o id do robô.
void Actuator::sendCommand(bool isYellow, int id, float vx, float vy, float vw, float vkx, float vkz, bool spinner){
    //Create grSimPacket
    grSim_Packet packet;

    //set macro informations
    packet.mutable_commands()->set_isteamyellow(isYellow);
    packet.mutable_commands()->set_timestamp(0.0);

    //Create robot command message
    grSim_Robot_Command *command = packet.mutable_commands()->add_robot_commands();

    //setting commands
    //set robot id
    command->set_id(id);

    //set velocity
    command->set_wheelsspeed(false);
    command->set_veltangent(vx);
    command->set_velnormal(vy);
    command->set_velangular(vw);

    //set kickspeed
    command->set_kickspeedx(vkx);
    command->set_kickspeedz(vkz);

    //set spinner (drible)
    command->set_spinner(spinner);

    //send data to simulator
    std::string buffer;
    packet.SerializeToString(&buffer);

    //write buffer in network
    _actuatorSocket->write(buffer.c_str(), buffer.length());
}
