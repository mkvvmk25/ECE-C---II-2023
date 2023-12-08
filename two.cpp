#include<iostream> 
using namespace std;


struct Node
{
        Node  *bef_address = NULL;
        int value;
        Node  *next_address = NULL;
};

struct DoubleLL
{
        Node *head = NULL;
        Node *tail = NULL;
        int length = 0;

        bool isempty()
        {
            if(this->head == NULL && this->tail == NULL)
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
                head->bef_address = newnode; // *****
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
                newnode->bef_address = this->tail;
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

                newnode->next_address = aft; // a10->n = a4
                bef->next_address = newnode; // a3->n = a10


                newnode->bef_address = bef;
                aft->bef_address = newnode;


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
                t = this->tail;
                this->head = NULL;
                this->tail = NULL;
                res = t->value;
            }
            else 
            {
                Node *t;
                t = this->head;
                this->head = this->head->next_address;

                t->next_address = NULL;
                head->bef_address = NULL; 

                res = t->value;
                this->length--;
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
                bef = this->tail->bef_address; // a10 

                Node *t = this->tail; // a4
                bef->next_address = NULL;
                res= this->tail->value;
                this->tail = bef;
                t->bef_address = NULL;
                this->length--;
            }

            return res;
        }
        //              2
        int del_btw(int pos)
        {
            int res = -1;
            if(pos == 0)
            {
                res = this->del_beg();
            }
            else if(pos >= this->length-1)
            {
                res = this->del_end();
            }
            else 
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

                bef->next_address = aft; // a1 -> a3
                posnode->next_address = NULL; //


                aft->bef_address = bef; 
                posnode->bef_address = NULL;


                res = posnode->value;
                this->length--;
                
            }
            return res;
        }   

        void printLL(int dir)
        {
            if(dir == 1)
            {
                Node *temp;
                temp = this->head; 
                while ( temp != NULL )
                {

                    cout << temp->value << ", ";   ///        1
                    temp = temp->next_address;    // 
                }
            }
            else 
            {
                Node *temp;
                temp = this->tail; // a4
                while ( temp != NULL )
                {

                    cout << temp->value << ", ";   ///        1
                    temp = temp->bef_address;    // 
                }
            }

        }

};

int main()
{

}