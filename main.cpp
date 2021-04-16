#include <iostream>
#include <QCoreApplication>
#include <vision/vision.h>
#include <actuator/actuator.h>

#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //endereço e porta do simulador.
    Vision *vision = new Vision("224.0.0.1", 10002);
    Actuator *actuator = new Actuator("127.0.0.1", 20011);

    //setando velocidades padrão
    float v = 0.5; //movimento
    float vkx = 1.0; //força do chute
    float vkz = 0.0; //altura do chute(acho)
    unsigned int microsecond = 1000000; //1 segundo

/*
    while(true){
        //run vision module
        vision->run();

        //Debug ball position
        SSL_DetectionBall ball = vision->getBall();
        //std::cout << ball.x() << " | " << ball.y() << std::endl;

        //Debug robot 0 position
        SSL_DetectionRobot yellowRobot = vision->getRobot(true, 0);
        std::cout << "Robot YELLOW 0:" << yellowRobot.x() << " | " << yellowRobot.y() << std::endl;

        if (yellowRobot.x() < 0){
            actuator->sendCommand(true, 0, -2.0, 0.0, 0.0);
        } else {
            actuator->sendCommand(true, 0, 2.0, 0.0, 0.0);
        }



        SSL_DetectionRobot blueRobot = vision->getRobot(false, 0);
        //std::cout << "Robot BLUE 0:" << blueRobot.x() << " | " << blueRobot.y() << std::endl;
    }
*/
    //Criando um controlador para o robô!
    while (true){


        //selecionar time
        bool isYellow;
        char team = '0';
        while (team != 'y' && team != 'b'){
            std::cout << "Qual time deseja usar? 'y' para yellow, 'b' para azul:" << std::endl;
            cin >> team;
            if (team == 'y'){
                isYellow = true;
            } else if (team == 'b'){
                isYellow = false;
            }
        }

        //Selecionar o robô
        int chosenID = -1;
        while(!(chosenID >= 0 && chosenID <= 3)){
            std::cout << "Qual robô deseja controlar? Digite o seu ID (0 a 3):" << std::endl;
            cin >> chosenID;
        }

        //run vision module
        vision->run();

        //pegando o robô selecionado
        SSL_DetectionRobot robot = vision->getRobot(isYellow, chosenID);

        //comandos:
        //Para que o comando seja tratado como um impulso, e não como uma velocidade constante,
        //fiz o programa pausar por um tempo, depois passei um novo comando zerando as velocidades após o impulso.
        std::cout << "Você já pode controlar o robô! wasd para movimentação, z para chutar, x para driblar, p para parar de controlar." << std::endl;
        char command = 's';
        while (command != 'p'){
            cin >> command;
            if (command == 'w'){
                actuator->sendCommand(isYellow, chosenID, v, 0, 0, 0, 0, false);
                usleep(microsecond);//sleeps for 1 second
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);
            } else if (command == 'a') {
                actuator->sendCommand(isYellow, chosenID, 0, v, 0, 0, 0, false);
                usleep(microsecond);//sleeps for 1 second
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);
            } else if (command == 's') {
                actuator->sendCommand(isYellow, chosenID, -v, 0, 0, 0, 0, false);
                usleep(microsecond);//sleeps for 1 second
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);
            } else if (command == 'd') {
                actuator->sendCommand(isYellow, chosenID, 0, -v, 0, 0, 0, false);
                usleep(microsecond);//sleeps for 1 second
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);
            } else if (command == 'z') {
                std::cout << "O robô tentou chutar!" << std::endl;
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, vkx, vkz, false);
                usleep(microsecond);//sleeps for 1 second
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);
            } else if (command == 'x') {
                std::cout << "O robô tentou driblar!" << std::endl;
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, true);
                usleep(microsecond);//sleeps for 1 second
                actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);
            }

            //nova posição do robô selecionado
            std::cout << "Coordenadas:" << robot.x() << " | " << robot.y() << std::endl;
        }
    }

    return a.exec();
}
