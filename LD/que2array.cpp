#include<iostream>
using namespace std;
struct que2 
{
    int f1 = -1,r1 = -1, f2, r2;
    int len;
    int *que; 
    void quesize(int n)
    {
        len = n;
        que = new int[n];
        f2 = n;
        r2 = n;
    }
    void enq1(int val)
    {
        if( r1+1 == r2)
        {
            std::cout << "full";
        }
      else if(f1 == -1 && r1 == -1)
      {
        f1++;
        r1++;
        que[r1] = val;
      }  
      else if(r1 +1 < r2 ) 
      {
        r1++;
        que[r1] = val;
      }
    }
    
    void enq2(int val)
    {   
         if( r1 == r2-1)
        {
            std::cout << "full";
        }
        else if(f2 == len && r2 == len)
        {
            f2--;
            r2--;
            que[r2] = val;
        }  
        else 
        {
            r2--;
            que[r2] = val;
        }
    }

    int deq1()
    {
        if(f1 == -1 && r1 == -1)
        {
            cout << "que 1 mpt";
            return -1;
        }
        else if(f1== r1)
        {
            int t = que[f1];
            f1 = -1;
            r1 = -1; 
            return t;
        }
        else
        {
            int t = que[f1];
            f1++;
            return t;
        }
    }
    int deq2()
    {
        if(f2 == len && r2 == len)
        {
            cout << "que 2 mpt";
            return -1;
        }
        else if(f2== r2)
        {
            int t = que[f2];
            f2 = len;
            r2 = len; 
            return t;
        }
        else
        {
            int t = que[f2];
            f2--;
            return t;
        }
    }

    void printque2()
    {
        if(f2 == len)
        {
            cout << "mpt";
        }
        else 
        {
            for(int i = f2; i >= r2 ; i--)
            {
                cout << que[i] << " ";
            }
        }
    }
    void printque1()
    {
        if(f1 == -1)
        {
            cout << "mpt";
        }
        else 
        {
            for(int i = f1; i <= r1 ; i++)
            {
                cout << que[i] << " ";
            }
        }
    }
};


int main()
{

}