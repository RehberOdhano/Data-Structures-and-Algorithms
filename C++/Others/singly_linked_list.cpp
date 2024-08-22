/*
AUTHOR: REHBER ODHANO
DATE: 01-10-2021
DATA STRUCTRES AND ALGORITHMS
LAB TASK: LINKED LIST OPERATIONS
*/

#include <iostream>
#include <math.h>
using namespace std;

struct node {
    float id;
    node* next;
};

node* head = NULL; // points to the first node
node* tail = NULL; // points to the last node

void insertNodeAtStart(); // insert node at start
void insertNodeAtEnd(); // insert node at end
void insertNodeAtNthPosition(); // insert node at specific position
void insertNodeAfterSpecificValue(); // insert node after specific value
void insertNodeBeforeSpecificValue(); // insert node before specific value
void deleteFirstNode(); // delete from start
void deleteLastNode(); // delete from end
void deleteNodeAtNthPosition(); // delete node at specific position
void deleteNodeAfterSpecificValue(); // delete node after specific value
void deleteNodeBeforeSpecificValue(); // delete node before specific value
bool isPalindrome();
void displayLinkedList();
void displayLLInReverseOrder();
// HELPER FUNCTIONS
// counts the length of the linked list
int countNumberOfNodes(node* start);
// finds a node of a given value
node* search(node* temp, int value);
// checks whether the list is empty or not
bool isEmpty();

int main()
{
    int option;
    do
    {
        cout<<"MENU"<<endl;
		cout<<"1. Insert Node At Start"<<endl;
		cout<<"2. Insert Node At End"<<endl;
		cout<<"3. Insert Node At Nth Position"<<endl;
		cout<<"4. Insert Node After Specific Value"<<endl;
		cout<<"5. Insert Node Before Specific Value"<<endl;
		cout<<"6. Delete First Node"<<endl;
		cout<<"7. Delete Last Node"<<endl;
		cout<<"8. Delete Node At Nth Position"<<endl;
		cout<<"9. Delete Node After Specific Value"<<endl;
		cout<<"10. Delete Node Before Specific Value"<<endl;
        cout<<"11. Check Palindrome"<<endl;
        cout<<"12. Display Linked List In Reverse Order"<<endl;
		cout<<"13. Display"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>option;
		cout<<endl;

        switch(option)
		{
			case 1:
				insertNodeAtStart();
				break;
			case 2:
				insertNodeAtEnd();
				break;
			case 3:
				insertNodeAtNthPosition();
				break;
            case 4:
				insertNodeAfterSpecificValue();
				break;
            case 5:
				insertNodeBeforeSpecificValue();
				break;
            case 6:
				deleteFirstNode();
				break;
            case 7:
				deleteLastNode();
				break;
            case 8:
				deleteNodeAtNthPosition();
				break;
            case 9:
				deleteNodeAfterSpecificValue();
				break;
            case 10:
				deleteNodeBeforeSpecificValue();
				break;
            case 11:
				if(isPalindrome()) cout<<"IT'S A PALINDROME!\n";
                else cout<<"IT'S NOT A PALINDROME!\n";
				break;
            case 12:
				displayLLInReverseOrder();
				break;
			case 13:
				displayLinkedList();
				break;
			default:
				cout<<"Thank you... :)"<<endl;
				break;
		}
    } while (option != 0);
    
    return 0;
}

// displays the linked list
void displayLinkedList()
{
    node* temp = head;
    cout<<"Linked List: ";
    if(isEmpty()) return;
    else
    {
        while(temp != NULL)
        {
            cout<<temp->id<<"->";
            temp = temp->next;
        }
    }
    cout<<"\n";
}

bool isEmpty()
{
    if(head == NULL)
    {
        cout<<"List is empty!\n";
        return true;
    }
    else return false;
}

int countNumberOfNodes(node* start)
{
    int count = 0;
    while(start != NULL)
    {
        count++;
        start = start->next;
    }
    return count;
}

node* search(node* temp, int value)
{
    if(isEmpty()) cout<<"List is empty!\n";
    while(temp->next != NULL)
    {
        if(temp->next->id == value) return temp;
        else temp = temp->next;
    }
    return temp;
}

void insertNodeAtStart()
{
    node* newNode = new node();
    if(head == NULL) head = tail = newNode;
    else 
    {
        newNode->next = head;
        head = newNode;
    }
    cout<<"Enter a value: ";
    cin>>newNode->id;
    cout<<"Node is inserted successfully!\n\n";
}

