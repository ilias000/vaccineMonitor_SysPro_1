#include "LinkedListCitizen.h"

#include <iostream>
using namespace std;

LinkedListCitizen::LinkedListCitizen() : start(NULL), end(NULL)
{
}

LinkedListCitizen::~LinkedListCitizen()
{
    LinkedListCitizenNode *tmpNode = start;
    LinkedListCitizenNode *tmpNodeNext;
    while (tmpNode != NULL)
    {
        tmpNodeNext = tmpNode->next;
        delete tmpNode->citizen;
        delete tmpNode;
        tmpNode = tmpNodeNext;
    }
}

void LinkedListCitizen::insertNode(CitizenRecord *citizen) // inserts a node at the end of the list
{
    LinkedListCitizenNode *newNode = new LinkedListCitizenNode; // creating a new node
    newNode->citizen = citizen;
    newNode->next = NULL;

    if (start == NULL) // the list is empty
    {
        // insert the node at the start
        start = newNode;
        end = newNode;
    }
    else // the list is not empty
    {
        // insert the node at the right place so the list is sorted
        LinkedListCitizenNode *current = start; // initialize current
        while (current->next != NULL)
        {
            if (current->next->citizen->getId() < newNode->citizen->getId())
            {
                current = current->next;
            }
            else if (current->next->citizen->getId() > newNode->citizen->getId())
            {
                newNode->next = current->next;
                current->next = newNode;
            }
            else
            {
                cout << "Same id " << current->next->citizen->getId() << " " << newNode->citizen->getId() << endl;
                break;
            }
        }
    }
}

LinkedListCitizenNode *LinkedListCitizen::findNode(int id) // if the id exist returns the node else returns NULL
{
    LinkedListCitizenNode *current = start; // initialize current
    while (current != NULL)
    {
        if (current->citizen->getId() == id)
            return current;
        current = current->next;
    }
    return NULL;
}
