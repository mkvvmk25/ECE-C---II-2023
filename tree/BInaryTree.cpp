#include<iostream>
using namespace std;
#include<vector>

struct Node
{
    Node *left = NULL;
    int val;
    Node *right = NULL;
};


struct BT 
{
    Node *root = NULL;
    //              30   ,    a10
    Node *insert(int v, Node *myroot)
    {
        if(myroot == NULL)
        {
            struct Node *newnode = new Node();
            newnode->val = v;
            return newnode; // a10
        }

        vector<Node*> que;
        que.push_back(myroot);
        int front = 0;
        int rear = 0; 

        while(front <= rear)
        {
            Node *stand = que[front];
            if(stand->left == NULL)
            {
                struct Node *newnode = new Node();
                newnode->val = v;
                stand->left = newnode;
                return myroot;
            }
            else 
            {
                que.push_back(stand->left);
                rear++;
            }
            if(stand->right == NULL)
            {
                struct Node *newnode = new Node();
                newnode->val = v;
                stand->right = newnode;
                return myroot;
            }
            else 
            {
                que.push_back(stand->right);
                rear++;
            }

            front++;
        }
    }
};

struct BST
{
    Node *root = NULL;
    //             5        NULL  
    Node* insert(int v, Node *myroot)
    {
        if(myroot == NULL)
        {
            struct Node* newnode = new Node();
            newnode->val = v; 
            return newnode;
        } 
        else if(myroot->val > v )// left insert
        {
            myroot->left = insert(v, myroot->left);  
        }
        else if(myroot->val < v )// right insert
        {
            myroot->right = insert(v, myroot->right);
            //                     20, null
        }
        return myroot;
    }


};


int main()
{
    struct BT *t = new BT();
    t->root = t->insert(10, t->root); 
    t->root = t->insert(20, t->root); 
    t->root = t->insert(30, t->root); 

}