// QUESTION 1---> 2 8 18 34 5 Because arr[i] = *(arr+i) = *(i+arr) = i[arr]

// QUESTION 2---> abcde will print as ch will treat as char* i.e. pointing to the first element of the first character of the string.




// QUESTION-3



#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
bool isPalindrom(Node* head){
    Node *fast = head, *slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *prev = NULL, *curr = slow, *Next = slow;
    while(curr!=NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        
    }
    slow->next = prev;
    Node* a = slow;
    Node* temp1 = head;
    Node* temp2 = a->next;
    while(temp1!=slow){
        if(temp1->val!=temp2->val) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

void Display(Node* head){
    Node* temp = head;
    if(temp==NULL) return;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    
    return ;
}

int main(){
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(30);
    Node* d = new Node(20);
    Node* e = new Node(10);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Display(head);
    cout<<" "<<endl;
    
    if(isPalindrom(head)) cout<<"Palindrom";
    else cout<<"Not Palindrom";
    
}



// QUESTION-4



#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) return head;
    
    ListNode* current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length++;
    }
    
    k = k % length;
    if (k == 0) return head;
    
    current->next = head;
    
    int stepsToNewHead = length - k;
    ListNode* newEnd = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newEnd = newEnd->next;
    }
    
    ListNode* newHead = newEnd->next;
    newEnd->next = nullptr;
    
    return newHead;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2;
    ListNode* rotatedList = rotateRight(head, k);
    
    cout << "Rotated list: ";
    printList(rotatedList);
    
    while (rotatedList) {
        ListNode* temp = rotatedList;
        rotatedList = rotatedList->next;
        delete temp;
    }
    
    return 0;
}




// QUESTION-5





#include<bits/stdc++.h>

using namespace std;

string smallestRotation(const string& S) {
    int n = S.size();
    string doubledS = S + S;
    vector<int> f(n * 2, -1);
    int k = 0;

    for (int j = 1; j < n * 2; ++j) {
        char sj = doubledS[j];
        int i = f[j - k - 1];

        while (i != -1 && sj != doubledS[k + i + 1]) {
            if (sj < doubledS[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }

        if (sj != doubledS[k + i + 1]) {
            if (sj < doubledS[k]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    return doubledS.substr(k, n);
}

int main() {
    string S = "cbabde";
    string result = smallestRotation(S);
    cout << "Lexicographically smallest rotation: " << result << endl;
    return 0;
}




// QUESTION-6




#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool areIsomorphic(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;
    if (root1 == nullptr || root2 == nullptr) return false;

    bool normal = areIsomorphic(root1->left, root2->left) && areIsomorphic(root1->right, root2->right);
    bool opposite = areIsomorphic(root1->left, root2->right) && areIsomorphic(root1->right, root2->left);

    return normal || opposite;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(4);

    if (areIsomorphic(root1, root2)) {
        cout << "The trees root1 and root2 are isomorphic." << endl;
    } else {
        cout << "The trees root1 and root2 are not isomorphic." << endl;
    }

    

    return 0;
}






