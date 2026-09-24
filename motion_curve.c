#include<stdio.h>

int main()
{
    int c1[20],e1[20],c2[20],e2[20],c3[40],e3[40];
    int result,power,n1=0,n2=0,n3=0,choice;
    int i,j,t;

    while(1)
    {
        printf("\n1. Create motion curve");
        printf("\n2. Display motion curve");
        printf("\n3. Evaluate object position");
        printf("\n4. Add two motion curves");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the no.of.terms: ");
                scanf("%d",&n1);
                for(i=0;i<n1;i++)
                {
                    printf("\nEnter the co-efficient: ");
                    scanf("%d",&c1[i]);
                    printf("\nEnter the exponent: ");
                    scanf("%d",&e1[i]);
                }
                break;

            case 2:
                for(i=0;i<n1;i++)
                {
                    if(c1[i]>=0 && i>0)
                        printf("+");

                    if(e1[i]==0)
                        printf("%d",c1[i]);
                    else if(e1[i]==1)
                        printf("%dt",c1[i]);
                    else
                        printf("%dt^%d",c1[i],e1[i]);
                }
                break;

            case 3:
                printf("Enter the t value: ");
                scanf("%d",&t);

                result=0;

                for(j=0;j<n1;j++)
                {
                    power=1;

                    for(i=0;i<e1[j];i++)
                        power=power*t;

                    result=result+(power*c1[j]);
                }

                printf("T value is %d",result);
                break;

            case 4:
                printf("Enter no. of terms for second curve: ");
                scanf("%d",&n2);

                for(i=0;i<n2;i++)
                {
                    printf("Coefficient: ");
                    scanf("%d",&c2[i]);

                    printf("Exponent: ");
                    scanf("%d",&e2[i]);
                }

                n3=n1;

                for(i=0;i<n3;i++)
                {
                    c3[i]=c1[i];
                    e3[i]=e1[i];
                }

                for(i=0;i<n2;i++)
                {
                    for(j=0;j<n3;j++)
                    {
                        if(e2[i]==e3[j])
                        {
                            c3[j]=c3[j]+c2[i];
                            break;
                        }
                    }

                    if(j==n3)
                    {
                        c3[n3]=c2[i];
                        e3[n3]=e2[i];
                        n3++;
                    }
                }

                printf("Motion curve: ");

                for(i=0;i<n3;i++)
                {
                    if(i>0 && c3[i]>=0)
                        printf("+");

                    if(e3[i]==0)
                        printf("%d",c3[i]);
                    else if(e3[i]==1)
                        printf("%dt",c3[i]);
                    else
                        printf("%dt^%d",c3[i],e3[i]);
                }

                break;

            case 5:
                return 0;
        }
    }
}