#include <iostream>
#include <string>
using namespace std;

struct ride {
    string rider_name;
    string current_location = "";
    string destination = "";
    float distance = 10;
    float charges = 1500;

    ride* forward = NULL;
};

struct car_data {
    string driver_name;
    string car_name;
    int reg_num;
    int car_type;
    float total_earning = 0.0f;

    car_data* next = NULL;
    car_data* prev = NULL;
    ride* rider = NULL;
};


string arr[4][4] = {
    {"HYDERABAD", "ISLAMABAD", "4000", "1330"},
    {"KARACHI", "ISLAMABAD", "5000", "1330"},
    {"ISLAMABAD", "KARACHI", "5000", "1330"},
    {"ISLAMABAD", "HYDERABAD", "4000", "1330"},
};


car_data* head = NULL;
car_data* tail = NULL;

ride* start = NULL;

// TASKS
void registerNewCar();
void displayDetailOfRegisteredCars();
void displayType2Cars();
void addNewRide();
void displayRides();
void totalEarningOfAnSpecificCar(int x);
void displayEarningsOfAllCars();

int main() {
    int option;
    do {

        cout<<"-----------------------------------------------------------------\n";
        cout<<"CAREEM MANAGEMENT SYSTEM                                        |\n";
        cout<<"-----------------------------------------------------------------\n";
		cout<<"1. REGISTER NEW CAR                                             |\n";
		cout<<"2. DISPLAY DETAILS OF ALL REGISTERED CARS                       |\n";
		cout<<"3. DISPLAY TYPE 2 CARS                                          |\n";
		cout<<"4. ADD NEW RIDE                                                 |\n";
		cout<<"5. DISPLAY RIDES WITH DETAIL                                    |\n";
		cout<<"6. TOTAL EARNING OF A SPECIFIC CAR                              |\n";
		cout<<"7. DISPLAY EARNING OF ALL CARS                                  |\n";
		cout<<"0. EXIT                                                         |\n";
        cout<<"-----------------------------------------------------------------\n";
		cout<<"SELECT A OPTION: ";
		cin>>option;
		cout<<endl;

        while(true) {
            if(option < 0 || option > 7) {
                cout<<"PLEASE SELECT A VALID OPTION!\n";
                cout<<"SELECT A OPTION: ";
                cin>>option;
                continue;
            } else break;
        }

        switch(option) {
			case 1:
				registerNewCar();
				break;
			case 2:
				displayDetailOfRegisteredCars();
				break;
			case 3:
				displayType2Cars();
				break;
			case 4:
				addNewRide();
				break;
			case 5:
				displayRides();
				break;
			case 6:
                int x;
                cout<<"Enter the type of car [1/2], that you want to check the total earning: ";
                cin>>x;
				totalEarningOfAnSpecificCar(x);
				break;
            case 7:
				displayEarningsOfAllCars();
				break;
			default:
				cout<<"Thank you for visiting careem... :)"<<endl;
				break;
		}
    } while (option != 0);

    return 0;
}

void registerNewCar() {
    car_data* new_car = new car_data();
    if(head == NULL) head = tail = new_car;
    else {
        tail->next = new_car;
        new_car->prev = tail;
        tail = new_car;
    }
    new_car->rider = NULL;
    cout<<"Enter your name: ";
    cin>>new_car->driver_name;
    cout<<"Enter car name: ";
    cin>>new_car->car_name;
    cout<<"Enter registration number of the car: ";
    cin>>new_car->reg_num;
    cout<<"Enter type of car: ";
    cin>>new_car->car_type;

    cout<<"CAR IS SUCCESSFULLY REGISTERED!\n";
}

void displayDetailOfRegisteredCars() {
    if(head == NULL) cout<<"LIST IS EMPTY!\n";
    else {
        cout<<"LIST OF REGISTERED CARS:\n";
        cout<<"------------------------------\n";
        car_data* temp = head;
        while(temp != NULL) {
            cout<<"DRIVER NAME: "<<temp->driver_name<<endl;
            cout<<"CAR NAME: "<<temp->car_name<<endl;
            cout<<"REGISTRATION NUMBER: "<<temp->reg_num<<endl;
            cout<<"TYPE: "<<temp->car_type<<endl;
            if(temp->total_earning != 0) cout<<"TOTAL EARNING: "<<temp->total_earning<<endl;
            temp = temp->next;
            cout<<"------------------------------\n";
        }
        cout<<endl;
    }
}

