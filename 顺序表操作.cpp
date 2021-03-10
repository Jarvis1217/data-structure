#include <iostream>
using namespace std;

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2

typedef int Elemtype;
typedef int Status;
//定义顺序表 
typedef struct list
{
	Elemtype *elem;
	int length;
}sqlist;
//初始化顺序表 
Status initList(sqlist &L)
{
	L.elem=new Elemtype[maxsize];
	if(!L.elem)
	exit(overflow);
	L.length=0;
	return ok;
}
//创建顺序表 
Status Creatlist(sqlist &L,Elemtype a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	L.elem[i]=a[i];
	L.length=n;
	return ok;
}

//0-退出程序 
Status Displist(sqlist &L)
{
	delete []L.elem;
	L.length=0;
	cout<<"谢谢使用，已退出程序";
	return ok;
}

//1-输出元素 
void output(sqlist &L)
{
	int i;
	for(i=0;i<L.length;i++)
	cout<<L.elem[i]<<" ";
}

//2-删除元素 
Status Delete(sqlist &L) 
{
	int i,j;
	cout<<"删除元素的序号为:";
	cin>>i;
	if((i<1)||(i>L.length))
	{
		cout<<"输入序号不合法"; 
	    return error;
	}
	for(j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
		--L.length;
		cout<<"执行成功";
		return ok;
}

//3-查找元素
Status findlist1(sqlist &L)
{
	int i,e;
	cout<<"请输入查找元素序号:";
	cin>>i;
	if((i<1)||(i>L.length))
	{
		cout<<"输入序号不合法"; 
	    return error;
	}
	e=L.elem[i-1];
	printf("第%d个元素为:%d",i,e);
	return ok;
} 
//4-查找元素序号 
Status findlist2(sqlist &L)
{
	int e,i;
	cout<<"您要查找的元素为：";
	cin>>e;
	for(i=0;i<L.length;i++)
	if(L.elem[i]==e)
	printf("元素%d为第%d个元素",e,i+1);
	return ok;
} 

//5-插入元素
Status cutin(sqlist &L)
{
	int i,e,j;
	cout<<"请输入插入位置和插入元素:";
	cin>>i>>e;
	if((i<1)||(i>L.length+1))
	{
		cout<<"输入序号不合法"; 
	    return error;
	}
	if(L.length==maxsize)
	{
		cout<<"存储空间已满";
		return error;
	}
	for(j=L.length-1;j>=i-1;j--)
	L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	++L.length;
	cout<<"执行成功";
	return ok;
} 

//6-删除区域元素
Status deletesome(sqlist &L)
{
	int i=0,x,y;  
    int j=0;  
    cout<<"请输入删除范围:";
    cin>>x>>y;
    while(i<L.length)  
    {  
        if(L.elem[i]>=x && L.elem[i]<=y)  
            j++;  
        else  
            L.elem[i-j]=L.elem[i];  
        i++;  
    }  
    L.length-=j; 
    cout<<"执行成功";
    return ok;
}

//7-单值化操作
Status Simplist(sqlist &L)
{
	Elemtype *p,*q,*r;
	q=L.elem;
	r=L.elem+L.length-1;
	for(q=L.elem;q<L.elem+L.length;q++)
	{
		for(r=L.elem+L.length-1;r>q;--r)
	     if(*q==*r)
	     {
	     	p=r;
	     	for(++p;p<=L.elem+L.length-1;++p)
	     	*(p-1)=*p;
	     	--L.length;
	     }
	}
	cout<<"执行成功";
	return ok;
}

int main()
{
	sqlist L;
	initList(L);
	int n,i;
	cout<<"输入元素的个数为：";
	cin>>n;
	Elemtype a[maxsize];
	cout<<"请输入元素:";
	for(i=0;i<n;i++)
		cin>>a[i];
	Creatlist(L,a,n);
	
	int s;
	cout<<endl;
	cout<<"提示："<<endl; 
	cout<<"0-结束退出;1-输出元素;2-删除元素;3-查找元素;"<<endl;
	cout<<"4-查找元素序号;5-插入元素;6-删除区域元素;7-单值化操作;"<<endl;
	do
	{
		cout<<endl;
 	    cout<<"请输入操作符："; 
	    cin>>s;
	    //判断操作方式 
	    if(s==0)
	    {
	    	Displist(L);
	    	cout<<endl;
	    }
	    
	    if(s==1)
	    {
	    	output(L);
	    	cout<<endl;
	    }
	    
	    if(s==2)
	    {
	    	Delete(L);
	    	cout<<endl;
	    }
	    
	    if(s==3)
	    {
	    	findlist1(L);
	    	cout<<endl;
	    }
	    
	    if(s==4)
	    {
	    	findlist2(L);
	    	cout<<endl;
	    }
		
		if(s==5)
		{
			cutin(L);
			cout<<endl;
		}
		  
		if(s==6)
		{
		    deletesome(L);
			cout<<endl;
		}  
		
		if(s==7)
		{
			Simplist(L);
			cout<<endl;
		}
		
	}while(s!=0);
	
	return 0;
}

