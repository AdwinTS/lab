
#include <stdio.h>
#include<string.h>

int main() {
    char exp[100];
    char left[20],right[20];
    char temp[20][20];
    int i,t=0;
    printf("enter expression:");
    scanf("%s",exp);
    printf("Three Address Code\n");
    for(i=0;exp[i]!='\0';i++)
        {
            if(exp[i]=='*'|| exp[i]=='/')
            {
                left[0]=exp[i-1];
                left[1]='\0';
                right[0]=exp[i+1];
                right[1]='\0';
                t++;
                sprintf(temp[t],"t%d",t);
                printf("%s=%s %c %s\n",temp[t],left,exp[i],right);
                exp[i-1]='0'+t;
                for(int j=i;exp[j+1]!='\0';j++)
                    {
                        exp[j]=exp[j+2];
                    }
                i--;
            }
        }
        for(i=0;exp[i]!='\0';i++)
            {
                if(exp[i]=='+'||exp[i]=='-')
                {
                    if (exp[i-1]>='1' && exp[i-1]<='9')
                    {
                        sprintf(left,"t%c",exp[i-1]);
                    }
                    else
                    {
                        left[0]=exp[i-1];
                left[1]='\0';
                    }
                    if (exp[i+1]>='1' && exp[i+1]<='9')
                    {
                        sprintf(right,"t%c",exp[i+1]);
                    }
                    else
                    {
                        right[0]=exp[i+1];
                right[1]='\0';
                    }
                    t++;
                    
                    sprintf(temp[t],"t%d",t);
                printf("%s=%s %c %s\n",temp[t],left,exp[i],right);
                }
            }
    
         
    return 0;

}
