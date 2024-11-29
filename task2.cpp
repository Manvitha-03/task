#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
struct Control
{
    int id;
    string type;
    string state;
    Control(int i,const string &t,const string &s): id(i), type(t),state(s){}
};
vector <Control> v;
void add(int id,const string &type,const string &state)
{
    Control obj(id,state,type);
    v.push_back(obj);
 
}
void dispaly()
{
    for(auto const&i:v)
    {
        cout<<i.id<<" "<<i.state<<" "<<i.type<<endl;
    }
}
void find()
{
    for (auto const &i:v)
    {
        if (i.state=="Disabled"&&i.type=="Button")
        {
            cout<<i.id<<" "<<i.state<<" "<<i.type<< endl;
        }
    }
}
void findif()
{
    auto it = find_if(v.begin(), v.end(), [](const Control &c){ return c.state == "Invisible"; });
    if(it!=v.end())
    {
        cout<<"First Invsible control:"<<it->id<<" "<<it->state<<" "<<it->type<< endl;
    }
    else
    {
        cout<<"No Invisible control found"<<endl;
    }
}
void adjacentfind()
{
    auto it=adjacent_find(v.begin(),v.end(),[](const Control &a,const Control &b){return a.state==b.state;});
    if(it!=v.end())
    {
        cout<<"Found adjacent controls with same state:"<<it->id<<" "<<it->state<<" "<<it->type<<" and "<<(it+1)->id<<" "<<(it+1)->state<<" "<<(it+1)->type<< endl;
    }
}
void count()
{
    auto count1=count_if(v.begin(),v.end(),[](const Control &a){return a.state=="Visible";});
    cout<<count1<<endl;
}
int main()
{
    add(1,"Visible","Button");
    add(2, "Invisible", "Slider");  
    add(3, "Visible", "Slider");
    add(4, "Disabled", "Button");
    add(5, "Visible", "Slider");
    add(6,"Visible","Slider");
    dispaly();
    findif();
    adjacentfind();
    count();
}