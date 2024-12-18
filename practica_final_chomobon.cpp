/*
El programa consiste en un programa que simule el movimiento de un robot por un mapa (nxm).
Debe presentar obstaculos (#) y un robot (R)
Las posiciones se reciben con un archivo config.txt

Creado por: Cristina Homobono Fernández
Fecha: 17/diciembre/2024
*/

/* includes */
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

/* estructuras */
// ? La del mapa
struct Map
{
    char map[100][100];
    int x;
    int y;
    int counter = 0;
};

// ? para comprobar el movimiento
struct GameState
{
    Map robotMap;
    bool canMove;
};

/* funciones */
// * situamos al robot
Map placerobot(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y = 'R'];

    return (robotMap);
}

// * inicializamos el mapa
Map initmap(Map robotMap, int x, int y)
{
    robotMap.x = x;
    robotMap.y = y;
    for (int i = 0; i <= robotMap.x; i++)
    {
        for (int j = 0; j <= robotMap.y; j++)
        {
            robotMap.map[i][j] = '.';
        }
    }
    return (robotMap);
}

// * mostramos el mapa
Map showmap(Map robotMap)
{
    system("clear");

    for (int i = 0; i < robotMap.x; i++)
    {
        for (int j = 0; j < robotMap.y; j++)
        {
            std::cout << robotMap.map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return (robotMap);
}

// * Leer primera line (tamaño del mapa)
Map sizeread(Map robotMap, std::ifstream& file, int& x, int& y)
{
    std::string firstline;

    std::getline(file, firstline);
    static const size_t len_err = -1;
    std::size_t coma = firstline.find(',');

    if (coma != len_err)
    {
        std::string firstnum = firstline.substr(0, coma); //obtengo la primera coordenada
        std::string secondnum = firstline.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
        x = stoi(firstnum);
        y = stoi(secondnum);
        if (x >= 0)
        {
            if (y >= 0)
            {
                robotMap = initmap(robotMap, x, y);
                showmap(robotMap);
            }
        }
    }
    return (robotMap);
}

// * Leer la segunda linea (posicionamiento del robot)
Map robotread(Map robotMap, std::ifstream& file, int& x, int& y)
{
    std::string secondline;

    std::getline(file, secondline);
    static const size_t len_err = -1;
    std::size_t coma = secondline.find(',');

    if (coma != len_err)
    {
        std::string firstnum = secondline.substr(0, coma); //obtengo la primera coordenada
        std::string secondnum = secondline.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
        x = stoi(firstnum);
        y = stoi(secondnum);
        if (x >= 0)
        {
            if (y >= 0)
            {
                robotMap = placerobot(robotMap);
                showmap(robotMap);
            }
        }
    }
    return (robotMap);
}

// * main
int main()
{
    GameState gameState;

    std::ifstream file("config.txt");
    assert(file.is_open());
    std::string line;

    int coor_x;
    int coor_y;

    coor_x = 0;
    coor_y = 0;
    //while(std::getline(file, line)) // ! sera para los objetos
    gameState.robotMap = sizeread(gameState.robotMap, file, coor_x, coor_y);
    gameState.robotMap = robotread(gameState.robotMap, file, coor_x, coor_y);
    file.close();
    return (0);
}
