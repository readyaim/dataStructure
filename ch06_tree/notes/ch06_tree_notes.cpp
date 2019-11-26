#include <iostream>
/* #include <bits/stdc++.h> */
#include <stack>
#include <queue>
#include <time.h>
using namespace std;

template <class Type> class BinaryTree;
template <class Type> class BinTreeNode
{
friend class BinaryTree<Type>;
public:
    BinTreeNode();
    BinTreeNode(Type item, BinTreeNode <Type> *left=NULL, BinTreeNode <Type> *right=NULL):\
        data(item), leftChild(left), rightChild(right){}

    Type GetData() const {return data;}

    BinTreeNode <Type> *Getleft() const {return leftChild;}
    BinTreeNode <Type> *Getright() const {return rightChild;}
    
    void SetData(const Type &item) { data = item;  }
    void SetLeft(BinTreeNode <Type> *L) {leftChild = L;}
    void SetRight(BinTreeNode <Type> *R) {rightChild = R;}

private:
    Type data;
    BinTreeNode <Type> *leftChild, *rightChild;

};

template <class Type> class BinaryTree
{
public:
    BinaryTree(): root(NULL) {}
    BinaryTree(Type value):RefValue(value), root(NULL) {}
    BinaryTree(const BinaryTree <Type> &s);
    virtual ~BinaryTree() {destroy(root);}
    virtual int IsEmpty() {return root ==NULL? 1: 0;}
    virtual BinTreeNode <Type> * Parent(BinTreeNode <Type> *current)
    {
        return (root ==NULL || root ==current)? NULL: Parent(root, current);
    }
    virtual BinTreeNode <Type> *leftChild (BinTreeNode <Type> *current)
    {
        return (root!=NULL? current->leftChild: NULL);
    }
    virtual BinTreeNode <Type> *rightChild (BinTreeNode <Type> *current)
    {
        return (root!=NULL? current->rightChild: NULL);
    }
    virtual int Insert(const Type &item);
    virtual int Find(const Type &item) const;
    const BinTreeNode <Type> *GetRoot () const {return root;}

    template<class>
    friend istream &operator >> (istream &in, BinaryTree <Type> &Tree);
    template<class>
    friend ostream &operator << (ostream &out, BinaryTree <Type> &Tree);

    void InOrder(void);
    void PreOrder(void);
    void PostOrder(void);


private:
    BinTreeNode <Type> *root;
    Type RefValue;

    BinTreeNode <Type> *Parent(BinTreeNode <Type> *start, BinTreeNode <Type> *current);
    int Insert(BinTreeNode <Type> *&current, const Type &item);
    void Traverse (BinTreeNode <Type> *current, ostream &out) const;
    int Find (BinTreeNode <Type> *current, const Type &item) const;
    void destroy(BinTreeNode <Type> *current);

    void InOrder (BinTreeNode <Type> *current);
    void PreOrder (BinTreeNode <Type> *current);
    void PostOrder (BinTreeNode <Type> *current);
    BinTreeNode <Type> * Copy(BinTreeNode <Type> *originode);
    
};

template <class Type> void BinaryTree <Type> :: destroy(BinTreeNode <Type> *current)
{
    if (current !=NULL)
    {
        destroy(current->leftChild);
        destroy(current->rightChild);
        delete current;
    }
}

template <class Type> BinTreeNode <Type> * BinaryTree <Type> :: \
             Parent(BinTreeNode <Type> *start, BinTreeNode <Type> *current)
{
    if (start==NULL) return NULL;
    if (start->leftChild == current || start->rightChild ==current)
    {
        return start;
    }
    BinTreeNode <Type> *p;
    p = Parent(start->leftChild, current);
    if (p!=NULL) 
        return p;
    else
       return Parent(start->rightChild, current);
}

template <class Type> void BinaryTree <Type> :: Traverse (BinTreeNode <Type> *current, ostream &out) const
{
    BinTreeNode <Type> *p = current;
    while(p!=NULL)
    {
        cout<< current->data<< " ";
        Traverse(p->leftChild, out);
        Traverse(p->rightChild, out);

    }
}

template <class Type> istream &operator >> (istream &in, BinaryTree <Type> &Tree)
{
    Type item;
    cout << "Construct binary tree :\n";
    cout << "Input data (end with" << Tree.RefValue <<"):";
    in >> item;
    while (item!=Tree.RefValue)
    {
        Tree.Insert(item);
        cout << "Input data (end with" << Tree.RefValue << "):";
        in >> item;
    }

    return in;
}