void insertNodeAtEnd()
{
    node* newNode = new node();
    // if the list is empty
    if(isEmpty()) head = tail = newNode;
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
    cout<<"Enter a value: ";
    cin>>newNode->id;
    newNode->next = NULL;
    cout<<"Node is inserted successfully!\n\n";
}

void insertNodeAtNthPosition()
{
    if(isEmpty()) return;
    int pos = 0;
    // finding the length of the linked list
    int count = countNumberOfNodes(head);
    // if list is empty
    if(count == 0)
    {
        insertNodeAtStart();
        return;
    }
    // this loop iterates until the user does not enter an valid input
    while(true)
    {
        cout<<"Enter a position where you want to insert the node: ";
        cin>>pos;
        // checks whether the input is -ve or greater than 
        // the (length + 1)
        if(pos <= 0 || pos > (count+1))
        {
            cout<<"Please enter a valid position!\n";
            continue;
        }
        else break;
    }

    if(pos == 1)
    {
        insertNodeAtStart();
        return;
    }
    else if(pos == (count+1))
    {
        insertNodeAtEnd();
        return;
    }
    else
    {
        node* newNode = new node();
        node* temp = head;
        for(int i = 1; i < (pos-1); i++)
            temp = temp->next;
        
        cout<<"Enter a value: ";
        cin>>newNode->id;
        newNode->next = temp->next;
        temp->next = newNode;
        cout<<"Node is inserted successfully!\n\n";
    }
}

void insertNodeAfterSpecificValue()
{
    if(isEmpty()) return;

    int key;
    cout<<"Enter the value after which the specific node is inserted: ";
    cin>>key;

    node* newNode = new node();

    if(key == head->id && head->next == NULL) insertNodeAtEnd();
    else if(key == head->id && head->next != NULL)
    {
        cout<<"KEY IS FOUND!\n";
        cout<<"Enter a value: ";
        cin>>newNode->id;
        newNode->next = head->next;
        head->next = newNode;
        cout<<"Node is inserted successfully!\n\n";
    }
    else
    {
        node* temp = search(head, key);
        if(temp->id != key && temp->next == NULL) cout<<"KEY NOT FOUND!\n";
        else
        {
            temp = temp->next;
            if(temp->id == key && temp->next == NULL) insertNodeAtEnd();
            else
            {
                cout<<"KEY IS FOUND!\n";
                cout<<"Enter a value: ";
                cin>>newNode->id;
                newNode->next = temp->next;
                temp->next = newNode;
                cout<<"Node is inserted successfully!\n\n";
            }
        }
    }

}

void insertNodeBeforeSpecificValue()
{
    if(isEmpty()) return;

    int key;
    cout<<"Enter the value before which the specific node is inserted: ";
    cin>>key;

    if(key == head->id && head->next == NULL) insertNodeAtStart();
    else if(key != head->id && head->next == NULL) cout<<"KEY NOT FOUND!\n";
    else
    {
        node* temp = search(head, key);
        if(temp->next == NULL) cout<<"KEY NOT FOUND!\n";
        else
        {
            cout<<"KEY IS FOUND!\n";
            node* temp_2 = temp->next;
            node* newNode = new node();
            cout<<"Enter a value: ";
            cin>>newNode->id;
            temp->next = newNode;
            newNode->next = temp_2;
            cout<<"Node is inserted successfully!\n\n";
        }
    }
}

void deleteFirstNode()
{
    node* temp = head;
    if(isEmpty()) return;
    else if(head->next == NULL) head = tail = NULL;
    else head = temp->next;
    delete temp;
    cout<<"Node is deleted successfully!\n\n";
}

void deleteLastNode()
{
    node* temp = head;
    int count = countNumberOfNodes(head);
    if(isEmpty()) return;
    else if(head->next == NULL) deleteFirstNode();
    else
    {
        for(int i = 1; i < (count - 1); i++)
            temp = temp->next;
        tail = temp;
        temp = temp->next;
        tail->next = NULL;
        delete temp;
        cout<<"Node is deleted successfully!\n\n";
    }
}

void deleteNodeAtNthPosition()
{
    int pos;
    int count = countNumberOfNodes(head);
    if(isEmpty()) return;

    while(true)
    {
        cout<<"Enter a position of node that you want to delete: ";
        cin>>pos;
        // checks whether the input is -ve or greater than 
        // the (length + 1)
        if(pos <= 0 || pos > count)
        {
            cout<<"Please enter a valid position!\n";
            continue;
        }
        else break;
    }

    if(pos == 1) deleteFirstNode();
    else if(pos == count) deleteLastNode();
    else
    {
        node* temp = head;
        for(int i = 1; i <= (pos - 2); i++)
            temp = temp->next;
        node* nodeToBeDeleted = temp->next;
        temp->next = nodeToBeDeleted->next;
        nodeToBeDeleted->next = NULL;
        delete nodeToBeDeleted;
        cout<<"Node is deleted successfully!\n\n";
    }
}

