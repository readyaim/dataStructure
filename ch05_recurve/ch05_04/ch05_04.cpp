#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;


bool IsValid(int row, int a[])
{
    int tempCol;
    int tempRow;
    int col = a[row];
    for (tempRow=0;tempRow<row;tempRow++)
    {
        tempCol= a[tempRow];
        if (tempRow == row || \
            tempCol == col || \
            (tempRow+tempCol) == (row+col) ||\
            (tempRow - tempCol) == (row - col))
            return false;
    }
    return true;
}
void ShowArray(int a[],int n, int idx)
{
    cout<<"The "<<idx<<" solution is:";
    for (int i=0;i<n;i++)
    {
        cout<<a[i]+1<<" ";
    }
    cout<<endl;

}

int queen_func1(int a[])
{
    int idx = 1;
    for (a[0]=0;a[0]<8;a[0]++)
    {
        /* place queen at (0,0), (0,1)...(0,7) one bye one */
        for (a[1]=0;a[1]<8;a[1]++)
        {
            if (!IsValid(1,a)) continue; //no position for row (1,1), stop this loop,  try (1,2)
            for (a[2]=0; a[2]<8;a[2]++)
            {
                if (!IsValid(2, a)) continue;
                for (a[3]=0; a[3]<8;a[3]++)
                {
                    if (!IsValid(3, a)) continue;
                    for (a[4]=0;a[4]<8;a[4]++)
                    {
                        if (!IsValid(4, a)) continue;
                        for (a[5]=0;a[5]<8;a[5]++)
                        {
                            if (!IsValid(5, a)) continue;
                            for (a[6]=0;a[6]<8;a[6]++)
                            {
                                if (!IsValid(6, a)) continue;
                                for (a[7]=0;a[7]<8;a[7]++)
                                {
                                    if(!IsValid(7,a)) continue;
                                    else
                                    {
                                        ShowArray(a,8,idx);
                                        idx++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void queen_func2(int a[], int dim)
{
    int idx = 1;
    int row=0;
    while(row>=0)
    {
        for (a[row]++;a[row]<dim;a[row]++)
        {
            if (IsValid(row,a))
            {
                break;
            }
        }
        if (a[row] < dim)
        {
            if (row==dim-1)
            {//find queen pos for last row, output result
                ShowArray(a,dim,idx++);
            }
            else
            {//not finished yet, try next row
                
                row++;
                a[row]=-1;  //Start from column 0;
            }
        }
        else
        {
            row--;
        }
            
    }
}

int queen(int row, int a[], int dim)
{
    static int idx=1;
    int col;
    for (col=0;col<dim;col++)
    {
        a[row]=col;
        if(IsValid(row, a))
        {
            if (row==dim-1)
            {
                /* ShowArray(a, dim, idx++); */
            }
            else
            {
                queen(row+1,a, dim);

            }
        }
    }
}


int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    int a[256]={-1};
    int dim;
    /* queen_func1(a); */
    cout<<"Input the dimention of Queen(int):";
    cin>>dim;
    /* queen_func2(a, dim); */
    queen(0,a,dim);

    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;

    cout<< "running time is: "<<duration<< " sec"<<endl;
    return 0;

}
