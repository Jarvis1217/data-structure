#include<stdio.h>
#include<string.h>
#define MAXSIZE 100  
  
typedef struct  
{  
    char a[MAXSIZE];  
    int top;  
} sequence_list;  
  
/*初始化栈*/  
void init(sequence_list *pt)  
{  
    pt->top=0;  
}  
  
/*输入函数*/  
void input(char *data)  
{  
    scanf("%s",data);  
}  
  
  
  
/*比较函数*/  
int cmp(char data[],sequence_list *pt)  
{  
    int a,b=0,i,j,k;  
    a=strlen(data)%2;  
    switch(a)  
    {  
    case 0:  
        for(i=0; i<=strlen(data)/2; i++)  
        {  
            pt->a[i]=data[i];  
            pt->top++;  
        }  
        pt->top--;  
        for(j=pt->top-1,k=pt->top; j>=0; j--,k++)  
        {  
            if(pt->a[j]!=data[k])b++;  
        }  
        break;  
    case 1:  
        for(i=0; i<=strlen(data)/2; i++)  
        {  
            pt->a[i]=data[i];  
            pt->top++;  
        }  
        pt->top--;  
        for(j=pt->top-1,k=pt->top+1; j>=0; j--,k++)  
        {  
            if(pt->a[j]!=data[k])b++;  
        }  
        break;  
    }  
    return b;  
}  
  
/*判断函数*/  
void judge(int a)  
{  
    if(a==0)printf("YES\n");  
    else printf("NO\n");  
}  
  
int main()  
{  
    sequence_list L;  
    char data[MAXSIZE];  
    init(&L);  
    input(&data[0]);  
    judge(cmp(data,&L));  
    return 0;  
} 
