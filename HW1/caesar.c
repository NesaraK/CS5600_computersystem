#include <stdio.h>
#include <ctype.h>

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

int main(){
	printf("testing caesar encryption\n");	
	const char* test_message = "HELLO my name is Nesara!";
	char* ciphered_message;
	ciphered_message = caesarEncode(test_message,3);
        printf("The plain text message is %s\n",test_message);	
        printf("The encrypted message is %s\n",ciphered_message);

	printf("testing caeser decryption\n");
	const char* test_message1 = ciphered_message;
	char* plain_message;
        printf("The encrypted message is %s\n",test_message1);	
	plain_message = caesarDecode(test_message1,3);
        printf("The plain text message is %s\n",plain_message);
}
