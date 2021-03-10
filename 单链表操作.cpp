#include<iostream>
using namespace std;

#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef int status;
typedef int ElemType;

typedef struct lnode
{
	ElemType date;
	struct lnode *next;
}LNode,*LinkList;

//初始化头节点
status initList(LinkList &La)
{
	La=new LNode;
	La->next=NULL;
	return OK;
} 

//创建单链表
status CreatList(LinkList &La,ElemType a[],int n)
{
	LNode *s,*r;
	int i;
	r=La;
	for(i=0;i<n;i++)
	{
		s=new LNode;
		s->date=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return OK;
} 
//销毁退出 
status destroy(LinkList &La)
{
	LNode *p;
	while(La!=NULL)
	{
		p=La;
		La=La->next;
		delete p;
	}
	return OK;
}
//输出元素
void  output(LinkList La)
{
    LNode *p=La->next;
	if(La->next==NULL)
	cout<<"该链表为空链表";
	while(p!=NULL)
	{
		cout<<p->date<<' ';
		p=p->next;
	}	
} 
//按序号查找 
status findlist1(LinkList La,int n,int &e)
{
	LNode *p=La->next;
	int j=1;
	while(p&&j<n)
	{
		p=p->next;
		j++;
	}
	if(!p||j>n)
	return ERROR;
	e=p->date;
	return OK;
} 
//按值查找
void findlist2(LinkList La,int e)
{
	LNode *q;
	int i=1;
	q=La->next;
	while(q&&q->date!=e)
	{
		q=q->next;
		i++;
	}
	if(q!=NULL)
	  cout<<e<<"为第"<<i<<"个元素";
	else
	  cout<<"查找元素不存在";
} 
//插入元素
status Insertlist(LinkList &La,int e,int i)
{
	LNode *p=La,*s;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next; 
		j++;
	}
	if(p==NULL||j>i+1)
	return ERROR;
	s=new LNode;
	s->date=e;
	s->next=p->next;
	p->next=s;
	return OK;
} 
//删除元素
void Listdelete(LinkList &La,int i)
{
	LNode *p=La,*q;
	int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if((p->next==NULL)||j>i-1)
	cout<<"删除的元素不存在";
	q=p->next;
	p->next=q->next;
	delete q;
	cout<<"执行成功"; 
} 
//求表长
void ListLength(LinkList La)
{
	LNode *p=La->next;
	int len=0;
	while(p!=NULL)
	{
		len++;
		p=p->next;
	}
	cout<<"表长为："<<len;
} 
//输出最大值
int Maxone(LinkList La)
{
	LNode *m=La->next;
	int max;
	max=m->date;
	while(m->next!=NULL)
	{
		m=m->next;
		if(m->date>max)
		max=m->date;
	};
    return max;
} 
//删除区域元素
status Deletearea(LinkList &La,int x,int y)
{
	LNode *p=La->next,*q,*m,*n,*d;
	while(p!=NULL)
	{
		if(p->date==x)
		q=p;
		if(p->date==y)
		m=p;
		p=p->next;
	}
	n=q->next;
	q->next=m;
	do
	{
		d=n;
		n=n->next;
		delete d;
	}while(n->date==m->date);
	return OK;
} 
//清空单链表
status ClearList (LinkList &La)
{
	LNode *p,*q;
	p=La->next;
	while(p!=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
	La->next=NULL;
	return OK;
}

int main(void)
{
	LinkList La;
	int i,n;
	ElemType a[MAXSIZE];
	initList(La);
	cout<<"请输入元素个数：";
	cin>>n;
	if(n!=0)
	cout<<"请输入元素：";
	for(i=0;i<n;i++)
	cin>>a[i];
	CreatList(La,a,n);
	cout<<endl;
	cout<<"提示："<<endl;
	cout<<"1-输出元素，2-按序号查找，3-按值查找，4-插入元素，5-删除元素"<<endl;
	cout<<"6-单链表长度，7-输出最大值，8-删除区域元素，9-清空链表，0-退出程序"<<endl;
	cout<<endl;
	
	int f;
do
{
	cout<<"请输入操作符：";
	cin>>f;
	switch(f)
	{
		case 0:                         //销毁退出 
			{
				destroy(La);
				cout<<"谢谢使用"; 
				break;
			}
		case 1:                         //输出 
			{
				output(La);
				cout<<endl;
		        break;
			}
		case 2:                        //按序号查找 
			{
				int n,e;
				cout<<"请输入查找元素的序号：";
				cin>>n;
				findlist1(La,n,e);
				cout<<"第"<<n<<"号元素为："<<e; 
				cout<<endl;
		        break;
			}
			case 3:                   //按值查找 
				{
					int e;
					cout<<"请输入查找的元素：";
					cin>>e;
					findlist2(La,e);
					cout<<endl;
					break;
			    }
			case 4:                    //插入元素 
				{
					 int e,i;
					 cout<<"请输入插入元素：";
					 cin>>e;
					 cout<<"请输入插入位置：";
					 cin>>i;
					 Insertlist(La,e,i) ;
					 cout<<"执行成功";
					 cout<<endl;
					 break;
				}
			case 5:                  //删除元素
			    {
			    	int i;
			    	cout<<"请输入删除元素序号：";
			    	cin>>i;
			    	Listdelete(La,i);
			    	cout<<endl;
			    	break;
			    }
			case 6:                  //求表长
			    {
			    	ListLength(La);
			    	cout<<endl;
			    	break;
			    } 
			case 7:                 //输出最大值
			    {
			    	int max;
			    	max=Maxone(La);
			    	cout<<"表中最大元素为："<<max;
			    	cout<<endl;
			    	break;
			    } 
			    case 8:              //删除区域元素
				{
					int x,y;
					cout<<"请输入删除范围：";
					cin>>x>>y;
					Deletearea(La,x,y);
					cout<<"执行成功";
					cout<<endl;
					break;
				} 
				case 9:               //清空单链表
				{
					ClearList(La);
					cout<<"执行成功";
					cout<<endl;
					break;
				} 
			
		default:cout<<"输入有误";cout<<endl;break;
	}
    cout<<endl;
}while(f!=0);
	
	return 0;
} 
