#include <iostream>
/* #include <bits/stdc++.h> */
/* #include <stack> */
#include <queue>
#include <time.h>
using namespace std;
int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    
    int a[10] = {0};
    for (int i=0;i<10;i++)
    {
        a[i] = 2*i;
    }
    
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    cout << qu.front()<<endl;
    qu.pop();

    cout << qu.front()<<endl;
    qu.pop();

    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;

    cout<< "running time is: "<<duration<< " sec"<<endl;
    return 0;

}
