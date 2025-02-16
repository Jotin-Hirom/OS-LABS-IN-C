#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t childProc, grandChildProc;
int childNum=0,grandChildNum=0;
childProc = fork();//creating a child process 
if(childProc<0){
printf("<<Error in creating child process!>>");
exit(1);
}else if(childProc==0){
printf("\n<<CHILD PROCESS>>\n");
printf("Child Process PID: %d and PPID: %d\n",getpid(),getppid());
childNum++;
grandChildProc = fork();//creating a process inside child process
if(grandChildProc<0){
printf("<<Error in creating grand child process!>>");
exit(1);
}else if(grandChildProc==0){
printf("\n<<GRANDCHILD PROCESS>>\n");
grandChildNum++;
printf("Roll Number: CSM24042\n");
}else{
printf("\n<<GRANDCHILD PARENT PROCESS>>\n");
exit(0);
}
}else{
printf("\n<<PARENT PROCESS>>\n");
printf("Parent Process PID: %d and PPID: %d\n",getpid(),getppid());
exit(0);
}
printf("\nTOTAL NUMBER OF CHILD PROCESS: %d",childNum);
printf("\nTOTAL NUMBER OF GRANDCHILD PROCESS: %d",grandChildNum);
return 0;
}
