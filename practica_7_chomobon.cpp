/*
Te pide ingresar una matriz(2x2 o 3x3) y despues que operacion hacer(determinante o visualizarla)

Creado por: Cristina Homobono Fernández
Fecha: 14/nov/2024
*/

/* Includes */
#include <iostream>

/* Funciones */
// * Display error de matriz
int err1()
{
    int option;

    std::cout << "Pofavor introduzca alguno de los valores dados(1 o 2)" << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "|Por favor indique que orden de matriz quiere usar:|" << std::endl;
    std::cout << "|1\tDe orden 2(2x2)                            |" << std::endl;
    std::cout << "|2\tDe orden 3(3x3)                            |" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cin >> option;
    return(option);
}

// * menu
int menu()
{
    int option;

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "|Por favor indique que orden de matriz quiere usar:|" << std::endl;
    std::cout << "|1\tDe orden 2(2x2)                            |" << std::endl;
    std::cout << "|2\tDe orden 3(3x3)                            |" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cin >> option;
    while (option != 1 && option != 2)
        option = err1();
    return(option);
}

// * Display error de opcion de matriz
int err2()
{
    int option;

    std::cout << "Pofavor introduzca alguno de los valores dados(1 o 2)" << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "|1\tVisualizar la matrix                       |" << std::endl;
    std::cout << "|2\tRealizar el determinante de la matriz      |" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cin >> option;
    return(option);
}

// * matriz menu
int m_menu()
{
    int option;

    std::cout << "¿Que es lo siguiente que le gustaria hacer?" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "|1\tVisualizar la matrix                       |" << std::endl;
    std::cout << "|2\tRealizar el determinante de la matriz      |" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cin >> option;
    while (option != 1 && option != 2)
        option = err2();
    return(option);
}

// * matriz 2x2
void matriz2()
{
    double matrix[2][2] = {{0, 0}, {0, 0}}; //Asi es de orden 2 es decir 1, 2
                                            //                           3, 4
    int iterator;
    double num1;
    int option;
    double det;

    num1 = 0.0;
    iterator = 1;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << "Por favor introduce el valor " << iterator << ":" << std::endl;
            std::cin >> num1;
            matrix[i][j] = num1;
            iterator++;
        }
    }
    option = m_menu();
    if (option == 1)
    {
        std::cout << "La matriz ingresada es:" << std::endl;
        std::cout << "|" << matrix[0][0] << "\t" << matrix[0][1] << "|" << std::endl;
        std::cout << "|" << matrix[1][0] << "\t" << matrix[1][1] << "|" << std::endl;
    }
    else if (option == 2)
    {
        det = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
        std::cout << "El determinante de la matriz" << std::endl;
        std::cout << "|" << matrix[0][0] << "\t" << matrix[0][1] << "|" << std::endl;
        std::cout << "|" << matrix[1][0] << "\t" << matrix[1][1] << "|" << std::endl;
        std::cout << "es: " << det << std::endl;
    }
}

// * matriz 3x3
void matrix3()
{
    double matrix3[3][3] = {{0, 0, 0}, {0, 0, 0}};
    double num1;
    int iterator;
    int option;
    double det;

    num1 = 0.0;
    iterator = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                std::cout << "Por favor introduce el valor " << iterator << ":" << std::endl;
                std::cin >> num1;
                matrix3[i][j] = num1;
                iterator++;
        }
    }
    option = m_menu();
    if (option == 1)
    {
        std::cout << "La matriz ingresada es:" << std::endl;
        std::cout << "|" << matrix3[0][0] << "\t" << matrix3[0][1] << "\t" << matrix3[1][2] << "|" << std::endl;
        std::cout << "|" << matrix3[1][0] << "\t" << matrix3[1][1] << "\t" << matrix3[1][2] << "|" << std::endl;
        std::cout << "|" << matrix3[2][0] << "\t" << matrix3[2][1] << "\t" << matrix3[2][2] << "|" << std::endl;
    }
    else if (option == 2)
    {
        det = ((matrix3[0][0] * matrix3[1][1] * matrix3[2][2]) + (matrix3[1][0] * matrix3[2][1] * matrix3[1][2]) + (matrix3[0][1] * matrix3[1][2] * matrix3[2][0]));
        det -= (matrix3[1][2] * matrix3[1][1] * matrix3[2][0]);
        det -= (matrix3[0][1] * matrix3[1][0] * matrix3[2][2]);
        det -= (matrix3[1][2] * matrix3[2][1] * matrix3[0][0]);

        std::cout << "El determinante de la matriz" << std::endl;
        std::cout << "|" << matrix3[0][0] << "\t" << matrix3[0][1] << "\t" << matrix3[1][2] << "|" << std::endl;
        std::cout << "|" << matrix3[1][0] << "\t" << matrix3[1][1] << "\t" << matrix3[1][2] << "|" << std::endl;
        std::cout << "|" << matrix3[2][0] << "\t" << matrix3[2][1] << "\t" << matrix3[2][2] << "|" << std::endl;
        std::cout << "es: " << det << std::endl;
    }
}

// * main
int main()
{
    int opt;

    opt = menu();
    if (opt == 1){
        matriz2();
    }
    else if(opt == 2)
    {
        matrix3();
    }
}