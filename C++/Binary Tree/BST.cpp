#include <iostream>
using namespace std;

struct BST_node {
	float data;
	BST_node* left = NULL;
	BST_node* right = NULL;
};

// root node -> points to the first/root node of the BST
BST_node* root = NULL;

// INSERTION OF NODE
void insert_node();

// DELETION OF NODE
void delete_node(BST_node* root_node, int key);

// TREE TRAVERSAL ALGORITHMS USING RECURSION
void preorder_traversal(BST_node* root_node);
void postorder_traversal(BST_node* root_node);
void inorder_traversal(BST_node* root_node);

// SEARCHING
int search_specific_key(BST_node* root_node, int key);

// FUNCTIONS FOR FINDING MIN, MAX & AVERAGE
int max_value(BST_node* root_node);
int min_value(BST_node* root_node);
float avg_value(BST_node* root_node, int sum, int count);

int main() {

	int option;
	do {
		cout<<"\n------------------------------------------------"<<endl;
		cout<<"BINARY SEARCH TREE - BST	                        |"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		cout<<"1. INSERT A NODE                                 |"<<endl;
		cout<<"2. DELETE A NODE                                 |"<<endl;
		cout<<"3. DISPLAY TREE USING PREORDER TRAVERSAL         |"<<endl;
		cout<<"4. DISPLAY TREE USING POSTORDER TRAVERSAL        |"<<endl;
		cout<<"5. DISPLAY TREE USING INORDER TRAVERSAL          |"<<endl;
		cout<<"6. SEARCH A KEY VALUE                            |"<<endl;
		cout<<"7. MIN VALUE OF THE TREE                         |"<<endl;
		cout<<"8. MAX VALUE OF THE TREE                         |"<<endl;
		cout<<"9. AVERAGE VALUE OF THE NODES OF TREE            |"<<endl;
		cout<<"0. EXIT            								|"<<endl;
		cout<<"--------------------------------------------------"<<endl;

		cout<<"ENTER YOUR CHOICE: ";
		cin>>option;
		cout<<endl;

		if(option < 0 || option > 9) {
			cout<<"INVALID OPTION! PLEASE SELECT A CORRECT OPTION!"<<endl;
		} else {
			switch(option) {
				case 1:
					insert_node();
					break;
				case 2:
					int x;
					cout<<"ENTER A VALUE THAT YOU WANT TO DELETE: ";
					cin>>x;
					delete_node(root, x);
					break;
				case 3:
					preorder_traversal(root);
					break;
				case 4:
					postorder_traversal(root);
					break;
				case 5:
					inorder_traversal(root);
					break;
				case 6:
					int key;
					cout<<"ENTER A VALUE THAT YOU WANT TO SEARCH: ";
					cin>>key;
					if(search_specific_key(root, key) == 0) cout<<"TREE IS EMPTY"<<endl;
					else if(search_specific_key(root, key) == 1) cout<<"KEY IS FOUND!"<<endl;
					else cout<<"KEY IS NOT FOUND!"<<endl;
					break;
				case 7:
					if(min_value(root) == -1) cout<<"TREE IS EMPTY"<<endl;
					else cout<<"MINIMUM: "<<min_value(root)<<endl;
					break;
				case 8:
					if(max_value(root) == -1) cout<<"TREE IS EMPTY"<<endl;
					else cout<<"MAXIMUM: "<<max_value(root)<<endl;
					break;
				case 9:
					if(avg_value(root, 0, 0) > 0) {
						cout<<"AVERAGE OF ALL NODES: "<<avg_value(root, 0, 0)<<endl;
					}
					else cout<<"TREE IS EMPTY!"<<endl;
					break;
				default:
					cout<<"SEE YOU SOON... :)"<<endl;
					break;
			}
		}
	} while(option != 0);

	return 0;
}

// INSERTION OF NODE
void insert_node() {
	BST_node* new_node = new BST_node();
	cout<<"Enter a value: ";
	cin>>new_node->data;

	// checks whether the tree exists or not
	if(root == NULL) root = new_node;
	else {
		BST_node* ptr = root;
		BST_node* prev_temp = root;
		
		// traverse the tree for finding the correct position for insertion
		while(ptr != NULL) {
			prev_temp = ptr;
			
			if(new_node->data >= ptr->data) ptr = ptr->right;
			else ptr = ptr->left;
		}
		
		if(new_node->data >= prev_temp -> data) prev_temp -> right = new_node;
		else prev_temp -> left = new_node; 
	}
	cout<<"NODE IS SUCCESSFULLY INSERTED!\n";
}

