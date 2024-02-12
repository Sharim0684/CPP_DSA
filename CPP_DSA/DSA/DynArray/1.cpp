#include <bits/stdc++.h>
using namespace std;
class DnyArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;
protected:
    void DoubleArray();
    void halfArray();
public:
    DnyArray();
    DnyArray(DnyArray&);
    DnyArray& operator=(DnyArray&);
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
    ~DnyArray();
};
DnyArray :: DnyArray()
{
    ptr = NULL;
}
DnyArray :: DnyArray(DnyArray&arr)
{
    capacity = arr.capacity;
    lastindex = arr.lastindex;
    ptr=new int[capacity];
    for (int  i = 0; i <lastindex; i++)
        ptr[i]=arr.ptr[i];
    
}
DnyArray& DnyArray:: operator=(DnyArray &arr)
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
void  DnyArray :: createArray(int cap)
{
    capacity = cap;
    lastindex =-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr = new int[capacity];
}
void DnyArray :: append(int data)
{
    if(isfull)
        DoubleArray();
    lastindex++;
    ptr[lastindex]=data;
    
}
bool DnyArray :: isfull()
{
    return lastindex == capacity-1;
}
bool DnyArray :: isempty(){
    return lastindex == -1;
}
void DnyArray :: insert(int index, int data)
{
    try{
    if(index<0 || index > lastindex+1)
       throw 1;
    if(isfull)
        DoubleArray();
    for(int i=lastindex;i>0;i--)
        ptr[i+1] = ptr[i];
    ptr[index] = data;
    lastindex++;

    }

    catch(int e)
    {
        if(e==1)
            cout<<"invalid index";
    }

}
int DnyArray::getItem(int index)
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
int DnyArray :: getCapacity()
{
    return capacity;

}
int DnyArray :: count()
{
    return lastindex+1;
}
void DnyArray::edit(int index, int newdata)

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
void  DnyArray::del(int index)
{
    try
    {
        if(index<0 || index>lastindex+1)
            throw 1;
        for(int i=index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
        if( capacity>1 && +1 <= capacity/2)
            halfArray();
    }
    catch(int e)
    {
        if(e==1)
            cout<<"invalid Index ";
    }
}
DnyArray::~DnyArray()
{
     delete []ptr;
} 
void DnyArray :: DoubleArray()
{
    int *temp;
    temp = new int [capacity*2];
    for(int i = 0 ;i<=lastindex;i++)
        temp[i] = ptr[i];
    delete []ptr;
    ptr = temp;
    capacity*=2;
}
void DnyArray :: halfArray()
{
    int *temp;
    temp = new int [capacity*2];
    for(int i = 0; i<=lastindex;i++)
        temp [i ] = ptr[i];
    delete []ptr;
    ptr = temp;
    capacity/=2;
}