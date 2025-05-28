/*
El programa consiste en un programa que
simule el movimiento de un robot por un mapa.

Creado por: Cristina Homobono Fernández
Fecha: 27/nov/2024
*/

/* includes */
#include <iostream>

/* estructuras */
// * Aqui defino la estructura a utilizar
struct Map
{
    char map[20][20]; //Hago una matriz 20 x 20
    int x; //Posición x
    int y; //Posición y
    int counter = 0; //contador de movimientos
    //me falta contar las celdas libres

};

// * Lo utilizo para comprobar que ha terminado o no el programa
struct GameState
{
    Map robotMap;
    bool canMove;
};


/* funciones */
// * Inicializo el mapa solo con "."
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

// * Muestro el mapa por la terminal
Map showmap(Map robotMap)
{
    system("clear");

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << robotMap.map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return (robotMap);
}

// * termina
void endgame(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = 'R';
    robotMap = showmap(robotMap);
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "No hay mas movimientos posibles" << std::endl;
    std::cout << "Ha hecho un total de " << robotMap.counter << " movimientos" << std::endl;
}

// * Pido las coordenadas de donde va a ir el robot
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

// * Situo al robot en el mapa
Map placerobot(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = 'R';

    return (robotMap);
}

// * Este movimiento solo se debe de realizar si la r esta
// * situado en las esquinas
GameState corner_robotMove(GameState gameState)
{
    Map robotMap = gameState.robotMap;

    int movement_x[4] = {-1, 1, 0, 0};
    int movement_y[4] = {0, 0, -1, 1};

    robotMap.map[robotMap.x][robotMap.y] = '*';

    for (int i = 0; i < 4; ++i)
    {
        int new_x = robotMap.x + movement_x[i];
        int new_y = robotMap.y + movement_y[i];

        if (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && robotMap.map[new_x][new_y] == '.')
        {
            robotMap.x = new_x;
            robotMap.y = new_y;
            robotMap.map[robotMap.x][robotMap.y] = 'R';
            robotMap = showmap(robotMap);
            robotMap.counter++;
            return {robotMap, true};
        }
    }
    endgame(robotMap); //Muestra el mapa y el numero de movimientos
    return {robotMap, false};
}

// * Ahora valoro los casos diferentes a las esquinas
GameState secondcuadrant_robotMove(GameState gameState)
{
    Map robotMap = gameState.robotMap;

    int move_x[4] = {1, -1, 0, 0};
    int move_y[4] = {0, 0, -1, 1};
    int s_check_x = robotMap.x;
    int s_check_y = robotMap.y;

    for (int i = 0; i < 4; i++)
    {
        int new_x = robotMap.x + move_x[i];
        int new_y = robotMap.y + move_y[i];

        while (new_x >= 0 && new_x < 20 && new_y >= 0 && new_y < 20 && robotMap.map[new_x][new_y] == '.')
        {
            robotMap.x = new_x;
            robotMap.y = new_y;
            robotMap.map[robotMap.x][robotMap.y] = 'R';
            if ((s_check_x == robotMap.x - 1) && s_check_y == robotMap.y)
            {
                int new_x = robotMap.x + move_x[3];
                int new_y = robotMap.y + move_y[3];
                robotMap.x = new_x;
                robotMap.y = new_y;
                robotMap.map[robotMap.x][robotMap.y] = 'R';
                robotMap = showmap(robotMap);
                robotMap.counter++;
                return {robotMap, true};
            }
            else
            {
                robotMap.x = new_x;
                robotMap.y = new_y;
                robotMap.map[robotMap.x][robotMap.y] = 'R';
                robotMap = showmap(robotMap);
                robotMap.counter++;
                return {robotMap, true};
            }
        }
    }
    endgame(robotMap); //Muestra el mapa y el numero de movimientos
    return {robotMap, false};
}

// * La fucion del movimiento
GameState robotMove(GameState gameState)
{
    Map robotMap = gameState.robotMap;

    if ((robotMap.x == 0 && robotMap.y ==0) || (robotMap.x == 19 && robotMap.y == 19)
            || (robotMap.x == 0 && robotMap.y == 19) || (robotMap.x == 19 && robotMap.y == 0))
    {
        return corner_robotMove(gameState);
    }
    else if (robotMap.x > 9 && robotMap.y > 9)
    {
        return secondcuadrant_robotMove(gameState);
    }
    
    //Otro if para implementar el secondcuadrant
    endgame(robotMap); //Muestra el mapa y el numero de movimientos
    return {robotMap, false};
}

// * main 
int main()
{
    char next;
    GameState gameState;

    gameState.robotMap = initmap(gameState.robotMap); //inicializo el mapa con solo puntos
    gameState.robotMap = showmap(gameState.robotMap);
    gameState.robotMap = initRobot(gameState.robotMap); //Situo al robot en las coordenadas recibidas
    gameState.robotMap = placerobot(gameState.robotMap);
    gameState.robotMap = showmap(gameState.robotMap);
    gameState.canMove = true;

    std::cout << "Enter any printable character to continue..." << std::endl;
    std::cin >> next;

    while (next >= 32 && next <= 126 && gameState.canMove)
    {
        gameState = robotMove(gameState);
        if (gameState.canMove)
        {
            std::cout << "Enter any printable character to continue..." << std::endl;
            std::cin >> next;
        }
    }
    while (next <= 32 && next >= 126)
    {
        std::cout << "Incorrect letter, please enter any printable character to continue..." << std::endl;
        std::cin >> next;
    }

    return (0);
}