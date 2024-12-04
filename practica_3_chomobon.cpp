/*
Calculadora de areas y volumenes de figuras geometricas regulares

Creado por: Cristina Homobono Fernández
Fecha: 15/oct/2023
*/

/* includes */
#include <iostream>
#include <cmath>

/* funciones area */

//cubo
double a_cube(double length)
{
    double area;

    area = 6 * (length * length);
    return(area);
}

//prisma
double a_prism (double length, double heigh)
{
    double area;
    double a_base;
    double p_base;

    a_base = length * length;
    p_base = length + length + length + length;
    area = (2 * a_base) + (p_base * heigh);
    return (area);
}

//piramide
double a_pyramid(double length, double ap)
{
    double area;
    double a_base;
    double p_base;

    a_base = length * length;
    p_base = length + length + length + length;
    area = a_base + ((p_base * ap) / 2);
    return (area);
}

//cilindro
double a_cylinder(double r, double heigh)
{
    double area;

    area = 2 * M_PI * r * (r + heigh);
    return (area);
}

//cono
double a_cone(double r, double g_side)
{
    double area;

    area = M_PI * r * (r + g_side);
    return (area);
}

//esfera
double a_sphere(double r)
{
    double area;

    area = 4 * M_PI * r * r;
    return (area);
}

/* funciones volumen */

//cubo
double v_cube(double length)
{
    double volume;

    volume = length * length * length;
    return(volume);
}

//prisma
double v_prism (double length, double heigh)
{
    double volume;
    double a_base;

    a_base = length * length;    
    volume = a_base * heigh;
    return (volume);
}

//piramide
double v_pyramid(double length, double heigh)
{
    double volume;
    double a_base;

    a_base = length * length; 
    volume = 0.33 * a_base * heigh;
    return (volume);
}

//cilindro
double v_cylinder(double r, double heigh)
{
    double volume;

    volume = M_PI * r * r * heigh;
    return (volume);
}

//cono
double v_cone(double r, double heigh)
{
    double volume;

    volume = 0.33 * M_PI * r * r * heigh;
    return (volume);
}

//esfera
double v_sphere(double r)
{
    double volume;

    volume = (4 / 3) * M_PI * r * r * r;
    return (volume);
}

