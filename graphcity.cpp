#include<iostream>
#include<cstring>	
using namespace std;
class cities
{
	int **g;
	char **city;
	int v,e,s,d,distance;
	public:
		void accept()
		{
        cout<<"Enter the number of cities"<<endl;
		cin>>v;
		city=new char*[20];
		for(int i=0;i<v;i++)
		{
			city[i]=new char[v];
		}
		g=new int*[v];
			for(int i=0;i<v;i++)
		{
			g[i]=new int[v];
		}
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				g[i][j]=0;
			}
		}
	}
	void cityes()
	{
		cout<<"Enter the cities one by one"<<endl;
		for(int i=0;i<v;i++)
		{
			cin>>city[i];
		}
		cout<<"The cities in order of entry are"<<endl;
		for(int i=0;i<v;i++)
		{
			cout<<city[i]<<"-"<<i+1<<endl;
		}
	}
	void airport()
	{
		cout<<"Enter the total connective paths"<<endl;
		cin>>e;
		for(int i=0;i<e;i++)
		{
		cout<<"Enter the connective path"<<" "<<i+1<<" by number"<<endl;
		cin>>s>>d;
		cout<<"Enter the time in minutes"<<endl;
		cin>>distance;
		g[s-1][d-1]=distance;
	}
	}
	void displaybymatrix()
	{
		cout<<"The adjacency matrix is"<<endl;
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				cout<<g[i][j]<<'\t';
			}
			cout<<endl;
		}	
	}
};
class gnode
{
	friend class graph;
	char data[50];
	int fuel;
	gnode *next;
};
class graph
{
	char city[50],connect[50];
	int v,e,connectno,f;
	gnode **headnodes, *curr, *prev;
	public:
	void create()
	{
		cout<<"Enter the number of cities"<<endl;
		cin>>v;
		headnodes=new gnode*[v];
		for(int i=0;i<v;i++)
		{
		    headnodes[i]=new gnode[v];
		}
		for(int i=0;i<v;i++)
		{
		  cout<<"Enter the city"<<" "<<i+1<<endl;
		  cin>>city;
			strcpy(headnodes[i]->data,city);
			
			cout<<"Enter the number of cities connected to"<<" "<<city<<endl;
			cin>>connectno;
			prev=headnodes[i];
			for(int i=1;i<=connectno;i++)
			{
				curr=new gnode;
			cout<<"Enter the connected city"<<i<<endl;
			cin>>connect;
			cout<<"Enter the fuel required"<<endl;
			cin>>f;
			strcpy(curr->data,connect);
			curr->fuel=f;
			curr->next=NULL;
			while(prev->next!=NULL)
			{
			    prev=prev->next;
			}
			prev->next=curr;
	    if(connectno==0)
	    {
	        prev->next!=NULL;
		}
			}
  	}
	}
  	void display()
  	{
  	    int i=0;
  	    cout<<"The adjacency list is"<<endl;
  	    while(i!=v)
  	    {
  	         gnode *temp=headnodes[i];
  	    while(temp->next!=NULL)
  	    {
  	        cout<<temp->data<<"("<<temp->fuel<<")"<<"->";
  	        temp=temp->next;
  	    }
  	    cout<<temp->data<<"("<<temp->fuel<<")"<<endl;
  	    i++;
  	    }
  	}
  };
int main()
{
cities c;
graph g;
int ch;
char repeat;
cout<<"Welcomme to Cities and their Airports Connection"<<endl;
do
{
cout<<"1.Matrix form for time between 2 cities"<<endl;
cout<<"2.List form for fuel between 2 cities"<<endl;
cout<<"Enter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
c.accept();
c.cityes();
c.airport();
c.displaybymatrix();
break;
case 2:
	g.create();
	g.display();
	break;
	default:
		cout<<"Invalid choice"<<endl;
		break;
	}
	cout<<"Do you want to repeat?Enter y for Yes"<<endl;
	cin>>repeat;
}
while(repeat=='y'||repeat=='Y');
return 0;
}
