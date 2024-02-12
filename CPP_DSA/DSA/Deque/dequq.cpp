#include<bits/stdc++.h>
using namespace std;
#define UNDERFLOW;
struct node{
    node *prev;
    int item;
    node *next;

};
class Deque
{
    private:
        node *front,*rear;
    public:
        Deque();
        ~Deque();
        Deque(Deque &);
        bool isempty();
        void insertfront(int );
        void insertrear(int);
        void deletefront();
        void deleterear();
        int getrear();
        int getfront();
        Deque operator=(Deque &);
};
Deque::Deque()
{
    front=NULL;
    rear=NULL;
}
Deque::~Deque()
{
    while (front)
        deletefront();
    
}
bool Deque::isempty()
{
    return front=NULL;
}
Deque::Deque(Deque &d)
{
    node *t;
    front=rear=NULL;
    if(d.front==NULL);
       
    else
    {
        t=d.front;
        while(t!=NULL)
        {
            insertrear(t->item);
            t=t->next;
        }
         
    }
}
Deque& Deque::operator=(Deque &d)
{
    while(front)
        deletefront();
     node *t;
    if(d.front==NULL)
        front=rear=NULL;
    else
    {
        t=d.front;
        while(t!=NULL)
        {
            insertrear(t->item);
            t=t->next;
        }
         
    }
    return *this;
}
void Deque::insertfront(int data)
{
    node *n = new node;
    n->prev=NULL;
    n->item=data;
    n->next=front;
    if(front==NULL)
    {
        front=rear=n;
    } 
    else
    {
        front->prev=n;
        front =n;
    }
}
void Deque::insertrear(int data)
{
    node *n=new node;
    n->next=NULL;
    n->item=data;
    n->prev=rear;
    if(rear==NULL)
    {
        front=rear=n;
    }
    else
    {
        rear->next=n;
        rear=n;
    }
}
void Deque::deletefront()
{
    if(front==NULL)
        throw UNDERFLOW;
    if(front==rear)
    {
        delete front;
        front=rear=NULL;
        front->prev=NULL;

    }
    else{
        front=front->next;
        delete front->prev;
    }
}
void Deque::deleterear()
{
    if(rear==NULL)
        throw UNDERFLOW
    if(rear==front)

    {
        delete rear;
        front=rear=NULL;
    }
    else
    {
        rear=rear->prev;
        delete rear->next;
        rear->next=NULL;
    }

}
int Deque::getfront()
{
    if(front==NULL)
        throw UNDERFLOW;
    return front->item;
}
int Deque::getrear()
{
    if(rear==NULL)
        throw UNDERFLOW;
    return rear->item;
}