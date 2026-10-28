#include <stdio.h>
#include<string.h>
char input[50];
int i=0;
int error=0;
void E();
void T();
void F();
void E()
{
    T();
    while(input[i]=='+')
    {
        i++;
        T();
    }
}
void T()
{
    F();
    while(input[i]=='*')
    {
        i++;
        F();
    }
}
void F()
{
    if(input[i]=='i')
    {
        i++;
    }
    else if (input[i]=='(')
    {
        i++;
        E();
        if (input[i]==')')
        {
            i++;
        }
        else
        {
            error=1;
        }
    }
    else
    {
        error=1;
    }
}
int main() {
    printf("enter expression:");
    scanf("%s",input);
    strcat(input,"$");
    E();
    if (input[i]=='$' && error==0)
    {
        printf("Accepted");
    }
    else
    {
        printf("Rejected");
    }
    return 0;
}
