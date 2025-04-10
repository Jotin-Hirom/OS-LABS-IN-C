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
            printf("Roll Number: CSM24042\n"); 
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






#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void check_users() {
    printf("\nUsers logged in (equivalent to 'who' command):\n");
    execlp("who", "who", NULL);  // Execute 'who' command
    perror("execlp"); // In case of error
    exit(1);
}

int main() {
    pid_t child_pid, grandchild_pid;
    int status;
    int child_count = 0, grandchild_count = 0;
    
    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (child_pid == 0) { // Child process
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        child_count++;
        
        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        else if (grandchild_pid == 0) { // Grandchild process
            printf("Grandchild: PID = %d, PPID = %d\n", getpid(), getppid());
            grandchild_count++;
            printf("My Roll No: 123456\n"); // Change to your actual roll number
            check_users(); // Print logged-in users
            exit(0);
        }
        wait(NULL); // Child waits for grandchild to finish
        exit(0);
    }
    
    wait(&status); // Parent waits for child
    
    if (WIFEXITED(status)) {
        printf("Parent: Child exited normally with status %d\n", WEXITSTATUS(status));
    }
    
    printf("Parent: PID = %d, PPID = %d\n", getpid(), getppid());
    printf("Total child processes created: %d\n", child_count);
    printf("Total grandchild processes created: %d\n", grandchild_count);
    
    pid_t exec_child = fork();
    if (exec_child == 0) {
        char *args[] = {"./user_program", "Argument1", "Argument2", NULL};
        execv(args[0], args);
        perror("execv failed");
        exit(1);
    }
    
    wait(&status); // Parent waits for exec_child
    if (WIFEXITED(status)) {
        printf("Parent: Exec child exited with status %d\n", WEXITSTATUS(status));
    }
    
    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utmp.h>

void print_logged_in_users() {
    struct utmp *user;
    setutent();
    printf("\nLogged-in users:\n");
    while ((user = getutent()) != NULL) {
        if (user->ut_type == USER_PROCESS) {
            printf("User: %s\n", user->ut_user);
        }
    }
    endutent();
}

int main() {
    pid_t child_pid, grandchild_pid;
    int status;
    int child_count = 0, grandchild_count = 0;
    
    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (child_pid == 0) { // Child process
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        child_count++;
        
        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        else if (grandchild_pid == 0) { // Grandchild process
            printf("Grandchild: PID = %d, PPID = %d\n", getpid(), getppid());
            grandchild_count++;
            printf("My Roll No: 123456\n"); // Change to your actual roll number
            print_logged_in_users(); // Print logged-in users
            exit(0);
        }
        wait(NULL); // Child waits for grandchild to finish
        exit(0);
    }
    
    wait(&status); // Parent waits for child
    
    if (WIFEXITED(status)) {
        printf("Parent: Child exited normally with status %d\n", WEXITSTATUS(status));
    }
    
    printf("Parent: PID = %d, PPID = %d\n", getpid(), getppid());
    printf("Total child processes created: %d\n", child_count);
    printf("Total grandchild processes created: %d\n", grandchild_count);
    
    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utmp.h>

void print_logged_in_users() {
    struct utmp *user;
    setutent();
    printf("\nLogged-in users:\n");
    while ((user = getutent()) != NULL) {
        if (user->ut_type == USER_PROCESS) {
            printf("User: %s\n", user->ut_user);
        }
    }
    endutent();
}

int main() {
    pid_t child_pid;
    int status;
    
    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (child_pid == 0) { // Child process
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        char *args[] = {"./user_program", "Argument1", "Argument2", NULL};
        execv(args[0], args);
        perror("execv failed");
        exit(1);
    }
    
    wait(&status); // Parent waits for child
    
    if (WIFEXITED(status)) {
        printf("Parent: Child exited normally with status %d\n", WEXITSTATUS(status));
    }
    
    printf("Parent: PID = %d, PPID = %d\n", getpid(), getppid());
    
    return 0;
}




#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("User Program Executed!\n");
    printf("Program Name: %s\n", argv[0]);
    
    if (argc > 1) {
        printf("Arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("Arg %d: %s\n", i, argv[i]);
        }
    } else {
        printf("No additional arguments provided.\n");
    }
    
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("User Program Executed!\n");
    printf("Program Name: %s\n", argv[0]);
    
    if (argc > 1) {
        printf("Arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("Arg %d: %s\n", i, argv[i]);
        }
    } else {
        printf("No additional arguments provided.\n");
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utmp.h>

void print_logged_in_users() {
    struct utmp *user;
    setutent();
    printf("\nLogged-in users:\n");
    while ((user = getutent()) != NULL) {
        if (user->ut_type == USER_PROCESS) {
            printf("User: %s\n", user->ut_user);
        }
    }
    endutent();
}

int main() {
    pid_t child_pid, grandchild_pid;
    int status;
    int child_count = 0, grandchild_count = 0;
    
    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (child_pid == 0) { // Child process
        printf("Child: PID = %d, PPID = %d\n", getpid(), getppid());
        child_count++;
        
        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        else if (grandchild_pid == 0) { // Grandchild process
            printf("Grandchild: PID = %d, PPID = %d\n", getpid(), getppid());
            grandchild_count++;
            printf("My Roll No: 123456\n"); // Change to your actual roll number
            print_logged_in_users(); // Print logged-in users
            exit(0);
        }
        wait(NULL); // Child waits for grandchild to finish
        
        char *args[] = {"./user_program", "Argument1", "Argument2", NULL};
        execv(args[0], args);char *
        perror("execv failed");
        exit(1);
    }
    
    wait(&status); // Parent waits for child
    
    if (WIFEXITED(status)) {
        printf("Parent: Child exited normally with status %d\n", WEXITSTATUS(status));
    }
    
    printf("Parent: PID = %d, PPID = %d\n", getpid(), getppid());
    printf("Total child processes created: %d\n", child_count);
    printf("Total grandchild processes created: %d\n", grandchild_count);
    
    return 0;
}
