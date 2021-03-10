#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
const int MAXSIZE=100;
typedef char TElemType;
typedef int  Status;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTree SElemType;

typedef struct sequencestack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

typedef struct{
	SElemType *base;
	int front;
	int rear;
}SqQueue;

void CreateBiTree(BiTree &t,char *ch);
Status InitStack(SqStack &S);
Status Push(SqStack &S,SElemType e);
Status Pop(SqStack &S,SElemType &e);
SElemType GetTop(SqStack S);
void DispBTNode(BiTree t);
BiTNode *FindNode(BiTree t,TElemType x);
void parent(BiTree t,BiTree t1,TElemType x);
void PreOrder(BiTree t);
void InOrder(BiTree t);
void PostOrder(BiTree t);
int CountLeaf(BiTree t);
int Depth(BiTree t);
void Doub(BiTree t);
int simi(BiTree t1,BiTree t2);
void findx(BiTree t);
int Findx(BiTree t);
void destroy(BiTree t);
void PrintTree(BiTree T,int nLayer);
void change(BiTree &t);
void doubleb(BiTree t);
void cOrder(BiTree t);
int NumLevel(BiTree t, int k); 
int plevel(BiTree t, int level);
void printlevel(BiTree t);

int main()
{
	int choice,h,e,d,f,k,level;char c[MAXSIZE],a[MAXSIZE];TElemType x;
	BiTree T,Ta,Tb,Tc;
	cout<<"请输入以括号法表示的树：\n";
	cin>>c;
	CreateBiTree(Ta,c);
		cout<<"  二叉树的基本操作\n";
		cout<<"      1.括号表示法输出"<<"2.横向树状输出\n"; 
		cout<<"      3.查找双亲"<<"4.查找孩子\n";
		cout<<"      5.先序遍历"<<"6.中序遍历"<<"7.后序遍历\n";
		cout<<"      8.统计叶子节点个数"<<"9.输出双分支结点\n";
		cout<<"      10.求深度"<<"11.判断两棵树是否相等\n";
		cout<<"      12.交换左右孩子"<<"13.双序遍历\n";
		cout<<"      14.按层次遍历"<<"15.求最大宽度\n";
		cout<<"      16.统计小写字母结点个数"<<"17.输出最长路径\n";
		cout<<"      18.输出叶子到根的路径"<<"19.找祖先\n";
		cout<<"      20.输出k层的结点个数\n";
		cout<<"      0.退出(销毁二叉树)\n";
	do{ 
		cin>>choice;
		switch(choice)
		{
			case 0:destroy(Ta);cout<<"Bye!"<<endl;break;
			case 1:DispBTNode(Ta);cout<<endl;break;
			case 2:cout<<"横向树状输出二叉树为：\n";PrintTree(Ta,0);break;
			case 3:cout<<"请输入要查找的结点的值\n";cin>>x;
			       Tb=FindNode(Ta,x);parent(Ta,Tb,x);break;
			case 4:cout<<"请输入要查找的结点的值\n";cin>>x;
			       Tc=FindNode(Ta,x);cout<<x<<"的左孩子为："<<Tc->lchild->data<<endl;
				   cout<<x<<"的右孩子为："<<Tc->rchild->data<<endl;break;
			case 5:PreOrder(Ta);cout<<endl;break;
			case 6:InOrder(Ta);cout<<endl;break;
			case 7:PostOrder(Ta);cout<<endl;break;
			case 8:e=CountLeaf(Ta);cout<<"二叉树中的叶子结点个数为："<<e;cout<<endl;
			break;
			case 9:Doub(Ta);cout<<endl;
			break;
			case 10:h=Depth(Ta);cout<<"二叉树的深度为："<<h;cout<<endl;
			break;
			case 11:cout<<"请输入第二棵树：\n";cin>>a;CreateBiTree(T,a);d=simi(Ta,T);
			        if(d) cout<<"相等\n";
					else cout<<"不相等\n";cout<<endl;
					break;
			case 12:change(Ta);cout<<"交换左右孩子后的二叉树为：\n";PrintTree(Ta,0);cout<<endl;
			break;
			case 13:cout<<"原二叉树为：\n";PrintTree(Ta,0);cout<<"双序遍历的结果为:\n";doubleb(Ta);cout<<endl;break;
			case 14:
			cout<<"按层次遍历的结果为："<<endl;
			printlevel(Ta);
			cout<<endl;
			break;
			case 15:break;
			case 16:cout<<"原二叉树为：\n";PrintTree(Ta,0);f=Findx(Ta);cout<<"小写字母结点个数为："<<f<<endl;break;
			case 17:break;
			case 18:break;
			case 19:break;
			case 20:
			cout<<"请输入要查找节点个数的层数k：";
			cin>>k;
			cout<<"该层有 "<<NumLevel(Ta, k)<<"个节点"<<endl;break;
			default:
			printf("请输入0~20之间的数字！\n"); 

		}
	}
	while(choice!=0);
	
	
	return 0;
}
int plevel(BiTree t, int level) 
{  
    if (!t || level < 0)  
        return 0;  
    if (level== 0 ) 
	{  
        cout << t->data << " ";  
        return 1;  
    }  
    return plevel(t->lchild, level - 1) + plevel(t->rchild, level - 1);  
}

