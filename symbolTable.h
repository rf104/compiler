#include<bits/stdc++.h>
#define N 10
using namespace std;
ofstream out("log.txt");


class symbolInfo{

    string name,type;

public:
    
    void setsymbolName(string n)
    {
        name=n;
    }
    void setsymbolType(string t)
    {
        type=t;
    }

    string getsymbolName()
    {
        return name;
    }

    string getsymbolType()
    {
        return type;
    }

    void printsymbol()
    {
        out<<"< "<<name<<" , "<<type<< " >" <<endl;
    }

};

class symbolTable{

    vector <symbolInfo> a[N];

public:

    int gethashIndex(symbolInfo n)
    {
        return (n.getsymbolName().length() * 39) % N ;
    }


    void insertsymbol(symbolInfo n)
    {
        int index = gethashIndex(n);

        for(int i=0 ; i < a[index].size();i++)
        {
            if(n.getsymbolName()==a[index][i].getsymbolName())
                   {
                       
                       return;
                   }
        }

        a[index].push_back(n);
        printsymbol();
        
    }

    int looksymbol(string n)
    {
        int index = (n.length() * 47) % N ;

        for(int i=0; i<a[index].size(); i++)
            {
                if(n==a[index][i].getsymbolName())
                   {
                     //  out <<"Found at "<< index <<"," << i <<endl;
                       return 1;
                   }
        }
       // out <<"Not Found"<<endl;
        return 0;
    }

    void deletesymbol(string n)
    {
        int index = (n.length() * 47) % N ;

        for(int i=0 ; i < a[index].size();i++)
            {
                if(n==a[index][i].getsymbolName())
                    {
                        cout <<"Deleted from "<< index <<"," << i <<endl;

                        a[index].erase(a[index].begin() + i);
                        return;
                   }
            }
        cout <<"Doesn't Exist"<<endl;
    }

    void printsymbol()
    {
        for(int i=0 ; i < N;i++)
        {
            out<< i << "->" ;
            for(int j=0 ; j < a[i].size();j++)
            {
                out<<" <"<< a[i][j].getsymbolType() << "," <<a[i][j].getsymbolName()<< "> ";
            
            }
            out<<endl;
        }
    }


};

/*

int main()
{

    symbolInfo arr;
    symbolTable brr;
    string n,t;

    string c;

    while(in >> c)
    {

        if(c=="I")
        {
            in>>n>>t;
            arr.setsymbolName(n);
            arr.setsymbolType(t);

            brr.insertsymbol(arr);
        }

        if(c=="P")
        {
            brr.printsymbol();
        }

        if(c=="L")
        {
            in>>n;
            brr.looksymbol(n);
        }

        if(c=="D")
        {
            in>>n;
            brr.deletesymbol(n);
        }

    }
}

*/
