#include<bits/stdc++.h>
using namespace std;
int a[10];

int Hash(string sym)
{
    int l = sym.length();
    int t = (l*202214056) % 10;
    a[t]++;
    return t;
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
        cout<<"Inserted into Hash Table!\n";
    }
};


int main()
{
    
}