#include<bits/stdc++.h>
using namespace std;
#define INVALID_QUEUE_STATE;
#define OVERFLOW;
#define UNDERFLOW;
class Queue{
    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    public:
        Queue(int);
        Queue(Queue&);
        Queue& operator=(Queue&);
        void insert(int);
        bool isfull();
        int getfront();
        int getback(); 
        bool isempty();
        void del();
        int count();
        ~Queue();
};
Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    if(cap>0)
        ptr=new int(cap);
    else
        ptr=NULL;
}
Queue::Queue(Queue &q)
{
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int (capacity);
    for(int i=0;i<capacity;i++)
        ptr[i]=q.ptr[i];
}
Queue& Queue::operator=(Queue &q)
{
    if(ptr)
        delete []ptr;
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int (capacity);
    for(int i=0;i<capacity;i++)
        ptr[i]=q.ptr[i];
    return *this ;
}
void Queue::insert(int data)
{
    if(capacity<=0)
        throw INVALID_QUEUE_STATE;
    if(isfull())
        throw OVERFLOW;
    if(rear==1)
    {
        rear=front=0;
        ptr[rear]=data;
    }
    else
    {
        rear++;
        ptr[rear]=data;
    }
}
void Queue::del()
{
    if(isempty())
        throw UNDERFLOW;
    if(front==rear)
        front=rear=-1;
    else if(front==capacity-1)
        front=0;
    else
        front++;
         
}
bool Queue::isfull()
{
   return (front==0&&rear==capacity-1 || rear+1=front);
}
bool Queue::isempty()

{
    return front==-1;
}
int Queue::getfront()
{
    if(isempty())
        throw UNDERFLOW;
    return ptr[front];
}
int Queue::getback()
{
    if(isempty())
        throw UNDERFLOW;
    return ptr[rear];
}
Queue::~Queue()
{
    delete []ptr;
}
int Queue::count()
{
    if(front==-1)
        return 1;
    if(front==rear)
        return 1;
    if(rear>front)
        return rear-front+1;
    else
        return capacity-front+rear+1;
    
}