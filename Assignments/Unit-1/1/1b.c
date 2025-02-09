#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<utmp.h>

void findOutLogged(){
struct utmp *user;
setutent();//starting the utmp file to read from
printf("\n<<LOGGED IN USERS>>\n");
while((user=getutent())!=NULL){
if(user->ut_type == USER_PROCESS)//normal process
printf("User: %s, Terminal: %s, Host: %s\n",user->ut_user,user->ut_line,user->ut_host);
}
endutent();//ending the utmp file
}

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
printf("Grandchild Process PID: %d and PPID: %d\n",getpid(),getppid());
grandChildNum++;
printf("Roll Number: CSM24042\n");
findOutLogged();
}else{
printf("\n<<GRANDCHILD PARENT PROCESS>>\n");
}
}else{
wait(NULL);
printf("\n<<PARENT PROCESS>>\n");
printf("Parent Process PID: %d and PPID: %d\n",getpid(),getppid());
exit(0);
}
printf("\nTOTAL NUMBER OF CHILD PROCESS: %d",childNum);
printf("\nTOTAL NUMBER OF GRANDCHILD PROCESS: %d",grandChildNum);
return 0;
}
