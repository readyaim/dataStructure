#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define NUM_OF_ARRAY 5
int Ackerman_LinkStack(int m, int n);
int Ackerman_recurve(int m, int n)
{
    static int counter=0;
    counter++;
    cout<<"m="<<m<<",n="<<n<<endl;
    cout<<"counter = "<<counter<<endl;
    if(m==0&&n>0)
    {
        return n+1;
    }
    else if (n==0&&m>0)
    {
        return Ackerman_recurve(m-1,1);
    }
    else if (m>0&&n>0)
    {
        return Ackerman_recurve(m-1, Ackerman_recurve(m,n-1));

    }
    else
    {
        cout<<"Error in running Ackerman_recurve."<<endl;
        return 0;
    }
}

int Ackerman(int m, int n)
{
    int tmp; 
    stack<int> st;
    
    while(true)
    {
        while(m>0)
        {
            if (n==0)
            {
                m--;
                n=1;
            }
            else
            //n>0
            {
                st.push(m-1);
                n--;
            }
        }
        tmp = n+1; //m=0
        if (st.empty())
            break;
        else
        {
            m=st.top();
            n=tmp;
        }
        st.pop();
        
    }
    return tmp;
}


int run_Ackerman_recurve()
{
    int ackermanValue;
    ackermanValue = Ackerman_recurve(3,3);

    cout<<"ackermanValue = "<<ackermanValue<<endl;
    return 1;
}

int run_Ackerman()
{
    int m,n;
    cin>>m>>n;
    // cout<<"ackerman("<<m<<","<<n<<") = "<<Ackerman(m,n)<<endl;
    cout<<"ackerman("<<m<<","<<n<<") = "<<Ackerman_LinkStack(m,n)<<endl;
    return 1;
}

struct StackNode
{
    int m;
    int n;
    StackNode *link;
};
void Show(StackNode *p)
{
    cout<<"m="<<p->m<<",n="<<p->n<<endl;
}
int Ackerman_LinkStack(int m, int n)
{
    StackNode *top = new StackNode;
    top->m = m;
    top->n = n;
    top->link = NULL;
    int x=0;
    Show(top);
    while(top!=NULL)
    {
        cout<<"read stack:";
        Show(top);
        if (top->m==0&& top->n>0)
        {
            x = top->n +1;
            StackNode *p;
            while (top->n!=-1)
            {
                if(top!=NULL)
                {
                    p=top;
                    top=top->link;      //top can be null after this
                    cout<<"delete: ";
                    Show(p);
                    delete p;
                }
                if (top==NULL)
                {
                    return x;
                }
            }
            top->n = x;     //put result n to stack;
        }
        else if (top->m>0 && top->n==0)
        {
            StackNode *p = new StackNode;
            p->m = top->m-1;
            p->n = 1;
            p->link = top;
            top = p;
            Show(top);
        }
        else if(top->m>0 && top->n>0)
        {
            StackNode *p = new StackNode;
            StackNode *q = new StackNode;
            p->m = top->m-1;
            p->n = -1;   //for recurve
            p->link = top;
            top=p;

            Show(top);
            q->m = top->link->m;
            q->n = top->link->n-1;
            q->link = top;
            top = q;
            Show(top);
        }
    }
    

    return 1;
}
int main()
{
    run_Ackerman();
}

