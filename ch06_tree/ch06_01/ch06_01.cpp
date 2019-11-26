#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <time.h>
using namespace std;

enum UTYPE_T
{
    HEAD = 0,
    LIST = 1,
    INTG = 2,
    CHAR = 3
};
/* genreal list for tree */
template <class Type> class GenListNode;
template <class Type> class GenListTree;

template <class Type>
class GenListNode
{

    friend class GenListTree <Type>;
public:
    GenListNode():utype(0),tlink(NULL){};
    int GetUtype() const {return utype;}
    void SetUtype(int value) {utype = value;}
    void SetValueData(Type d) { value.data = d; }
    int GetValueData() const {return value.data;}
/* private: */
    int utype;
    union
    {
        int ref;
        Type data;
        GenListNode <Type> *hlink;
    }value;   
    
    
    GenListNode <Type> *tlink;
};

template <class Type>
class GenListTree
{
    template <class>
    friend ostream &operator <<(ostream &out, const GenListTree <Type> &T);
    template <class>
    friend istream &operator >>(istream &in, const GenListTree <Type> &T);
    template <class>
    friend int &operator == (const GenListTree <Type> &s, const GenListTree <Type> &t);
public:
    GenListTree():first(NULL), last(NULL), RefValue(-1) {};
    GenListTree(const GenListTree <Type> &T);
    ~GenListTree() {DestroyTree(first);first = NULL;}
    void operator ==(const GenListTree <Type> &T);
    void InsertNode(GenListNode <Type> *p);
    void InsertNode(GenListNode<Type>**pre,  GenListNode <Type> *p);
    int RefValue;
    void ShowTree();    // {ShowTree(first);}
   
void InputTree() { InputTree(&first); }
private:
    GenListNode <Type> *first;
    GenListNode <Type> *last;
    GenListNode <Type> *Copy(GenListNode <Type> *p);
    /* int Equal(const GenListTree <Type> &s, const GenListTree <Type> &t); */
    void DestroyTree(GenListNode <Type> *p);
    void InputTree(GenListNode<Type> **p);
    void ShowTree(GenListNode <Type> *p);
};
template <class Type>
void GenListTree <Type>:: ShowTree(GenListNode <Type> *p)    //GenListNode <Type> *p)
{
    while (p!=NULL)
    {
        /* cout << p->GetValueData()<<endl; */
        if (p->utype!=1)
        {
            cout << p->utype << " " << p->value.data <<  endl;
        }
        else
        {
            ShowTree(p->value.hlink);
            
        }
        p=p->tlink;
    }

}
template <class Type>
void GenListTree <Type> :: ShowTree(void)
{
    ShowTree(first);
}



template <class Type>
void GenListTree <Type>::DestroyTree(GenListNode <Type> *p)
{
    GenListNode <Type> *next;
    while (p!=NULL)
    {
        if (p->utype==1)
        {
            DestroyTree(p->value.hlink);
        }
        next = p->tlink;
        delete p;
        p = next;
    }
}

template <class Type>
void GenListTree<Type> :: InsertNode(GenListNode<Type> *p)
{
    if (first==NULL)
    {
        first = p;
    }
    else if (first->tlink == NULL)
    {
        first->tlink = p;
    }
    else
    {
        p->tlink = first->tlink;
        first->tlink = p;
    }
}
template <class Type>
void GenListTree<Type> :: InsertNode(GenListNode<Type> **head, GenListNode<Type> *p)
{
    if (*head==NULL)
    {
       *head = p;
    }
    else if ((*head)->tlink == NULL)
    {
        (*head)->tlink = p;
    }
    else
    {
        p->tlink = (*head)->tlink;
        (*head)->tlink = p;
    }
}


template <class Type>
GenListNode <Type> * GenListTree <Type>::Copy(GenListNode <Type> *p)
{
    if (p==NULL) return NULL;
    GenListNode <Type> *temp = new GenListNode<Type>;
    temp->utype = p->utype;
    switch (p->utype)
    {
    case 1: temp->value.hlink = Copy(p->value.hlink); break;
    case 2: temp->value.data = p->value.data;break;
    default:break;
    }
    temp->tlink = Copy(p->tlink);
    return temp;
}

template <class Type>
int Equal(const GenListNode <Type> *p, const GenListNode <Type> *q)
{
    if (p==NULL && q == NULL) return 1;
    if (p->utype == q->utype)
    {
        if ((p->utype == 1) && \
            Equal(p->value.hlink, q->value.hlink) && \
            Equal (p->tlink, q->tlink))
        {
            return 1;
        }
        else if ((p->value.data == q->value.data) && \
                 Equal (p->tlink, q->tlink))
        {
            return 1;
        }
    }
    return 0;
}

template <class Type>
GenListTree<Type> ::GenListTree (const GenListTree <Type> &T)
{
    first= Copy (T.first);
}
template <class Type>
istream & operator >> (istream &in, GenListTree <Type> &T )
{
    T.InputTree();
}
template <class Type>
void GenListTree<Type>::InputTree(GenListNode <Type> **head)
{
    Type item;
    int utype=1;    //utype init value MUST be 1, for preUtype
    int preUtype=LIST;
    cout << "Construct General List Tree:\n";
    
    GenListNode <Type> **preHead = head;
    while (1)
    {
        cout<< "Input the utype (HEAD=0,LIST=1,INT=2,CHAR=3), end=-1: ";
        cin >> utype;
        if (cin.fail())
        {
            cout<< "Wrong input!"<<endl;
            /* clean the cin flag */
            cin.clear();
            /* clean the input queue of cin */
            while (cin.get()!='\n')
            {
                continue;
            }
            /**/
            continue;
        }
        if (utype == RefValue) break;  //end of input
        if (utype != HEAD && *preHead == NULL) 
        {
            cout << "Error! Must input HEAD(0) at beginning of the List"<<endl;
            continue;
        }
        if (utype == HEAD && preUtype != LIST)
        {
            cout << "Error, Head(0) is allowed only after LIST(1)"<<endl;
            continue;
        }
        GenListNode <Type> *p = new GenListNode<Type>;
        p->SetUtype(utype);
        switch (utype)
        {
        case HEAD:
            cout<< "Add HEAD to List! "<<endl;;
            p->value.ref = 0;
            InsertNode(preHead, p);
            break;
        case LIST:
            cout << "Input LIST. "<<endl;;
            p->value.hlink = NULL;
            InsertNode(preHead, p);
            InputTree(&p->value.hlink);
            break;
        case INTG:
            cout<< "Input the value.data with INTG: ";
            cin >> item;
            p->SetValueData(item);
            InsertNode(preHead, p);
            break;
        case CHAR:
            break;
        default: break;
        }
        /* save previous utype, utype can not be 0, unless preUtype is 1 */
        preUtype = utype;
        

    }//while
}


template <class Type>
ostream & operator << (ostream &out, GenListTree <Type> &T )
{
    cout<< "Display Tree:"<<endl;
    T.ShowTree();
}

template <class Type>
int operator ==(const GenListTree <Type> &s, const GenListTree <Type> &t)
{
    return Equal(s.first, t.first);
}

int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    GenListTree <int> Tree;
    cin >> Tree;
    cout << Tree;
    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;

    cout<< "running time is: "<<duration<< " sec"<<endl;
    return 0;

}
