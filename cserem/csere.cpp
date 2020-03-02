#include <iostream>

int main()
{

    int a = 7;
    int b = 5;

    std::cout << "a=" << a << " b=" << b << std::endl;

    // mit éne itt csinálni, hogy a tartalma b-be legyenm b tartalma a-ba?

    int c = a;
    a = b;
    b = c;

    std::cout << "a=" << a << " b=" << b << std::endl;

    // mit éne itt csinálni, hogy a tartalma b-be legyenm b tartalma a-ba?

    b = b - a;
    a = a + b;
    b = a - b;

    std::cout << "a=" << a << " b=" << b << std::endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    std::cout << "a=" << a << " b=" << b << std::endl;

}
