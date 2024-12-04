/*
El programa consiste en un programa que
simule el movimiento de un robot por un mapa.

Creado por: Cristina Homobono Fernández
Fecha: 27/nov/2024
*/

/* includes */
#include <iostream>

/* estructura */
// * Aqui defino la estructura a utilizar
struct Map
{
    int x; //Posición x
    int y; //Posición y
    char map[20][20]; //Hago una matriz 20 x 20
};

/* struct robot
{
    char r; //Defino al robot
}; */

/* funciones */
// * Set map
Map initmap(Map robotMap)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            robotMap.map[i][j] = '.';
        }
    }
    return (robotMap);
}

// * Display del mapa
Map showmap(Map robotMap)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << robotMap.map[i][j];
        }
        std::cout << std::endl;
    }
    return (robotMap);
}

// * situa al robot
Map initRobot(Map robotMap)
{
    std::cout << "Porfavor introduzca en que posicion quiere que este el robot" << std::endl;
    std::cout << "Introduzca la posicion x del robot:" << std::endl;
    std::cin >> robotMap.x;

    while (robotMap.x < 0 || robotMap.x > 19)
    {
        std::cout << "Valor incorrecto!" << std::endl;
        std::cout << "************************************************************" << std::endl;
        std::cout << "Por favor introduzca una x valida" << std::endl;
        std::cin >> robotMap.x;
    }

    std::cout << "Introduzca la posicion y del robot:" << std::endl;
    std::cin >> robotMap.y;

    while (robotMap.y < 0 || robotMap.y > 19)
    {
        std::cout << "Valor incorrecto!" << std::endl;
        std::cout << "************************************************************" << std::endl;
        std::cout << "Por favor introduzca una x valida" << std::endl;
        std::cin >> robotMap.y;
    }
    
    return (robotMap);
}

Map placerobot(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = 'R';

    return (robotMap);
}
// * main 
int main(Map robotMap)
{
    robotMap = initmap(robotMap);
    robotMap = showmap(robotMap);
    robotMap = initRobot(robotMap);
    robotMap = placerobot(robotMap);
    robotMap = showmap(robotMap);
    return 0;
}