#include<bits/stdc++.h>
using namespace std;

class Box{
  int l,b,h;
 public:
    Box();
    Box(int a,int br,int c):l(a),b(br),h(c)
    { }
    Box(const Box&);
    int getLength(){ return this->l;} // Return box's length
    int getBreadth (){ return this->b;} // Return box's breadth
    int getHeight (){ return this->h;}  //Return box's height
    long long CalculateVolume(){ return (long long)l*b*h; } ; // Return the volume of the box
    /* Operator Overloading */
    bool operator<(const Box& b);
    friend ostream& operator<<(ostream& out, Box& B)
    {
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};
Box::Box()
{
    this->l = 0;
    this->b = 0;
    this->h = 0;
}
Box::Box(const Box& bx)
{
    this->l = bx.l;
    this->b = bx.b;
    this->h = bx.h;
}
bool Box::operator<(const Box& bx)
{
    if(this->l < bx.l) return true;
    else if(this->b < bx.b && this->l == bx.l) return true;
    else if(this->h < bx.h && this->l == bx.l && this->b == bx.b) return true;
    else return false;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
