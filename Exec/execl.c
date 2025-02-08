//LIST(CHAR *ARGS1,CHAR *ARGS2,..., NULL )
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
printf("Before exec\n");
//REPLACE CURRENT PROCESS WITH /bin/ls
execl("/bin/ls","ls","-l",NULL);
//OUTPUT: total 4 (that 4 means the total number of disk blocks used by the files in that directory. If ls-l is not used, it will not be shown.) 
perror("Exec failed!");
return 0;
}
