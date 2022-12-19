#include <iostream>
#include <math.h>
using namespace std;

int valLength(int num)
{
    int digitCount = 0;

    if (num == 0)
    {
        digitCount = 1;
    }
    while (num != 0)
    {
        num = num / 10;
        digitCount++;
    }

    return digitCount;
}

int maxEvenLength(int num1_Length, int num2_Length)
{
    if (num1_Length >= num2_Length)
    {
        if (num1_Length % 2 != 0)
        {
            return num1_Length + 1;
        }
        return num1_Length;
    }
    else
    {
        if (num2_Length % 2 != 0)
        {
            return num2_Length + 1;
        }
        return num2_Length;
    }
}

int KaratsubasFM(int a, int b)
{
    if (a < 10 || b < 10)
    {
        return a * b;
    }
    else
    {
        // Equalizing the no. of digits
        int numOfDigits = maxEvenLength(valLength(a), valLength(b));

        // Dividing the numbers into two parts
        int divisor = pow(10, numOfDigits / 2);
        int a1 = a / divisor;
        int a2 = a % divisor;
        int b1 = b / divisor;
        int b2 = b % divisor;

        // A = a1 * b1
        int A = KaratsubasFM(a1, b1);
        // B = a2 * b2
        int B = KaratsubasFM(a2, b2);
        // C = (a1 + a2) * (b1 + b2)
        int C = KaratsubasFM(a1 + a2, b1 + b2);
        // D = C - A - B
        int D = C - A - B;

        // Result = (A * 10^n) + (D * 10^(n/2)) + B
        int result = (A * (pow(10, numOfDigits))) + (D * (pow(10, numOfDigits / 2))) + B;

        return result;
    }
}

int main()
{
    // Taking inputs
    int a, b;
    cout << ("\nEnter first value -> ");
    cin >> a;
    cout << ("Enter second number -> ");
    cin >> b;

    // Karatsuba's Fast Multiplication function
    cout << ("Result = ");
    cout << KaratsubasFM(a, b) << endl;

    // Footer
    cout << ("\nDevanshu Gupta [21BCE0597]") << endl;
    return 0;
}