template <class Type> ostream &operator >> (ostream &out, BinaryTree <Type> &Tree)
{
    out << "Preorder traversal of binary tree. \n";
    Tree.Traverse(Tree.root, out);
    out << endl;
    return out;
}

template <class Type> void BinaryTree <Type>::InOrder(void)
{
    InOrder(root);
}


template <class Type> void BinaryTree <Type>::InOrder(BinTreeNode <Type> *current)
{
    if (current != NULL)
    {
        InOrder(current->leftChild);
        cout << current->data;
        InOrder(current->rightChild);
    }
}
template <class Type> void BinaryTree <Type>::PreOrder(BinTreeNode <Type> *current)
{
    if (current != NULL)
    {
        cout << current->data;
        PreOrder(current->leftChild);
        PreOrder(current->rightChild);
    }
}
template <class Type> void BinaryTree <Type>::PostOrder(BinTreeNode <Type> *current)
{
    if (current != NULL)
    {
        PostOrder(current->leftChild);
        PostOrder(current->rightChild);
        cout << current->data;
    }
}


template <class Type> BinaryTree <Type>::BinaryTree (const BinaryTree <Type> &s)
{
    root = Copy(s.root);
}


template <class Type> BinTreeNode <Type> * BinaryTree <Type>::Copy(BinTreeNode <Type> *originode)
{
    if (originode == NULL) return NULL;
    BinTreeNode <Type> *temp = new BinTreeNode <Type>();
    temp->data = originode->data;
    temp->leftChild = Copy(originode->leftChild);
    temp->rightChild = Copy (originode->rightChild);
    return temp;
}


template <class Type> int operator == (const BinaryTree <Type> &s, const BinaryTree <Type> &t)
{
    return Equal(s.root, t.root);
}


template <class Type> int Equal (const BinTreeNode <Type> *p, const BinTreeNode <Type> *q)
{
    if (p==NULL && q==NULL) return 1;
    if (p!=NULL & q!=NULL && \
        p->data==q->data && \
        Equal(q->leftChild, q->leftChild) && \
        Equal(p->rightChild, q->rightChild))
        return 1;
    return 0;
}

template <class Type> class TreeIterator
{
public:
    TreeIterator(const BinaryTree <Type> &BT):T(BT), current(NULL) {}
    virtual ~TreeIterator();
    virtual void First() = 0;
    virtual void operator ++() = 0;
protected:
    BinaryTree<Type> &T;
    BinTreeNode <Type> *current;
private:
    TreeIterator(const TreeIterator &) {}
    TreeIterator &operator = (const TreeIterator &) const;
};

template <class Type> class TreeStackType
{
public:
    TreeStackType(BinTreeNode <Type> *p=NULL, int tim =0):mNode(p), mTim(tim) {  }
    ~TreeStackType();
    const BinTreeNode<Type> *mNode;
    int mTim;
};

template <class Type> class PostOrder:public TreeIterator<Type>
{
public:
    PostOrder(const BinaryTree <Type> &BT);
    ~PostOrder();
    virtual void First();
    virtual void operator ++();
protected:
    stack <TreeStackType <Type>> st;

};

template <class Type> PostOrder <Type>::PostOrder (const BinaryTree <Type> &BT):TreeIterator<Type> (BT)
{
    TreeStackType <Type> GNode;
    GNode.mNode = this->T.GetRoot();
    st.Push(GNode);
}

template <class Type>
void PostOrder <Type>::First(void)
{
    st.MakeEmpty(); 
    if (this->T.GetRoot()!=NULL)
    {
        st.Push(TreeStackType <Type> (this->T.GetRoot()));
        operator ++();
    }
}

template <class Type>
void PostOrder<Type>::operator++(void)
{
    if (st.IsEmpty())
    {
        if (this->current!=NULL)
        {
            this->current = NULL;
            return;
        }
        else
        {
            cerr << "Advanced past end"<<endl;
            exit(1);
        }
    }

    TreeStackType <Type> tNode;
    while(1)
    {
        tNode = st.pop();

        if (++tNode.mTim ==3)
        {
            this->current = tNode.mNode;
            return;
        }

        st.push(tNode); //push back

        if (tNode.mTim ==2)
        {
            if (tNode.mNode->Getleft()!=NULL) st.push(TreeStackType<Type>(tNode.mNode->Getleft()));

        }

        if (tNode.mTim ==1)
        {
            if (tNode.mNode->Getright()!=NULL) st.push(TreeStackType<Type>(tNode.mNode->Getright()));
        }

    }
}

