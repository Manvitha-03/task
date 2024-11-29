#include<iostream>
#include<vector>
#include<iterator>
#include<set>
using namespace std;
void dynamicdisplay(vector <string> d)
{
    for(auto it=d.begin();it!=d.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
void staticdisplay(set <string> d)
{
    for(auto it=d.begin();it!=d.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
void staticfind(set <string> s)
{
    string ele;
    cout<<"Enter the element you want to find:";
    cin>>ele;
    if(s.find(ele)!=s.end())
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
       
    }
}
void combinedfind(vector <string> d)
{
    string ele;
    cout<<"Enter the element you want to find:";
    cin>>ele;
    bool f=false;
    for(auto it:d)
    {
        if(ele==it)
        {
            cout<<"Element found"<<endl;
            f=true;
            break;
        }
    }
    if(!f)
    {
        cout<<"Element not found";
    }
}
int main()
{
    vector <string> d;
    d.push_back("Speedometer");
    d.push_back("Techometer");
    set <string> s;
    s.insert("WarningLights");
    s.insert("Logo");
    dynamicdisplay(d);
    staticdisplay(s);
    staticfind(s);
    copy(s.begin(), s.end(), back_inserter(d));
    dynamicdisplay(d);
    combinedfind(d);
 
}