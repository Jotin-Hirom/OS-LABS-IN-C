#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	fork(); //1 2
	fork(); //3 4
	fork(); //1-5 2-6 3-7 4-8
	printf("\nMy process id is: %d",getpid());
	return 0;
}
