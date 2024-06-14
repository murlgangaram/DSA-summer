#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"


int main() {
	Queue Q;
	
 initQueue(&Q);
 
 enqueue(&Q, 5);
 enqueue(&Q, 10);
 enqueue(&Q, 15);
  display(Q);
  
 dequeue(&Q);
 display(Q);
 
 front(Q);
 rear(Q);
 
 isEmpty(Q); 
 
 display(Q);
 
	return 0;
}

