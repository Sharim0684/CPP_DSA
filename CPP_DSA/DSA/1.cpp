#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    int *ptr;
    int capacity;
    int lastindex;


    
    int insert(int, int);
    int append(int);
    int getitem(int);
    int isempty();
    bool isfull();
    void del(int);
    void edit(int, int);
    int count();
    int getcapacity();
    int Createarr(int);

};
void Array :: Createarr(int cap)
{
    capacity = cap;
    lastindex = -1;
    if(ptr!=NULL)
        delete []ptr;
        ptr = new int[capacity];
}
void Array :: append(int data)
{
    if(!isfull())
    {
        lastindex++;
        ptr[lastindex]=data;

    }
    else
    {
        cout<<"overflow";
    }
}
void Array :: getitem(int index) 
{
    try{
        if(index<0 || index>lastindex)
            throw 1;
        return ptr[index];
    }
    catch(int e)
    {
        if(e==1)
        cout<<"invalid Index";
    }
    return -1;
}
void Array::isempty()
{
   return lastindex == -1;
}
bool Array :: isfull()
{
    return lastindex==capacity-1;
}
void Array :: insert(int index , int data)
{
    int i;
    try{
    if(index<0 || index>lastindex + 1)
        throw 1;
        if(isfull())
            throw 2; 
        for(i=lastindex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastindex++;
    }
    catch(int e)
        if(e==1)
            cout<<"invalid Index";
        else if(e==2)
            cout<<"overflow";
}
int Array::getcapacity()
{
    return capacity;
}
int Array::count()
{
    return lastindex+1; 
}
void Array::edit(int index,int newdata)
{
    try
    {
        if(index<0 || index>lastindex)
            throw 1;
        ptr[index]=newdata;
    }
    catch(int e)
    {
        if(e==1)
            cout<<"invalid index";   
    }
    
}
void Array::del(int index)
{
    try
    {
        if(index<0 || index>lastindex)
            throw 1;
        for(int i = index;i<lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
    }
    catch(int e)
    {
         if(e==1)
            cout<<"Invalid index ";
    }
    
}
int main()
{
}