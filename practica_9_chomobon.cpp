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
    char map[20][20]; //Hago una matriz 20 x 20
    int x; //Posición x
    int y; //Posición y
    int counter; //contador de movimientos
};

/* funciones */
// * print se acabo
void endgame(Map robotMap)
{
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "No hay mas movimientos posibles" << std::endl;
    std::cout << "Ha hecho un total de " << robotMap.counter << " movimientos" << std::endl;
}

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

// * avanza a la derecha
Map moveright(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x + 1][robotMap.y] = 'R';

    return (robotMap);
}

// * avanza a la izquierda
Map moveleft(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x - 1][robotMap.y] = 'R';

    return (robotMap);
}

// * avanza hacia arriba
Map moveup(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x][robotMap.y - 1] = 'R';

    return (robotMap);
}

// * avanza hacia abajo
Map movedown(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x][robotMap.y + 1] = 'R';

    return (robotMap);
}

// * avanza a arriba-derecha
Map moveUpRight(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x + 1][robotMap.y - 1] = 'R';

    return (robotMap);
}

// * avanza a arriba-izquierda
Map moveUpLeft(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x - 1][robotMap.y - 1] = 'R';

    return (robotMap);
}

// * avanza a abajo-derecha
Map moveDownRight(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x + 1][robotMap.y + 1] = 'R';

    return (robotMap);
}

// * avanza a abajo-izquierda
Map moveDownLeft(Map robotMap)
{
    robotMap.map[robotMap.x][robotMap.y] = '*';
    robotMap.map[robotMap.x - 1][robotMap.y + 1] = 'R';

    return (robotMap);
}

// * Verifico que el camino no este bloqueado
Map checkpath(Map robotMap)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (robotMap.map[robotMap.x + 1][robotMap.y] == '*')
            {
                if (robotMap.map[robotMap.x + 1][robotMap.y + 1] == '*')
                {
                    if (robotMap.map[robotMap.x][robotMap.y + 1] == '*')
                    {
                        if (robotMap.map[robotMap.x - 1][robotMap.y + 1] == '*')
                        {
                            if (robotMap.map[robotMap.x + 1][robotMap.y] == '*')
                            {
                                if (robotMap.map[robotMap.x - 1][robotMap.y - 1] == '*')
                                {
                                    if (robotMap.map[robotMap.x][robotMap.y - 1] == '*')
                                    {
                                        if (robotMap.map[robotMap.x + 1][robotMap.y - 1] == '*')
                                        {
                                            robotMap = showmap(robotMap);
                                            endgame(robotMap);
                                        }
                                        else if (robotMap.map[robotMap.x + 1][robotMap.y - 1] != '*')
                                        {
                                            robotMap = moveUpRight(robotMap);
                                            robotMap.counter++;
                                        }
                                    }
                                    else if (robotMap.map[robotMap.x][robotMap.y - 1] != '*')
                                    {
                                        robotMap = moveup(robotMap);
                                        robotMap.counter++;
                                    }
                                }
                                else if (robotMap.map[robotMap.x + 1][robotMap.y - 1] != '*')
                                {
                                    robotMap = moveUpLeft(robotMap);
                                    robotMap.counter++;
                                }
                            }
                            else if (robotMap.map[robotMap.x + 1][robotMap.y] != '*')
                            {
                                robotMap = moveleft(robotMap);
                                robotMap.counter++;
                            }
                        }
                        else if (robotMap.map[robotMap.x - 1][robotMap.y + 1] != '*')
                        {
                            robotMap = moveDownLeft(robotMap);
                            robotMap.counter++;
                        }
                    }
                    else if (robotMap.map[robotMap.x][robotMap.y + 1] != '*')
                    {
                        robotMap = movedown(robotMap);
                        robotMap.counter++;
                    }
                }
                else if (robotMap.map[robotMap.x + 1][robotMap.y + 1] != '*')
                {
                    robotMap = moveDownRight(robotMap);
                    robotMap.counter++;
                }
            }
            else if (robotMap.map[robotMap.x + 1][robotMap.y] != '*')
            {
                robotMap = moveright(robotMap);
                robotMap.counter++;
            }
        }
    }
    return (robotMap);
}

// * main 
int main()
{
    Map robotMap;
    /* Map keepMap; */
    robotMap = initmap(robotMap); //inicializo el mapa con solo puntos
    robotMap = showmap(robotMap);
    robotMap = initRobot(robotMap); //Situo al robot en las coordenadas recibidas
    robotMap = placerobot(robotMap);
    robotMap = showmap(robotMap);
    robotMap = checkpath(robotMap);
    robotMap = showmap(robotMap);
/*     keepMap = robotMap; //Utilizo un auxiliar para poder analizar si hay movimientos viables */
    return 0;
}