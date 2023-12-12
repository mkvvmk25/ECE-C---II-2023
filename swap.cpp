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
        void ins_between(int pos, int val, Node *add)
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

                Node *newnode = add; 
                newnode->value = val;


                newnode->next_address = aft;
                bef->next_address = newnode;

            }

        }

        int del_beg()
        {
            Node *t;
            int res = -1;
            if(this->isempty() == true)
            {
                cout << " no ele ";
            }
            else if(this->head->next_address == NULL)
            {
                this->length--;
                t = head;
                this->head = NULL;
                this->tail = NULL;
                res = t->value;
            }
            else 
            {
                this->length--;
                t = this->head;
                this->head = this->head->next_address;
                t->next_address = NULL;
                res = t->value;
            }

            return res;
        }
 
        int del_end()
        {
            Node *t;
            int res = -1;
            if(this->isempty() == true)
            {
                cout << " no ele ";
            }
            else if(this->length == 1)
            {
                this->length--;
                
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

                t = bef->next_address; // a3
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
            if(pos == 0)
            {
                return this->del_beg();
            }
            else if( pos >= this->length-1)
            {
                return this->del_end();
            }
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

        void swap(int num1, int num2)
        {   
            int fst_pos, sec_pos;
            Node *t1 = NULL, *t2 = NULL; 

            Node *temp = this->head;
            int i = 0;
            while(temp != NULL)
            {
                if(num1 == temp->value)
                {
                    fst_pos = i;
                    t1 = temp;
                }
                else if(num2 == temp->value)
                {
                    sec_pos = i;
                    t2 = temp;
                }
                i++;
                temp = temp->next_address; 
            }
    
            // delete 

            this->del_btw(fst_pos);
            this->del_btw(sec_pos-1);

            this->ins_between(fst_pos, t2->value, t2);
            this->ins_between(sec_pos, t1->value, t1); 
            
        }

        void reverseLL()
        {
            
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
    struct SingleLL *k = new SingleLL();
    k->push(1);
    k->push(2);
    k->push(3);
    k->push(4);
    k->push(5);
    k->push(6);
    k->printLL();
    cout<<"\n";
    k->swap(1,6);
    k->printLL();
}