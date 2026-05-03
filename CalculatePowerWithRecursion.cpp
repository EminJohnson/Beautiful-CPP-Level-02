#include <iostream>

using namespace std;

unsigned short CalculatPower(unsigned short M, unsigned short N)
{
    return (N == 0) ? 1 : M * CalculatPower(M, N - 1);
}

int main()
{
    cout << "Result: " << CalculatPower(2, 4) << endl;
    return 0;
}
