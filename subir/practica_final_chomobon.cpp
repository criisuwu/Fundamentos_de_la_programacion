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
//Podria agregar otra estructura solo para el robot y sus coordenadas asi lograria que el mapa no se modifique(?)

// ? La del mapa
struct Map
{
    char map[100][100];
    int x;
    int y;
    int counter = 0;
    int x_robot;
    int y_robot;
};

// ? para comprobar el movimiento
struct GameState
{
    bool canMove;
    Map robotMap;
};

/* funciones */
// * situamos al robot
Map placerobot(Map robotMap, int& x, int& y, std::ifstream& file)
{
    std::string nextline;

    if (x < 0 || y < 0 || x >= robotMap.x || y >= robotMap.y)
    {
        std::getline(file, nextline);
        static const size_t len_err = -1;
        std::size_t coma = nextline.find(',');

        if (coma != len_err)
        {
            std::string firstnum = nextline.substr(0, coma); //obtengo la primera coordenada
            std::string secondnum = nextline.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
            x = stoi(firstnum);
            y = stoi(secondnum);
        }
    }
    robotMap.x_robot = x;
    robotMap.y_robot = y;
    robotMap.map[robotMap.x_robot][robotMap.y_robot] = 'R';

    return (robotMap);
}

// * situamos los objetos
Map placeobstacules(Map robotMap, int x, int y)
{
    robotMap.x_robot = x;
    robotMap.y_robot = y;
    robotMap.map[robotMap.x_robot][robotMap.y_robot] = '#';
    
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

    if (std::getline(file, firstline))
    {
        static const size_t len_err = -1;
        std::size_t coma = firstline.find(',');

        if (coma != len_err)
        {
            std::string firstnum = firstline.substr(0, coma); //obtengo la primera coordenada
            std::string secondnum = firstline.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
            x = stoi(firstnum);
            y = stoi(secondnum);
            while (x <= 0 || y <= 0)
            {
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
            }
            if (x >= 0)
            {
                if (y >= 0)
                {
                    robotMap = initmap(robotMap, x, y);
                    showmap(robotMap);
                }
            }
        }
    }
    return (robotMap);
}

// * Leer la segunda linea (posicionamiento del robot)
Map robotread(Map& robotMap, std::ifstream& file, int& x, int& y)
{
    std::string secondline;

    if (std::getline(file, secondline))
    {
        static const size_t len_err = -1;
        std::size_t coma = secondline.find(',');

        if (coma != len_err)
        {
            std::string firstnum = secondline.substr(0, coma); //obtengo la primera coordenada
            std::string secondnum = secondline.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
            x = stoi(firstnum);
            y = stoi(secondnum);
            while (x < 0 || y < 0)
            {
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
                            robotMap = placerobot(robotMap, x, y, file);
                            showmap(robotMap);
                        }
                    }
                }
            }
            if (x >= 0)
            {
                if (y >= 0)
                {
                    robotMap = placerobot(robotMap, x, y, file);
                    showmap(robotMap);
                }
            }
        }
    }
    return (robotMap);
}

// * siguientes lineas para los obstaculos
Map readobstacles(Map robotMap, std::ifstream& file, int& x, int& y)
{
    std::string line;

    while (std::getline(file, line))
    {
        static const size_t len_err = -1;
        std::size_t coma = line.find(',');

        if (coma != len_err)
        {
            std::string firstnum = line.substr(0, coma); //obtengo la primera coordenada
            std::string secondnum = line.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
            x = stoi(firstnum);
            y = stoi(secondnum);
            while (x < 0 || y < 0)
            {
                static const size_t len_err = -1;
                std::size_t coma = line.find(',');

                if (coma != len_err)
                {
                    std::string firstnum = line.substr(0, coma); //obtengo la primera coordenada
                    std::string secondnum = line.substr(coma + 1, coma + 2); //obtengo la segunda coordenada
                    x = stoi(firstnum);
                    y = stoi(secondnum);
                    if (x >= 0)
                    {
                        if (y >= 0)
                        {
                            robotMap = placeobstacules(robotMap, x, y);
                            showmap (robotMap);
                        }
                    }
                }
            }
            if (x >= 0)
            {
                if (y >= 0)
                {
                    robotMap = placeobstacules(robotMap, x, y);
                    showmap (robotMap);
                }
            }
        }
    }
    return (robotMap);
}

