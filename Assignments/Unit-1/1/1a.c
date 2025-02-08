#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid;
    int child_count = 0, grandchild_count = 0;

    child_pid = fork();  // First fork to create child

    if (child_pid > 0) {  
        // Parent process
        child_count++;
        printf("Parent Process: PID = %d, PPID = %d\n", getpid(), getppid());

        wait(NULL);  // Wait for child to complete
        printf("Total Child Processes Created: %d\n", child_count);
        printf("Total Grandchild Processes Created: %d\n", grandchild_count);

        exit(0);  // Successful exit
    } 
    else if (child_pid == 0) {  
        // Child process
        printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());

        grandchild_pid = fork();  // Second fork to create grandchild

        if (grandchild_pid > 0) {  
            // Child process
            wait(NULL);  // Wait for grandchild to finish
            exit(0);  // Successful exit
        } 
        else if (grandchild_pid == 0) {  
            // Grandchild process
            printf("Grandchild Process: PID = %d, PPID = %d\n", getpid(), getppid());
            printf("Roll Number: 123456\n");  // Replace with actual roll number
            exit(0);  // Successful exit
        } 
        else {  
            // Error handling for grandchild fork failure
            printf("Failed to create grandchild process!\n");
            exit(1);  // Error exit
        }
    } 
    else {  
        // Error handling for child fork failure
        printf("Failed to create child process!\n");
        exit(1);  // Error exit
    }

    return 0;
}
