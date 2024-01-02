#include<iostream> 
using namespace std;


struct Node
{
        int value;
        Node  *next_address = NULL;
};

struct SingleCircularLL 
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
                this->tail->next_address = newnode; 
                newnode->next_address = newnode; 
            }
            else 
            {
                Node *bef = this->tail;
                Node *aft = this->head;
                newnode->next_address = aft;
                bef->next_address = newnode; 
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
                Node *bef = this->tail;
                Node *aft = this->head;
                newnode->next_address = aft;
                bef->next_address = newnode; 
                this->tail = newnode; 
            }

        }
        
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
                bef = this->head;// a0
                int i = 0;
                while(bef != this->tail)// a0 != N
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
            while ( temp != this->tail )
            {

                cout << temp->value << ", ";   ///        1
                temp = temp->next_address;    // 
            }
            cout << this->tail->value << " ";

        }

};






int main()
{

}