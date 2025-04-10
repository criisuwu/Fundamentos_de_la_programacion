/*
Resolución de diferentes problemas: Estadistica de alturas y
resolución de tablas de multiplicar.

Creado por: Cristina Homobono Fernández
Fecha: 25/oct/2024
*/

/* includes */
#include <iostream>

/* funciones */

// * tablas de multiplicar
void times_table()
{
    int sol;

    for(int fixed_num = 1; fixed_num < 11; fixed_num++)
    {
        std::cout << "TABLA DEL " << fixed_num << std::endl;
        for(int num_max = 1;num_max < 13; num_max++)
        {
            sol = fixed_num * num_max;
            std::cout << fixed_num << "x" << num_max << "=" << sol << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }
}

// * estadistica de estaturas

void stadistic()
{
    int student_num;
    float height;
    float table[4][2]; //El cuatro corresponde al numero de grupos que hay, y el 2 corresponde al 0 = dato, 1 = contador 
    float sum = 0;
    float average_g1;
    float average_g2;
    float average_g3;
    float average_g4;
    float average_total;

    //Con este buble inicializo todos los grupos a 0 para evitar errores
    for (int i = 0; i < 4; i++)
        table[i][0] = 0;

    std::cout << "Porfavor ingrese el numero de estudiantes quiere incluir en la estadistica: ";
    std::cin >> student_num;
    std::cout << std::endl;

    if (student_num > 0){
        for (int i = 0; i < student_num; i++)
        {
            std::cout << "Ingrese la altura del estudiante " << i + 1 << " en metros: ";
            std::cin >> height;
            sum += height;
            if (height <= 1.60)
            {
                table[0][0] = table[0][0] + height; //grupo 1, posicion de datos
                printf("%f\n", table[0][0]);
                table[0][1]++; //Le sumo uno al contador
            }
            else if (height <= 1.70 && height > 1.60)
            {
                table[1][0] = table[1][0] + height;
                printf("%f\n", table[1][0]);
                table[1][1]++;
            }
            else if (height <= 1.80 && height > 1.70)
            {
                table[2][0] = table[2][0] + height;
                printf("%f\n", table[2][0]);
                table[2][1]++;
            }
            else if (height > 1.80)
            {
                table[3][0] = table[3][0] + height;
                printf("%f\n", table[3][0]);
                table[3][1]++;
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
    else
    {
        std::cout << "Valor incorrecto" << std::endl;
        stadistic();
    }
}

/* main */
int main()
{
    int option;

    std::cout << "Bienvenido, porfavor indique que operacion quiere hacer:" << std::endl;
    std::cout << "1\tEstadistica de alturas" << std::endl;
    std::cout << "2\tTablas de multiplicar" << std::endl;
    std::cout << "3\tSalir" << std::endl;
    std::cin >> option;
    if (option == 1)
    {
        stadistic();
        std::cout << "Problema " << option << " solucionado! :)" << std::endl;
    }
    else if (option == 2)
    {
        times_table();
        std::cout << "Problema " << option << " solucionado! :)" << std::endl;
    }
    else if (option == 3)
    {
        std::cout << "Saliendo..." << std::endl;
        return (0);
    }
    else
    {
        std::cout << "Opción no valida introduzca alguna de las opciones" << std::endl;
    }
}