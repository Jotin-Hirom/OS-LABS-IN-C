#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

printf("Before exec\n");

char *temp[3];
temp[0]="ls";
temp[1]="-l";
temp[2]=NULL;

//REPLACE CURRENT PROCESS WITH /bin/ls
execv("/bin/ls",temp);
//OUTPUT: total 4 (that 4 means the total number of disk blocks used by the files in that directory. If ls-l is not used, it will not be shown.) 
perror("Exec failed!");
return 0;
}
