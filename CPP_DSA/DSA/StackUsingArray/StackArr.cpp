#include<bits/stdc++.h>
using namespace std;
#define STACK_IS_EMPTY;
class Stack{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack();
        Stack(int);
        Stack(Stack&);
        Stack& operator=(Stack&);
        ~Stack();
        void CreatStack(int);
        void push(int);
        bool isfull();
        int peek();
        bool isempty();
        void pop();
};
Stack::Stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
Stack::Stack(int cap)
{
    capacity=cap;
    top=-1;
    ptr=NULL;
}
Stack::Stack(Stack &s)
{
    capacity=s.capacity;
    top=s.top;
    ptr=new int [capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
}
Stack& Stack::operator=(Stack &s)
{
    if(ptr!=NULL)
        delete []ptr; 
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    for(int i=0;i<=top;i++)
        ptr[i]=s.ptr[i];
    return *this;
}
void Stack::CreatStack(int cap)
{
    if(ptr!=NULL)
        delete []ptr;
    capacity=cap;
    top=-1;
    ptr=new int(cap);
}
void Stack::push(int data)
{
    if(isfull())
        cout<<"overflow";
    else
    {
        top++;
        ptr[top]=data;
    }
}
bool Stack::isfull()
{
    return top==capacity-1;
}
int Stack::peek()
{
    if(isempty())
        throw STACK_IS_EMPTY;
    return ptr[top];
}
bool Stack::isempty()
{
    return top==-1;
}
void Stack::pop()
{
    if(isempty())
        cout<<"stack underflow";
    else
    {
        top--;
    }
}
Stack::~Stack()
{
    if(ptr!=NULL)
        delete []ptr;
}