//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        Node* temp = head;
        int i=0;
        while(temp){
            if(i%2==0){
                if(temp->next!=NULL && temp->data > temp->next->data){
                    int x = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = x;
                }
            }
            else{
                if(temp->next!=NULL && temp->data < temp->next->data){
                    int x = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = x;
                }
            }
            i++;
            temp = temp->next;        
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = new Node(x);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.zigZag(head);
        print(ans);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends