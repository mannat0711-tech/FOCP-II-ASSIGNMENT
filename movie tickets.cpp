#include<iostream>
#include<map>
#include<set>
using namespace std;

class MovieTicket
{
public:
    map<int,set<int> > movie;

    int BOOK(int x,int y)
    {
        if(movie[y].count(x))
            return 0;

        if(movie[y].size()==100)
            return 0;

        movie[y].insert(x);
        return 1;
    }

    int CANCEL(int x,int y)
    {
        if(movie[y].count(x)==0)
            return 0;

        movie[y].erase(x);
        return 1;
    }

    int IS_BOOKED(int x,int y)
    {
        if(movie[y].count(x))
            return 1;

        return 0;
    }

    int AVAILABLE_TICKETS(int y)
    {
        return 100-movie[y].size();
    }
};

int main()
{
    int q;
    cin>>q;

    MovieTicket obj;

    while(q--)
    {
        string s;
        cin>>s;

        if(s=="BOOK")
        {
            int x,y;
            cin>>x>>y;

            if(obj.BOOK(x,y)==1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }

        else if(s=="CANCEL")
        {
            int x,y;
            cin>>x>>y;

            if(obj.CANCEL(x,y)==1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }

        else if(s=="IS_BOOKED")
        {
            int x,y;
            cin>>x>>y;

            if(obj.IS_BOOKED(x,y)==1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }

        else if(s=="AVAILABLE_TICKETS")
        {
            int y;
            cin>>y;
            cout<<obj.AVAILABLE_TICKETS(y)<<endl;
        }
    }

    return 0;
}