void displayType2Cars() {
    if(head == NULL) cout<<"LIST IS EMPTY!"<<endl;
    else {
        car_data* temp = head;
        cout<<"LIST OF TYPE-2 CARS: "<<endl;
        cout<<"------------------------------\n";
        while(temp != NULL) {
            if(temp->car_type == 2) {
                cout<<"DRIVER NAME: "<<temp->driver_name<<endl;
                cout<<"CAR NAME: "<<temp->car_name<<endl;
                cout<<"REGISTRATION NUMBER: "<<temp->reg_num<<endl;
                cout<<"TYPE: "<<temp->car_type<<endl;
                if(temp->total_earning != 0) cout<<"TOTAL EARNING: "<<temp->total_earning<<endl;
                cout<<"------------------------------\n";
            }
            temp = temp->next;
        }
        if(temp == NULL && temp->car_type != 2) cout<<"CAR NOT FOUND!"<<endl;
        cout<<endl;
    }
}

void addNewRide() {
    ride* new_ride = new ride();
    if(start == NULL) start = new_ride;
    else {
        while(start->forward != NULL) 
            start = start->forward;
        start->forward = new_ride;
        new_ride = start;
    }
    
    int car_num;
    string current_location, destination;
    cout<<"Enter the car number you've booked: ";
    cin>>car_num;

    car_data* temp = head;
    while(temp != NULL) {
        if(temp->reg_num == car_num) break;
        else temp = temp->next;
    }

    if(temp != NULL) {
        cout<<"FOUND THE CAR!\n";
        cout<<"Enter your name: ";
        cin>>new_ride->rider_name;
        cout<<"Enter your current_location: ";
        cin>>current_location;
        cout<<"Enter where you want to go: ";
        cin>>destination;

        for(int i = 0; i < 4; i++) {
            int j = 0;
            if(current_location == arr[i][j] && destination == arr[i][++j]) {
                new_ride->current_location = current_location;
                new_ride->destination = destination;
                new_ride->charges = stof(arr[i][2]);
                new_ride->distance = stof(arr[i][3]);
                break;               
            }
        }

        if(new_ride->current_location == "") new_ride->current_location = current_location;
        else if(new_ride->destination == "") new_ride->destination = destination;
        else {
            new_ride->current_location = current_location;
            new_ride->destination = destination;
        }

        temp->rider = new_ride;
        
        temp->total_earning += new_ride->charges;
        cout<<"RIDE IS SUCCESSFULLY ADDED!\n";

    } else cout<<"OOPS! CAR NOT FOUND!\n";
}


void displayRides() {
    if(start == NULL) cout<<"LIST IS EMPTY!\n";
    else {
        cout<<"DETAILS OF ALL RIDES:\n";
        cout<<"------------------------------\n";
        car_data* temp = head;
        while(temp != NULL) {
            if(temp->rider != NULL) {
                ride* front = temp->rider;
                while(front != NULL) {
                    cout<<"DRIVER NAME: "<<temp->driver_name<<endl;
                    cout<<"CAR TYPE: "<<temp->car_type<<endl;
                    cout<<"CAR REGISTRATION NUMBER: "<<temp->reg_num<<endl;
                    cout<<"RIDER NAME: "<<front->rider_name<<endl;
                    cout<<"FROM: "<<front->current_location<<endl;
                    cout<<"TO: "<<front->destination<<endl;
                    cout<<"CHARGES: "<<front->charges<<endl;
                    cout<<"DISTANCE: "<<front->distance<<endl;
                    cout<<"------------------------------\n";
                    front = front->forward;
                }
            }
            temp = temp->next;
        }
    }
}

void totalEarningOfAnSpecificCar(int x) {
    if(head == NULL) cout<<"LIST IS EMPTY!"<<endl;
    else {
        car_data *temp = head;
        while(temp != NULL) {
            if(temp->car_type == x) {
                cout<<"TOTAL EARNING OF CAR TYPE "<<x<<" IS: "<<temp->total_earning<<endl;
                break;
            }
            temp = temp->next;
        }
    }
}

void displayEarningsOfAllCars() {
    if(head == NULL) cout<<"LIST IS EMPTY!"<<endl;
    else {
        car_data *temp = head;
        cout<<"TOTAL EARNINGS OF ALL CARS:\n";
        cout<<"------------------------------\n";
        while(temp != NULL) {
            cout<<"TOTAL EARNINGS OF CAR TYPE "<<temp->car_type<<" IS: "<<temp->total_earning<<endl;
            temp = temp->next;
        }
    }
}
