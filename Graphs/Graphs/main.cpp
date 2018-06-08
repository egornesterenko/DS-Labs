#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node {
    int top;
    Node* next;
};

class List {
public:
    Node* first = nullptr;
    void push(const int data);
    void clear();
    Node* returnFirst();
};

void List::push(const int data){
    auto* newElement = new Node;
    newElement->top = data;
    newElement->next = this->first;
    this->first = newElement;
}
void List::clear() {
    Node* curr = this->first;
    while (curr){
        Node* temp = curr;
        curr = NULL;
        curr = temp->next;
    }
}
Node* List::returnFirst(){
    return this->first;
}

int main() {
    int n;
    cout << "Введите количество вершин графа: ";
    cin >> n;
    vector<List*> list;
    for(int i = 0; i < n; i++) {
        auto *temp = new List;
        int s;
        cout << "Введите количество вершин смежных с вершиной " << i << ": ";
        cin >> s;
        for(int j = 0; j < s; j++) {
            int rib;
            cout << "Введите вершину смежную с " << i << ", число от 0 до " << n - 1 << ": ";
            cin >> rib;
            int v = {rib};
            temp->push(v);
        }
        list.push_back(temp);
    }
    
    for (int i = 0; i < n; i++) {
        Node * curr = list[i]->returnFirst();
        cout << i << " : ";
        while (curr) {
            cout << curr->top << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
    
    int dist[list.size()][list.size()];
    
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            dist[j][i] = 0;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        Node * curr = list[i]->returnFirst();
        while (curr){
            dist[i][curr->top] = 1;
            curr = curr->next;
        }
    }
    
    cout << endl;
    cout << "    ";
    for(int i = 0; i < n; i++) {
        cout << i << ' ';
    }
    cout << endl << endl;
    for (int l = 0; l < n; ++l) {
        cout << l << "  ";
        for (int i = 0; i < n; ++i) {
            cout << setw(2)<< dist[l][i];
        }
        cout << endl;
    }
    
    // Floyd–Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
            }
        }
    }
    cout << endl;
    cout << "    ";
    for(int i = 0; i < n; i++) {
        cout << i << ' ';
    }
    cout << endl << endl;
    for (int l = 0; l < n; ++l) {
        cout << l << "  ";
        for (int i = 0; i < n; ++i) {
            cout << setw(2) << dist[l][i];
        }
        cout << endl;
    }
    return 0;
}


