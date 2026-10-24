#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/types.h>

int main()
{
    int semid,i,pid;
    int dir[5]={1,2,1,2,1};

    semid=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
    semctl(semid,0,SETVAL,1);

    for(i=0;i<5;i++)
    {
        pid=fork();

        if(pid==0)
        {
            struct sembuf s;
            s.sem_num=0;
            s.sem_op=-1;
            s.sem_flg=0;
            semop(semid,&s,1);

            if(dir[i]==1)
                printf("Vehicle %d crossing North to South\n",i+1);
            else
                printf("Vehicle %d crossing South to North\n",i+1);

            sleep(2);

            printf("Vehicle %d left the bridge\n",i+1);

            s.sem_op=1;
            semop(semid,&s,1);

            _exit(0);
        }
    }

    for(i=0;i<5;i++)
        wait(NULL);

    semctl(semid,0,IPC_RMID);

    return 0;
}