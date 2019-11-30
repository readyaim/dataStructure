#include <iostream>
/* #include <bits/stdc++.h> */
/* #include <stack> */
#include <queue>
#include <time.h>
using namespace std;
#define MAX_QUEUE_SIZE 100

template <class Type>
class ArrTreeNode
{
public:
    Type data;
    int fcTag; 
    int nsTag;  

    ArrTreeNode():fcTag(0), nsTag(0) {}
    ~ArrTreeNode() {}
};

template <class Type>
class ArrTree
{
public:
    ArrTree(): arraySize(0) {}
    ~ArrTree() {}
    enum {MAXSIZE = 100};
private:
    ArrTreeNode <Type> a[MAXSIZE];
    int arraySize;
};

template <class Type> class LinkedTree;

template <class Type>
class LinkTreeNode
{
    friend class LinkedTree <Type>;
public:
    LinkTreeNode():firstchild(NULL), nextsibling(NULL) {}
    LinkTreeNode(Type item):data(item), firstchild(NULL), nextsibling(NULL) {}
    ~LinkTreeNode () {}
private:
    LinkTreeNode <Type> *firstchild, *nextsibling;
    Type data;
};

template <class Type>
class LinkedTree
{
public:
    LinkedTree(): first(NULL) {}
    LinkTreeNode <Type> * Transfer2LinkedTree(ArrTreeNode<Type> a[], int idx, int maxsize);
    void Transfer(const ArrTree<Type> & aTree);
    ~LinkedTree() {}
private:
    LinkTreeNode <Type> *first;
};

template <class Type>
void LinkedTree<Type>::Transfer(const ArrTree<Type> &aTree)
{
    first = Transfer2LinkedTree(aTree.a, 0, aTree.arraySize);
}

template <class Type>
LinkTreeNode <Type> * LinkedTree<Type>:: Transfer2LinkedTree(ArrTreeNode<Type> a[], int idx, int maxsize)
{
    LinkTreeNode <Type> *p = new LinkTreeNode<Type>(a[idx].data);
    if (idx>maxsize-1) //0..n-1
    {
        exit(1);
    }
    if (a[idx].fcTag!=0)
    {
        p->firstchild = Transfer2LinkedTree(a, a[a[idx].fcTag], maxsize);
    }
    if (a[idx].nsTag!=0)
    {
        p->nextsibling = Transfer2LinkedTree(a, a[a[idx].nsTag], maxsize);
    }
    return p;

}


int main()
{
    clock_t start, finish;
    double duration;
    start = clock();

    ArrTreeNode <int> sTree[100];

    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;

    cout<< "running time is: "<<duration<< " sec"<<endl;
    return 0;

}
