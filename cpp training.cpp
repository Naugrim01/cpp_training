#include <iostream>
#include <cmath>


void is_prime_number();
int main()
{
    std::cout << "Hello World!\n";
    is_prime_number();

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