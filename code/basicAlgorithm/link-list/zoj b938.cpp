#include<iostream>
#define line cout<<__LINE__<<'\n';
using namespace std;

struct link_list
{
    int data;    link_list *next;
};
link_list *head = nullptr;

bool alive(int idx)
{
    int i;
    link_list *ptr;
    for(i = 0, ptr = head; i <= idx && ptr; i++, ptr = ptr->next)
    {
        // cout<<"idx : "<<i<<" vul : "<<ptr->data<<'\n';
    }
    return (i==idx+1);
}

void remove(int idx)
{
    
    int i;
    link_list *ptr, **pre;
    for(i=0, ptr = head, pre = &head; i<idx; i++)
    {
        pre = &(ptr->next);
        ptr = ptr-> next;
    }
    *pre = ptr->next;
    delete ptr;
   
}

int insert(int data,int idx)
{
    int i;
    link_list *ptr, **pre;
    for(i=0, ptr = head, pre = &head; i<idx; i++)
    {
        pre = &(ptr->next);
        ptr = ptr->next;
    }
    link_list *res = new link_list;
    res->data = data;
    res->next = ptr;
    *pre = res;
}

int main()
{
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        insert(i,i-1);
    }
    while(m--)
    {
        
        cin>>a;
        if(!alive(a)) 
        {           
            cout<<"0u0 ...... ?\n";
        }
        else
        {
            remove(a);
            cout<<a+1<<'\n';
        }
    }
}
