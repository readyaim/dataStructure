#include <iostream>
#include <time.h>
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
    int MaxList(void);
    int MaxList(GenListNode *p);
    float AvgList(GenListNode *p);
    int NumberofNode(void);
    float AvgList(void);
public:
    GenList();
    ~GenList();
    void InitIntList(int size);
    void Show();
    int Max(void);
    int Len(void);
    float Avg(void);
};


int GenList::NumberofNode(void)
{
    int num=0;
    GenListNode *p;
    p=first;
    while(p->utype!=2)
    {
        p=p->tlink;
    }
    
    while(p->tlink!=NULL)
    {
        num++;
        p=p->tlink;
    }
    return num;
}
int GenList::MaxList(void)
{
    int maxvalue;
    GenListNode *p;
    p=first->tlink;
    if (p!=NULL)
    {
        maxvalue = p->value.intginfo;
        p=p->tlink;
    }
    while(p!=NULL)
    {
        if (maxvalue<p->value.intginfo)
        {
            maxvalue = p->value.intginfo;
        }
            p = p->tlink;
    }
    return maxvalue;
}
float GenList::AvgList(void)
{
    int sumvalue=0;
    int num=0;
    GenListNode *p;
    p = first->tlink;
    while(p!=NULL)
    {
        sumvalue += p->value.intginfo;
        num++;
        p=p->tlink;
    }
    return (float)sumvalue/num;
}
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
    srand((unsigned)time(NULL));  //seed of rand(), need time.h
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
    /* return MaxList(first); */  //last very long time
    return MaxList();
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
    /* return NumberofNode(); */
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
    /* return AvgList(); */
}
int main()
{
    int maxvalue;
    int lenvalue;
    float avgvalue;
    int size;
    GenList L = GenList();
    cout<<"Input the size(int):";
    cin>>size;
    L.InitIntList(size);
    L.Show();
    maxvalue = L.Max();
    cout<<endl<<"maxvalue is "<<maxvalue<<endl;

lenvalue = L.Len();
   cout<<endl<<"lenvalue is "<<lenvalue<<endl;

    avgvalue = L.Avg();
    cout<<endl<<"avgvalue is "<<avgvalue<<endl;

}
