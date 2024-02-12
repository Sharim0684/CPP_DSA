#include <bits/stdc++.h>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;
public:
    Array();
    Array(Array&);
    Array& operator=(Array&);
    void createArray(int);
    void insert(int , int);
    void append(int);
    int getItem(int);
    bool isempty();
    bool isfull();
    void del(int);
    void edit(int , int);
    int count();
    int getCapacity();
    ~Array();
};
Array :: Array()
{
    ptr = NULL;
}
Array :: Array(Array&arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr=new int[capacity];
    for (int  i = 0; i <lastindex; i++)
        ptr[i]=arr.ptr[i];
    
}
Array& Array:: operator=(Array &arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr = new int[capacity];
    if(ptr!=NULL)
        delete []ptr;
    for(int i=0;i<lastindex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
void  Array :: createArray(int cap)
{
    capacity = cap;
    lastindex =-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr = new int[capacity];
}
void Array :: append(int data)
{
    if(!isfull)
    {
        lastindex++;
        ptr[lastindex]=data;
    }
    else
    {
        cout<<"Overflow"<<endl;
    }
}
bool Array :: isfull()
{
    return lastindex == capacity-1;
}
bool Array :: isempty(){
    return lastindex == -1;
}
void Array :: insert(int index, int data)
{
    try{
    if(index<0 || index > lastindex+1)
       throw 1;
    if(isfull)
        throw 2;
    for(int i=lastindex;i>0;i--)
        ptr[i+1] = ptr[i];
    ptr[index] = data;
    lastindex++;

    }

    catch(int e)
    {
        if(e==1)
            cout<<"invalid index";
        else if(e==2)
            cout<<"overflow";
    }

}
int Array::getItem(int index)
{
    try{
        if(index<0 || index>lastindex)
            throw 1;
        return ptr[index];
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid index";
    }
    return -1;
}
int Array :: getCapacity()
{
    return capacity;

}
int Array :: count()
{
    return lastindex+1;
}
void Array::edit(int index, int newdata)

{
    try
    {
        if(index<0 || index>lastindex+1)
            throw 1;
        ptr[index]=newdata;
    }
    catch(int e)
    { 
        if(e==1)
            cout<<"invalid index";
    }
    
}
void  Array::del(int index)
{
    try
    {
        if(index<0 || index>lastindex+1)
            throw 1;
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"invalid Index ";
    }
}
Array::~Array()
{
     delete []ptr;
} 