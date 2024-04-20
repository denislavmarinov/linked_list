#include <stdio.h>

// Define the struucture
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node SN;

// Globally create the struct beggining
SN *head = NULL;

//Define the functions
void addNode(int data);


int main()
{

}

/*
* Method for adding new element to the list
* params:
*   - int data - the data that is to be entered
* return: None
*/
void addNode(int data)
{
    SN *temp = NULL, *newNode = NULL;
    // Check if the linked list is empty
    if (head == NULL)
    {
        // Allocate dynamically memory
        head = (SN*)malloc(sizeof(SN));
        // Check if the memory is allocated
        if (head != NULL)
        {
            // Save the data
            head->data = data;
            head->next = NULL;
        }
    }
    else
    {
        // Assign to temp the address of the last element of the list
        while(temp->next != NULL)
        {
            // Go to the next element
            temp = temp->next;
        }
        // Dynamically allocate memory for the new element
        newNode = (SN*)malloc(sizeof(SN));
        // Check if the memory is allocated
        if (newNode != NULL)
        {
            // Save the data
            newNode->data = data;
            newNode->next = NULL;
            // Add the link for the new to the previous one
            temp->next = newNode;
        }
    }
}
