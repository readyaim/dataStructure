#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100


int W[MAXSIZE];
int gcounter=0;
void InitW()
{
    for (int i=0; i<MAXSIZE;i++)
    {
        W[i]=i;
    }
}

bool knap(int s, int n)
{
    /* gcounter=gcounter+1; */
    if (s==0)
        return true;
    else if (s<0)
        return false;
    else if (s>0 && n<1)
        return false;
    else if (s>0 && n>0)
    {
        if (knap(s-W[n],n-1))
        {
            cout<<W[n]<<" ";
            return true;
        }
        else
            return knap(s,n-1);
    }

}

int main()
{
    int s;
    gcounter = 0;
    InitW();
    cout<<"Input s: ";
    cin>>s;
    if (knap(s,MAXSIZE))
        cout<<endl<<"True"<<endl;
    else
        cout<<endl<<"False"<<endl;
    cout<<"gcounter = "<<gcounter<<endl;
    return 0;

}


