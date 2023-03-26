//  Word reader program based on a simple linked list
//  Created by Antoun, Sherine on 10/12/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//
	
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 128;

struct word{
	char data[MAX];
	int count;
	word* next;
};

void initialise(word*&);		// initalise the linked list
bool addnode(char[], word*&);		// add a word to the list
void printnodes(word*&);		// print the linked list
void freelist(word*&);			// delete the linkedlist

int main()
{
	word* head;
	char buffer[MAX];
	char textfile[MAX];
	ifstream ins;

	cout << "Enter Text file to open: ";
	cin >> textfile;
	
	ins.open(textfile, ios::in);

	if (!ins.good())
	{
		cout << "Can not open text file.. Terminating" << endl;
		return 0;
	}

	initialise(head);

	while (ins>>buffer)
	{
		if (ins.eof())
			break;
	
		if (addnode(buffer, head) == false)
		{
			cout << "Could not insert word into list" << endl;
			freelist(head);
			return 0;
		}		
	}

	//printnodes(head);

	//freelist(head);

	return 0;
}

//
// The initialise function takes a head node and sets it to NULL.
//

void initialise(word *&head) // initalise the linked list
{
	head->next = NULL;
	return;
}

//
// addnode function takes a word to insert into the list and a
// pointer to the head of the list.
// If the word exists in the list then it finds it and increments
// the count indicating it has been seen before. If it is a new
// word then the word is inserted at the end of the list

bool addnode(char data[], word *&head)
{
	// bool finished = false;
	// word *temp;
	// word *curr;
	// curr = head->next;
	return true;
	// if (head->next == NULL)
	// {
	// 	temp = new word;
	// 	head->next = temp;
	// 	temp->next = NULL;
	// 	return true;
	// }

	// while (!finished)
	// {

	// 	int i = 0;
	// 	if (curr->data[i] == data[i])
	// 	{
	// 		while (curr->data[i] == data[i])
	// 		{
	// 			++i;
	// 			if (curr->data[i] == '\0' && data[i] == '\0')
	// 			{
	// 				curr->count++;
	// 				return false;
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		curr = curr->next;
	// 		if(curr == NULL)
	// 		{
	// 			temp = new word;
	// 			head->next = temp;
	// 			temp->next = NULL;
	// 			return true;
	// 		}
	// 		continue;
	// 	}
	// }
}

//  printnodes is given the head node of the list and prints
// out each word and count - it does this for every node in
// the list.

void printnodes(word*& head)		// print the linked list
{

	return;
}

// deletes the linked list.

void freelist(word*& head)			// delete the linkedlist
{

	return;
}
