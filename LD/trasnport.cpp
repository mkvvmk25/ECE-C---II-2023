#include<iostream>
using namespace std;

struct CirqueArr
{
  int front = -1;  
  int rear = -1;  
  int *que;
  int len = 0;
  int avl_ele = 0;
  
  void ss(int n)
  {
      len = n;
      que = new int[n];
  }
  
  void enq(int v)
  {
    // mt full more than 1  
    if( (rear+1)%len == front)
    {
        cout << "full";
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        que[rear] = v;
        avl_ele++;
    }
    else 
    {
        rear = rear+1 % len
        que[rear] = v;
        avl_ele++;
    }
    
  }
  
  int deq()
  {
    // mp 1 ele more 1  
    if(front == -1 && rear == -1)
    {
        // cout << "mpt";
        return -1;
    }
    else if(front == rear)
    {
        int t = que[front];
        front = -1;
        rear = -1;
        avl_ele--;
        return t;
    }
    else 
    {
        int t = que[front];
        front = (front+1)%len;
        avl_ele--;
        return t;
        
    }
    
  }
  
  bool isfull()
  {
    if((rear+1)%len == front)
    {
        return true;
    }
    return false;
  }
 
  bool ismpt()
  {
    if(rear == -1 && front == -1)
    {
        return true;
    }
    return false;
  }
  
  int peek()
  {
     if(ismpt() == true)
     {
         return -1;
     }
     return que[front];
  }
//   0 1 2 3 4
//       f   r  
  void prt()
  {
      for(int i = front; i != rear; i=(i+1)%len)
      {
          cout << que[i] << " ";
      }
      cout << que[rear] << " ";
      
      cout << "\n";
  }
  
};



int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    struct CirqueArr *t = new CirqueArr();
    t->ss(n);
    for(int i = 0; i < k; i++)
    {
        int val;
        cin >> val;
        if(i < n)
        {
            t->enq(val);
        }
        else 
        {
            if(val % 2 == 0)
            {
                t->deq();
                t->enq(val);
            }
            else 
            {
                continue;
            }
        }
    }

    t->prt();
}