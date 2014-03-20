// Copyright 2014 by Siarkowy.
// Released under the terms of GNU GPL v3 license.

#include <iostream>
#include <cstdarg>

#define MAX_IDX 5

using namespace std;

int& at(int i)
{
    static int data[MAX_IDX] = { 2, 6, 3, 1, 7 };

    if (i < 0 || i >= MAX_IDX)
        throw new exception("Range exceeded");

    return data[i];
}

int sum(int n, ...)
{
    int s = 0;

    va_list args;           // name variable argument list ... as "args"
    va_start(args, n);      // set last obligatory parameter

    while (n--)
        s += va_arg(args, int);     // get next element from ... as int

    va_end(args);           // clean up unneeded vararg

    return s;
}

int main(int argc, char **argv)
{
    // Task 1
    for (int i = 0; i < MAX_IDX; ++i)
        cout << at(i) << " ";

    cout << endl;

    // Task 2
    cout << "Sum of 2, 6, 3 is " << sum(3, 2, 6, 3) << endl;
    cout << "Sum of 1, 8, 5, 10, 0 is " << sum(5, 1, 8, 5, 10, 0) << endl;

    return 0;
}
