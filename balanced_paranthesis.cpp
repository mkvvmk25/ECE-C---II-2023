#include<iostream>
using namespace std;
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

    int ch_rank(char ch)
    {
        if(ch == '/' || ch == '*' || ch == '%')
        {
            return 3;
        }
        else if(ch == '+' || ch == '-')
        {
            return 2;
        }
        else 
        {
            return 1;
        }
    }
    
    string infix_to_post(string exp)
    {
        string post = "";
        // a/b*c+(d*(e%f)-g)%h/i  ---> 22
        //                ^ 
        for(int i = 0; i < exp.length(); i++)
        {
            char inc = exp[i];
            // 98 >=  97      98 <=  122
            if(inc >= 'a' && inc <= 'z')
            {
                post = post + inc;
            }
            else if(inc == '(')
            {
                this->push(inc);
            }
            else if(inc == ')')
            {
                while(this->peek() != '('  )
                {
                    char t = this->pop();
                    post = post + t;
                }
                this->pop();
            }
            else 
            {
                char p = this->peek(); // /
                while( this->isempty() == false &&
                    ch_rank(inc) <= ch_rank(p)    )
                {
                    // its going to pop
                    char r = this->pop();
                    p = this->peek();
                    post = post + r;
                }
                this->push(inc);
            }
        }

        // check stack is empty or nor 
        while( this->isempty() == false )
        {
            // its going to pop
            char r = this->pop();
            post = post + r;
        }

        return post;
    }


    int bal_para(string exp)
    {
        int t = exp.length(); 
        int c = 0;
        if(t%2 == 1)
        {
            return -1;
        }
        else 
        {
            for(int i = 0; i < t; i++)
            {
                if(exp[i] == '{' )
                {
                    this->push(exp[i]);
                }
                else 
                {
                    // sc1 pop + notempt 
                    if(this->isempty() == false)
                    {
                        this->pop();
                    }
                    else{
                        c++;
                    }
                }
            } 
            int pes = (this->top + 1);
            int f = (pes + c)/2;
            return f;
        }


    }
};


int main()
{
    string k = "}}{}}}}}";
    //          12345678
    struct stackARR *n = new stackARR();
    n->stacksize(100);
    n->bal_para(k);
}