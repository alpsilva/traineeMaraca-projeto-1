#include "vision.h"

Vision::Vision(QString visionAddress, quint16 visionPort)
{
    _visionAddress = visionAddress;
    _visionPort = visionPort;
    _visionSocket = new QUdpSocket();

    //Assim que a classe for declarada, ela já conecta.
    connectToNetwork();
}

void Vision::connectToNetwork(){
    _visionSocket->bind(QHostAddress(_visionAddress), _visionPort, QUdpSocket::ShareAddress);
    //Multicast group: Endereços da rede que podemos conectar e receber pacotes em grupo.
    _visionSocket->joinMulticastGroup(QHostAddress(_visionAddress));
}

void Vision::run(){
    //enquanto existirem datagramas pendentes, pega o datagrama e fazer a interpretação, preenchendo as variáveis.
    while(_visionSocket->hasPendingDatagrams()){
        //receiving datagram
        QNetworkDatagram datagram;
        datagram = _visionSocket->receiveDatagram();

        //parsing datagram to protobuf
        SSL_WrapperPacket packet;
        packet.ParseFromArray(datagram.data().data(), datagram.data().size());

        //check if packet has detection
        if (packet.has_detection()){
            SSL_DetectionFrame visionFrame = packet.detection();

            //check if frame has balls
            if (visionFrame.balls_size() > 0){
                //has ball in frame
                _ball = visionFrame.balls(0);
                //Devido a ruidos, pode ser que mais de uma bola seja capitada. Por definição, a bola enviada primeiro, na posição '0', é a mais confiável.
            }

            //check if frame has blue robots
            if (visionFrame.robots_blue_size() > 0){
                for (int i = 0; i < visionFrame.robots_blue_size(); i++){
                    SSL_DetectionRobot robot = visionFrame.robots_blue(i);
                    _blueRobots.insert(robot.robot_id(), robot);
                    //o insert garante que o conteúdo antigo é apagado quando um novo é inserido.
                }
            }

            //check if frame has yellow robots
            if (visionFrame.robots_yellow_size() > 0){
                for (int i = 0; i < visionFrame.robots_yellow_size(); i++){
                    SSL_DetectionRobot robot = visionFrame.robots_yellow(i);
                    _yellowRobots.insert(robot.robot_id(), robot);
                    //o insert garante que o conteúdo antigo é apagado quando um novo é inserido.
                }
            }

        }
    }
}

SSL_DetectionBall Vision::getBall(){
    return _ball;
}

SSL_DetectionRobot Vision::getRobot(bool isYellow, int id){
    if (isYellow){
        if (_yellowRobots.contains(id)){
            //robô aparece na visão
            return _yellowRobots.value(id);
        }
        else{
            //robô não aparece na visão
            //Nesse momento estamos assumindo que os robôs sempre aparecem, mas na prática não é sempre o caso.
            return SSL_DetectionRobot(); //objeto default
        }
    }
    else{
        if (_blueRobots.contains(id)){
            //robô aparece na visão
            return _blueRobots.value(id);
        }
        else{
            //robô não aparece na visão
            //Nesse momento estamos assumindo que os robôs sempre aparecem, mas na prática não é sempre o caso.
            return SSL_DetectionRobot(); //objeto default
        }
    }

}
