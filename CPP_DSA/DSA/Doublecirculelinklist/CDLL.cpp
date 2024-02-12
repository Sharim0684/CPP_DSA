#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL{
    private:
       node *start;
    public:
        CDLL();
        CDLL(CDLL &);
        ~CDLL();
        CDLL & operator=(CDLL &);
        void insertatstart(int);
        void insertatlast(int );
        node *search(int);
        void insertafter(node* ,int);
        void deletefirst();
        void deletelast();
        void del(node *);
};
CDLL::CDLL()
{
    start == NULL;
}
CDLL :: CDLL(CDLL &d)
{
    node *t;
    if(d.start==NULL)
        start=NULL;
    else
    {
        t=d.start;
        do{
            insertatlast(t->item);
            t=t->next;
        }while(t!=d.start);
    }
}
CDLL& CDLL::operator=(CDLL &d)
{
    while(start)
        deletefirst();
    
    node *t;
    if(d.start==NULL)
        start=NULL;
    else
    {
        t=d.start;
        do{
            insertatlast(t->item);
            t=t->next;
        }while(t!=d.start);
    }
    return *this;  
}
CDLL::~CDLL()
{
    while(start)
        deletefirst();   
}
void CDLL::insertatstart(int data)

{
    node *n;
    n = new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;  
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void CDLL::insertatlast(int data)
{
    node *n;
    n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->prev=n;
        start->prev=n;

    }
}
node* CDLL :: search(int data)
{
    node *t;
    if(start==NULL)
        return NULL;
    t=start;
    do
    {
        if(t->item==data)
            return t;
        t=t->next;
    }while(t!=NULL);
    return NULL;
}
void CDLL::insertafter(node *temp,int data)
{
    node *n ,*t;
    if(start==NULL || temp == NULL) 
        cout<<"insertion can not be perform";
    else
    {
        n= new node;
        n->item=data;
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}
void CDLL::deletefirst()
{
    node *r;
    if(start!=NULL)
    {
        r=start;
        if(start->next=start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            start->prev->next=r->next;
            start= start->next;
            start->prev=r->prev;
            delete r;
        }
    }
}
void CDLL::deletelast()
{
    node *r;
    if(start!=NULL)
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
             r=start->prev;
             r->prev->next=start;
             start->prev=r->prev;
             delete r;

        }   
    }
}
void CDLL::del(node *temp)
{
    if(start==NULL || temp ==NULL)
    {
        cout<<"deletion can't be performed";
    }
    else
    {
         if(start==temp)
        {
            deletefirst(); 
        }
        else
        {
            temp->prev->next= temp->next;
            temp->next->prev= temp->prev;
            delete temp; 
        }
    }
}