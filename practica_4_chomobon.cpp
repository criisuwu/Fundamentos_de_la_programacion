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
void heights_calc()
{
    int count[4]; //Los contadores para saber cuantos datos se han almacenado en cada grupo
    int student_num;
    double height;
    double groups[4]; //Los datos de cada grupo
    double sum = 0;
    double average_groups[4]; //Una media para cada grupo
    double average_total;

    //Con este buble inicializo todos los grupos a 0 para evitar errores
    for (int i = 0; i < 4; i++)
        groups[i] = 0;
    for (int i = 0; i < 4; i++)
        average_groups[i] = 0;

    //Imprimo el mensaje de lo que quiero que inserten
    std::cout << "Porfavor ingrese el numero de estudiantes quiere incluir en la estadistica: ";
    std::cin >> student_num;
    std::cout << std::endl;

    if (student_num <= 0)
    {
        std::cout << "Valor incorrecto" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        heights_calc;
    }
    for (int i = 0; i < student_num; i++)
    {
        std::cout << "Ingrese la altura del estudiante " << i + 1 << " en metros: ";
        std::cin >> height;
        sum += height;

        if (height <= 1.60)
        {
            groups[0] += height;
            count[0] += 1;
        }
        else if (height <= 1.70 && height > 1.60)
        {
            groups[1] += height;
            count[1] += 1;
        }
        else if (height <= 1.80 && height > 1.70)
        {
            groups[2] += height;
            count[2] += 1;
        }
        else if (height > 1.80)
        {
            groups[3] += height;
            count[3] += 1;
        }
        else
            std::cout << "Argumento invalido" << std::endl;
        
        //Verificacion de que las medias no den 0 o algun error
        for (int i = 0; i < 4; i++)
        {
            if (groups[i] <= 0)
                average_groups[i] = 0;
            else
                average_groups[i] = groups[i] / count[i];
        }
        average_total = sum / student_num;

        for (int i = 0; i < 4; i++)
            std::cout << "La media del grupo" << i <<  "es: " << average_groups[i] << std::endl;
        std::cout << "La media total es: " << average_total << std::endl;
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
        heights_calc();
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