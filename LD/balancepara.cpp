#include<iostream>
using namespace std;
#include<vector> 

struct stackARR 
{
    char *stack; 
    int top = -1; 
    int length = 0;

    void stacksize(int siz)
    {
        this->length = siz;
        this->stack = new char[siz];
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

    char peek()
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

    char pop()
    {
        if(this->isempty() == true)
        {
            cout << "stack underflow"; 
            return '\0'; 
        }
        else 
        {
            char r = this->stack[this->top]; //  
            this->top--; // 3
            return r;
        }
    }

    int check_para(char close[], char br)
    {
        for (int i = 0; i < 3; i++)
        {
            if(br == close[i])
            {
                return i;
            }
        }
        return -1;
    }

    bool bal_para(string s) // ({}[]) 
    {
        char open[3] =  {'[', '(', '{' };

        char close[3] = {']', ')', '}' };

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '{' || s[i] == '(' ||
             s[i] == '[')
             {
                this->push(s[i]);
             }
             else 
             {
                //   }
                // check s[i] ind in close
                int ind = check_para(close, s[i] );
                if( open[ind] == this->peek() )
                {
                    this->pop();
                }
                else 
                {
                    return false;
                }
             }
        }

        return true;



    }
   

    //  ([(}{})])

};

int main()
{
    string n;
    cin >> n;
    struct stackARR *t = new stackARR();
    t->stacksize(100);

    t->bal_para(n);

   
    int arr[5];

}