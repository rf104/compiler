#include<bits/stdc++.h>
using namespace std;
int a[10];
int HashTableSize = 61;
int T;

int Hash(string sym)
{
    int l = sym.length();
    int i ;
    int s = 0;
    for(i= 0;i<l;i++)
    {
        int u = sym[i];
        s = s + u;
    }
    int r  = (s * 56) % 10;
    return r;
}

class Symbolinfo{
    string name ,symbol_type;
    public:
    Symbolinfo()
    {
        this->name = "";
        this->symbol_type ="";
    }
    Symbolinfo(string a, string b)
    {
        this->name = a;
        this->symbol_type =  b;
    }
    string getName()
    {
        return this->name;
    }
    string getType()
    {
        return this->symbol_type;
    }
    void display()
    {
        int y = Hash(this->name);
        cout<<"<"<<this->name<<","<<this->symbol_type<<">";
    }
};

class SymbolTable{
    map<int,vector<Symbolinfo>>ht;
    public:
    void print()
    {
        for (auto it = ht.begin(); it!= ht.end(); it++)
        {
            cout<<it->first<<"\n";
        }
    }
    void insrt(Symbolinfo obj1)
    {
        int y = Hash(obj1.getName());
        ht[y].push_back(obj1);
        cout<<"Inserted at Position "<<y<<","<<ht[y].size() -1 <<"\n";
    }
};


int main()
{
    while(1)
    {
        string a1,b1,c1;
        cin>>a1>>b1>>c1;
        if(a1=="I"){
            Symbolinfo obj1(b1,c1);
            SymbolTable t1;
            t1.insrt(obj1);
        }
        else if(a1=="P")
        {

        }
        else if(a1=="L")
        {

        }
        else if(a1=="D")
        {
            
        }
    }


}