#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
//execlp(char *file, char *args,..,NULL);
execlp("echo","echo","Hello, World!",NULL);
char *original_path = getenv("home/jotin/OS_LAB/first.c");//original path
char new_path[1024];//defining a new path
snprintf(new_path,sizeof(new_path),"%s:%s","/home/jotin/OS_LAB",original_path);
pid_t pid = fork();//creating process
if(pid==-1){
perror("Fork failed!");
return 1;
} else if (pid==0){
setenv("PATH",new_path,1);
printf("\nChild: PATH modified, executing...");
execlp("first.c","first.c",NULL);
perror("EXECLP failed!");
exit(1);
}else{
wait(NULL);
setenv("home/jotin/OS_LAB/first.c",original_path,1);
printf("Parent: PATH restored to original.\n");
}

return 0;
}