void deleteNodeAfterSpecificValue()
{
    if(isEmpty()) return;

    int key;
    cout<<"Enter the value after which you want to delete the node: ";
    cin>>key;

    if(key == head->id && head->next == NULL) 
        cout<<"END OF THE LIST!\n";
    // if list contains only two elements...
    // head->next->next represents the last element
    else if(key == head->id && head->next->next == NULL)
    {
        cout<<"KEY IS FOUND!\n";
        node* temp = head->next;
        tail = head;
        tail->next = NULL;
        delete temp;
        cout<<"Node is deleted successfully!\n\n";
    }
    else
    {
        node* temp = search(head, key);
        if(temp->next == NULL && temp->id != key) cout<<"KEY IS NOT FOUND!\n";
        else
        {
            temp = temp->next;
            if(temp->id == key && temp->next == NULL) cout<<"END OF THE LIST!\n";
            else
            {
                cout<<"KEY IS FOUND!\n";
                if(temp->next->next == NULL)
                {
                    tail = temp;
                    temp = temp->next;
                    tail->next = NULL;
                    delete temp;
                }
                else
                {
                    node* temp_2 = temp->next;
                    temp->next = temp_2->next;
                    temp_2->next = NULL;
                    delete temp_2;
                }
                cout<<"Node is deleted successfully!\n\n";
            }
        }
    }   
}

void deleteNodeBeforeSpecificValue()
{
    if(isEmpty()) return;

    int key;
    cout<<"Enter the value before which you want to delete the node: ";
    cin>>key;

    if(key == head->id && head->next == NULL) cout<<"Key is found but only one value exists!\n";
    else
    {
        node* temp = search(head, key);
        if(key == head->id) cout<<"KEY IS FOUND BUT IT'S THE HEAD ELEMENT!\n";
        else if(temp->next == NULL && temp->id != key) cout<<"KEY IS NOT FOUND!\n";
        else
        {
            if(temp == head)
            {
                cout<<"KEY IS FOUND!\n";
                deleteFirstNode();
            }
            else
            {
                cout<<"KEY IS FOUND!\n";
                node* temp_2 = temp;
                temp = temp->next;
                node* nodeToBeDeleted = temp_2;

                if(head->next == temp_2) temp_2 = head;
                else temp_2 = search(head, temp_2->id);

                temp_2->next = temp;
                nodeToBeDeleted->next = NULL;
                delete nodeToBeDeleted;
                cout<<"Node is deleted successfully!\n";
            }
        }
    }    
}

bool isPalindrome()
{
    int count = countNumberOfNodes(head);
    if(count == 2)
    {
        if(head->id == tail->id) cout<<"IT'S A PALINDROME!\n";
        else cout<<"IT'S NOT A PALINDROME!\n";
    }
    else
    {
        node* temp = head;
        if(count % 2 == 1)
        {
            int mid = ceil(count/2);
            for(int i = 1; i < mid; i++)
                temp = temp->next;
            
            node* afterMid = temp->next;
            temp = head;

            for(int i = 1; i < mid; i++)
            {
                if(temp->id != afterMid->id) return false;
                else
                {
                    temp = temp->next;
                    afterMid = afterMid->next;
                }
            }
            return true;
        }
        else
        {
            int mid = count/2;
            for(int i = 1; i < mid+1; i++)
                temp = temp->next;
            
            node* temp_2 = temp->next;
            temp = head;

            for(int i = 1; i < mid; i++)
            {
                if(temp->id != temp_2->id) return false;
                else
                {
                    temp = temp->next;
                    temp_2 = temp_2->next;
                }  
            }
            return true;
        }
    }
    
}

void displayLLInReverseOrder()
{
    if(isEmpty()) return;
    else
    {
        // first rotation
        node* temp = head;
        while(temp->next != tail)
            temp = temp->next;
        
        tail->next = head;
        head = tail;
        tail = temp;
        tail->next = NULL;

        // remaining rotations
        int count = countNumberOfNodes(head);
        for(int i = 1; i <= (count-2); i++)
        {
            temp = head;
            while(temp-> next != tail) temp = temp->next;
            tail->next = head->next;
            temp->next = NULL;
            head->next = tail;
            tail = temp;
        }
    }
}
