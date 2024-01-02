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

    int ch_rank(char ch)
    {
        if(ch == '^')
        {
            return 4;
        }
        else if(ch == '/' || ch == '*' || ch == '%')
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

    //  ([(}{})])

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

    for(int i = 0; i < ind+1; i++)
    {
        cout << s[i] <<"-->" << stoi(s[0])+1;
    }

}