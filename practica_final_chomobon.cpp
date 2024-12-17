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
// * cambiar a numero la primera coordenada
Map changenum1(Map robotMap, std::string coor_x)
{
    robotMap.x = stoi(coor_x);
    return (robotMap);
}

// * cambio a numero la segunda coordenada
Map changenum2(Map robotMap, std::string coor_y)
{
    robotMap.x = stoi(coor_y);
    return (robotMap);
}

// * inicializamos el mapa
Map initmap(Map robotMap)
{
    for (int i = 0; i <= robotMap.x; i++)
    {
        std::cout << robotMap.x << std::endl;
        for (int j = 0; j <= robotMap.y; j++)
        {
            std::cout << robotMap.y << std::endl;
            std::cout << j << std::endl;
            robotMap.map[i][j] = '.';
        }
        std::cout << i << std::endl;
    }
    return (robotMap);
}

// * mostramos el mapa
Map showmap(Map robotMap)
{
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

// * main
int main()
{
    GameState gameState;

    std::ifstream file("config.txt");
    assert(file.is_open());
    std::string line;

    while(std::getline(file, line))
    {
        static const size_t len_err = -1;
        std::size_t coma = line.find(',');

        if (coma != len_err)
        {
            std::string firstnum = line.substr(0, coma); //obtengo la primera coordenada
            std::string secondnum = line.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
            changenum1(gameState.robotMap, firstnum);
            changenum2(gameState.robotMap, secondnum);
            if (robotMap.x >= 0)
            {
                if (robotMap.y >= 0)
                {
                    gameState.robotMap = initmap(gameState.robotMap);
                    gameState.robotMap = showmap(gameState.robotMap);
                }
            }
        }
        file.close();
        return (0);
    }
}
