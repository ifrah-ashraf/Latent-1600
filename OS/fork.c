#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    printf("Main function:\n");
    int retval;
    pid_t pid = fork();
    if(pid<0){
        printf("Error in fork operation");
    }
    if(pid==0){
        printf ("PID for child process %d\nPID of parent process: %d\n",getpid(),getppid());
        execl("/bin/ps","ps","-d",(char*)NULL);
    }
    else{
        printf("PID for parent process %d\n",getpid());
        wait(&retval);
        if(WIFEXITED(retval)==1){
            printf("Child terminated normally\n");
        }
        else{
            printf("Child terminated abnormally\n");
            exit(0);
        }
    }
    return 0;
}