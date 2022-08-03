/*
AUTHOR: REHBER
REG. NO. SP19-BCS-024
DSA LAB MID-TERM EXAMINATION 2021
SUBMITTED TO: SIR INAYAT-UR-REHMAN
DATE: 22/11/2021
*/

// required libraries
#include <iostream>
#include <string>
using namespace std;

// required structures
struct patient {
    int patient_id;
    int age;
    string name;
    string assigned_dept;

    patient* forward = NULL;
};

struct doctor {
    int doctor_id;
    string name;
    string dept;

    doctor* next = NULL;
    patient* next_patient = NULL;
};

// REQUIRED POINTERS
// for dequeue
patient* first = NULL;
patient* last = NULL;

// for circular queue
patient* front;
patient* rear;

// for priority queue
patient* p_front = NULL;
patient* p_rear = NULL;

// points to the start and end of the doctor's list respectively
doctor* head = NULL;
doctor* tail = NULL;

// TASKS
void doubleEndedQueueOfENTPatients(doctor* ENT);
void circularQueueOfSkinPatients(doctor* SKIN);
void priorityQueueOfCardiacPatients(doctor* CARDIAC);

// HELPER FUNCTIONS
// for dequeue
void insertAtFront(patient* start, string assigned_dept);
void insertAtRear(patient* start, string assigned_dept);
void deleteFromFront(patient* start);
void deleteFromRear(patient* start);
// for circular queue
void insertAtRearInCircularQueue(patient* start, string assigned_dept);
void deleteFromFrontInCircularQueue(patient* start, string assigned_dept);
// for priority queue
void insertPatientRecord(patient* start, string assigned_dept);
void deletePatientRecord(patient* start, string assigned_dept);
// creating a list of 3 different doctors 
void createDoctorsList();
// display patients records based on the choice of dept
void displayPatientsList(int choice, patient* start);

int main() {

    int option;
    createDoctorsList();

    do {
        cout<<"--------------------------------------------\n";
        cout<<"MAIN MENU"<<endl;
        cout<<"--------------------------------------------\n";
		cout<<"1. ENT DOCTOR"<<endl;
		cout<<"2. SKIN DOCTOR"<<endl;
		cout<<"3. CARDIAC DOCTOR"<<endl;
		cout<<"4. DISPLAY PATIENT'S LIST"<<endl;
		cout<<"0. EXIT"<<endl;
        cout<<"--------------------------------------------\n";
		cout<<"Enter your choice: ";
		cin>>option;
		cout<<endl;

        if(option < 0 || option > 4) {
            cout<<"Please select a valid option!\n";
        } else {
            switch(option) {
                case 1:
                    doubleEndedQueueOfENTPatients(head);
                    break;
                case 2:
                    circularQueueOfSkinPatients(head->next);
                    break;
                case 3:
                    priorityQueueOfCardiacPatients(tail);
                    break;
                case 4:
                    int choice;
                    patient* temp;
                    cout<<"Select your option...\n";
                    cout<<"1. ENT PATIENT'S LIST    2. SKIN PATIENT'S LIST      3. CARDIAC PATIENT'S LIST\n";
                    cin>>choice;
                    while(choice < 0 || choice > 3) {
                        cout<<"Please select a valid option!\n";
                        cout<<"Select 1 option...\n";
                        cout<<"1. ENT PATIENT'S LIST    2. SKIN PATIENT'S LIST      3. CARDIAC PATIENT'S LIST";
                        cin>>choice;
                    }
                    if(option == 1) temp = head->next_patient;
                    else if(option == 2) temp = head->next->next_patient;
                    else temp = tail->next_patient;
                    
                    displayPatientsList(choice, temp);
                    break;
                default:
                    cout<<"Thank You... :)\n";
            }
        }
	
    } while (option != 0);
    
    return 0;
}

