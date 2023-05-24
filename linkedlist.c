/**
 * CSO1 HW8 Circularly Linked List Implementation
 *
 * Your Computing ID: mge2zx
 */

//TODO: Remember to add include statement here. 

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

cll_node *cll_head(cll_node *list){
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement.
	 //for this one are we assuming that the is_head value is already 1 and we are just finding it?

        cll_node *ptr = list; //initiate pointer location
	if (list == NULL) { //if empty list, return null
		return NULL;
	}
	if (!ptr->is_head) { //if pointer is not the head go through loop
		do {
			ptr = ptr->next; //move pointer to next node
		} while (!ptr->is_head); //continue until is_head = 1
	}
    return ptr;
}


cll_node *cll_tail(cll_node *list) {
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement. 
	if (list == NULL)
		return NULL;
	cll_node *head = cll_head(list); //find location of the head node
	cll_node *tail = head->prev; //head.prev will be the tail, since its circular list
    return tail; 
}


unsigned long cll_length(cll_node *list) {
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement. 
	unsigned long  length = 0; //initialize counter
	cll_node *head = cll_head(list); //start as the head node
	cll_node *ptr = head; //duplicate head pointer to know when loop ends
	if (head != NULL){ //while list is not empty
		do {
			ptr = ptr->next; //move to next node
			length++; //add to counter
		} while (ptr != head); //while not back at the beginning of the list

	}

    return length;
}

cll_node *cll_find(cll_node *list, int value) {
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement. 
	cll_node *head = cll_head(list); //start looking at the head of the list
	cll_node *ptr = head; //duplicate head in order to iterate through list
	if (list == NULL){ //list is empty, return null
		return NULL;
	}
	if (head->value != value){ //while value not found
		do {
			ptr = ptr->next; //move to next node
			if (ptr->is_head){ //if gone through whole loop and not found, return null
				return NULL;
			}
		} while (ptr->value != value); //break loop when value is found
	}

    return ptr;
}


cll_node *cll_remove(cll_node *list) {
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement.
	if (list == NULL){ //nothing to remove, return null
		return NULL;
	}
	if (list->next == list){
		free(list);
		return NULL;
	}

	cll_node *placehold = list->next; //create the return pointer
	cll_node *prev = list->prev; //next few lines remove the node (drew this out on paper)
	cll_node *next = list->next;
	prev->next = next;
	next->prev = prev;
	free(list); //free the allocated memory for list pointer
    return placehold;
}


cll_node *cll_insert(int value, cll_node *list, int before) {  
    //TODO: Implement this function, see header file for description
    //TODO: Update return statement. 

	if (list == NULL){ //instance: list is empty
		cll_node *nuevo = (cll_node *)calloc(sizeof(cll_node), 1); //uses calloc rather than malloc in order to clear memory after each insertion
		nuevo->is_head = 1; //set as head
		nuevo->value = value; //give value
		nuevo->prev = nuevo; //points to itself
		nuevo->next = nuevo;
		return nuevo;
	}
	cll_node *cur = list;
	cll_node *nuevo;
	if (before == 0){ //immediately following (after) the node pointed to by `list`
		nuevo = (cll_node *)calloc(sizeof(cll_node), 1); //allocate memory
		nuevo->value = value; //give new node the value
		cur->next->prev = nuevo; //used code created in dsa
		nuevo->next = cur->next;
		nuevo->prev = cur;
		cur->next = nuevo;
	}
	else { //same as the previous but every prev becomes a next and every next becomes a prev (dres both before situations out)
		nuevo = (cll_node *)calloc(sizeof(cll_node), 1); 
		nuevo->value = value;
		cur->prev->next = nuevo;
		nuevo->prev = cur->prev;
		nuevo->next = cur;
		cur->prev = nuevo;
	}
    return nuevo;

}


/**
 * Displays the contents of the list separated by commas and surrounded by
 * brackets, with the pointed-to node highlighted with asterisks.
 *
 * Reference solution provided with assignment description
 */
void cll_show(cll_node *list) {
    // Find the head of the linked list
    cll_node *head = cll_head(list);
    cll_node *ptr = head;
    // Print opening [
    putchar('[');
    // Loop through list printing values
    if (ptr) {
        do {
            if (!ptr->is_head) 
                printf(", "); // include a comma if not the first element
            if (ptr == list) 
                putchar('*'); // include * surrounding parameter element
            printf("%d", ptr->value);
            if (ptr == list) 
                putchar('*');
            ptr = ptr->next; // next pointer
        } while (ptr != head);
    }
    // Print closing ]
    puts("]");
}


int main(int argc, const char *argv[]) {

    // Example debugging code.  You should write other
    // tests, including testing corner cases.
    cll_node *x = NULL;
    putchar('A'); cll_show(x);
    x = cll_insert(25, x, 1);
    putchar('B'); cll_show(x);
    x = cll_insert(1, x, 0);
    putchar('C'); cll_show(x);
    x = cll_insert(98, x, 1);
    putchar('D'); cll_show(x);
    x = cll_insert(0, x, 1);
    putchar('E'); cll_show(x);
    x = cll_insert(-8, cll_tail(x), 0);
    putchar('F'); cll_show(x);
    cll_node *y = cll_head(x);
    putchar('G'); cll_show(y);
    printf("Length: %lu (or %lu)\n", cll_length(y), cll_length(x));
    x = cll_remove(x);
    putchar('H'); cll_show(x);
    putchar('I'); cll_show(y);
    x = cll_remove(cll_find(y, 98));
    putchar('J'); cll_show(x);
    putchar('K'); cll_show(y);

    return 0;
}
