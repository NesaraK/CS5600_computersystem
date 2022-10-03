#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
	const char* test_message = "Hello my name is Nesara!";
	const char* ciphered_message = "KHOOR PB QDPH LV QHVDUD!";
	int key = 3;
	char buffer[10];
	sprintf(buffer,"%d",key);
	printf("this is a main program which is used to spawn a new process\n");
	printf("calling caesar program for encryption message %s with the key = %s\n",test_message,buffer);

	int pid = fork();
	if(pid == 0){
		printf("creating the child process\n");
		//execl("./caesar", "./caesar", argv[2], argv[3], argv[4],(char *)NULL);


		execl("./caesar", "./caesar", "-e", test_message, buffer,(char *)NULL);
		return(0);
	}else{
		;
	}
	printf("waiting for the child process to complete\n");
	wait(NULL);
	printf("child has completed the task for encryption\n\n\n");







	printf("calling caesar program for decryption message %s with the key = %s\n",ciphered_message,buffer);
	pid = fork();
	if(pid == 0){
		printf("creating the child process\n");
		execl("./caesar", "./caesar", "-d", ciphered_message, buffer,(char *)NULL);
		return(0);
	}else{
		;

	}
	printf("waiting for the child process to complete\n");
	wait(NULL);
	printf("child has completed the task for decryption\n");
}


