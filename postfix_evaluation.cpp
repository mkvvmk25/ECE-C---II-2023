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

    void push(char val)
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
            return '\0'; 
        }
        else 
        {
            int r = this->stack[this->top]; //  
            this->top--; // 3
            return r;
        }
    }

    int postevauation(string arr[] , int n)
    {   //    10  5 
        //           *
        for(int i = 0; i<n;i++)
        {
            if(arr[i][0] >= '0' && arr[i][0] <= '9'  )
            {
                int a = stoi(arr[i]); 
                this->push(a);
            }
            else 
            {
                int fp = this->pop();
                int sp = this->pop();
                int r;
                switch(arr[i][0])//'+'
                {
                    case '+': r = sp + fp;
                              break;
                    case '-': r = sp - fp;
                              break;
                    case '*': r = sp * fp;
                              break;
                    case '/': r = sp / fp;
                              break;
                    case '%': r = sp % fp;
                              break;
                }
            this->push(r);

            }

        }

        cout << this->peek();
    }
};

int main()
{
    string n;
    getline(cin, n); 
    string g = "";
    string s[100];
    int ind = 0;
    for(int i = 0; i < n.length(); i++)
    {
        if(n[i] != ' ')
        {
            g = g + n[i]; // "10"
        }
        else 
        {
            s[ind] = g;
            ind++;
            g = "";
        }
    }
    
    s[ind] = g;
    struct stackARR *t = new stackARR();
    t->stacksize(100);
    t->postevauation(s,ind+1);


    //  "123" "2" "3" "+" "*"
    //   0    1   2   3   4





}