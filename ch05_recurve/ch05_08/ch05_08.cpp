#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

class GenList;
class GenListNode
{
    friend class GenList;
private:
    int utype;
    int mark;
    GenListNode *tlink;
    union {
        int ref;
        int intginfo;
        char charinfo;
        GenListNode *hlink;
    }value;
};

class GenList
{
private:
    GenListNode *first;
    void Search(GenListNode *ls);
public:
    GenList();
    ~GenList();
    void Search();
};

void GenList::Search()
{
    Search(first);
}

void GenList::Search(GenListNode *ls)
{
    GenListNode *p;
    p=first->tlink;
    while(p!=NULL)
    {
        if (p->mark == 0)
        {
            p->mark = 1;
            if (p->utype!=3)
            {
                cout<<p->value.intginfo<<" ";
            }
            else
            {
                Search(p->value.hlink);
            }
        }
        p=p->tlink;
    }

}
int main()
{
    clock_t start, finish;
    double duration;
    start = clock();

    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;

    cout<< "running time is: "<<duration<< " sec"<<endl;
    return 0;

}
