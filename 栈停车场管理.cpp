#include<iostream>
#include<iomanip>
using	namespace	std;

#define	OK	1
#define	ERROR	0

typedef	int	Status;
typedef	int	ElemType;
typedef	struct	StackNode
{
	ElemType	data;
	struct	StackNode	*next;
}StackNode,*LinkStack;

Status   Push(LinkStack	&S,ElemType	id);
Status	Pop(LinkStack	&S,ElemType	&r);
Status	GoOut(LinkStack	&S,ElemType	ID);
Status	Print(LinkStack	S);

int	main()
{
	LinkStack	S;
	S=NULL;
	int	z,id,ID;
	do{
		cout<<setw(35)<<"停车场管理"<<endl;
		cout<<"请输入命令（1、到达：2、离开：3、浏览停车场：0、退出）及车牌号"<<endl;
		cin>>z;
		switch(z){
			case	1:
				cout<<"请输入到达的汽车车牌号："<<endl;
				cin>>id;
				Push(S,id);
				break;
			case	2:
				cout<<"请输入即将离开的汽车车牌号：";
				cin>>ID;
				GoOut(S,ID);
				cout<<"该车离开后停车场剩余车辆为："<<endl;
				Print(S);
				break;
			case	3:
				if(S==NULL){
					cout<<"当前停车场为空"<<endl;
					break;
				}
				cout<<"当前停车场车辆信息为："<<endl;
				Print(S);
				break;
			 case	0:
			 	cout<<"退出管理系统"<<endl;
			 	break;
		};
	}while(z!=0);
	delete	[]S->next;
	return	0;
	 
}
Status	Push(LinkStack	&S,ElemType	id){
	LinkStack	p;
	p=new	StackNode;
	p->data=id;
	p->next=S;
	S=p;
	return	OK;
}
Status	Pop(LinkStack	&S,ElemType	&r)
{
	LinkStack	p;
	if(S==NULL){
		cout<<"停车场为空"<<endl;
		return	ERROR;
	}
	r=S->data;
	p=S;
	S=S->next;
	delete	p;
	return	OK;
}
Status	GoOut(LinkStack	&S,ElemType	ID)
{
	LinkStack	p;
	p=NULL;	
	int	e,t;
	while(S->data!=ID)
	{
		Pop(S,e);
		Push(p,e);
	}
	Pop(S,e);
	while(p)
	{
		Pop(p,t);
		Push(S,t);
	}
	return	OK;
}
Status	Print(LinkStack	S)
{
	int	e,q,i=1;
	LinkStack	p;
	LinkStack	z;
	p=NULL;
	z=S;
	while(z!=NULL)
	{
		Pop(z,e);
		Push(p,e);
	}
	while(p!=NULL){
		Pop(p,q);
		Push(z,q);
		cout<<"车牌号："<<q<<" 位置号"<<i<<endl;
		i++;
	}
	return	OK;
}
