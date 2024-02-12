#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
    int height;
};
class AVL
{
private:
    node *root;

protected:
    node *insertion(node *, int);
    node *deletion(node *, int);
    void inorderrec(node *);
    node *minvaluenode(node *);

public:
    AVL();
    int getbalancefactor(node *);
    int getheight(node *);
    node *leftRotate(node *);
    node *rightRotate(node *);
    void insert(int);
    void updateAnscestoresheights(node *, int);
    void inorder();
    void del(int);
};
node *AVL::minvaluenode(node *ptr)

{
    node *current = ptr;
    while (current->left != NULL)
        current = current->left;
    return current;
}
void AVL::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<" "<<ptr->item<<"("<<getbalancefactor(ptr);
        inorderrec(ptr->right);
    }
}
void AVL::inorder()
{
    inorderrec (root);
}
node *AVL::deletion(node *ptr, int data) 
{
    if (ptr == NULL)
        return ptr;
    if (data < ptr->item)
        ptr->left = deletion(ptr->left, data);
    else if (data > ptr->item)
        ptr->right = deletion(ptr->right, data);
    else
    {
        if ((ptr->left == NULL) || (ptr->right == NULL))
        {
            node *temp = ptr->left ? ptr->left : ptr->right;
            // No child case
            if (temp == NULL)
            {
                temp = ptr;
                ptr = NULL;
            }
            else
            {
                *ptr = *temp;
                free(temp);
            }
        }
        else
        {
            // node with two children:get the inorder
            // successor(smallest in the right subtree)

            node *temp = minvaluenode(ptr->right);
            ptr->item = temp->item;

            // delete the inorder successor
            ptr->right = deletion(ptr->right, temp->item);
        }
    }
    if (ptr == NULL)
        return ptr;
    ptr->height = 1 + max(getheight(ptr->left), getheight(ptr->right));
    int balance = getbalancefactor(ptr);

    // left left case
    if (balance > 1 && getbalancefactor(ptr->left) >= 0)
        return rightRotate(ptr);

    //left right case
    if (balance > 1 && getbalancefactor(ptr->left) < 0)
    {
        ptr->left=leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    //right right case
    if(balance < -1 && getbalancefactor(ptr->right) <=0 )
        return leftRotate(ptr);
    //right left case
    if(balance < -1 && getbalancefactor(ptr->right) > 0)
    {
        ptr->right=rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
}
void AVL::del(int data)
{
    root = deletion(root, data);
}
node *AVL::insertion(node *ptr, int data)
{
    node *n;
    if (ptr == NULL)
    {
        n = new node;
        n->left = NULL;
        n->item = data;
        n->right = NULL;
        n->height = 1;
        return n;
    }
    if (data < ptr->item)
        ptr->left = insertion(ptr->left, data);
    else if (data > ptr->item)
        ptr->right = insertion(ptr->right, data);
    else // duplicate value not allowed
        return ptr;
    // update height of this ancestor node
    ptr->height = 1 + max(getheight(ptr->left), getheight(ptr->right));

    /*
    get the balance factor of this
    ancestor node to check whether
    this node became unbalanced
    */
    int balance = getbalancefactor(ptr);

    // if this node became unbalanced,
    // then there are 4 cases

    // left left case
    if (balance > 1 && data < ptr->left->item)
        return rightRotate(ptr);

    // right right case
    if (balance < -1 && data > ptr->right->item)
        return leftRotate(ptr);

    // left right case

    if (balance > 1 && data > ptr->left->item)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    // right left case
    if (balance < -1 && data < ptr->right->item)
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
}
void AVL::insert(int data)
{
    root = insertion(root, data);
}
node *AVL::rightRotate(node *A)
{
    node *B = A->left;
    node *RT = B->right;
    B->right = A;
    A->left = RT;
    A->height = max(getheight(A->left), getheight(A->right)) + 1;
    B->height = max(getheight(B->left), getheight(B->right)) + 1;

    return B;
}
node *AVL::leftRotate(node *A)
{
    node *B = A->right;
    node *LT = B->left;

    B->left = A;
    A->right = LT;

    A->height = max(getheight(A->left), getheight(A->right)) + 1;
    B->height = max(getheight(B->left), getheight(B->right)) + 1;
}
int AVL::getheight(node *ptr)
{
    if (ptr == NULL)
        return 0;
    return ptr->height;
}
int AVL::getbalancefactor(node *ptr)
{
    if (ptr == NULL)
        return 0;
    return getheight(ptr->left) - getheight(ptr->right);
}
AVL::AVL()
{
    root = NULL;
}
int max(int a, int b)
{
    return (a > b ? a : b);
}
int main()
{
    AVL tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(90);
    tree.insert(110);
    tree.inorder();
    tree.del(110);
    cout<<endl;
    //tree.del(30);
    tree.inorder();
    cout<<endl;
    return 0;
}