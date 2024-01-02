#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<queue>


struct Node
{
    Node *left = NULL;
    int val;
    Node *right = NULL;
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

    Node *serch_val(Node *myroot, int element)
    {
        if(myroot == NULL ||   myroot->val == element)
        {
            return myroot;
        }
        //           p           se
        else if(myroot->val > element) // go to left
        {
            return serch_val(myroot->left, element);
        }
        //            p        <  se
        else if(myroot->val < element)// go ot right
        {
            return serch_val(myroot->right, element);
        }
    }

    int sum_leaf(Node *myroot)
    {
        vector<Node*> que;
        que.push_back(myroot);
        int front = 0;
        int rear = 0;
        int sum = 0; 
        while(front <= rear)
        {
            Node *stand = que[front];
            if(stand->left == NULL && stand->right == NULL)
            {
                sum = sum + stand->val;
            }

            if(stand->left != NULL)
            {
                que.push_back(stand->left);
                rear++;
            }
            if(stand->right != NULL)
            {
                que.push_back(stand->right);
                rear++;
            }

            front++;

        }

        return sum;
    }

    void sum_leaf_rec(Node *myroot ,int &d)
    {
        
        if(myroot != NULL)
        {
            sum_leaf_rec(myroot->left, d);

            if(myroot->left == NULL && myroot->right == NULL)
            {
                d =  d + myroot->val;
            }  
            // cout << myroot->val << " ";

            sum_leaf_rec(myroot->right, d);
        }
    }

    int diameter(Node *myroot, int &maxD)
    {
        if(myroot == NULL)
        {
            return 0;
        }   
        int left = diameter(myroot->left, maxD );
        int right = diameter(myroot->right, maxD);
        if(left + right + 1 > maxD)
        {
            maxD = left+right+1;
        }

        if(left > right)
        {
            return left + 1;
        }
        else 
        {
            return right+1;
        }

    }

    bool find_path(Node *myroot, vector<Node*> &path, 
                    vector<vector<Node*>> &ans, int target)
    {
        if(myroot == NULL)
        {
            return false;
        }
        path.push_back(myroot);
        if(true == find_path(myroot->left, path, ans,target) )
        {
            return true;
        }
        if(true == find_path(myroot->right, path, ans,target))
        {
            return true;
        }
        if(myroot->val == target)
        {
            ans.push_back(path);
            return true;
        }
        path.pop_back();
        return false;
    }

    void inorder(Node *myroot)
    {
        if(myroot != NULL)
        {
            inorder(myroot->left);
            cout << myroot->val << " ";
            inorder(myroot->right);
        }
    }

    void verticalorder(Node *myroot, map<int, vector<int> > &k)
    {
        queue< pair<Node*, int > > que;
        que.push( { myroot, 0});
        while(que.empty() == false)
        {
            pair<Node*, int > g = que.front();
            Node *stand = g.first;
            int ver_order = g.second;

            k[ver_order].push_back(stand->val);

            if(stand->left != NULL)
            {
                que.push( {stand->left, ver_order-1});
            }
            if(stand->right != NULL)
            {
                que.push( {stand->right, ver_order+1});
            }


            que.pop();
        }


    }  

    Node* delete_node(Node *myroot, int element)
    {
        //    c            p
        if(element < myroot->val)
        {
            myroot->left = delete_node(myroot->left, element);
        }
        else if(element > myroot->val)
        {
            myroot->right = delete_node(myroot->right, element);
        }
        else 
        {
            if(myroot->right == NULL)
            {
                return myroot->left;
            }
            else if(myroot->left == NULL)
            {
                return myroot->right;
            }
            else 
            {
                // find the successor 
                Node *r_sub_root = myroot->right; 
                Node *temp = r_sub_root; 
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                // myroot-a1, r_sub_root-a3, temp-a2 
                int sucessor_ele = temp->val;
                myroot->right = delete_node(myroot->right, sucessor_ele );
                myroot->val = sucessor_ele;
            }
            // return NULL;
        }
        return myroot;
    }

    void kthsmall(Node *myroot, int &cnt, int kth)
    {
        if(myroot != NULL)
        {
            kthsmall(myroot->left, cnt, kth);
            cnt++;
            if(cnt == kth)
            {
                cout << myroot->val;
            }
            kthsmall(myroot->right,cnt, kth);
            
        }
    }

    bool path_finding(Node *myroot, vector<int> &path,int target)
    {
        if(myroot == NULL)
        {
            return false;
        }
        path.push_back(myroot->val);
        if(path_finding(myroot->left, path, target) == true)
        {
            return true;
        }
        if(path_finding(myroot->right, path, target) == true)
        {
            return true;
        }
        if(myroot->val == target)
        {
            return true;
        }
        path.pop_back();
        return false;

        

        

    }
};

int main()
{
    
    struct BST *tree = new BST();
    tree->root = tree->insert(50, tree->root);
    tree->root = tree->insert(25, tree->root);
    tree->root = tree->insert(15, tree->root);
    tree->root = tree->insert(75, tree->root);
    tree->root = tree->insert(30, tree->root);
    tree->root = tree->insert(18, tree->root);
    tree->root = tree->insert(8, tree->root);
    tree->root = tree->insert(12, tree->root);
    tree->root = tree->insert(26, tree->root);
    tree->root = tree->insert(20, tree->root);
    tree->root = tree->insert(7, tree->root);

    map<int, vector<int> > mp; 
    tree->verticalorder(tree->root, mp);
    vector<int> h = {1,2,3,4};
    for(pair<int, vector<int>> i :mp)
    {
        int order = i.first; 
        cout << order << " ";
        vector<int> f = i.second;
        for(int j: f)
        {
            cout << j << "-->";
        }
        cout << endl;
    }





}