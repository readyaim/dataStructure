#include <iostream>
/* #include <bits/stdc++.h> */
/* #include <stack> */
#include <queue>
#include <time.h>
using namespace std;
#define MAX_QUEUE_SIZE 100

template <class Type> class BinTreeNode;
template <class Type> class BinaryTree;

template <class Type>
class BinTreeNode
{
    friend class BinaryTree <Type>;
public:
    BinTreeNode():leftchild(NULL), rightchild(NULL) {}
    ~BinTreeNode();
private:
    BinTreeNode <Type> *leftchild;
    BinTreeNode <Type> *rightchild;
    Type data;
};

template <class Type>
class BinaryTree
{
public:
    BinaryTree():first(NULL) {}
    BinaryTree(Type arr[], int n) { first = Array2BinTree(arr, n); }
    ~BinaryTree() {}
    void ShowTree(void);
    void DoubleOrderTravl(BinTreeNode<Type> *p);
private:
    int LeafSize(BinTreeNode <Type> *p);
    BinTreeNode <Type> * Array2BinTree(Type arr[], int n);
    int SwitchChild(BinTreeNode <Type> *p);
    BinTreeNode <Type> *first;
    void ShowTree(BinTreeNode<Type> *p);
};
/* Question 06-18 */
template <class Type>
void BinaryTree<Type>::DoubleOrderTravl(BinTreeNode<Type> *p)
{
    if (p!=NULL)
    {
        cout<<p->data<<endl;
        DoubleOrderTravl(p->leftchild);
        cout<<p->data<<endl;
        DoubleOrderTravl(p->rightchild);
    }
}
/* Question 06-18 end */
template <class Type>
int BinaryTree <Type>:: LeafSize( BinTreeNode <Type> *p )
{
    if (p==NULL) return 0;
    if (p->leftchild == NULL && p->rightchild == NULL) return 1;
    else 
        return LeafSize(p->leftchild)+LeafSize(p->rightchild);
}

template <class Type>
int BinaryTree <Type>::SwitchChild(BinTreeNode <Type> *p)
{
    BinTreeNode <Type> *temp;
    if (p!=NULL)
    {
        SwitchChild(p->leftchild);
        SwitchChild(p->rightchild);
        temp = p->leftchild;
        p->leftchild = p->rightchild;
        p->rightchild = temp;
    }
}

/* Question 12 */
template <class Type>
BinTreeNode <Type> * BinaryTree <Type>::Array2BinTree(Type arr[], int n)
{
    int idx=1;
    int flag;
    queue <BinTreeNode <Type>*> qu;    //(MAX_QUEUE_SIZE);
    BinTreeNode <Type> *head;
    BinTreeNode <Type> *parent;
    if (n<=0 || n>MAX_QUEUE_SIZE) return NULL;
    BinTreeNode<Type> *p = new BinTreeNode<Type>;
    head = p;
    p->data = arr[0];
    qu.push(p);

    while(idx<n)
    {   
        parent = qu.front();    //front() return the first data of queue
        qu.pop();   //pop() return void
        flag = 0;
        while(flag<2 && idx<n)
        {
            BinTreeNode<Type> *p = new BinTreeNode<Type>;
            p->data = arr[idx];
            if (idx%2==1)
            {
                parent->leftchild = p;
            }
            else
            {
                parent->rightchild = p;
            }
            flag++;
            idx++;
            qu.push(p);
            
        }
    }
    return head;
}

template <class Type>
void BinaryTree<Type> :: ShowTree()
{
    ShowTree(first);
}
template <class Type>
void BinaryTree<Type> :: ShowTree(BinTreeNode<Type> *p)
{
    queue <BinTreeNode<Type> *> qu;
    BinTreeNode <Type> *temp;
    if (p==NULL)
        return;
    else
    {
        qu.push(p);
    }
    while (!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        cout<<temp->data<<endl;
        if (temp->leftchild!=NULL)
            qu.push(temp->leftchild);
        if (temp->rightchild!=NULL)
            qu.push(temp->rightchild);
    }
}

int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    
    int a[10] = {0};
    for (int i=0;i<10;i++)
    {
        a[i] = i;
    }
    
    BinaryTree <int> tree(a, 10);
    tree.ShowTree();


    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;

    cout<< "running time is: "<<duration<< " sec"<<endl;
    return 0;

}
