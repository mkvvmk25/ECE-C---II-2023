#include<iostream>
using namespace std;
struct stackARR 
{
    int *stack; 
    int top = -1; 
    int length = 0;

    void stacksize(int siz)
    {
        this->length = siz;
        this->stack = new int[siz];
    }
   
    bool isfull()   
    {
        if(this->top == this->length - 1)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    bool isempty()
    {
        if(this->top == -1)
        {
            return true;
        }
        return false;
    }

    int peek()
    {
        if(this->isempty() == true)
        {
            return -1;
        }
        else 
        {
            return this->stack[ this->top ]; 
        }
    }

    void push(int val)
    {
        if(this->isfull() == true)
        {
            cout << "stack overflow";
        }
        else 
        {
            this->top++;
            int r = this->top; // 0
            this->stack[r] = val; 
        }
    }

    int pop()
    {
        if(this->isempty() == true)
        {
            cout << "stack underflow"; 
            return -1; 
        }
        else 
        {
            int r = this->stack[this->top]; //  
            this->top--; // 3
            return r;
        }
    }

};


struct que2stack
{
    struct stackARR *s1 =  new stackARR();
    struct stackARR *s2 =  new stackARR();
    
    void quesize(int n)
    {
        s1->stacksize(n);
        s2->stacksize(n);
    }

    void enq(int val)
    {
        // s1 is CF and s2 is PF 
        if(s1->isfull() == true && s2->isempty() == false )
        {
            cout << "q is full";
        }
        // s1 is CF and s2 is CE 
        else if(s1->isfull() == true && s2->isempty() == true)
        {
            // transfer the ele from s1 to s2 
            while(s1->isempty() != true)
            {
                int p_ele = s1->pop();
                s2->push(p_ele);
            } 
            s1->push(val);
        }
        else 
        {
            s1->push(val);
        }

        // 


    }
    
    int deq()
    {
        // s1 is CE and s2 is CE 
        if(s1->isempty() == true && s2->isempty() == true)
        {
            cout << "no ele";
            return -1;
        }
        // 
        else if( s1->isempty() == false   && s2->isempty() == true) 
        {
             // transfer the ele from s1 to s2 
            while(s1->isempty() != true)
            {
                int p_ele = s1->pop();
                s2->push(p_ele);
            } 
            int d = s2->pop();
            return d;
        }
        else 
        {
            int e = s2->pop();
            return e;
        }
    }

    bool isempty()
    {
        if(s1->isempty() == true && s2->isempty() == true)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    bool isfull()
    {
        // s1 is CF and s2 is PF
        if(s1->isfull() == true && s2->isempty() != true)
        {
            return true;
        } 
        else 
        {
            return false;
        }
    }

    int peek()
    {
        if(s1->isempty() == true && s2->isempty() == true)
        {
            cout << "mpt";
            return -1;
        }
        else if(s1->isempty() != true && s2->isempty() == true)
        {
            while(s1->isempty() == false)
            {
                int t = s1->pop();
                s2->push(t);
            }
            return s2->peek();
        }
        else 
        {
            return s2->peek();
        }
    }
};



int main()
{
    struct que2stack *t = new que2stack();
    t->quesize(3); 
    int queries;
    cin >> queries; 

    for(int i = 0; i < queries; i++)
    {
        int num;
        cin >> num;
        if(num == 1)
        {
            int val;
            cin >> val;
            t->enq(val);
        }
        else if(num == 2)
        {
            t->deq();
        }
        else 
        {
            cout << t->s2->peek();
        }
    }

}