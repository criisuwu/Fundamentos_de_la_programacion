#include "../include/utils.hpp"
#include <iostream>

int contador = 0;

void contador_unos()
{
  int leer;
  int contador;

  contador = 0;
  std::cout << "Por favor introduzca una secuencia de numeros (1 y 0)" << std::endl;
  std::cin >> leer;
  while(leer == 0 || leer == 1)
  {
    if (leer == 1)
    {
      contador++;
      std::cin >> leer;
    }
    else if(leer == 0)
      std::cin >> leer;
  }
  std::cout << "El contador de 1s es: " << contador << std::endl;
  ::contador++;
  std::cout << "El contador de llamadas a contador_unos es: " << ::contador << std::endl;
}

void elevar(int base, int exponente)
{
  int contador;

  contador = 1;
  for (int i = 0; i < exponente; i++)
  {
    contador *= base;
  }
  std::cout << "Elevar " << base << " al exponente " << exponente << " es: " << contador << std::endl;
  ::contador++;
  std::cout << "El contador de llamadas a elevar es: " << ::contador << std::endl;
}