// TREE TRAVERSAL ALGORITHMS
void preorder_traversal(BST_node* root_node) {
	if(root_node == NULL) return;

	cout<<root_node->data<<"->";
	preorder_traversal(root_node->left);
	preorder_traversal(root_node->right);
}

void postorder_traversal(BST_node* root_node) {
	if(root_node == NULL) return;

	postorder_traversal(root_node->left);
	postorder_traversal(root_node->right);
	cout<<root_node->data<<"->";	
}

void inorder_traversal(BST_node* root_node) {
	if(root_node == NULL) return;

	inorder_traversal(root_node->left);
	cout<<root_node->data<<"->";
	inorder_traversal(root_node->right);
}

// DELETION OF NODE
void delete_node(BST_node* root_node, int key) {
	if(root_node == NULL) {
		cout<<"TREE IS EMPTY!"<<endl;
		return;
	// delete the root node
	} else if(key == root_node->data) {
		BST_node* temp = root->right;
		BST_node* prev_temp = NULL;
		BST_node* del = root_node;
		while(temp->left != NULL) {
			prev_temp = temp;
			temp = temp->left;
		}
		prev_temp->left = NULL;
		temp->left = root->left;
		temp->right = root->right;
		root = temp;
		delete del;
		cout<<"NODE IS DELETED SUCCESSFULLY!"<<endl;
	} else {
		BST_node* temp = root_node;
		BST_node* prev_temp = NULL;
		// searching the key - whether the key exists or not
		while(temp->left != NULL && temp->right != NULL) {
			if(temp->data == key) break;
			prev_temp = temp;

			if(temp->data > key) temp = temp->left;
			else temp = temp->right;
		}

		if(temp->data != key && (temp->left == NULL && temp->right == NULL)) {
			cout<<"THE VALUE DOES NOT EXIST!"<<endl;
			return;
		// if key exists, then do the following:
		} else {
			BST_node* del = temp;
			// node that is to be deleted has only left subtree
			if(temp->right == NULL) {
				prev_temp->left = temp->left;
				delete del;
			// node that is to be deleted has only right subtree
			} else if(temp->left == NULL) {
				prev_temp->left = temp->right;
				delete del;
			// deleting a leaf node
			} else if(temp->left == NULL && temp->right == NULL) {
				prev_temp->left = prev_temp->right = NULL;
				delete del;
			} else {
				// if node that is to be deleted has subtree on both
				// left and right side
				BST_node* p = temp->left;
				BST_node* prev_p = NULL;
				if(p->right != NULL) {
					while(p->right != NULL) {
						prev_p = p;
						p = p->right;
					}
					prev_p->right = NULL;
					prev_temp->left = p;
					p->left = prev_p;
					p->right = temp->right;
					delete del;
				} 
				else {
					prev_temp->left = p;
					p->right = temp->right;
					delete del;
				}
			}
			cout<<"NODE IS DELETED SUCCESSFULLY!"<<endl;
		}
	}
}

// SEARCHING
int search_specific_key(BST_node* root_node, int key) {
	if(root_node == NULL) return 0;

	if(root_node->data == key) return 1;
	else {
		while(root_node != NULL) {
			if(root_node->data == key) return 1;

			if(key > root_node->data) root_node = root_node->right;
			else root_node = root_node->left;
		}

		if(root_node == NULL) return -1;
		else return 1;
	}
}

// FUNCTIONS FOR FINDING MIN, MAX & AVERAGE
int max_value(BST_node* root_node) {
	if(root_node == NULL) return -1;
	else {
		int max = 0;
		while(root_node != NULL) {
			// if(max < root_node->data) max = root_node->data;
			max = root_node->data;
			root_node = root_node->right;
		}
		return max;
	}
}

int min_value(BST_node* root_node) {
	if(root_node == NULL) return -1;
	else {
		int min = 0;
		while(root_node != NULL) {
			min = root_node->data;
			root_node = root_node->left;
		}
		return min;
	}
}

float avg_value(BST_node* root_node, int sum, int count) {
	if(root_node == NULL) return 0;

	sum += root_node->data;
	count++;
	cout<<sum<<"	"<<count<<endl;
	avg_value(root_node->left, sum, count);
	avg_value(root_node->right, sum, count);
	return (sum/count);
}




