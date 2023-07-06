#include <iostream>
#include <cmath>


void is_prime_number();
void prime_number_generator();

int main()
{
    //is_prime_number();
    prime_number_generator();

    system("pause");
    return 0;
}
void is_prime_number()
{
    bool check = true;
    int a;
    std::cout << "Please insert the number, the program will check is it prime number or not\n";
    std::cin >> a;
    std::cin.ignore();

    for (unsigned int i = 2; i <= sqrt(a) ; i++)
    {
        if (a <= 1)
        {
            check = false;
            break;
        }
        if (!(a % i))
        {
            std::cout << "this number is not prime number\n";
            check = false;
            break;
        }
    }
        if (check)
            std::cout<<"this number is prime number\n";

}

void prime_number_generator()
{
    bool check = true;
    int a = 2, b = 0;
    std::cout << "Please enter the number of prime numbers to generate:\n";
    std::cin >> b;
    std::cin.ignore();
    for (unsigned int i = 0; i < b; i++)
    {
        check = true;
        for (unsigned int j = 2; j <= sqrt(a); j++)
        {
            if (!(a % j))
            {
                check = false;
                break;
            }
        }
        if (check)
            std::cout << i + 1 <<". "<< a << "\n";
        else
            i--;
        a++;
    }
}