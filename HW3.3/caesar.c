#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char message[256];
char* caesarEncode(const char *plaintext, int key){
	int i = 0;
	char c;
	char* ptr = message;
	while((c = *plaintext++) != '\0'){
		if(isalpha(c)){
			c = toupper(c);
			int pos = c - 'A';
			pos+=key;
			pos = pos%26;
			*ptr++ = 'A' + pos;
		}else{
			*ptr++ = c;
		}	
	}
	*ptr = '\0';
	return(message);
}

char* caesarDecode(const char *ciphertext, int key){
	char c;
	char* ptr = message;

	while((c = *ciphertext++) != '\0'){
		if(isalpha(c)){
			c = toupper(c);
			c = c - key + 26;
			int pos = c-'A';
			pos = pos%26;
			*ptr++ = 'A' + pos;
		}else{
			*ptr++ = c;
		}
	}
	*ptr = '\0';
	return(message);
}

int main(int argc, char* argv[]){
	printf("testing caesar encryption\n");	
	/*const char* test_message = "HELLO my name is Nesara!";
	char* ciphered_message;
	ciphered_message = caesarEncode(test_message,3);
        printf("The plain text message is %s\n",test_message);	
        printf("The encrypted message is %s\n",ciphered_message);

	printf("testing caeser decryption\n");
	const char* test_message1 = ciphered_message;
	char* plain_message;
        printf("The encrypted message is %s\n",test_message1);	
	plain_message = caesarDecode(test_message1,3);
        printf("The plain text message is %s\n",plain_message);*/
	
	char* message;

	printf("the value of argc is = %d\n", argc);
	for(int i = 0; i<argc; i++){
		printf("argument %d is %s\n", i,argv[i]);
	}
	if(argc <= 3){
		printf("invalid number of arguments\n");
		return(0);
	}	
	if((strcmp(argv[1],"-e")) && (strcmp(argv[1],"-d"))){
		printf("the valid argument can be -e or -d\n");
		return(0);
	}

	int key = 0;
	for(int i = 0; i<strlen(argv[3]); i++){
		if(!isdigit(argv[3][i])){
			printf("they key has to be numeric only\n");
			return(0);	
		}
	}
	key = atoi(argv[3]);
	if(!strcmp(argv[1], "-e")){
		printf("the string to be encrypted is %s and the key is %s\n", argv[2], argv[3]);
		message = caesarEncode(argv[2],key);
	}else{
		printf("the string to be decrypted is %s and the key is %s\n", argv[2], argv[3]);
		message = caesarDecode(argv[2],key);
	}
	printf("the result = %s\n", message);
	return(0);
}
