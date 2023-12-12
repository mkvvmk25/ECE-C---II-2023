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

int main()
{
    struct stackARR *st = new stackARR(); 

    st->stacksize(5);
    st->push(10);
    st->push(20);
    st->push(30);
    st->push(40);
    st->push(50);
    st->push(60);
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();
    st->pop();

}