template <class Type> class InOrder:public PostOrder<Type>
{
public:
    InOrder(const BinaryTree <Type> &BT);
    ~InOrder();
    virtual void First();
    virtual void operator ++();
protected:
    stack <TreeStackType <Type>> st;

};

template <class Type> InOrder <Type>::InOrder (const BinaryTree <Type> &BT):PostOrder<Type> (BT)
{
    st.Push(TreeStackType <Type>(this->T.GetRoot()));
}

template <class Type>
void InOrder<Type>::operator++(void)
{
    if (st.IsEmpty())
    {
        if (this->current!=NULL)
        {
            this->current = NULL;
            return;
        }
        else
        {
            cerr << "Advanced past end"<<endl;
            exit(1);
        }
    }

    TreeStackType <Type> tNode;
    while(1)
    {
        tNode = st.pop();

        if (++tNode.mTim ==2)
        {
            this->current = tNode.mNode;
            if (tNode.mNode->Getright()!=NULL) st.push(TreeStackType<Type>(tNode.mNode->Getright()));
            return;
        }
        st.push(tNode);
        if (tNode.mNode->Getleft()!=NULL) st.push(TreeStackType<Type>(tNode.mNode->Getleft()));
    }
}
template <class Type> class PreOrder:public TreeIterator<Type>
{
public:
    PreOrder(const BinaryTree <Type> &BT);
    ~PreOrder();
    virtual void First();
    virtual void operator ++();
protected:
    stack <TreeStackType <Type>> st;

};


template <class Type> PreOrder <Type>::PreOrder (const BinaryTree <Type> &BT):TreeIterator<Type> (BT)
{
    TreeStackType <Type> GNode;
    GNode.mNode = this->T.GetRoot();
    st.Push(GNode);
}

template <class Type>
void PreOrder <Type>::First(void)
{
    st.MakeEmpty(); 
    if (this->T.GetRoot()!=NULL)
    {
        st.Push(TreeStackType <Type> (this->T.GetRoot()));
        operator ++();
    }
}

template <class Type>
void PreOrder<Type>::operator++(void)
{
    if (st.IsEmpty())
    {
        if (this->current!=NULL)
        {
            this->current = NULL;
            return;
        }
        else
        {
            cerr << "Advanced past end"<<endl;
            exit(1);
        }
    }

    TreeStackType <Type> tNode;
    while(1)
    {
        tNode = st.pop();

        this->current = tNode.mNode;
        if (tNode.mNode->Getright()!=NULL) st.push(TreeStackType<Type>(tNode.mNode->Getright()));
        if (tNode.mNode->Getleft()!=NULL) st.push(TreeStackType<Type>(tNode.mNode->Getleft()));
        return;
    }
}

template <class Type> class LayerOrder:public TreeIterator<Type>
{
public:
    LayerOrder(const BinaryTree <Type> &BT);
    ~LayerOrder();
    virtual void First();
    virtual void operator ++();
protected:
    queue <TreeStackType <Type>> qu;

};


template <class Type> LayerOrder <Type>::LayerOrder (const BinaryTree <Type> &BT):TreeIterator<Type> (BT)
{
    TreeStackType <Type> GNode;
    GNode.mNode = this->T.GetRoot();
    qu.EnQueue(GNode);
}

template <class Type>
void LayerOrder <Type>::First(void)
{
    qu.MakeEmpty(); 
    if (this->T.GetRoot()!=NULL)
    {
        qu.EnQueue(TreeStackType <Type> (this->T.GetRoot()));
        operator ++();
    }
}

template <class Type>
void LayerOrder<Type>::operator++(void)
{
    if (qu.IsEmpty())
    {
        if (this->current!=NULL)
        {
            this->current = NULL;
            return;
        }
        else
        {
            cerr << "Advanced past end"<<endl;
            exit(1);
        }
    }

    TreeStackType <Type> tNode;
    while(1)
    {
        tNode = qu.DeQueue();

        this->current = tNode.mNode;
        if (tNode.mNode->Getright()!=NULL) qu.EnQueue(TreeStackType<Type>(tNode.mNode->Getright()));
        if (tNode.mNode->Getleft()!=NULL) qu.EnQueue(TreeStackType<Type>(tNode.mNode->Getleft()));
        return;
    }
}

template <class Type>  class ThreadTree;
template <class Type> class ThreadInorderIterator;

