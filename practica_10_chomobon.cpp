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
    //int num;

    std::ifstream file("entrada.txt"); //Abre el archivo
    assert(file.is_open()); //Termina el programa en caso de fallo al abrir el archivo
    std::string line;

    std::getline(file, line); //Leo la primera linea
    while (std::getline(file, line))
    {
        
    }
    

    file.close(); //Cierra el archivo
    //std::cout << "La suma total de los numeros es: " << num << std::endl; 
    return(0);
}