//Problem        : Messed up Rugby
//Language       : C++14
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <vector> 
#include <set> 

using namespace std;

void ways(int n)
{
    for (int i = 0; i <= n/7; ++i)
    {
        int sum = n-(i*7);
        for (int j = 0; j <= sum/3; ++j)
        {
            if ((sum - 3*j)%2 == 0)
                cout << i << " " << j << " " << (sum - 3*j)/2 << endl;
        }
    }
}

int main() 
{
    int score;
    cin >> score;

    ways(score);

    return 0;
}
