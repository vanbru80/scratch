#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int k = 0;

int digits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n/10;
    }
    return count;
}

int find(int n, int index)
{
    int count = 0;
    index = digits(n)-index;
    while (count != index)
    {
        count++;
        n = n/10;
    }

    return n%10;
}

int seq(int num)
{
    if (num == 1) return 12;
    if (num == 2) return 20;
    if (num == 3) return 32;
    if (num == 4) return 4;

    if (num%4 ==0) return num;
    for (int i = 0; i < 4; ++i)
    {
        if ( (num*10+i) % 4 == 0)
            return num*10+i;
    }
}

int calc()
{
    int n = 12;
    int i = 1;
    while (1)
    {
        int d = digits(n);
        //cout << n << "," << d << "," << k <<endl;
        if (d >= k)
            return find(n, k);
        i++;
        k = k-d;
        n = seq(i);
    }

    return 0;
}

int main()
{
    cin >> k;
    cout << calc() <<endl;
    return 0;
}
