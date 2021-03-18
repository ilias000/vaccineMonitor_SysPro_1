#ifndef LINKEDLISTCITIZEN_H
#define LINKEDLISTCITIZEN_H

#include "../../CitizenRecord/CitizenRecord.h"

#include <iostream>

using namespace std;

struct LinkedListCitizenNode
{
    CitizenRecord *citizen;
    LinkedListCitizenNode *next;
};

class LinkedListCitizen
{
    LinkedListCitizenNode *start;
    LinkedListCitizenNode *end;

public:
    LinkedListCitizen();
    ~LinkedListCitizen();

    void insertNode(CitizenRecord *);     // inserts a node at the end of the list
    LinkedListCitizenNode *findNode(int); // if the id exist returns the node else returns NULL
};

#endif