Map moveforward(Map robotMap)
{
    int new_pos = robotMap.x_robot + 1;

    while (robotMap.x_robot <= robotMap.x)
    {
        robotMap.map[new_pos][robotMap.y_robot] = 'R';
        robotMap.map[robotMap.x_robot][robotMap.y_robot] = '*';
        robotMap.x_robot = new_pos;
    }
    return (robotMap);
}

Map movebackward(Map robotMap)
{
    int new_pos = robotMap.x_robot - 1;

    while (robotMap.x_robot <= robotMap.x)
    {
        robotMap.map[new_pos][robotMap.y_robot] = 'R';
        robotMap.map[robotMap.x_robot][robotMap.y_robot] = '*';
        robotMap.x_robot = new_pos;
    }
    return (robotMap);
}

Map moveup(Map robotMap)
{
    int new_pos = robotMap.y_robot - 1;

    while (robotMap.y_robot <= robotMap.y)
    {
        robotMap.map[robotMap.x_robot][new_pos] = 'R';
        robotMap.map[robotMap.x_robot][robotMap.y_robot] = '*';
        robotMap.y_robot = new_pos;
    }
    return (robotMap);
}

Map movedown(Map robotMap)
{
    int new_pos = robotMap.y_robot + 1;

    while (robotMap.y_robot <= robotMap.y)
    {
        robotMap.map[robotMap.x_robot][new_pos] = 'R';
        robotMap.map[robotMap.x_robot][robotMap.y_robot] = '*';
        robotMap.y_robot = new_pos;
    }
    return (robotMap);
}

Map search(Map robotMap) //No logro entender porque los contadores no aumentan, pero si aumentaran estoy segua de que se moveria correctamente
{
    int countxf = 0;
    int countxb = 0;
    int countyf = 0;
    int countyb = 0;

    int new_xf = robotMap.x_robot + 1;
    int new_xb = robotMap.x_robot - 1;
    int new_yf = robotMap.y_robot + 1;
    int new_yb = robotMap.y_robot - 1;

    printf ("x: %i", countxf);
    while (new_xf == '.' && new_xf <= robotMap.x)
    {
        countxf++;
        new_xf++;
    }
    while (new_xb == '.' && new_xb <= robotMap.x)
    {
        countxb++;
        new_xb++;
    }
    while (new_yf == '.' && new_yf <= robotMap.y)
    {
        countyf++;
        new_yf++;
    }
    while (new_yb == '.' && new_yb <= robotMap.y)
    {
        countyb++;
        new_yb++;
    }
    while (countxf > countxb && countxf > countyb && countxf > countyf)
    {
        while(countxf <= robotMap.x)
            moveforward(robotMap);
        showmap(robotMap);
    }
    while (countxb > countxf && countxb > countyb && countxf > countyf)
    {
        while(countxf <= robotMap.x)
            movebackward(robotMap);
        showmap(robotMap);
    }
    while (countyf > countyb && countxf < countyf && countxb < countyf)
    {
        while(countxf <= robotMap.x)
            movedown(robotMap);
        showmap(robotMap);
    }
    while (countyf < countyb && countxf < countyb && countxb < countyb)
    {
        while(countxf <= robotMap.x)
            moveup(robotMap);
        showmap(robotMap);
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
    gameState.robotMap = sizeread(gameState.robotMap, file, coor_x, coor_y);
    gameState.robotMap = robotread(gameState.robotMap, file, coor_x, coor_y); // No me lo situa me lo modifica
    gameState.robotMap = readobstacles(gameState.robotMap, file, coor_x, coor_y);
    gameState.robotMap = search(gameState.robotMap);
    file.close();
    return (0);
}
