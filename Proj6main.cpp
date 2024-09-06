#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#include "header.h"

using namespace std;

class ArchipelagoExpedition
{
 private:
   // Create the Data Members for the Archipelago Network here
  Island* darr;
	int size;
	bool bfs (int y, IslandQueue queue) 
    {
		while (!queue.is_empty()) 
      {

			int x = queue.peak();
			queue.dequeue();
			MyNode* temp = darr[x - 1].getHead();
			temp = temp->getNext();

			while (temp != nullptr) 
      {
				if (darr[temp->getValue() - 1].getVisited() == -1)
        {
					darr[temp->getValue() - 1].setVisited(x);

				if (temp->getValue() == y)
        {
					return true;
				}
					queue.enqueue(temp->getValue());
				}

				temp = temp->getNext();
			}
		}
		return false;
	}

IslandStack breadthFirstSearch (int x, int y) 
{
		for (int i = 0; i < size; i++) 
    {
			darr[i].setVisited(-1);
		}

		IslandQueue queue;
		queue.enqueue(x);

		if ( bfs(y, queue) == false) 
    {
			cout << "You can NOT get from island " << x << " to island " << y << endl;
			IslandStack stack;
			return stack;
		} 
    else 
    {
			cout << "You can get from island " << x << " to island " << y << endl;
			IslandStack stack;
			int currentIsland = y;
			stack.push(currentIsland);

			do 
      {
				currentIsland = darr[currentIsland - 1].getVisited();
				stack.push(currentIsland);
			} 
            while (currentIsland != x);
			return stack;
		}
	}

public:

 // Use a constructor to initialize the Data Members for your expedition
ArchipelagoExpedition()
{
	size = 10;
	darr = new Island[size];

	for (int i = 0; i < size; i++) 
  {
    darr[i].setDefault(i + 1);
	}

} 

void setSize(int val) 
{
	size = val;
}

 // The main loop for reading in input
 void processCommandLoop (FILE* inFile, Node* &head)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \r\n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
        printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
        exit(1);

    else if ( strcmp (command, "?") == 0) 
        showCommands();
     
    else if ( strcmp (command, "t") == 0) 
        doTravel();
  
    else if ( strcmp (command, "r") == 0) 
        doResize();

    else if ( strcmp (command, "i") == 0) 
        doInsert();

    else if ( strcmp (command, "d") == 0) 
         doDelete();

    else if ( strcmp (command, "l") == 0) 
        doList();

    else if ( strcmp (command, "f") == 0) 
        doFile(head);

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 // Shows the commands of the program
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q\n");
   printf ("  ?\n");
   printf ("  #\n");
   printf ("  t <int1> <int2>\n");
   printf ("  r <int>\n");
   printf ("  i <int1> <int2>\n");
   printf ("  d <int1> <int2>\n");
   printf ("  l\n");
   printf ("  f <filename>\n");
 }

 void doTravel()
 {
   int int1 = 0;
   int int2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");

   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }

   int1 = atoi ( next );

   if ( int1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }

   int2 = atoi ( next );

   if ( int2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   
   printf ("Performing the Travel Command from %d to %d\n", int1, int2);

	if (int1 < 1 || int1 > size || int2 < 1 || int2 > size) 
  {
		printf("Invalid value for island\n");
		return;
	}


	IslandStack stack = breadthFirstSearch(int1, int2);
	if (!stack.is_empty()) 
  {
		cout << "shortest path from " << int1 << " to " << int2 << ": ";

		while (!stack.is_empty()) 
    {
			if (stack.getHead()->getNext() == nullptr) 
      {
				cout << stack.top();
			} 
      else 
      {
				cout << stack.top() << " - ";
			}
				stack.pop();
		}
			cout << endl;
	}
 }

 void doInsert()
 {
   int int1 = 0;
   int int2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");

   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }

   int1 = atoi ( next );

   if ( int1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");

   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }

   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }

   int2 = atoi ( next );

   if ( int2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   if ( int2 == int1)
   {
     printf("Can not add ferry ride to self\n");
     return;
   }

	if (int1 < 1 || int1 > size || int2 < 1 || int2 > size) 
  {
	  printf("Invalid value for island\n");
	  return;
	}

	printf ("Performing the Insert Command for %d\n", int1);
  
	if (darr[int1 - 1].exists(int2)) 
  {
		printf("Ferry ride already added!\n");
		return;
	}

	darr[int1 - 1].insert(int2);

}

void doResize()
 {
   int int1 = 0;

	// get an integer value from the input
   char* next = strtok (NULL, " \n\t");

   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }

   int1 = atoi ( next );

   if ( int1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   printf ("Performing the Resize Command with %d\n", int1 );

	for (int i = 0; i < 10; i++) 
  {
		darr[i].clear();
	}

	 delete[] darr;
	 size = int1;
	 darr = new Island[size];

	for (int i = 0; i < size; i++) 
  {
		darr[i].setDefault(i + 1);
	}

}

void doDelete()
{
	int int1 = 0;
  int int2 = 0;

  // get an integer value from the input
  char* next = strtok (NULL, " \n\t");

  if ( next == NULL )
  {
    printf ("Integer value expected\n");
    return;
  }

  int1 = atoi ( next );

  if ( int1 == 0 && strcmp (next, "0") != 0)
  {
    printf ("Integer value expected\n");
    return;
  }
   
 // get another integer value from the input
  next = strtok (NULL, " \n\t");

  if ( next == NULL )
  {
    printf ("Integer value expected\n");
    return;
  }

  int2 = atoi ( next );

  if ( int2 == 0 && strcmp (next, "0") != 0)
  {
    printf ("Integer value expected\n");
    return;
  }

if (int1 < 1 || int1 > size || int2 < 1 || int2 > size)
{
	printf("Invalid value for island\n");
	return;
}

	printf ("Performing the Delete Command for %d\n", int1);

	if (!darr[int1 - 1].exists(int2)) 
  {
		printf("Ferry ride does not exist\n");
		return;
	}

	darr[int1 - 1].remove(int2);

}

void removeFirst(Node* &head) 
{
	if (head == nullptr) 
  {
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;

}

void doList()
{
	printf ("Displaying the adjacency list:\n" );
    
  for (int i = 0; i < size; i++) 
  {
		cout << darr[i].getValue() << " -->  ";
		darr[i].printList();
		cout << endl;
	}

}

void insert(Node* &head, string value) 
{
	Node* n = new Node;
	n->value = value;
	n->next = head;
	head = n;
}

void doFile(Node* &head)
{
   // get a filename from the input
   char* fname = strtok (NULL, " \r\n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);

	 std::string str(fname);

   Node* temp = head;
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
	 while (temp != nullptr) 
    {
		  if (temp->value == str) 
      {
			  printf("File is already in use\n");
			  return;
		  }
		temp = temp->next;
	  }

   //  2. open the file using fopen creating a new instance of FILE*
	 FILE* newFile = fopen(fname, "r");
	 insert(head, str);

   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
	 processCommandLoop(newFile, head);
	 removeFirst(head);

   //  4. close the file when processCommandLoop() returns
	 fclose(newFile);
 }
};

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
	Node* stringList = nullptr;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile, stringList);
   
  printf ("Goodbye\n");
  return 1;
 }