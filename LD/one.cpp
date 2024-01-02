#include<iostream> 
using namespace std;


struct Node
{
        int value;
        Node  *next_address = NULL;
};

struct SingleLL 
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

        void ins_beg(int val) 
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
                newnode->next_address = this->head; 
                this->head = newnode;
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
        //                  1       40
        void ins_between(int pos, int val)
        {
            if(pos == 0)
            {
                this->ins_beg(val);
            }
            else if(pos >= this->length)
            {
                this->push(val);
            }
            else 
            {
                this->length++;
                Node *bef;
                bef = this->head;// a1
                int i = 0;
                while(bef != NULL)// a1 != N
                {
                    if(pos-1 == i)
                    {
                        break;
                    }
                    i++; // 1
                    bef = bef->next_address;// a2
                }

                Node *aft;
                aft = bef->next_address;// null

                Node *newnode = new Node();
                newnode->value = val;


                newnode->next_address = aft;
                bef->next_address = newnode;

            }

        }

        int del_beg()
        {
            int res = -1;
            if(this->isempty() == true)
            {
                cout << " no ele ";
            }
            else if(this->head->next_address == NULL)
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
                this->length--;
                Node *t;
                t = this->head;
                this->head = this->head->next_address;
                t->next_address = NULL;
                res = t->value;
            }

            return res;
        }
 
        int del_end()
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
                ///   a0 --a1 --a2 --a3
                //              b
                //i   0    1    2
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
        //              2
        int del_btw(int pos)
        {

            Node *bef;
            bef = this->head;// a0
            int i = 0;  // bef --> a1
            while(bef != NULL)// a1 != N
            {
                if(pos-1 == i)// 1==1
                {
                    break;
                }
                i++; // 1
                bef = bef->next_address;// a1
            }
            // bef --> a1
            Node *aft, *posnode;
            posnode = bef->next_address; // a2
            aft = bef->next_address->next_address; // a3

            bef->next_address = aft;
            posnode->next_address = NULL;

            int res = posnode->value;
            this->length--;
            return res;

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
    struct SingleLL *r = new SingleLL();
    struct SingleLL t = SingleLL();
    struct SingleLL a[6];
    a[0].push(10);
    a[0].push(20);
    a[0].push(30);
    a[1].push(0);
    a[2].push(3);
    a[2].push(9);



}



/*
int n;
    cin >> n;
    struct SingleLL *t = new SingleLL();

    for(int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        if(t->isempty() == true)
        {
            t->push(f);
        }
        else if(f > t->head->value)
        {
            t->ins_beg(f);
        }
        else if(f < t->tail->value)
        {
            t->push(f);
        }
        else 
        {
            Node *temp = t->head;
            int i = 0; 
            while(f < temp->value)
            {
                temp = temp->next_address;
                i++;
            }
            t->ins_between(i, f);
        }


    }

*/