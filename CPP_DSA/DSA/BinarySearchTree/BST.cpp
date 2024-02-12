#include <bits/stdc++.h>
using namespace std;
#define EMPTY_TREE
#define DATA_NOT_FOUND
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
private:
    node *root;
    void recpreorder(node *);
    void recinorder(node *);
    void recpostorder(node *);
    void inordercopy(BST &, node *);
public:
    BST();
    BST(BST &);
    BST& operator=(BST&);
    ~BST();
    bool isempty();
    void insert(int);
    void preorder();
    void inorder();
    void postorder();
    node *search(int);
    void del(int);
};
BST::BST()
{
    root = NULL;
}
void BST::inordercopy(BST &b, node *ptr)
{
    if (ptr)
    {
         
        inordercopy(b,ptr->left);
        b.insert(ptr->item);
        inordercopy(b,ptr->right);
    } 
}
BST::BST(BST &bst)
{
    root=NULL;
    if(bst.root)
    {
        bst.inordercopy(*this,bst.root);
    }
}
BST& BST::operator=(BST &bst)
{
    while(root)
        del(root->item);
    bst.inordercopy(*this,bst.root);
    return  *this;
}
BST::~BST()
{
    while(root)
        del(root->item);
}
bool BST::isempty()
{
    return root == NULL;
}
void BST::insert(int data)
{

    node *ptr;

    if (root == NULL)
    {
        node *n = new node;
        n->left = NULL;
        n->item = data;
        n->right = NULL;
        root = n;
    }
    else
    {
        bool flag = true;
        ptr = root;
        while (flag)
        {
            node *n = new node;
            n->left = NULL;
            n->item = data;
            n->right = NULL;
            if (data == ptr->item)
                break;
            if (data < ptr->item)
            {
                if (ptr->left == NULL)
                {
                    ptr->left = n;
                    flag = false;
                }
                else
                    ptr = ptr->left;
            }
            else
            {
                if (ptr->right == NULL)
                {
                    node *n = new node;
                    n->left = NULL;
                    n->item = data;
                    n->right = NULL;
                    ptr->right = n;
                    flag = false;
                }
                else
                    ptr = ptr->right;
            }
        }
    }
}
void BST::recpreorder(node *ptr)

{
    if (ptr)
    {
        cout << ptr->item << " ";
        recpreorder(ptr->left);
        recpreorder(ptr->right);
    }
}

void BST::preorder()
{
    recpreorder(root);
}
void BST::recinorder(node *ptr)
{
    if (ptr)
    {
        recinorder(ptr->left);
        cout << ptr->item << " ";
        recinorder(ptr->right);
    }
}
void BST::inorder()
{
    recinorder(root);
}
void BST::recpostorder(node *ptr)
{
    if (ptr)
    {
        recpostorder(ptr->left);
        recpostorder(ptr->right);
        cout << ptr->item << " ";
    }
}
node *BST::search(int data)
{
    node *ptr = root;
    while (ptr)
    {
        if (ptr->item == data)
            return ptr;
        if (data < ptr->item)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return NULL;
}
void BST::del(int data)
{
    node *ptr, *parptr;
    if (root == NULL)
    {
        throw EMPTY_TREE;
    }
    parptr = NULL;
    ptr = root;
    while (ptr)
    {
        if (ptr->item == data)
            break;
        if (data < ptr->item)
        {
            parptr = ptr;
            ptr = ptr->left;
        }
        else
        {
            parptr = ptr;
            ptr = ptr->right;
        }
    }
    if (ptr == NULL)
        throw DATA_NOT_FOUND;
    if (parptr == NULL && ptr != NULL) // root node to be deleted
    {
        if (ptr->left == NULL && ptr->right == NULL) // no child
        {
            delete ptr;
            root = NULL;
        }
        else if (ptr->left && ptr->right) // two children
        {
            node *suc, *parsuc;
            suc = ptr->right;
            parsuc = ptr;
            while (suc->left != NULL)
            {
                parsuc = suc;
                suc = suc->left;
            }
            ptr->item = suc->item;
            // now delete successor
            if (suc == parsuc->left)
                parsuc->left = suc->right;
            else
                parsuc->right = suc->right;
            delete suc;
        }
        else // one child
        {
            if (ptr->left)
                root = ptr->left;
            else
                root = ptr->right;
            delete ptr;
        }
    }
    else // node to be deleted is not a root node
    {
        if (ptr->left == NULL && ptr->right == NULL) // no child
        {
            if (ptr == parptr->left) // ptr is left child of parptr
            {
                parptr->left = NULL;
                delete ptr;
            }
            else // ptr is right child of parptr
            {
                parptr->right = NULL;
                delete ptr;
            }
        }
        else if (ptr->left && ptr->right)
        {
            node *suc, *parsuc;
            suc = ptr->right;
            parsuc = ptr;
            while (suc->left != NULL)
            {
                parsuc = suc;
                suc = suc->left;
            }
            ptr->item = suc->item;
            // now delete successor
            if (suc == parsuc->left)
                parsuc->left = suc->right;
            else
                parsuc->right = suc->right;
            delete suc;
        }
        else
        {

            if (ptr == parptr->left) // ptr is left child of parptr
            {
                if (ptr->left)
                    parptr->left = ptr->left;
                else
                    parptr->left = ptr->right;
                delete ptr;
            }
            else // ptr is right child of parptr
            {
                if (ptr->left)
                    parptr->right = ptr->left;
                else
                    parptr->right = ptr->right;
                delete ptr;
            }
        }
    }
}