template <class Type> class ThreadNode
{

friend class ThreadTree<Type>;
friend class ThreadInorderIterator<Type>;
private:
    int leftThread, rightThread;
    ThreadNode <Type> *leftChild, *rightChild;
    Type data;
public:
    ThreadNode(const Type item):data(item), leftChild(NULL), rightChild(NULL), \
                                leftThread(0), rightThread(0) {  }
};

template <class Type>  
class ThreadTree
{
public:
friend class ThreadInorderIterator<Type>;
    void InThread(ThreadNode<Type> *current, ThreadNode<Type> *pre);    
    void CreateInThread(void);
    void InsertRight(ThreadNode<Type> *s, ThreadNode<Type> *r);
private:
    ThreadNode <Type> *root;

};

template <class Type> 
class ThreadInorderIterator
{
public:
    ThreadInorderIterator (ThreadTree <Type> &Tree):T(Tree) {current = T.root;}
    ThreadNode <Type> *First();
    ThreadNode <Type> *Last();
    ThreadNode <Type> *Next();
    ThreadNode <Type> *Prior();
    void Inorder(void);
private:
    ThreadTree <Type> T;
    ThreadNode <Type> current;
};

template <class Type> 
ThreadNode <Type> *ThreadInorderIterator<Type> :: First()
{
    /* Attention: current->leftChild is never NULL */
    while(current->leftThread==0) current = current->leftChild;
    return current;
}

template <class Type>
ThreadNode <Type> *ThreadInorderIterator<Type> :: Next()
{
    if (current.rightThread ==1) 
    {
        current = current.rightChild;
        return current;
    }
    else if (current.rightThread==0)
    {
        /* current = First(current.rightChild); */
        ThreadNode <Type> *p = current.rightChild;
        while (p->leftThread ==0)
        {
            p = p->leftChild;
        }
        current = p;
        if (current == T.root) return NULL;
        else return current;
    }
}


template <class Type>
void ThreadInorderIterator<Type>::Inorder()
{
    ThreadNode <Type> *p;
    for (p = First(); p!=NULL; p=Next())
    {
        cout<<p->data<<endl;
    }
}

template <class Type>
void ThreadTree<Type>:: InThread(ThreadNode<Type> *current, ThreadNode<Type> *pre)
{
    if (current!=NULL)
    {
        InThread(current->leftChild, pre);
        if (current->leftChild==NULL)
        {
            current->leftChild = pre; current->leftThread = 1;
        }
        if (pre->rightChild == NULL)
        {
            pre->rightChild = current; pre->rightThread = 1;
        }
        pre = current;
        InThread(current->rightChild, pre);
    }
}

template <class Type>
void ThreadTree<Type>::CreateInThread(void)
{
    ThreadNode<Type> *pre;
    root = new ThreadNode<Type>;
    root->leftThread = 0;
    root->rightThread =1;
    if (this==NULL) {root->leftChild = root;root->rightChild = root;}
    else
    {
        this->current =root->leftChild = this;
        root->leftThread = 0;
        pre = root;
        InThread(this->current, pre);
        pre->rightChild = root;
        pre->rightThread = 1;
    }
}

template <class Type>
void ThreadTree <Type> ::InsertRight(ThreadNode<Type> *s, ThreadNode<Type> *r)
{       
    r->leftChild = s;
    r->leftThread = 1;
    s->rightThread = 0;
    s->rightChild = r;

    r->rightChild = s->rightChild;

        r->rightThread = s->rightThread;
    if (s->rightThread == 0)
    {
        ThreadNode<Type> *temp;
        temp = s->rightChild;
        while (temp->leftThread==0)
        {
            temp=temp->leftChild;
        }
        temp->leftChild = r;
    }
}

/*
 * Heap
 */

template <class Type>
class MinPQ
{
public:
    virtual int Insert (const Type &)=0;
    virtual int RemoveMin (Type &) = 0;
};


template <class Type>
class MinHeap: public MinPQ<Type>
{
public:
    MinHeap(int maxsize);
    MinHeap(Type arr[], int n);
    ~MinHeap() {delete [] heap;}
    const MinHeap <Type> &operator = (const MinHeap &R);
    int Insert(const Type &x);
    int RemoveMin(Type &x);
    int IsEmpty() const {return CurrentSize ==0;}
    int Full() const {return CurrentSize == MaxHeapSize;}
    void MakeEmpty() {CurrentSize=0;}
private:
    int CurrentSize;
    int MaxHeapSize;
    Type *heap;
    enum {DefaultSize=10};
    void FilterDown (int i, int m);
    void FilterUp(int i);
};



