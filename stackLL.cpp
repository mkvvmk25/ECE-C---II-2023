#include<iostream> 
using namespace std;


struct Node
{
        int value;
        Node  *next_address = NULL;
};

struct StackSingleLL 
{
        Node *head = NULL; 
        Node *tail = NULL; 
        int length = 0; 

        bool isempty()
        {
            if(this->head == NULL)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
     
        void push(int val) 
        {
            Node *newnode  = new Node();
            this->length += 1;
            newnode->value = val; 
            if( this->isempty() == true)
            {
                this->head = newnode;
                this->tail = newnode;
            }
            else 
            {
                this->tail->next_address = newnode;
                this->tail = newnode; 
            }

        }
 
        int pop()
        {
            int res = -1;
            if(this->isempty() == true)
            {
                cout << " no ele ";
            }
            else if(this->length == 1)
            {
                this->length--;
                Node *t;
                t = head;
                this->head = NULL;
                this->tail = NULL;
                res = t->value;
            }
            else 
            {
                
                Node *bef;
                bef = this->head;// a0
                int i = 0;
                while(bef != NULL)// a2 != N
                {
                    if(this->length-2 == i)// 2==2
                    {
                        break;
                    }
                    i++; // 1
                    bef = bef->next_address;// a2
                }

                Node *t = bef->next_address; // a3
                bef->next_address = NULL;
                res= this->tail->value;
                this->tail = bef;
                this->length--;
            }

            return res;
        }

        int peek()
        {
            if(this->isempty() == true)
            {
                return -1;
            }
            return this->tail->value;
        }

        void printLL()
        {
            Node *temp;
            temp = this->head; 
            while ( temp != NULL )
            {

                cout << temp->value << ", ";   ///        1
                temp = temp->next_address;    // 
            }

        }

};

int main()
{
    char n;
    int num;
    struct StackSingleLL *stackLink = new StackSingleLL();
    cin >> num;
    stackLink->push(num);
    cin >> n; // y 


    while(n != 'N')
    {

        cin >> num;
        stackLink->push(num);
        cin >> n;
    }
    cout << "stack elements\n";
    while( stackLink->isempty() != true)
    {
        int g = stackLink->pop(); 
        cout << g << "\n";
    }
}

/*
    20
    y
    45
    y
    89
    y
    65
    n
*/