void printlevel(BiTree t) 
{  
    int i = 0;   
    for (i = 0; ; i++) 
	{  
        if (!plevel(t, i))  
            break;  
    }  
    cout << endl;  
}  
int NumLevel(BiTree t, int k)  
{  
    if(t == NULL || k < 1)  
        return 0;  
    if(k == 1)  
        return 1;  
    int numLeft = NumLevel(t->lchild, k-1);  
    int numRight = NumLevel(t->rchild, k-1); 
    return (numLeft + numRight);  
}  
void doubleb(BiTree t)
{
	if(t)
	{
		cout<<t->data;
	    doubleb(t->lchild);
	    cout<<t->data;
	    doubleb(t->rchild);
	}
}
void change(BiTree &t)
{
	BiTree t1;
	if(t==NULL) return ;
	change(t->lchild);
	change(t->rchild);
		t1=t->lchild;
		t->lchild=t->rchild;
		t->rchild=t1;
}
void PrintTree(BiTree T,int nLayer) 
{
    int i;
	 if(T==NULL) return;
	 PrintTree(T->rchild,nLayer+3);
	 for(i=0;i<nLayer;i++)
	  cout<<' ';
	 cout<<T->data;
	 if(T->lchild&&T->rchild)
	   cout<<'<';
	 else if(T->lchild==NULL&&T->rchild!=NULL)
	   cout<<'/';
	 else if(T->lchild!=NULL&&T->rchild==NULL)
	   cout<<'\\';
	 else 
	   cout<<'-';
	 cout<<endl;
	 PrintTree(T->lchild,nLayer+3);
}
void destroy(BiTree t)
{
	if(t!=NULL)
	{
	 BiTree p;
	 destroy(t->lchild);
	 destroy(t->rchild);
	 p=t;
	 delete p;
	}	
}
int Findx(BiTree t)
{
	if(t==NULL) return 0;
	if(t->data>='a'&&t->data<='z')
	  return Findx(t->lchild)+Findx(t->rchild)+1;
}
int simi(BiTree t1,BiTree t2)
{
	int like1,like2;
	if(t1==NULL&&t2==NULL)  return 1;
	else if(t1==NULL||t2==NULL)  return 0;
	else
	{
		like1=simi(t1->lchild,t2->lchild);
		like2=simi(t1->rchild,t2->rchild);
		return (like1&like2);
	}
}
void Doub(BiTree t)
{
	if(t!=NULL)
	{
	if(t->lchild&&t->rchild)
	 cout<<t->data<<' ';
	Doub(t->lchild);
	Doub(t->rchild);
    }
}
int Depth(BiTree t)
{
	int m,n;
	if(t==NULL)  return 0;
	else{
		m=Depth(t->lchild);
		n=Depth(t->rchild);
		if(m>n)   return (m+1);
		else return (n+1);
	}
}
int CountLeaf(BiTree t)
{
	int num;
	if(t==NULL)  num=0;
	else if(t->lchild==NULL&&t->rchild==NULL)
	     num=1;
	else
	     num=CountLeaf(t->lchild)+CountLeaf(t->rchild);
	return num;
}
void CreateBiTree(BiTree &t,char *ch)
{
	BiTNode *p=NULL;   int k,j=0;
	char c; SqStack s; SElemType x;
	t=NULL; c=ch[j];  InitStack(s);
	while(c!='\0') 
	{
		switch(c)
		{
			case '(':  Push(s,p);k=1;break;
			case ')':  Pop(s,x);break;
			case ',':  k=2;break;
			default :
				p=new BiTNode;
				p->data=c;
				p->lchild=NULL;
				p->rchild=NULL;
				if(t==NULL)
				   t=p;
				else
				{
					switch(k)
					{
						case 1:x=GetTop(s);x->lchild=p;break;
						case 2:x=GetTop(s);x->rchild=p;break;
					}
				}
		}
		j++;c=ch[j];
	}
}
void PreOrder(BiTree t)
{
	if(t)
	{
		cout<<t->data;
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}
void InOrder(BiTree t)
{
	if(t)
	{
		InOrder(t->lchild);
		cout<<t->data;
		InOrder(t->rchild);
	}
}
void PostOrder(BiTree t)
{
	if(t)
	{
		InOrder(t->lchild);
		InOrder(t->rchild);
		cout<<t->data;
	}
}
void DispBTNode(BiTree t)
{
	if(t!=NULL)
	{
		cout<<t->data;
		if(t->lchild!=NULL||t->rchild!=NULL)
		{
			cout<<'(';
			DispBTNode(t->lchild);
			if(t->rchild!=NULL)
			   cout<<',';
			DispBTNode(t->rchild);
			cout<<')';
		}
	}
}
void parent(BiTree t,BiTree t1,TElemType x)
{
	if(t->lchild||t->rchild)
	{
	 if(t->lchild==t1||t->rchild==t1)
	  cout<<x<<"的双亲为："<<t->data<<endl;
	 else 
	  {
	   parent(t->lchild,t1,x);
       parent(t->rchild,t1,x);
      }
    }
}
BiTNode *FindNode(BiTree t,TElemType x)
{
	BiTNode *p;
	if(t==NULL)
	   return NULL;
	else if(t->data==x)
	    return t;
	    else 
	    {
	    	p=FindNode(t->lchild,x);
	    	if(p!=NULL)
	    	    return p;
	    	    else return FindNode(t->rchild,x);
	    }
}
Status InitStack(SqStack &S)
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)  exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
Status Push(SqStack &S,SElemType e)
{
	if(S.top-S.base==S.stacksize)  return ERROR;
	*S.top++=e;
	return OK;
}
Status Pop(SqStack &S,SElemType &e)
{
	if(S.top==S.base)  return ERROR;
	e=*--S.top;
	return OK;
}
SElemType GetTop(SqStack S)
{
	if(S.top!=S.base)
	   return *(S.top-1);
} 
