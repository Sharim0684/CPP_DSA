#include <bits/stdc++.h>
using namespace std;
#define EMPTY_QUEUE;
struct node
{
    int item;
    node *next;
    int pno; // prioruty num
};
class priorityQueue
{
private:
    node *start;

public:
    priorityQueue();
    ~priorityQueue();
    priorityQueue(priorityQueue &);
    priorityQueue& operator=(priorityQueue &);
    void insert(int, int);
    void del();
    int getitem();
    int getpriority();
    bool isempty();
};
priorityQueue::priorityQueue()
{
    start = NULL;
}
priorityQueue::~priorityQueue()
{
    while(start)
        del();
}
priorityQueue::priorityQueue(priorityQueue &pq)
{
    node *t;
    start=NULL;
    if(pq.start)
    {
        t=pq.start;
        while(t!=NULL)
        {
            insert(t->pno,t->item);
            t=t->next;
        }
    }
}
priorityQueue & priorityQueue::operator=(priorityQueue &pq)
{
    while(start)
        del();
    node *t;
    if(pq.start)
    {
        t=pq.start;
        while(t!=NULL)
        {
            insert(t->pno,t->item);
            t=t->next;
        }
    }
    return *this;
}
void priorityQueue::insert(int p, int data)
{
    node *n = new node;
    n->pno = p;
    n->item = data;
    node *t;
    if (start == NULL || start->pno < n->pno)
    {
        n->next = start;
        start = n;
    }
    else
    {
        t = start;
        while (t->next != NULL)
        {
            if (t->next->pno < n->pno)
                break;
            t = t->next;
        }
        n->next = t->next;
        t->next = n;
    }
}
void priorityQueue::del()
{
    node *t;
    if(start)
    {
        t=start;
         start=start->next;
         delete t;
    }
}
int priorityQueue::getitem()
{
    if(start)
        return start->item;
    throw EMPTY_QUEUE;
}
int priorityQueue::getpriority()
{
    if(start)
        return start->pno;
    throw EMPTY_QUEUE;
}
bool priorityQueue::isempty()
{
    return start==NULL;
}