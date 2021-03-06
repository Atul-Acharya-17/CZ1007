/////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
*/

/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////   linked list /////////////////////////////////

typedef struct _listnode{
   int item;
   struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
   ListNode *tail;
} LinkedList;

////////////////////////////////// stack    ///////////////////////////////////////////////////////

typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;



void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////

Queue popToQueue(Queue *q, Stack *s, int value);

///////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    int c, value;

    Queue q;
	Stack s;

    //initialize the queue
	q.ll.head =NULL;
	q.ll.size =0;
	q.ll.tail=NULL;

	//initialize the stack
    s.ll.head = NULL;
    s.ll.size = 0;
    s.ll.tail = NULL;

    c =1;

    printf("1: Insert an integer into the queue and stack;\n");
    printf("2: Pop the stack to the queue;\n");
    printf("0: Quit;\n");

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want insert into the queue and stack: ");
			scanf("%d", &value);
			enqueue(&q, value);
			push(&s, value);
			printf("The queue is: ");
			printList(&(q.ll));
			printf("The stack is: ");
			printList(&(s.ll));
			break;
		case 2:
			printf("The queue is ");
			printList(&(q.ll));
			printf("The stack is ");
			printList(&(s.ll));
			if (isEmptyQueue(&q)) break;

			printf("Enter the integer in the queue that you want to pop the stack to : ");
			scanf("%d", &value);
			Queue newQ = popToQueue(&q, &s, value); // You need to code this function
			if (!isEmptyQueue(&newQ)) {
				printf("The resulting queue after popping the stack elements is: ");
				printList(&(newQ.ll));
			}
			break;
		case 0:
			removeAllItems(&(q.ll));
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Queue  popToQueue(Queue *q, Stack *s, int value)
{
  if(s->ll.head==NULL)
    return *q;

  Queue QU;
  QU.ll.size = 0;
  QU.ll.head = NULL;
  QU.ll.tail = NULL;

  ListNode* last, *final_node;

  while(q->ll.head!=NULL)
  {
      enqueue(&QU,q->ll.head->item);
      dequeue(q);
  }

  ListNode* temp = QU.ll.head;
  ListNode* prev = QU.ll.head;


  while(temp!=NULL)
  {
      last=temp;
      temp=temp->next;
  }
  final_node = last;
  temp = QU.ll.head;

  int move = 0;
  int check = 0;
  int i = 0;

  while(temp!=NULL)
  {
    if(temp->item==value)
    {
        check = 1;
        while(s->ll.head!=NULL)
        {
            enqueue(&QU,s->ll.head->item);
            pop(s);
            final_node = final_node->next;
        }
        break;
    }
    else{
        temp = temp->next;
        if(move)
            prev = prev->next;
        i++;
        move = 1;
    }
  }
  if(check==1&&i>0)
  {
      final_node->next = temp;
      prev->next = last->next;
      last->next = NULL;
  }
  else if(check==1&&i==0)
  {
      final_node->next = QU.ll.head;
      QU.ll.head = last->next;
      last->next = NULL;
  }

 return QU;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
   insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
   int item;
   if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
   }
    return INT_MIN;
}

int peek(Stack *s){
   return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
   if ((s->ll).size == 0)
      return 1;
   return 0;
}

void enqueue(Queue *q, int item){
   insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
   int item;
   item = ((q->ll).head)->item;
   removeNode(&(q->ll), 0);
   return item;
}

int isEmptyQueue(Queue *q){
   if ((q->ll).size == 0)
      return 1;
   return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}

void removeAllItems(LinkedList *ll)
{
	if (ll == NULL)
		return;

	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}
