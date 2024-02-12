#include<bits/stdc++.h>
#include "DynArray.cpp"
using namespace std;
struct node
{
    int item;
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        node* getstart();
        void setvertex(int);
        void addNode(int,int);
        void removefirstnode();
        void printlist();
        ~AdjList();
};
node* AdjList::getstart()
{
    return start;
}
void AdjList::printlist()
{
    node *t;
    t-start;
    while(t)
    {
        cout<<" ("<<t->vertex<<","<<t->item<<")";
        t=t->next;
    }
}
AdjList::~AdjList()
{
    while(start)
        removefirstnode(); 
}
void AdjList::removefirstnode()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
void AdjList::setvertex(int v)
{
    vertex=v;
}
void AdjList::addNode(int v, int data)
{
    node *n=new node ;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start-n;
}
AdjList::AdjList()
{
    start=NULL;
}
AdjList::AdjList(int v)
{
    start=NULL;
    vertex=v;
}
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        int getVcount();
        DynArray& AdjacentNodes(int);
        void creategraph();
        void printGraph();
        ~Graph();
};
DynArray& Graph::AdjacentNodes(int n)
{
    DynArray *p=new DynArray(1);
    node *t = this->arr[n].getstart();
    while(t)
    {
        p->append(t->vertex);
        t=t->next;
    }
    return *p;
}
int Graph::getVcount()
{
    return v_count;
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++)
    {
        cout<<endl;
        arr[i].printlist();
    }
}
Graph::~Graph()
{
    delete []arr;
}
void Graph::creategraph(int vno)
{
    int n,v,data;
    v_count=vno;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++)
    {
        arr[i].setvertex(i);
        cout<<"\nhow many adjacent node of v"<<i<<":";
        cin>>n;
        for(int j=0;i<n;j++)
        {
            cout<<"\n Enter Vertex Number ";
            cin>>v;
            data=10;
            arr[i].addNode(v,data);
        }
    }
}
Graph::Graph()
{
    v_count=0;
    arr=NULL;
}
int main()
{
    Graph g;
    g.creategraph(6);
    g.printGraph();
    cout<<endl;
    return 0;
}