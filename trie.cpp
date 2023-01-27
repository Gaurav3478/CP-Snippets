class Node {
public:
    int data;
    map<int, Node *> children;
    bool isTerminal;

    Node(int d) {
        data = d;
        isTerminal = false;
    }
};

class Trie {
    Node *root;

public:
    Trie()  {
        root = new Node(0);
    }

    void insert(vector<int> vect) {
        Node *temp = root;
        for(int i = 0; i < vect.size(); i++) {
            if(temp->children.find(vect[i]) != temp->children.end()) {
                temp = temp->children[vect[i]];
            }
            else {
                Node *newNode = new Node(vect[i]);
                temp->children[vect[i]] = newNode;
                temp = newNode;
            }
        }
        temp->isTerminal = true;
    }

    int search(vector<int> vect) {
        Node *temp = root;
        for(int i = 0; i < vect.size(); i++) {
            if(temp->children.find(vect[i]) == temp->children.end()) {
                return false;
            }
            temp = temp->children[vect[i]];

        return temp->isTerminal;
    }
};
