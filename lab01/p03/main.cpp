#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

void badSwap(int a, int b)
{
    a += b;
    b = a - b;
    a = a - b;
}

void pointerSwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void referenceSwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 13, b = 5;

    cout << "Before very bad swap:\n" << "a = " << a << ", b = " << b << "\n";
    badSwap(a, b);
    cout << "After very bad swap:\n" << "a = " << a << ", b = " << b << "\n\n";

    a = 21; b = 9;

    cout << "Before pointer swap:\n" << "a = " << a << ", b = " << b << "\n";
    pointerSwap(&a, &b);
    cout << "After pointer swap:\n" << "a = " << a << ", b = " << b << "\n\n";

    a = 0; b = 7;

    cout << "Before reference swap:\n" << "a = " << a << ", b = " << b << "\n";
    referenceSwap(a, b);
    cout << "After reference swap:\n" << "a = " << a << ", b = " << b << "\n\n";

    a = 99; b = 11;

    cout << "Before template swap:\n" << "a = " << a << ", b = " << b << "\n";
    templateSwap(a, b);
    cout << "After template swap:\n" << "a = " << a << ", b = " << b << "\n\n";


}