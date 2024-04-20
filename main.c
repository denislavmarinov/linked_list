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
void searchNode(int data);


int main()
{

}

/*
* Function for adding new element to the list
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

/*
* Function for searching new element to the list
* params:
*   - int data - the data that is to be entered
* return:
*    int - the position of the element
*    -1 - the element is not found
*/
void searchNode(int data)
{
    int positionOfSearchedNode = 0;
    SN *searchedNode = NULL, *temp = head;

    // Loop that goes through the list until it found the searched item
    while (temp->data != data)
    {
        temp = temp->next;
        positionOfSearchedNode++;
    }
    // Assign the searchedNode variable to the element where the loop has ended
    searchedNode = temp;

    // Check if the element is found
    if (searchedNode->data == data)
    {
        // If the element is found, return the position of the element
        return positionOfSearchedNode;
    }
    else
    {
        // If the element is not found, return -1
        return -1;
    }
}
