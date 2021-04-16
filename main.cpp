#include <iostream>
#include <QCoreApplication>
#include <vision/vision.h>
#include <actuator/actuator.h>
#include <qmath.h>

#include <unistd.h>

using namespace std;

//endereço e porta do simulador.
Vision *vision = new Vision("224.0.0.1", 10002);
Actuator *actuator = new Actuator("127.0.0.1", 20011);

//setando velocidades padrão
float v = 0.5; //movimento
float vw = 0.5; //velocidade angular
float vkx = 1.0; //força do chute
float vkz = 0.0; //altura do chute(acho)

unsigned int microsecond = 1000000; //1 segundo em microsegundos
int seconds = 1; //Seletor de espaçamentos
unsigned int secs = seconds * microsecond; //segundos selecionados em microssegundos

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //uso de lambdas, talvez eu refatore pra funções dentro do actuator.

    auto pickBall = [](Vision *vision, bool isYellow, int chosenID){
        //pegando instância atual do robô selecionado
        SSL_DetectionRobot robot = vision->getRobot(isYellow, chosenID);
        //pegando instância atual da posição da bola
        SSL_DetectionBall ball = vision->getBall();

        //Faz o robô virar na direção da bola.
        //
        //
        //
        //
        //

        float bx = ball.x();
        float by = ball.y();
        float rx = robot.x();
        float ry = robot.y();

        //Calcula distância d entre a bola e o robô
        float c1 = rx - bx;
        float c2 = ry - by;
        c1 = qPow(c1, 2);
        c2 = qPow(c2, 2);
        float d = qSqrt(c1 + c2);
        std::cout << "Distância para a bola: " << d << std::endl;

        //calcula velocidade v necessária para chegar na bola
        v = d / (secs / 1000000);

        //Aciona o robô para ir em frente, com o spinner ligado para segurar a bola
        actuator->sendCommand(isYellow, chosenID, v, 0, 0, 0, 0, true);
        usleep(secs);//sleeps for 1 second
        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, true);

    };

    auto kickToGoal = [](Vision *vision, bool isYellow, int chosenID){
        //pegando instância atual do robô selecionado
        SSL_DetectionRobot robot = vision->getRobot(isYellow, chosenID);
        //pegando instância atual da posição da bola
        SSL_DetectionBall ball = vision->getBall();

        //Teoricamente, o robô já está em posse da bola!

        //Faz o robô virar na direção do gol.
        //Lembrar de manter o spinner ligado!
        //
        //
        //
        //
        //

        //Faz o robô chutar!
        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, vkx, vkz, false);
        usleep(secs);//sleeps for 1 second
        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, false);

    };



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
        std::cout << "Qual modo deseja usar? 'a' para automático, 'm' para manual:" << std::endl;
        char modo = '0';
        cin >> modo;
        if (modo == 'a'){
            std::cout << "O amarelo 3 ficará chutando ao gol!" << std::endl;
            //Definição do robô atacante: amarelo 3
            bool isYellow = true;
            int chosenID = 3;
            while (true){

                //run vision module
                vision->run();

                pickBall(vision, isYellow, chosenID);
                kickToGoal(vision, isYellow, chosenID);
            }

        } else if (modo == 'm'){
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

                //comandos:
                //Para que o comando seja tratado como um impulso, e não como uma velocidade constante,
                //fiz o programa pausar por um tempo, depois passei um novo comando zerando as velocidades após o impulso.
                std::cout << "Você já pode controlar o robô! wasd para movimentação, z para chutar, x para ligar ou desligar drible, p para parar de controlar." << std::endl;
                char command = 's';
                bool spinner = false;
                while (command != 'p'){

                    cin >> command;

                    if (command == 'w'){
                        actuator->sendCommand(isYellow, chosenID, v, 0, 0, 0, 0, spinner);
                        usleep(secs);//sleeps for 1 second
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, spinner);
                    } else if (command == 'a') {
                        actuator->sendCommand(isYellow, chosenID, 0, v, 0, 0, 0, spinner);
                        usleep(secs);//sleeps for 1 second
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, spinner);
                    } else if (command == 's') {
                        actuator->sendCommand(isYellow, chosenID, -v, 0, 0, 0, 0, spinner);
                        usleep(secs);//sleeps for 1 second
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, spinner);
                    } else if (command == 'd') {
                        actuator->sendCommand(isYellow, chosenID, 0, -v, 0, 0, 0, spinner);
                        usleep(secs);//sleeps for 1 second
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, spinner);
                    } else if (command == 'z') {
                        //Faz o robô chutar!
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, vkx, vkz, false);
                        usleep(secs);//sleeps for 1 second
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, spinner);
                    } else if (command == 'x') {
                        //Liga/desliga o spinner o spinner
                        if (spinner){
                            spinner = false;
                            std::cout << "Spinner será desligado." << std::endl;
                        } else {
                            spinner = true;
                            std::cout << "Spinner será ligado." << std::endl;
                        }
                        actuator->sendCommand(isYellow, chosenID, 0, 0, 0, 0, 0, spinner);
                    }

                    //Roda a visão
                    vision->run();

                    SSL_DetectionRobot robot = vision->getRobot(isYellow, chosenID);

                    //nova posição do robô selecionado
                    std::cout << "Coordenadas: " << robot.x() << " | " << robot.y() << std::endl;
                    std::cout << "Orientação: " << robot.orientation() << std::endl;
                }
            }

        }

    }




    return a.exec();
}
