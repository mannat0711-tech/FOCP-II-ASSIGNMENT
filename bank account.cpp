#include<iostream>
#include<map>
using namespace std;

class Bank
{
public:
    map<int,int> user;

    int CREATE(int x,int y)
    {
        if(user.count(x)==0)
        {
            user[x]=y;
            return 1;
        }

        user[x]=user[x]+y;
        return 0;
    }

    int DEBIT(int x,int y)
    {
        if(user.count(x)==0 || user[x]<y)
            return 0;

        user[x]=user[x]-y;
        return 1;
    }

    int CREDIT(int x,int y)
    {
        if(user.count(x)==0)
            return 0;

        user[x]=user[x]+y;
        return 1;
    }

    int BALANCE(int x)
    {
        if(user.count(x)==0)
            return -1;

        return user[x];
    }
};

int main()
{
    int q;
    cin>>q;

    Bank obj;

    while(q--)
    {
        string s;
        cin>>s;

        if(s=="CREATE")
        {
            int x,y;
            cin>>x>>y;

            if(obj.CREATE(x,y)==1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }

        else if(s=="DEBIT")
        {
            int x,y;
            cin>>x>>y;

            if(obj.DEBIT(x,y)==1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }

        else if(s=="CREDIT")
        {
            int x,y;
            cin>>x>>y;

            if(obj.CREDIT(x,y)==1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }

        else if(s=="BALANCE")
        {
            int x;
            cin>>x;

            cout<<obj.BALANCE(x)<<endl;
        }
    }

    return 0;
}