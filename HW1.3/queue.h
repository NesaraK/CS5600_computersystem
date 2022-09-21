#ifndef MYQ_H
#define MYQ_H

#define TRUE 1
#define FALSE 0

//The structure for the process

typedef struct process {
	int id;
	char *name;
} process_t;

//Defining a node
typedef struct node {
	void *data;
	struct node* next;
} node_t;

//Defining a queue
typedef struct queue {
	int count;
	node_t *head;
	node_t *tail;
} queue_t;

//create process
process_t* create_process(int id, char* name){
	process_t* p = (process_t*)malloc(sizeof (process_t));
	if(p == NULL){
		return(NULL);
	}
	p -> id = id;
	p -> name = name;
	return(p);
}
//Create and initialise the queue
queue_t* create_queue(){
	queue_t* myQ = NULL;
	myQ = (queue_t*)malloc(sizeof(queue_t));
	if(myQ == NULL){
		return NULL;
	}
	myQ->head = NULL;
	myQ->tail = NULL;
	myQ->count = 0;
	return myQ;
}

//enqueue to insert a new element into the queue
int enqueue(queue_t *q, void *element){
	node_t *newnode = (node_t*)malloc(sizeof(node_t));

	if(newnode == NULL) return(FALSE);
	newnode->data = element;
	newnode->next = NULL;

	if(q->tail != NULL){
		q->tail->next = newnode;
	}
	q->tail = newnode;

	if(q->head == NULL){
		q->head = newnode;
	}
	return(TRUE);
}

//dequeue to remove an element from the queue
void* dequeue(queue_t *q){
	
	if(q->head == NULL) return(NULL);

	node_t *node = q->head;
	void *element = node->data;
	q->head = q->head->next;
	if(q->head == NULL){
		q->tail = NULL;
	}
	free(node);
	return(element);
}

//to free the memory
void free_queue(queue_t *q){

	while(q->head != NULL){
		dequeue(q);
	}
	free(q);
}

//print the content of the queue
void print_queue(queue_t *q){
	node_t *node = q->head;
	process_t *p = NULL;
	printf("printing the content of the queue\n");
	while(node != NULL){
		p = node->data;
		printf("node_id is %d \n",p->id);
		printf("node data is %s\n",p->name);
		node = node->next;

	}

}

#endif

