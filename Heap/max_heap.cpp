#include <iostream>
#include <cmath>
using namespace std;

class MaxHeap {
	public:
		int* heap_arr;
		int max_size;
		int current_size = -1;

	public:
		MaxHeap(int size);
		// ~MaxHeap();
		void insert(int x);
		void delete_item();
		void display_heap();

		// UTILITY FUNCTION TO SWAP TWO NUMBERS
		// void swap();
};

MaxHeap::MaxHeap(int size) {
	max_size = size;
	heap_arr = new int[max_size];
	// INITIALIZING THE ELEMENTS OF MaxHeap WITH THE INFINITE VALUE
	for(int i = 0; i < size; i++) {
		heap_arr[i] = -1;
	}
}

void MaxHeap::display_heap() {
	if(current_size == -1) {
		cout<<"Heap is empty!"<<endl;
	} else {
		cout<<"MIN HEAP"<<endl;
		int temp = 0;
		while(temp <= current_size) {
			cout<<heap_arr[temp]<<endl;
			temp++;
		}
		cout<<endl;
	}
}

void MaxHeap::insert(int x) {
	if(current_size == max_size) {
		cout<<"OverFlow... Can't insert item in the heap!"<<endl;
		return;
	} else {

		if(current_size == -1) {
			heap_arr[++current_size] = x;			
		} else {
			heap_arr[++current_size] = x;
			int index = current_size;
			int temp = 0;
			while(index >= 0) {
				if(index == 0) break;
				if(heap_arr[index] > heap_arr[abs(index-1)/2]) break;
				if(heap_arr[index] < heap_arr[abs(index-1)/2]) {
					temp = heap_arr[(index-1)/2];
					heap_arr[(index-1)/2] = heap_arr[index];
					heap_arr[index] = temp;
				}
				index = (abs(index-1))/2;
				cout<<"temp->"<<temp<<"	index->"<<index<<endl;
			}
			
		}
		heap_arr[++current_size] = x;
		cout<<"Successfully inserted!"<<endl;
	}
}

void MaxHeap::delete_item() {
	if(current_size == -1) {
		cout<<"Min heap is empty"<<endl;
		return;
	} else {
		int temp = 0, index = 0, max_value = 0;
		heap_arr[0] = heap_arr[current_size--];

		for(int i = 0; i < current_size; i++) {

			if(index > current_size) break;

			max_value = max(heap_arr[(2*index)+1], heap_arr[(2*index)+2]);
			if(max_value != -1) {
				if(heap_arr[abs(index-1)/2] < max_value && heap_arr[(2*index)+1] 
					== max_value) {

					temp = heap_arr[abs(index-1)/2];
					heap_arr[abs(index-1)/2] = heap_arr[(2*index)+1];
					heap_arr[(2*index)+1] = temp;
					index = (2*index)+1;
				}

				if(heap_arr[abs(index-1)/2] < max_value && heap_arr[(2*index)+2] 
					== max_value) {

					temp = heap_arr[abs(index-1)/2];
					heap_arr[abs(index-1)/2] = heap_arr[(2*index)+2];
					heap_arr[(2*index)+2] = temp;
					index = (2*index)+2;
				}
				cout<<"temp->"<<temp<<"		index->"<<index<<endl;
			}
		}
		cout<<"ITEM IS SUCCESSFULL DELETED!"<<endl;
	}
}

int main() {

	int option;
	MaxHeap max_heap(5);

	do {
		cout<<"MENU - MIN HEAP"<<endl;
		cout<<"1. INSERT A VALUE"<<endl;
		cout<<"2. DELETE A VALUE"<<endl;
		cout<<"3. DISPLAY THE MIN HEAP"<<endl;
		cout<<"0. EXIT"<<endl;

		cout<<"SELECT AN OPTION FROM THE ABOVE MENU"<<endl;
		cin>>option;

		if(option < 0 || option > 3) {
			cout<<"INVALID OPTION... PLEASE SELECT AN APPROPRIATE OPTION..."<<endl;
		} else {
			switch(option) {
				case 1:
					int x;
					cout<<"ENTER A NUMBER: "<<endl;
					cin>>x;
					max_heap.insert(x);
					break;
				case 2:
					max_heap.delete_item();
					break;
				case 3:
					max_heap.display_heap();
					break;
				default:
					cout<<"Thank You... :)"<<endl;
					break;
			}
		}

	} while(option != 0);

	return 0;
}