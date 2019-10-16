#include <iostream>
using namespace std;

#define NUM_OF_ARRAY 5

int A[10];


void initA(void)
{
    for(int i=0;i<10;i++)
    {
        A[i] = rand()%100;
    }
}

void showA()
{
    for (int i=0;i<10;i++)
    {
        cout<<A[i]<<endl;
    }
}

int Max(int n)
{
    static int counter = 0;
    counter++;
  //  cout<<"Max() is running for "<<counter<<" times";
    if (n==1)
    {
        if (A[1]>A[0]) 
            return A[1];
        else
            return A[0];
    }
    else
    {
        if (A[n]>Max(n-1)) 
            return A[n];
        else
            return Max(n-1);
    }
}

int Sum(int n)
{
    if (n==1)
    {
        return A[0];
    }
    else
    {
        return A[n-1]+Sum(n-1);
    }
}

float Avg(int n)
{
    if (n==1) return float(A[0]);
    else return (A[n-1]+Avg(n-1)*(n-1))/n;
}
int main()
{
    int maxvalue;
    int sumvalue;
    float avgvalue;
    initA();
    cout<<"Hello world!"<<endl;
    showA();
    maxvalue = Max(NUM_OF_ARRAY);
    cout<<"maxvalue = "<<maxvalue<<endl;

    sumvalue = Sum(NUM_OF_ARRAY);
    cout<<"sumvalue = "<<sumvalue<<endl;

    avgvalue = Avg(NUM_OF_ARRAY);
    cout<<"avgvalue = "<<avgvalue<<endl;
    return 1;
}
