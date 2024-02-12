#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    node *next;
    int item;
};
class DLL
{
private:
    node *start;

public:
    DLL();
    DLL(DLL &);
    DLL operator=(DLL &);
    void insertatstart(int);
    void insertatend(int);
    node *search(int);
    void insertafter(node *, int);
    void deletefirst();
    void deletelast();
    void del(node *);
    ~DLL();
};
DLL::DLL()
{
    start = NULL;
}
DLL::DLL(DLL &d)
{
    node *t;
    if (d.start != NULL)
    {
        t = d.start;
        while (t->next != NULL)
            t = t->next;
        while (t)
        {
            insertatstart(t->item);
            t = t->next;
        }
    }
    else
    {
        start=NULL;

    }
}
DLL& DLL:: operator=(DLL &d)
{
    while(start==NULL)
        deletefirst(); 
  node *t;
    if (d.start != NULL)
    {
        t = d.start;
        while (t->next != NULL) 
            t = t->next;
        while (t)
        {
            insertatstart(t->item);
            t = t->next;
        }
    }
    else
    {
        start=NULL;

    }  
    return *this; 
}
void DLL ::insertatstart(int data)
{
    node *n;
    n = new node;
    n->prev = NULL;
    n->item = data;
    n->next = start;
    if (start != NULL)
        start->prev = n;
    start = n;
}
void DLL ::insertatend(int data)
{
    node *n;
    node *t;
    n = new node;
    n->item = data;
    n->next = NULL;
    if (start == NULL)
    {
        n->prev = NULL;
        start = n;
    }
    else
    {
        t = start;
        while (t->next != NULL)
            t = t->next;
        n->prev = t;
        t->next = n;
    }
}
node *DLL::search(int data)
{
    node *t;
    t = start;
    while (t)
    {
        if (t->item == data)
            return t;
        else
            t = t->next;
    }
    return NULL;
}
void DLL::insertafter(node *t, int data)
{
    node *n;
    n = new node;
    n->prev = t;
    n->item = data;
    n->next = t->next;
    if (t->next != NULL)
        t->next->prev = n;
    t->next = n;
}
void DLL::deletefirst()
{
    node *r;
    if (start != NULL)
    {
        r = start;
        start = r->next;
        start->prev = NULL;
        delete r;
    }
}
void DLL::deletelast()
{
    node *t;
    t = start;
    if (start == NULL)
    {
        cout << "list underflow";
    }
    else
    {
        if (start->next == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            t = start;
            while (t->next != NULL)
                t = t->next;
            t->prev->next = NULL;
            delete t;
        }
    }
}
void DLL::del(node *t)
{
    if (start == NULL)
        cout << "underflow";
    else if (start == t)
        deletefirst();
    else if (t->next == NULL)
        deletelast();
    else
    {
        t->next->prev = t->prev;
        t->prev->next = t->next;
        delete t;
    }
}
DLL::~DLL()
{
    while (start == NULL)
        deletefirst();
}