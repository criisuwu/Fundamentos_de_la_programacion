/*
Resolución de diferentes problemas: Estadistica de alturas y
resolución de tablas de multiplicar.

Creado por: Cristina Homobono Fernández
Fecha: 29/oct/2024
*/

/* includes */
#include <iostream>

/* funciones */

// * tablas de multiplicar
void times_table()
{
    int sol;
    int fixed_num;
    int num_max;

    fixed_num = 1;
    num_max = 1;
    while (fixed_num < 11)
    {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "TABLA DEL " << fixed_num << std::endl;
        while (num_max < 13)
        {
            sol = fixed_num * num_max;
            std::cout << fixed_num << "x" << num_max << "=" << sol << std::endl;
            num_max++;
        }
        num_max = 1;
        fixed_num++;
    }
}

// * estadistica de estaturas

void stadistic()
{
    int student_num;
    int iter;
    float height;
    float table[4][2]; //El cuatro corresponde al numero de grupos que hay, y el 2 corresponde al 0 = dato, 1 = contador 
    float sum = 0;
    float average_g1;
    float average_g2;
    float average_g3;
    float average_g4;
    float average_total;

    //inicializaciones
    iter = 0;
    table[0][0] = 0;
    table[1][0] = 0;
    table[2][0] = 0;
    table[3][0] = 0;

    std::cout << "Porfavor ingrese el numero de estudiantes quiere incluir en la estadistica: ";
    std::cin >> student_num;
    std::cout << std::endl;
    while (student_num <= 0)
    {
        std::cout << "Dato no valido porfavor introduzca un valor numerico positivo (ej.: 10, 5...)" << std::endl;
        std::cout << "*****************************************************************************" << std::endl;
        std::cout << "Porfavor ingrese el numero de estudiantes quiere incluir en la estadistica: ";
        std::cin >> student_num;
        std::cout << std::endl;
    }
    if (student_num > 0){
        while (iter < student_num)
        {
            std::cout << "Ingrese la altura del estudiante " << iter + 1 << " en metros: ";
            std::cin >> height;
            sum += height;
            while (height < 0)
            {
                std::cout << "Dato no valido porfavor introduzca un valor numerico positivo (ej.: 10, 5...)" << std::endl;
                std::cout << "*****************************************************************************" << std::endl;
                std::cout << std::endl;
                std::cout << "Ingrese la altura del estudiante " << iter + 1 << " en metros: ";
                std::cin >> height;
                sum += height;
            }
            if (height <= 1.60)
            {
                table[0][0] += height; //grupo 1, posicion de datos
                table[0][1]++; //Le sumo uno al contador
                iter++;
            }
            else if (height <= 1.70 && height > 1.60)
            {
                table[1][0] += height;
                table[1][1]++;
                iter++;
            }
            else if (height <= 1.80 && height > 1.70)
            {
                table[2][0] += height;
                table[2][1]++;
                iter++;
            }
            else if (height > 1.80)
            {
                table[3][0] += height;
                table[3][1]++;
                iter++;
            }
            else
                std::cout << "Argumento invalido" << std::endl;
        }
        if (table[0][1] == 0)
            average_g1 = 0;
        else
            average_g1 = table[0][0] / table[0][1];
        if (table[1][1] == 0)
            average_g2 = 0;
        else
            average_g2 = table[1][0] / table[1][1];
        if (table[2][1] == 0)
            average_g3 = 0;
        else
            average_g3 = table[2][0] / table[2][1];
        if (table[3][1] == 0)
            average_g4 = 0;
        else
            average_g4 = table[3][0] / table[3][1];
        average_total = sum / student_num;
        std::cout << "La media del primer grupo es: " << average_g1 << std::endl;
        std::cout << "La media del segundo grupo es: " << average_g2 << std::endl;
        std::cout << "La media del tercer grupo es: " << average_g3 << std::endl;
        std::cout << "La media del cuarto grupo es: " << average_g4 << std::endl;
        std::cout << "La media total es: " << average_total << std::endl;
    }
}

/* main */
int main()
{
    int option;

    std::cout << "Bienvenido, porfavor indique que operacion quiere hacer:" << std::endl;
    std::cout << "0\tSalir" << std::endl;
    std::cout << "1\tEstadistica de alturas" << std::endl;
    std::cout << "2\tTablas de multiplicar" << std::endl;
    std::cin >> option;
    while (option >= 0 || option < 0)
    {
        if (option == 1)
        {
            stadistic();
            std::cout << "------------------------------" << std::endl;
            std::cout << "| Problema " << option << " solucionado! :) |" << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "*****************************************" << std::endl;
            std::cout << std::endl;
            std::cout << "Bienvenido, porfavor indique que operacion quiere hacer:" << std::endl;
            std::cout << "0\tSalir" << std::endl;
            std::cout << "1\tEstadistica de alturas" << std::endl;
            std::cout << "2\tTablas de multiplicar" << std::endl;
            std::cin >> option;
        }
        else if (option == 2)
        {
            times_table();
            std::cout << "------------------------------" << std::endl;
            std::cout << "| Problema " << option << " solucionado! :) |" << std::endl;
            std::cout << "------------------------------" << std::endl;
            std::cout << std::endl;
            std::cout << "*****************************************" << std::endl;
            std::cout << std::endl;
            std::cout << "Bienvenido, porfavor indique que operacion quiere hacer:" << std::endl;
            std::cout << "0\tSalir" << std::endl;
            std::cout << "1\tEstadistica de alturas" << std::endl;
            std::cout << "2\tTablas de multiplicar" << std::endl;
            std::cin >> option;
        }
        else if (option == 0)
        {
            std::cout << "Saliendo..." << std::endl;
            return (0);
        }
        else
        {
            std::cout << "Opción no valida introduzca alguna de las opciones" << std::endl;
            std::cout << std::endl;
            std::cout << "*****************************************************************************" << std::endl;
            std::cout << "Bienvenido, porfavor indique que operacion quiere hacer:" << std::endl;
            std::cout << "0\tSalir" << std::endl;
            std::cout << "1\tEstadistica de alturas" << std::endl;
            std::cout << "2\tTablas de multiplicar" << std::endl;
            std::cin >> option;
        }
    }
}