template <class Type>
MinHeap <Type> :: MinHeap(int maxsize)
{
    MaxHeapSize = maxsize > DefaultSize? maxsize:DefaultSize;
    heap = new Type[MaxHeapSize];
    CurrentSize = 0;
}


template <class Type>
MinHeap<Type> ::MinHeap(Type arr[], int n)
{
    MaxHeapSize = DefaultSize < n ? n:DefaultSize;
    heap = new Type [MaxHeapSize];
    heap = arr;
    CurrentSize = n;
    int currentPos = (CurrentSize - 2)/2;
    while(currentPos>=0)
    {
        FilterDown(currentPos, CurrentSize);
        currentPos--;
    }
}


template <class Type>
void MinHeap<Type> :: FilterDown(const int start, const int endofheap)
{
    int i =start;
    int j = 2*i+1;
    Type temp = heap[i];

    while (j<=endofheap)
    {
        if (j<endofheap && heap[j].key>heap[j+1].key) j++;
        if (temp.key<heap[j].key)
        {
            break;
        }
        else
        {
            heap[i]=heap[j];
            i=j;
            j=2*i+1;
        }
    }
    heap[i]=temp;
}

template <class Type>
void MinHeap<Type> :: FilterUp(const int start)
{
    int j = start;
    int i = (j-1)/2;
    Type temp = heap[j];
    while(i>=0)
    {
        if (temp.key>=heap[i].key) break;
        else
        {
            heap[j] = temp;
            j = i;
            i = (j-1)/2;
        }
    }
    heap[j] = temp;
}

template <class Type>
int MinHeap<Type> ::RemoveMin(Type &x)
{
    if (!CurrentSize) {cout << "Heap Empty"<<endl; return 0;}
    x = heap[0];
    heap[0]= heap[CurrentSize-1];
    CurrentSize--;
    FilterDown(0, CurrentSize-1);
    return 1;
}
/*
 *Tree
 *
 */

template <class Type> class Tree;

template <class Type>
class TreeNode
{
friend class Tree <Type>;
private:
    Type data;
    TreeNode<Type> *firstChild;
    TreeNode<Type> *nextSibling;
    TreeNode(Type value=0, TreeNode <Type> *fc = NULL, TreeNode <Type> *ns = NULL):\
        data(value), firstChild(fc), nextSibling(ns) {}
};



template <class Type> 
class Tree
{
public:
    Tree() {root = current = NULL;}
    void BuildRoot(Type rootVal);
    int Root(void);
    int FirstChild(void);
    int NextSibling(void);
    int Parent(void);
private:
    TreeNode <Type> * root, *current;
    void PreOrder (ostream &out, TreeNode <Type> *p);
    int Find (TreeNode <Type> *p, Type target );
    void RemovesubTree(TreeNode <Type> *p);
    int FindParent(TreeNode <Type> *t, TreeNode <Type> *p);

};

template <class Type>
void Tree <Type> :: BuildRoot(Type rootVal)
{
    root = current = new TreeNode<Type>(rootVal);
}
template <class Type>
int Tree<Type>::Root(void)
{
    if (root ==NULL) 
    {
        current = NULL; 
        return 0;
    }
    else
    {
        current = root; 
        return 1;
    }
}

template <class Type>
int Tree<Type> :: FirstChild()
{
    if (current!=NULL && current->firstChild!=NULL)
    {
        current = current->firstChild;
        return 1;
    }
    else
    {
        current = NULL;
        return 0;
    }
}

template <class Type>
int Tree<Type> ::NextSibling(void)
{
    if (current!=NULL && current->nextSibling!=NULL)
    {
        current = current->nextSibling;
        return 1;
    }
    current = NULL;
    return 0;
}

template <class Type>
int Tree<Type> ::Parent(void)
{
    TreeNode <Type> *t, *p=current;
    if (current!=NULL && current!= root)
    {
        t=root;
        int k = FindParent(t, p);
        return k;
    }
    else
    {
        current = NULL;
        return 0;
    }
}

template <class Type>
int Tree <Type> :: FindParent(TreeNode<Type> *t, TreeNode<Type> *p)
{
    if (t!=NULL && t->firstChild==p)
    {
        current =t;
        return 1;
    }
    else
    {
        t=t->firstChild;
        TreeNode <Type> *q=t->nextSibling;
        while (q!=NULL & !FindParent(q, p))
        {
            q = q->nextSibling;
        }
        current = NULL;
        return 0;
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
