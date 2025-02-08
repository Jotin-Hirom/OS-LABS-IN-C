#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

printf("\n<<PROCESS STARTED>>\n");
printf("\nSleep for 1 sec in different formats:");
sleep(1);
usleep(1000);
printf("\nAfter sleep..");
exit(0);//0->success others->error
//Next line won't execute
printf("\n<<PROCESS ENDS>>\n");
return 0;
}
