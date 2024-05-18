#include<bits/stdc++.h>
using namespace std;
int a[10];
int HashTableSize = 61;
int T;
ofstream out("output.txt");
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
    void setter(string a, string b)
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
        //cout<<"<"<<this->name<<","<<this->symbol_type<<">";
        out<<"<"<<this->name<<","<<this->symbol_type<<">";
    }
};

class SymbolTable{
    map<int,list<Symbolinfo>>ht;
    public:
    void print()
    {
        for (map<int,list<Symbolinfo>> :: iterator it = ht.begin(); it!= ht.end(); it++)
        {
            //cout<<"Position: "<<it->first<<"->";
            out<<"Position: "<<it->first<<"->";
            list<Symbolinfo>& value = it->second;
            for (list<Symbolinfo>::iterator it2 = value.begin(); it2 != value.end(); ++it2) {
                Symbolinfo& p = *it2;

                //cout <<"<"<<p.getName()<<","<< p.getType() <<">  ";
                out <<"<"<<p.getName()<<","<< p.getType() <<">  ";
            }
            out<<endl;
        }
    }
    void insrt(Symbolinfo obj1)
    {
        int y = Hash(obj1.getName());
        ht[y].push_back(obj1);
        //cout<<"Inserted at Position "<<y<<","<<ht[y].size() -1 <<"\n";
        out<<"Inserted at Position "<<y<<","<<ht[y].size() -1 <<"\n";
    }
    void lookup(string s)
    {
        int flg = 1;
        map<int,list<Symbolinfo>>::iterator it;
        for(it=ht.begin();it!=ht.end();it++)
        {
            list<Symbolinfo>&value = it->second;
            list<Symbolinfo>:: iterator it2 ;
            for(it2=value.begin();it2!=value.end();it2++)
            {
                Symbolinfo& p = *it2;
                if(p.getName()==s){
                    //cout<<"FOUND\n";
                    out<<"FOUND\n";
                    flg = 0;
                    break;
                }
            }
            if(flg==0) break;
        }
        if(flg==1) //cout<<"NOT FOUND\n";
        {
            out<<"NOT FOUND\n";
        }
    }

    void Delete(string s)
    {
        int flg = 1;
        map<int,list<Symbolinfo>>::iterator it;
        for(it=ht.begin();it!=ht.end();it++)
        {
            list<Symbolinfo>&value = it->second;
            list<Symbolinfo>:: iterator it2 ;
            for(it2=value.begin();it2!=value.end();it2++)
            {
                Symbolinfo& p = *it2;
                if(p.getName()==s){
                    //value.remove(s);
                    it2 = value.erase(it2);
                    flg = 0;
                    break;
                }
            }
            if(flg==0){
              //cout<<"Deleted\n";
              out<<"Deleted\n";
              break;
            }
        }
        if(flg==1) out<<"NOT FOUND\n";
    }
};


int main()
{
    SymbolTable t1;
    Symbolinfo obj1;
    ifstream in("rf.txt");
    while(1)
    {
        string a1,b1,c1;
        if(in.is_open()){
            //cin>>a1;
            in>>a1;
            if(a1=="I"){
            //cin>>b1>>c1;
            in>>b1;
            in>>c1;
            obj1.setter(b1,c1);
            t1.insrt(obj1);
            }
            else if(a1=="P")
            {
                t1.print();
            }
            else if(a1=="L")
            {
                //cin>>b1;
                in>>b1;
                t1.lookup(b1);
            }
            else if(a1=="D")
            {
                //cin>>b1;
                in>>b1;
                t1.Delete(b1);
            }
            else if(a1=="K"){
                cout<<"Invalid Input!";
                break;
            }
        }
    }
}
