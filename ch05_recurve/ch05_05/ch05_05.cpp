#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

class GenList;
class GenListNode{
friend class GenList;
private:
    int utype;
    union {
        int ref;
        char charinfo;
        int intginfo;
        GenListNode *hlink;
    }value;
    GenListNode * tlink;
};


class GenList {
private:
    GenListNode *first;
    int NumberofNode(GenListNode *p);
    int MaxList(GenListNode *p);
    float AvgList(GenListNode *p);
public:
    GenList();
    ~GenList();
    void InitIntList(int size);
    void Show();
    int Max(void);
    int Len(void);
    float Avg(void);
};

GenList::GenList()
{
    first = new GenListNode;
    first->utype = 0;
    first->value.ref = 1;
    first->tlink = NULL;
}

GenList::~GenList()
{
    GenListNode *p;
    p = first;
    while (p!=NULL)
    {
        first = first->tlink;
        delete p;
        p = first;
    }
}

void GenList::InitIntList(int size)
{
    GenListNode *p;
    GenListNode *head;
    head = first;
    for (int i = 0;i<size; i++)
    {
        p = new GenListNode;
        p->utype = 2;
        /* p->value.intginfo = i; */
        p->value.intginfo = rand()%100;
        p->tlink = NULL;
        head->tlink = p;
        head = p;
    }

}
void GenList::Show(void)
{
    GenListNode *head;
    head = first->tlink;
    while(head!=NULL)
    {
        if (head->utype == 2)
        {
            cout<< head->value.intginfo<< " ";

        }
            head= head->tlink;
    }
}

/* int InitList(GenListNode *head) */
/* { */
/*     /1* GenListNode *p = new GenListNode(); *1/ */
/*     GenListNode *p; */
/*     p = head; */
/*     for (int i=0;i<MAXSIZE;i++) */
/*     { */
/*         p->tlink = new GenListNode(i); */
/*         p = p->tlink; */
/*     } */
/* } */

int GenList::MaxList(GenListNode *p)
{
    if (p->utype == 0) //head
    {
        p = p->tlink;
    }
    if (p->tlink ==NULL)    //last data
    {
        return p->value.intginfo;
    }
    else if (p->value.intginfo > MaxList(p->tlink))
        return p->value.intginfo;
    else
        return MaxList(p->tlink);
}
int GenList::Max(void)
{
    return MaxList(first);
}

int GenList::NumberofNode(GenListNode *p)
{
    if (p->utype ==0)
    {
        p=p->tlink;
    }
    if (p->tlink==NULL)
    {
        return 1;
    }
    else
    {
        return 1+NumberofNode(p->tlink);
    }
}
int GenList::Len(void)
{
    return NumberofNode(first);
}

float GenList::AvgList(GenListNode *p)
{
    if (p->utype == 0)
    {
        p=p->tlink;
    }

    if (p->tlink ==NULL)
    {
        return p->value.intginfo;
    }
    else
    {
        return (p->value.intginfo+AvgList(p->tlink)*NumberofNode(p->tlink))/(NumberofNode(p->tlink)+1);
    }
}

float GenList::Avg(void)
{
    return AvgList(first);
}
int main()
{
    int maxvalue;
    int lenvalue;
    float avgvalue;
    GenList L = GenList();
    L.InitIntList(6);
    L.Show();
    maxvalue = L.Max();
    cout<<endl<<"maxvalue is "<<maxvalue<<endl;

    lenvalue = L.Len();
    cout<<endl<<"lenvalue is "<<lenvalue<<endl;

    avgvalue = L.Avg();
    cout<<endl<<"avgvalue is "<<avgvalue<<endl;

}
