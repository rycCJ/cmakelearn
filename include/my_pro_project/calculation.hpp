#include<iostream>
#include<cstdlib>


double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
    }

double divide(double a, double b)
{
    if(b == 0)
    {
        std::cout << "error!" << std::endl;
        return 0.0;
    }
    return a / b;

}