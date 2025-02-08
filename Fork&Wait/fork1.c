#include<stdio.h>
#include<unistd.h>
int main(){
	printf("\n Process id of currently working or runnng process is: %d",getpid());
	fork();
	printf("\nMy process id is: %d",getpid());
	return 0;
}
