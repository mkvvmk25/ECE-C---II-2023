#include<iostream>
#include<vector>
using namespace std;
struct UDGraph
{
    int vertex = 0;
    int edges = 0;
    vector<vector<int>> *mat; 
    void init_graph(int ver)
    {
        this->vertex = ver;
        this->mat = new vector<vector<int>>(ver, vector<int>(ver,0));
    }
    void connect_edge(int from, int to, int weight)
    {
        this->mat->at(from).at(to) = weight;
        this->mat->at(to).at(from) = weight;
        this->edges = this->edges + 2;
    }
    void print_graph()
    {
        for(int i = 1; i < this->vertex+1; i++)
        {
            for(int j = 1; j < this->vertex+1; j++)
            {
                cout << mat->at(i).at(j) << " ";
            }
            cout << "\n";
        }
    }
};
struct UDGraphLL
{
    int vertex = 0;
    int edges = 0;
    vector<vector<int>> *mat; 
    void init_graph(int ver)
    {
        this->vertex = ver;
        this->mat = new vector<vector<int>>(ver);
    }
    void connect_edge(int from, int to)
    {
        this->mat->at(from).push_back(to);
        //             1        0   
        this->mat->at(to).push_back(from);
        this->edges = this->edges + 2;
    }
    void print_graph()
    {
        mat->at(2).size();// 2

        for(int i = 0; i < this->vertex; i++)
        {
            cout << i; 
            for(int j = 0; j < mat->at(i).size(); j++)
            {
                cout <<"->"<< mat->at(i).at(j) << " ";
            }
            cout << "\n";
        }
    }
};

struct DGraph
{
    int vertex = 0;
    int edges = 0;
    vector<vector<int>> *mat; 
    void init_graph(int ver)
    {
        this->vertex = ver;
        this->mat = new vector<vector<int>>(ver+1, vector<int>(ver+1,0));
    }
    void connect_edge(int from, int to,int weight )
    {
        this->mat->at(from).at(to) = weight;
        this->edges = this->edges + 1;
    }

    void print_graph()
    {
        for(int i = 1; i < this->vertex+1; i++)
        {
            for(int j = 1; j < this->vertex+1; j++)
            {
                cout << mat->at(i).at(j) << " ";
            }
            cout << "\n";
        }
    }
};



int main()
{
    // vector<vector<int>> *t;
    // t = new vector<vector<int>>(3); 
    struct UDGraphLL *t = new UDGraphLL();
    t->init_graph(5);
    t->connect_edge(1,0);
    t->connect_edge(2,4);
    t->connect_edge(3,2);
    t->connect_edge(1,4);
    t->connect_edge(4,3);


}

/*
int n, ed;
    string g;
    cin >> n >> ed;
    cin >> g;
    if(g.compare("yes") == 0)
    {
        struct DGraph *t = new DGraph();
        t->init_graph(n);
        for(int i = 0; i < ed; i++)
        {
            int p,q,r;
            cin >> p >> q >> r; 
            t->connect_edge(p,q,r);
        }

        t->print_graph();
    }
    else 
    {
        struct UDGraph *t = new UDGraph();
        t->init_graph(n);
        for(int i = 0; i < ed; i++)
        {
            int p,q,r;
            cin >> p >> q >> r; 
            t->connect_edge(p,q,r);
        }

        t->print_graph();
    }
    string h = "yes";
    cout << h.compare("yew");
*/