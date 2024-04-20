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
int addNode(int data);
int searchNode(int data);
int deleteNode(int data);
void printNode();
int clearNode();

int main()
{
    return 0;
}

/*
* Function for adding new element to the list
* params:
*   - int data - the data that is to be entered
* return:
*   0 - the element is successfully added
*   -1 - there was an error while entering the element to the list
*/
int addNode(int data)
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

            // Returns 0 for success
            return 0;
        }
        else
        {
            // Returns an error
            return -1;
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

            // Return 0 for success
            return 0;
        }
        else
        {
            // Returns an error
            return -1;
        }
    }
}

/*
* Function for searching element of the list
* params:
*   - int data - the data that is to be entered
* return:
*    int - the position of the element
*    -1 - the element is not found
*/
int searchNode(int data)
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
/*
* Function for deleting element of the list
* params:
*   - int data - the data that is to be entered
* return:
*   0 - when the element is correctly deleted
*   -1 - when the element is not found
*/
int deleteNode(int data)
{
    // Get the position of the element
    int positionOfTheNode = searchNode(data);
    SN *deleteNode = NULL, *temp = head;
    // Check if the element exists
    if (positionOfTheNode != -1)
    {
        // Go through the list until the previous node is fonud
        for (int i = 0; i < positionOfTheNode - 2; i++)
        {
            temp = temp->next;
        }
        // Get the address of the element that will be deleted
        deleteNode = temp->next;

        // Make the link between the previous and the next element
        temp->next = temp->next->next;

        // Delete the element
        free(deleteNode);

        // Return the result of the function
        return 0;
    }
    else
    {
        // The element is not found and the function returns -1
        return -1;
    }
}
/*
* Function for printing all element of the list
* params: Node
* return: None
*/
void printNode()
{
    SN *temp = head;

    // Check if the list is empty
    if (temp == NULL)
    {
        // Print the message that the list is empty
        printf("The list is empty");
    }
    else
    {
        // Loop that goes through all elements
        while(temp != NULL)
        {
            // Print the element value on new line
            printf("%d\n", temp->data);
            // Go to the next element
            temp = temp->next;
        }
    }
}

/*
* Function for clearing all elements of the list
* params: Node
* return:
*   0 - the whole list is cleared successfully
*/
int clearNode()
{
    SN *currentNode = NULL, *temp = head;
    // Loop that goes through the whole list
    while (temp->next != NULL)
    {
        // Save the current node
        currentNode = temp;
        // Go to the next node
        temp = temp->next;
        // Delete the current node
        free(currentNode);
    }
    // Set the list to NULL
    head = NULL;
    // Return success message
    return 0;
}
