/*
Muestra la media de temperatura del dia, semana, amanecer, medio dia y atardecer

Creado por: Cristina Homobono Fernández
Fecha: 6/nov/2024
*/

/* includes */
#include <iostream>

/* funciones */
// * menu
void interface()
{
    std::cout << "Bienvenido, este programa le dira varias cosas:" << std::endl;
    std::cout << "La temperatura media de la semana" << std::endl;
    std::cout << "La temperatura media de cada dia" << std::endl;
    std::cout << "La temperatura media tomadas al amanecer" << std::endl;
    std::cout << "La temperatura media tomadas al medio dia" << std::endl;
    std::cout << "La temperatura media tomadas al atardecer" << std::endl;
}

// * Recolecta de datos
void data()
{
    double temperature[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double w_average;
    double d_average;
    double m_average;
    double no_average;
    double ni_average;
    int iterator;
    int iterator2;
    double m_temperature;
    double no_temperature;
    double ni_temperature;

    iterator = 0;
    iterator2 = 0;
    w_average = 0;
    d_average = 0;
    m_average = 0;
    no_average = 0;
    ni_average = 0;
    interface();
    while (iterator < 7)
    {
        std::cout << "*******************************************************" << std::endl;
        std::cout << "Porfavor introduzca los datos correspondientes del día "<< iterator + 1 << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;

        std::cout << "Introduzca la temperatura al amanecer" << std::endl;
        std::cin >> m_temperature;
        temperature[iterator2] += m_temperature;
        std::cout << "-------------------------------------------------------" << std::endl;

        std::cout << "Introduzca la temperatura al medio dia" << std::endl;
        std::cin >> no_temperature;
        temperature[iterator2 + 1] += no_temperature;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Introduzca la temperatura al anochecer" << std::endl;
        std::cin >> ni_temperature;
        temperature[iterator2 + 2] += ni_temperature;
        iterator2 = iterator2 + 3;
        iterator++;
    }
    iterator2 = 0;
    while (iterator2 < 21)
    {
        m_average += temperature[iterator2];
        iterator2 = iterator2 + 3;
    }
    iterator2 = 1;
    while (iterator2 < 21)
    {
        no_average += temperature[iterator2];
        iterator2 = iterator2 + 3;
    }
    iterator2 = 2;
    while (iterator2 < 21)
    {
        ni_average += temperature[iterator2];
        iterator2 = iterator2 + 3;
    }
    m_average = m_average / 7;
    no_average = no_average / 7;
    ni_average = ni_average / 7;
    iterator = 0;
    while (iterator < 21)
    {
        w_average += temperature[iterator];
        iterator++;
    }
    w_average = w_average / 21;
    std::cout << "*****************************************************************" << std::endl;
    std::cout << "La temperarura media del amanecer es: " << m_average << std::endl;
    std::cout << "La temperarura media del medio dia es: " << no_average << std::endl;
    std::cout << "La temperarura media del atardecer es: " << ni_average << std::endl;
    std::cout << "La temperarura media de la semana es: " << w_average << std::endl;
    iterator = 1;
    iterator2 = 1;
    while (iterator < 8)
    {
        d_average += temperature[iterator2 - 1];
        d_average += temperature[iterator2];
        d_average += temperature[iterator2 + 1];
        d_average = d_average / 3;
        if (d_average >= w_average)
        {
            std::cout << "*****************************************************************" << std::endl;
            std::cout << "La temperarura media del dia " << iterator << " es: " << d_average << std::endl;
            std::cout << "Y es mayor a la temperatura media de la semana." << std::endl; //Esto lo tengo que cambiar
        }
        else
        {
            std::cout << "*****************************************************************" << std::endl;
            std::cout << "La temperarura media del dia " << iterator << " es: " << d_average << std::endl;
        }
        d_average = 0;
        iterator2 = iterator2 + 3;
        iterator++;
    }
    iterator = 1;
    iterator2 = 0;
    while (iterator < 8)
    {
        std::cout << "*****************************************************************" << std::endl;
        std::cout << "Las temperaturas recogidas en el dia " << iterator << " son:" << std::endl;
        std::cout << "La temperarura del amanecer es " << temperature[iterator2] << std::endl;
        std::cout << "La temperarura del medio dia es " << temperature[iterator2 + 1] << std::endl;
        std::cout << "La temperarura del atardecer es " << temperature[iterator2 + 2] << std::endl;
        iterator++;
        iterator2 = iterator2 + 3;
    }
    std::cout << "*****************************************************************" << std::endl;
}

/* main */
int main()
{
    data();
}