/* main */
int main()
{
    int option;
    int a_option;
    int v_option;
    double length;
    double heigh;
    double ap;
    double r;
    double g_side;
    double f_area;
    double f_volume;

    //interfaz principal
    std::cout << "Hola bienvenido a la calculadora de areas y volumenes\n";
    std::cout << "¿Que le gustaria hacer?\n1";
    std::cout << "\tCalcular un area\n";
    std::cout << "2\tCalcular un volumen\n";
    std::cout << "3\tSalir\n";
    std::cin >> option;
    if (option == 1)
    {
        //interfaz areas
        std::cout << "¿Que area quiere calcular?\n";
        std::cout << "1\tCubo\n2\tPrisma\n";
        std::cout << "3\tPiramide\n4\tCilindro\n";
        std::cout << "5\tCono\n6\tEsfera\n";
        std::cin >> a_option;
        if (a_option <= 0)
        {
            std::cout << "Entrada no valida\n";
            return (0);
        }
        switch (a_option)
        {
            case 1:
                std::cout << "Introduce la longitud en cm\n";
                std::cin >> length;
                if (length <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_area = a_cube(length);
                std::cout << "El area es: " << f_area << "cm" << std::endl;
                break;
            case 2:
                std::cout << "Introduce el lado de la base en cm\n";
                std::cin >> length;                
                std::cout << "Introduce la altura en cm\n";
                std::cin >> heigh;
                if (length <= 0 || heigh <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_area = a_prism (length, heigh);
                std::cout << "El area es: " << f_area << "cm" << std::endl;
                break;
            case 3:
                std::cout << "Introduce el lado de la base en cm\n";
                std::cin >> length;
                std::cout << "Introduce el apotema en cm\n";
                std::cin >> ap;
                if (length <= 0 || ap <= 0)
                {
                    std::cout << "Entrada no valida en cm\n";
                    return (0);
                }
                f_area= a_pyramid(length, ap);
                std::cout << "El area es: " << f_area << "cm" << std::endl;
                break;
            case 4:
                std::cout << "Introduce el radio en cm\n";
                std::cin >> r;
                std::cout << "Introduce la altura en cm\n";
                std::cin >> heigh;
                if (r <= 0 || heigh <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_area = a_cylinder(r, heigh);
                std::cout << "El area es: " << f_area << "cm" << std::endl;
                break;
            case 5:
                std::cout << "Introduce el radio en cm\n";
                std::cin >> r;
                std::cout << "Introduce el generatriz en cm\n";
                std::cin >> g_side;
                if (r <= 0 || g_side <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_area = a_cone(r, g_side);
                std::cout << "El area es: " << f_area << "cm" << std::endl;
                break;
            case 6:
                std::cout << "Introduce el radio en cm\n";
                std::cin >> r;
                if (r <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_area = a_sphere(r);
                std::cout << "El area es: " << f_area << "cm" << std::endl;
                break;
        }
        main();
    }
    else if (option == 2)
    {
        //interfaz volumen
        std::cout << "¿Que volumen quiere calcular?\n";
        std::cout << "1\tCubo\n2\tPrisma\n";
        std::cout << "3\tPiramide\n4\tCilindro\n";
        std::cout << "5\tCono\n6\tEsfera\n";
        std::cin >> v_option;
        if (v_option <= 0)
        {
            std::cout << "Entrada no valida\n";
            return (0);
        }
        switch (v_option)
        {
            case 1:
                std::cout << "Introduce la longitud en cm\n";
                std::cin >> length;
                if (length <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_volume = v_cube(length);
                std::cout << "El volumen es: " << f_volume << "cm" << std::endl;
                break;
            case 2:
                std::cout << "Introduce el lado de la base en cm\n";
                std::cin >> length;                
                std::cout << "Introduce la altura en cm\n";
                std::cin >> heigh;
                if (length <= 0 || heigh <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_volume = v_prism (length, heigh);
                std::cout << "El volumen es: " << f_volume << "cm" << std::endl;
                break;
            case 3:
                std::cout << "Introduce el lado de la base en cm\n";
                std::cin >> length;
                std::cout << "Introduce la altura en cm\n";
                std::cin >> heigh;
                if (length <= 0 || heigh <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_volume= v_pyramid(length, heigh);
                std::cout << "El volumen es: " << f_volume << "cm" << std::endl;
                break;
            case 4:
                std::cout << "Introduce el radio en cm\n";
                std::cin >> r;
                std::cout << "Introduce la altura en cm\n";
                std::cin >> heigh;
                if (r <= 0 || heigh <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_volume = v_cylinder(r, heigh);
                std::cout << "El volumen es: " << f_volume << "cm" << std::endl;
                break;
            case 5:
                std::cout << "Introduce el radio en cm\n";
                std::cin >> r;
                std::cout << "Introduce la altura en cm\n";
                std::cin >> heigh;
                if (r <= 0 || heigh <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_volume = v_cone(r, heigh);
                std::cout << "El volumen es: " << f_volume << "cm" << std::endl;
                break;
            case 6:
                std::cout << "Introduce el radio en cm\n";
                std::cin >> r;
                if (r <= 0)
                {
                    std::cout << "Entrada no valida\n";
                    return (0);
                }
                f_volume = v_sphere(r);
                std::cout << "El volumen es: " << f_volume << "cm" << std::endl;
                break;
        }
        main();
    }
    else if (option == 3)
    {
        std::cout << "Saliendo\n";
        return(0);
    }
    else if (option <= 0)
    {
        std::cout << "Entrada no valida\n";
        return (0);
    }
    else
    {
        std::cout << "Opción no valida\n";
        main();
    }
}