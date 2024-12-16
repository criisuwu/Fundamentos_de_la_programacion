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
// * funcion principal
void solve_file()
{
    bool last_num = 0; //no hay mas numeros en esa linea
    int sum_num;

    sum_num = 0;
    std::ifstream file("entrada.txt"); //Abre el archivo
    assert(file.is_open()); //Termina el programa en caso de fallo al abrir el archivo
    std::string line;

    while (std::getline(file, line)) // va leyendo line a linea
    {
        static const size_t len_err = -1;
        std::size_t pos1 = line.find('a'); //busca la posicion de la letra a
        std::size_t pos2 = line.find('z'); //busca la posicion de la letra z

        if(pos1 != len_err && pos2 != len_err && (pos1 < pos2)) //si las posiciones son mayores que -1 y la posicion 1 es menor que la 2
        {
            std::string az_str = line.substr(pos1 + 1, pos2 - pos1 - 1); //Donde encuentra la a + 1 = num y pos2 - pos1 -1 me da la pos del num desde la posicion
            std::string num_as_str;
            for (std::size_t i = 0; i < az_str.length(); i++)
            {
                char ch_num = az_str[i]; //al ser una string tiene posiciones y por ello las puedo recorrer
                if (ch_num >= '0' && ch_num <= '9') //Lo uso para ver si es un numero
                {
                    num_as_str += ch_num; //lo voy añadiendo a mi strings de numeros
                    last_num = 1; //lo paso a verdadero
                }
            }
            if (last_num) //Por si ya no hay mas numeros (por si es de dos, tres... cifras)
            {
                sum_num += std::stoi(num_as_str); //lo paso a numero y hago la suma
                num_as_str = ""; //Con esto reseteo para que no haya ningun numero y que no genere conflicto
                last_num = 0; //lo paso a falso
            }
        }
    }
    

    file.close(); //Cierra el archivo
    std::cout << "La suma total de los numeros es: " << sum_num << std::endl; 
}

// * main
int main()
{
    solve_file();
    return(0);
}