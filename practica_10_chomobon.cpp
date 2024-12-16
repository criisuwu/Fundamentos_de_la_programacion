/*
El programa recibe un archivo .txt y debe de sumar el numero
que este dentro de las letras 'a' y 'z'.
Ejemplo:
a45z
g4z
a1z7
ga4z

Devuelve 50.

Creado por: Cristina Homobono Fernández
Fecha: 10/diciembre/2024
*/

/* includes */
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

/* funciones */
// * main
int main()
{
    int sum_num;

    sum_num = 0;
    std::ifstream file("entrada.txt"); //Abre el archivo
    assert(file.is_open()); //Termina el programa en caso de fallo al abrir el archivo
    std::string line;

    while (std::getline(file, line))
    {
        static const size_t lenerr = -1;
        std::size_t pos1 = line.find('a');
        std::size_t pos2 = line.find('z');

        if(pos1 != lenerr && pos2 != lenerr && pos1 < pos2)
        {
            std::string az_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string num;
            for (std::size_t i = 0; i < az_str.length(); i++)
            {
                char ch_num = az_str[i]; //al ser una string tiene posiciones y por ello las puedo recorrer
                if (ch_num >= '0' && ch_num <= '9') //Lo uso para ver si es un numero
                {
                    num += ch_num;
                }
                else if(num.length() > 0)
                {
                    sum_num = std::stoi(num);
                    num = ""; //Lo uso para resetear el numero que esta usando y que no de fallo
                }
            }
            if (num.length() > 0) //Por si hay un ultimo numero para añadirlo
            {
                sum_num += std::stoi(num);
            }
        }
    }
    

    file.close(); //Cierra el archivo
    std::cout << "La suma total de los numeros es: " << sum_num << std::endl; 
    return(0);
}