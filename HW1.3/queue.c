#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

char* buffer[5] = {"process0","process1", "process2", "process3", "process4"};
int main(){
	//char buffer[50];
	process_t* p = NULL;
	printf("testing queue\n");
	//create the queue
	queue_t *myQ = create_queue();
	if(myQ == NULL){
		printf("error in creating the queue\n");
		return(0);
	}	
	
	for(int i = 0; i<5; i++){
		//Create process
		//sprintf(buffer, "Process %d",i);
		p = create_process(i,buffer[i]);
		int result = enqueue(myQ,p);
	}

	printf("printing the content of the queue\n");
	print_queue(myQ);
	printf("dequeue the first node\n");
	p = dequeue(myQ);
	printf("retrieved data is %d %s\n",p->id, p->name);
	free(p);
	printf("printing the items in the queue after the first dequeue\n");
	print_queue(myQ);
	free_queue(myQ);
	return(0);
}
