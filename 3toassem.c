
#include <stdio.h>
#include<string.h>

int main() {

    int n,i;
    char line[50];
    char result[10],op1[10],op2[10],op;
    char *equal,*operator;
    printf("Enter no of instructions:");
    scanf("%d",&n);
    printf("enter three address code:");
    getchar();
    for(int i=0;i<n;i++)
        {
            fgets(line,sizeof(line),stdin);
            line[strcspn(line,"\n")]='\0';
            equal=strchr(line,'=');
            if (equal!=NULL)
            {
                sscanf(line,"%[^=]",result);
                equal++;
                operator=strpbrk(equal,"+-*/");
                if(operator!=NULL)
                {
                    op=*operator;
                    sscanf(equal,"%[^+-*/]",op1);
                    sscanf(operator+=1,"%s",op2);
                    printf("MOV AX,%s\n",op1);
                    if(op=='+')
{
    printf("ADD AX,%s\n",op2);
}
else if(op=='-')
{
   printf("SUB AX,%s\n",op2); 
}
else if(op=='*')
{
   printf("MUL %s\n",op2); 
}
else if(op=='/')
{
   printf("DIV %s\n",op2); 
}
printf("MOV %s,AX\n",result);
}
else
{
    sscanf(equal,"%s",op1);
    printf("MOV AX,%s",op1);
    printf("MOV %s,AX\n",result);
}
                }
            }
         
    return 0;
