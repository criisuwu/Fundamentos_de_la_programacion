#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // Para system("clear")

struct Posicion {
    int fila;
    int columna;
};

void mostrarTablero(char** tablero, int filas, int columnas) {
    system("clear");
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << tablero[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Presione Enter para continuar . . .";
    std::cin.get();
}

bool esPosicionValida(int fila, int columna, int filas, int columnas) {
    return fila >= 0 && columna >= 0 && fila < filas && columna < columnas;
}

bool moverRobot(char** tablero, int &fila, int &columna, int filas, int columnas) {
    const int desplazamientos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; ++i) {
        int nuevaFila = fila + desplazamientos[i][0];
        int nuevaColumna = columna + desplazamientos[i][1];

        if (esPosicionValida(nuevaFila, nuevaColumna, filas, columnas) && tablero[nuevaFila][nuevaColumna] == '.') {
            tablero[fila][columna] = '*';
            fila = nuevaFila;
            columna = nuevaColumna;
            tablero[fila][columna] = 'R';
            return true;
        }
    }
    return false;
}

int main() {
    int filas = 0, columnas = 0;
    Posicion robot;
    bool posicionRobotValida = false;

    std::ifstream archivo("config.txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de configuración.\n";
        return 1;
    }

    std::string linea;

    // Leer dimensiones del tablero
    if (getline(archivo, linea)) {
        size_t coma = linea.find(',');
        if (coma != std::string::npos) {
            filas = std::stoi(linea.substr(0, coma));
            columnas = std::stoi(linea.substr(coma + 1));
            if (filas <= 0 || columnas <= 0) {
                std::cerr << "Error: Dimensiones del tablero no válidas.\n";
                return 1;
            }
        } else {
            std::cerr << "Error: Formato de dimensiones incorrecto.\n";
            return 1;
        }
    }

    // Crear tablero dinámicamente
    char** tablero = new char*[filas];
    for (int i = 0; i < filas; ++i) {
        tablero[i] = new char[columnas];
        for (int j = 0; j < columnas; ++j) {
            tablero[i][j] = '.';
        }
    }

    // Leer ubicación del robot
    while (getline(archivo, linea)) {
        size_t coma = linea.find(',');
        if (coma != std::string::npos) {
            robot.fila = std::stoi(linea.substr(0, coma)) - 1;
            robot.columna = std::stoi(linea.substr(coma + 1)) - 1;
            if (robot.fila >= 0 && robot.columna >= 0 && esPosicionValida(robot.fila, robot.columna, filas, columnas)) {
                posicionRobotValida = true;
                tablero[robot.fila][robot.columna] = 'R';
                break;
            }
        }
    }

    // Si no encontró una posición válida
    if (!posicionRobotValida) {
        std::cerr << "Error: No se encontró una posición válida para el robot en el archivo.\n";
        for (int i = 0; i < filas; ++i) delete[] tablero[i];
        delete[] tablero;
        return 1;
    }

    // Leer ubicación de los obstáculos
    while (getline(archivo, linea)) {
        size_t coma = linea.find(',');
        if (coma != std::string::npos) {
            int fila = std::stoi(linea.substr(0, coma)) - 1;
            int columna = std::stoi(linea.substr(coma + 1)) - 1;
            if (fila >= 0 && columna >= 0 && esPosicionValida(fila, columna, filas, columnas)) {
                tablero[fila][columna] = '#';
            }
        }
    }
    archivo.close();

    int celdasLibres = 0, celdasRecorridas = 0;
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            if (tablero[i][j] == '.')
                ++celdasLibres;

    // Movimiento del robot
    while (moverRobot(tablero, robot.fila, robot.columna, filas, columnas)) {
        ++celdasRecorridas;
        mostrarTablero(tablero, filas, columnas);
    }

    // Guardar el resultado final
    std::ofstream salida("salida.txt");
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            salida << tablero[i][j] << ' ';
        }
        salida << '\n';
    }
    salida << "Celdas Recorridas: " << celdasRecorridas << "\n";
    salida << "Celdas Libres: " << celdasLibres << "\n";
    salida.close();

    std::cout << "Simulación completada. Resultado guardado en salida.txt\n";

    for (int i = 0; i < filas; ++i) delete[] tablero[i];
    delete[] tablero;

    return 0;
}








Map moveforward(Map robotMap)
{
    int new_pos = robotMap.x_robot + 1;

    while (robotMap.x_robot <= robotMap.x)
    {
        new_pos = 'R';
        robotMap.x_robot = '*';
        robotMap.x_robot = new_pos;
    }
    return (robotMap);
}

Map search(Map robotMap)
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
        printf("c: %i", countxf);
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
    if (countxf > countxb)
    {
        moveforward(robotMap);
        showmap(robotMap);
    }
    return (robotMap);
}
















Map search(Map &robotMap) {
    int dx[] = {-1, 1, 0, 0};  // Cambios en x (arriba, abajo)
    int dy[] = {0, 0, -1, 1};  // Cambios en y (izquierda, derecha)
    bool moved = false;

    // Intentar mover al menos un 10% en alguna dirección
    for (int dir = 0; dir < 4; dir++) {
        int new_x = robotMap.x_robot;
        int new_y = robotMap.y_robot;

        // Mover el robot en esa dirección mientras haya espacio libre
        while (true) {
            new_x += dx[dir];
            new_y += dy[dir];

            // Comprobar si la nueva posición está dentro del mapa y si es una celda vacía
            if (new_x >= 0 && new_x < robotMap.x && new_y >= 0 && new_y < robotMap.y) {
                if (robotMap.map[new_x][new_y] == '.') {
                    // Marca la celda por la que ha pasado el robot con un *
                    robotMap.map[robotMap.x_robot][robotMap.y_robot] = '*';

                    // Mover el robot a la nueva posición
                    robotMap.x_robot = new_x;
                    robotMap.y_robot = new_y;

                    // Colocar el robot en la nueva posición
                    robotMap.map[robotMap.x_robot][robotMap.y_robot] = 'R';

                    // Se ha movido al menos una celda
                    moved = true;
                    break;
                }
            } else {
                break;  // Sale del bucle si se sale del mapa o encuentra un obstáculo
            }
        }

        // Si se movió, salimos del ciclo de direcciones
        if (moved) break;
    }
    showmap(robotMap);

    // Si no pudo moverse, se queda en la misma posición
    return robotMap;
}