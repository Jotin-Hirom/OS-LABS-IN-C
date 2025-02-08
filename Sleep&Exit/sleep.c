#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t q = fork();
if(q==0){
printf("\n<<CHILD PROCESS>>\n");
	for(int i=0;i<10;i++){
	sleep(1);//in sec
	printf("\ni=%d",i);
	}
printf("\nChild Process ends..");
}else{
printf("\n<<PARENT PROCESS>>\n");
/*for(int i=0;i<2;i++){
usleep(1000);//in microsec
nanosleep(1000);//in nanosec
printf("\ni=%d",i);
}*/
printf("\nParent Process ends..");
}
return 0;
}
