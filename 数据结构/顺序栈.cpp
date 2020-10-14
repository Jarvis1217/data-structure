#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	int *base;
	int *top;
}sqstack;

Status initstack(sqstack &s)
{
	s.base=new int[MAXSIZE];
	if(!s.base) exit(OVERFLOW);
	s.top=s.base;
	return OK;
}
//入栈 
Status push(sqstack &s,int e)
{
	if(s.top-s.base==MAXSIZE)
	return ERROR;
	*s.top=e;
	s.top++;
	return OK;
}
//出栈 
Status pop(sqstack &s,int &x)
{
	if(s.top==s.base)
	{
		cout<<"stack is empty"<<endl;
		return ERROR;
	}
	s.top--;
	x=*s.top;
	return OK;
}
//取栈顶
int gettop(sqstack s)
{
	if(s.top!=s.base)
	return *(s.top-1);
} 
//求栈的长度 
int stacklen(sqstack s)
{
	int *dis,length=0;
	dis=s.top;
	while(dis!=s.base)
	{
		dis--;
		length++;
	}
	return length;
} 
//输出栈元素
Status dispstack(sqstack s)
{
	int *p;
	p=s.top;
	if(p==s.base) return ERROR;
	cout<<"All data is:";
	while(p!=s.base)
	{
		p--;
		cout<<*p<<' ';
	}
	return OK;
} 
//清空栈
Status clearstack(sqstack &s)
{
	s.top=s.base;
	return OK;
} 
//
Status destorys(sqstack &s)
{
	delete []s.base;
	s.top=s.base=NULL;
	return OK;
}

int main(void)
{
	int k;
	sqstack s;
	initstack(s);
	cout<<"Tip:0-exit;1-push;2-pop;3-get top"<<endl;
	cout<<"    4-get length;5-disp;6-clear"<<endl;
	cout<<endl;
	
	do
	{
		cout<<"Enter your option:";
	    cin>>k;
		switch(k)
		{
			case 1:
				{
					int e;
					cout<<"Enter:";
					cin>>e;
					push(s,e);
					cout<<"OK"<<endl;
					cout<<endl;
					break;
				}
			case 2:
				{
					int x,q;
					q=pop(s,x);
					if(q==1)
					cout<<"Top one is:"<<x<<endl;
					cout<<endl;
					break;
				}
			case 3:
				{
					int top;
					top=gettop(s);
					cout<<"Top data is:"<<top<<endl;
					cout<<endl;
					break;
				} 
			case 4:
				{
					int length;
					length=stacklen(s);
					cout<<"stack length is:"<<length<<endl;
					cout<<endl;
					break;
				}
			case 5:
				{
					int q;
					q=dispstack(s);
					if(q==0)
					cout<<"stack is empty";
					cout<<endl<<endl;
					break;
				}
			case 6:
				{
					clearstack(s);
					cout<<"OK"<<endl;
					cout<<endl;
					break;
				}
			case 0:
				{
					destorys(s);
					cout<<"OK"<<endl;
					cout<<endl;
					break;
				}
			default:cout<<"Enter is wrong"<<endl<<endl;break;	
		}
	}while(k!=0);
	return 0;
}
