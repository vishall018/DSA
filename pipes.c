#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int p1[2], p2[2];
    int pid[5], at[5], bt[5];
    int ct[5], tat[5], wt[5], rem[5];
    int q[20], front=0, rear=0;
    int i, time=0, done=0, x;
    float avgtat, avgwt;

    pipe(p1);
    pipe(p2);

    if(fork() == 0)
    {
        /* Process 2 */

        close(p1[1]);
        close(p2[0]);

        read(p1[0], pid, sizeof(pid));
        read(p1[0], at, sizeof(at));
        read(p1[0], bt, sizeof(bt));

        for(i=0;i<5;i++)
            rem[i]=bt[i];

        /* Add processes arriving at time 0 */
        for(i=0;i<5;i++)
        {
            if(at[i]==0)
                q[rear++]=i;
        }

        while(done<5)
        {
            if(front==rear)
            {
                time++;

                for(i=0;i<5;i++)
                {
                    if(at[i]==time)
                        q[rear++]=i;
                }

                continue;
            }

            x=q[front++];

            if(rem[x]>3)
            {
                time=time+3;
                rem[x]=rem[x]-3;
            }
            else
            {
                time=time+rem[x];
                rem[x]=0;

                ct[x]=time;
                tat[x]=ct[x]-at[x];
                wt[x]=tat[x]-bt[x];

                done++;
            }

            /* Add newly arrived processes */
            for(i=0;i<5;i++)
            {
                if(at[i]>time-3 && at[i]<=time && rem[i]==bt[i])
                    q[rear++]=i;
            }

            if(rem[x]>0)
                q[rear++]=x;
        }

        avgtat=0;
        avgwt=0;

        for(i=0;i<5;i++)
        {
            avgtat=avgtat+tat[i];
            avgwt=avgwt+wt[i];
        }

        avgtat=avgtat/5;
        avgwt=avgwt/5;

        write(p2[1],ct,sizeof(ct));
        write(p2[1],tat,sizeof(tat));
        write(p2[1],wt,sizeof(wt));
        write(p2[1],&avgtat,sizeof(avgtat));
        write(p2[1],&avgwt,sizeof(avgwt));

        close(p1[0]);
        close(p2[1]);
    }
    else
    {
        /* Process 1 */

        close(p1[0]);
        close(p2[1]);

        printf("Enter PID Arrival Time Burst Time:\n");

        for(i=0;i<5;i++)
            scanf("%d %d %d",&pid[i],&at[i],&bt[i]);

        write(p1[1],pid,sizeof(pid));
        write(p1[1],at,sizeof(at));
        write(p1[1],bt,sizeof(bt));

        wait(NULL);

        read(p2[0],ct,sizeof(ct));
        read(p2[0],tat,sizeof(tat));
        read(p2[0],wt,sizeof(wt));
        read(p2[0],&avgtat,sizeof(avgtat));
        read(p2[0],&avgwt,sizeof(avgwt));

        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

        for(i=0;i<5;i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                   pid[i],at[i],bt[i],
                   ct[i],tat[i],wt[i]);
        }

        printf("\nAverage TAT = %.2f\n",avgtat);
        printf("Average WT = %.2f\n",avgwt);

        close(p1[1]);
        close(p2[0]);
    }

    return 0;
}