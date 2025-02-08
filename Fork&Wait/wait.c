#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
pid_t q = fork();
if (q<0){
printf("Error! No child created.");
}else if(q==0){
printf("\n<<CHILD PROCESS>>\n");
printf("\nChild process id is: %d",getpid());
printf("\nChild->Parent id is: %d",getppid());
printf("\n");
}else{
wait(NULL);
printf("\n<<PARENT PROCESS>>\n");
printf("\nParent process id is: %d",getpid());
printf("\nParent->Child id is: %d",q);
printf("\n");
}
return 0;
}
