#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>
using namespace std;
struct Control
{
    int id;
    string type;
    string state;
    Control(int i, const string &t, const string &s) : id(i), type(t), state(s) {}
};
list <Control> l;
list <Control> l2;
void add(int id,string type,string state)
{
    Control obj(id,type,state);
    l.push_back(obj);
}
void display()
{
    for( const auto it:l)
    {
        cout<<it.id<<" " <<it.type<<" "<<it.state<<endl;
    }
}
void copy()
{
    copy(l.begin(),l.end(),back_inserter(l2));
}
void fill()
{
    for(auto &c:l)
    {
        c.state="Disabled";
    }
}
void transform()
{
    transform(l.begin(),l.end(),l.begin(),[](Control &c){
        if(c.state=="Visible"||c.state=="Disabled")
        {
        c.state="Invisible";
           
        }
    return c;});
}
void removeif()
{
    auto it=remove_if(l.begin(),l.end(),[](const Control&c){
        return c.state=="Invisible";});
}
int main()
{
    add(1,"Button","Visible");
    add(2,"Slider","Visible");
    add(3,"Button","Invisible");
    add(4,"Slider","Invisible");
    add(5,"Button","Disabled");
    add(6,"Slider","Disabled");
    display();
    removeif();
    cout<<"After removing"<<endl;
    display();
    copy();
    cout<<"After Copying"<<endl;
    for(auto &it:l2)
    {
        cout<<it.id<<" "<<it.type<<" "<<it.state<<endl;
    }
    fill();
    cout<<"After Filling:"<<endl;
    display();
    transform();
    cout<<"After Transforming:"<<endl;
    display();
}