void createDoctorsList() {
    for(int i = 0; i < 3; i++) {
        doctor* node = new doctor();
        if(head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
        cout<<"Inserting the node...\n";
        cout<<"Enter your ID: ";
        cin>>node->doctor_id;
        cout<<"Enter your name: ";
        cin>>node->name;
        cout<<"Enter your dept: ";
        cin>>node->dept;
        tail->next = NULL;
    } 
}

void displayPatientsList(int choice, patient* start) {

    if(start == NULL) cout<<"NO RECORD... LIST IS EMPTY!\n";
    else {
        if(choice == 1) cout<<"ENT PATIENT'S LIST...\n";
        else if(choice == 2) cout<<"SKIN PATIENT'S LIST...\n";
        else cout<<"CARDIAC PATIENT'S LIST...\n";
        cout<<"------------------------------------------------\n";

        patient* temp = start;
        while(temp != NULL) {
            cout<<temp->age<<" ";
            temp = temp->forward;
        }
        cout<<"\n";
        cout<<"------------------------------------------------\n";
    }
}

void doubleEndedQueueOfENTPatients(doctor* ENT) {
    int option;
    do {
        cout<<"\n---------------------------\n";
        cout<<"ENT PATIENT'S MENU"<<endl;
        cout<<"---------------------------\n";
		cout<<"1. INSERT AT FRONT"<<endl;
		cout<<"2. INSERT AT REAR"<<endl;
		cout<<"3. DELETE FROM FRONT"<<endl;
		cout<<"4. DELETE FROM REAR"<<endl;
		cout<<"0. EXIT"<<endl;
        cout<<"---------------------------\n";
		cout<<"Enter your choice: ";
		cin>>option;
		cout<<endl;

        if(option < 0 || option > 4) {
            cout<<"Please select a valid option!\n";
        } else {
            switch(option) {
                case 1:
                    insertAtFront(ENT->next_patient, "ENT"); 
                    break;
                case 2:
                    insertAtRear(ENT->next_patient, "ENT");
                    break;
                case 3:
                    deleteFromFront(ENT->next_patient);
                    break;
                case 4:
                    deleteFromRear(ENT->next_patient);
                    break;
                default:
                    cout<<"Back to MAIN MENU\n";
            }
        }
	
    } while (option != 0);

}

void insertAtFront(patient* start, string assigned_dept) {
    patient* node = new patient();
    if(start == NULL) {
        start->forward = node;
        first = last = node;
    }
    else {
        last = start->forward;
        node->forward = start->forward;
        start->forward = node;
        first = node;
    }
    cout<<"Enter patient's ID: ";
    cin>>node->patient_id;
    cout<<"Enter patient's name: ";
    cin>>node->name;
    cout<<"Enter patient's age: ";
    cin>>node->age;
    node->assigned_dept = assigned_dept;
    cout<<"RECORD IS SUCCESSFULLY INSERTED IN THE ENT PATIENT'S LIST!\n";

}

void insertAtRear(patient* start, string assigned_dept) {
    patient* node = new patient();
    if(start == NULL) {
        first = last = node;
        start->forward = node;
    }
    else {
        last->forward = node;
        last = node;
    }
    cout<<"Enter patient's ID: ";
    cin>>node->patient_id;
    cout<<"Enter patient's name: ";
    cin>>node->name;
    cout<<"Enter patient's age: ";
    cin>>node->age;
    node->assigned_dept = assigned_dept;
    cout<<"RECORD IS SUCCESSFULLY INSERTED IN THE ENT PATIENT'S LIST!\n";
}

void deleteFromFront(patient* start) {
    if(start == NULL) cout<<"ENT PATIENT'S LIST IS EMPTY!\n";
    else if(first == last) {
        patient* p = first;
        start = first = last = NULL;
        p->forward = NULL;
        delete p;
    }
    else {
        patient* p = start->forward;
        start->forward = p->forward;
        p->forward = NULL;
        delete p;
        cout<<"PATIENT'S RECORD FROM ENT LIST IS SUCCESSFULLY DELETED!\n";
    }
}

void deleteFromRear(patient* start) {
    if(start == NULL) cout<<"ENT PATIENT'S LIST IS EMPTY!\n";
    else if(first == last) {
        patient* p = first;
        start = first = last = NULL;
        p->forward = NULL;
        delete p;
    }
    else {
        patient* temp = first;
        patient* p = last;
        while(temp->forward != last) temp = temp->forward;
        temp->forward = NULL;
        last = temp;
        delete p;
        cout<<"PATIENT'S RECORD FROM ENT LIST IS SUCCESSFULLY DELETED!\n";
    }
}

void circularQueueOfSkinPatients(doctor* SKIN) {
    int option;
    do {
        cout<<"\n---------------------------\n";
        cout<<"MENU"<<endl;
        cout<<"---------------------------\n";
		cout<<"1. INSERT AT FRONT"<<endl;
		cout<<"2. DELETE FROM REAR"<<endl;
		cout<<"0. EXIT"<<endl;
        cout<<"---------------------------\n";
		cout<<"Enter your choice: ";
		cin>>option;
		cout<<endl;

        if(option < 0 || option > 2) {
            cout<<"Please select a valid option!\n";
        } else {
            switch(option) {
                case 1:
                    insertAtRearInCircularQueue(SKIN->next_patient, "SKIN");
                    break;
                case 2:
                    deleteFromFrontInCircularQueue(SKIN->next_patient, "SKIN");
                    break;
                default:
                    cout<<"Back to MAIN MENU\n";
            }
        }
	
    } while (option != 0);
}

void insertAtRearInCircularQueue(patient* start, string assigned_dept) {
    patient* node = new patient();
    if(start == NULL) {
        start->forward = node;
        front = rear = node;
    } else {
        rear->forward = node;
        rear = rear->forward;
    }

    node->forward = front;
    cout<<"Enter patient's ID: ";
    cin>>node->patient_id;
    cout<<"Enter patient's name: ";
    cin>>node->name;
    cout<<"Enter patient's age: ";
    cin>>node->age;
    node->assigned_dept = assigned_dept;
    cout<<"RECORD IS SUCCESSFULLY INSERTED IN THE SKIN PATIENT'S LIST!\n";

}

void deleteFromFrontInCircularQueue(patient* start, string assigned_dept) {
    patient* node = new patient();
    if(start == NULL) cout<<"NO RECORD... LIST IS EMPTY!\n";
    else if(front == rear) {
        patient* p = front;
        start = front = rear = NULL;
        p->forward = NULL;
        delete p;
    }
    else {
        patient* p = front;
        front = front->forward;
        start->forward = front;
        p->forward = NULL;
        delete p;   
        cout<<"PATIENT'S RECORD FROM SKIN LIST IS SUCCESSFULLY DELETED!\n";
    }

}

void priorityQueueOfCardiacPatients(doctor* CARDIAC) {

    int option;
    do {
        cout<<"\n---------------------------\n";
        cout<<"MENU"<<endl;
        cout<<"---------------------------\n";
		cout<<"1. INSERT AT PATIENT RECORD "<<endl;
		cout<<"2. DELETE PATIENT RECORD "<<endl;
		cout<<"0. EXIT"<<endl;
        cout<<"---------------------------\n";
		cout<<"Enter your choice: ";
		cin>>option;
		cout<<endl;

        if(option < 0 || option > 2) {
            cout<<"Please select a valid option!\n";
        } else {
            switch(option) {
                case 1:
                    insertPatientRecord(CARDIAC->next_patient, "SKIN");
                    break;
                case 2:
                    deletePatientRecord(CARDIAC->next_patient, "SKIN");
                    break;
                default:
                    cout<<"Back to MAIN MENU\n";
            }
        }
	
    } while (option != 0);
}

void insertPatientRecord(patient* start, string assigned_dept) {
    patient* node = new patient();
    cout<<"Enter your age: ";
    cin>>node->age;

    if(start == NULL) {
        start->forward = node;
        p_front = p_rear = node;
    } else if(node->age <= p_front->age) {
        node->forward = p_front;
        start->forward = node;
        p_front = node;
    } else if(node->age >= p_rear->age) {
        p_rear->forward = node;
        p_rear = node;
    } else {
        // searching for the right position
        patient* temp = p_front;
        while(temp != NULL) {
            if(temp->age <= node->age) break;
            else temp = temp->forward;
        }

        patient* prev_temp = p_front;
        while(prev_temp->forward != temp) {
            prev_temp = prev_temp->forward;
        }

        prev_temp->forward = node;
        node->forward = temp;
    }

    cout<<"Enter patient's ID: ";
    cin>>node->patient_id;
    cout<<"Enter patient's name: ";
    cin>>node->name;
    node->assigned_dept = assigned_dept;
    cout<<"RECORD IS SUCCESSFULLY INSERTED IN THE CARDIAC PATIENT'S LIST!\n";

}

void deletePatientRecord(patient* start, string assigned_dept) {
    if(start == NULL) cout<<"NO RECORD.... LIST IS EMPTY!\n";
    else if(p_front == p_rear) {
        patient* p = p_front;
        start = p_front = p_rear = NULL;
        p->forward = NULL;
        delete p;
        cout<<"PATIENT'S RECORD FROM CARDIAC LIST IS SUCCESSFULLY DELETED!\n";
    } else {
        patient* p = p_front;
        p_front = p->forward;
        start->forward = p_front;
        p->forward = NULL;
        delete p;
        cout<<"PATIENT'S RECORD FROM CARDIAC LIST IS SUCCESSFULLY DELETED!\n";
    }

}


