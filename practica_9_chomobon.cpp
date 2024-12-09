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
    int counter = 0; //contador de movimientos
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
            std::cout << robotMap.map[i][j];
        }
        std::cout << std::endl;
    }
    return (robotMap);
}

// * termina
int endgame(Map robotMap, int check)
{
    robotMap.map[robotMap.x][robotMap.y] = 'R';
    robotMap = showmap(robotMap);
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "No hay mas movimientos posibles" << std::endl;
    std::cout << "Ha hecho un total de " << robotMap.counter << " movimientos" << std::endl;

    printf ("check en end (antes): %i", check);
    check++;
    printf ("check en end (after): %i", check);
    return(check);
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

//hace que se mueva el robot para completar entero el mapa
Map robotMove(Map robotMap, int check)
{
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
            return (robotMap);
        }
    }
    printf ("check en move: %i", check);
    endgame(robotMap, check); //Muestra el mapa y el numero de movimientos
    return (robotMap);
}

// * main 
int main()
{
    char next;
    int check = 0;
    Map robotMap;

    robotMap = initmap(robotMap); //inicializo el mapa con solo puntos
    robotMap = showmap(robotMap);
    robotMap = initRobot(robotMap); //Situo al robot en las coordenadas recibidas
    robotMap = placerobot(robotMap);
    robotMap = showmap(robotMap);

    std::cout << "Enter any printable character to continue..." << std::endl;
    std::cin >> next;

    while (next >= 32 && next <= 126)
    {
        robotMap = robotMove(robotMap, check);
        if (check == 1)
        {
            printf("aaaaaaaaaaaaaaaaa");
            break;
        }
        std::cout << "Enter any printable character to continue..." << std::endl;
        std::cin >> next;
    }
    while (next <= 32 && next >= 126)
    {
        std::cout << "Incorrect letter, please enter any printable character to continue..." << std::endl;
        std::cin >> next;
    }

    return (0);
}