#include <iostream>
#include <unordered_map>
#include <stdexcept>
using namespace::std;

// std::list is usually built with a doubly linked list and offers O(1) removal and append. But we will
// todo: write this again with an STD list instead of our own since it is O(1)

class Node {
    public:
        Node *next = nullptr;
        Node *prev = nullptr;
        int value;
        int key;
};

class DoublyLinkedList{
    public:

    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void print () {
        Node *node = head;
        while(node){
            //cout << node->key;
            node = node->next;
        }
        //cout << "\n";
        //cout << "head is: " << head->key << "\n";
        //cout << "tail is: " << tail->key << "\n";
    }

    void add_front(Node * node){

        node->prev = nullptr;
        node->next = head;

        if (head == nullptr){
            tail = node;
        }
        else {
            head->prev = node;
        }

        head = node;
    }

    void access(Node * node){
        if (node == head) return;

        Node * prev = node->prev;
        Node * next = node->next;
        if (prev != nullptr){
            prev->next = next;
        }

        if (next != nullptr){
            next->prev = prev;
        }

        if (node == tail){
            tail = prev;
        }

        add_front(node);
    }

    int prune(){
        //print();
        if (tail){
            Node* prev = tail->prev;
            //cout << "pruning: " << tail->key << "\n";
            int key = tail->key;
            delete(tail);
            tail = prev;
            prev->next = nullptr;
            return key;
        }
        //cout << "not in a prunable state\n";
        throw logic_error("not in a prunable state");

    }

    private:
        Node *head;
        Node *tail;
};

class LRUCache {
public:
    LRUCache(int capacity):
        _capacity(capacity){
    }

    int get(int key) {
        //cout << "get: " << key << "\n";
        if (cache.find(key) == cache.end()){

           return -1;
        }
        Node * node = cache[key];
        _list.access(node);
        return node->value;
    }

    void print(){
        //_list.print();
    }

    void put(int key, int value) {
        //cout << "put: " << key << " value: " << value << "\n";
        Node* entry;

        //replace?
        if (cache.find(key) != cache.end()){
            entry = cache[key];
            entry->value = value;
            _list.access(entry);
        }
        else {
            //add it
            entry = new Node();
            entry->value = value;
            entry->key = key;
            cache[key] = entry;
            _list.add_front(entry);
            count++;
            ejectIfNeeded();

        }
    }

private:
    unordered_map<int, Node*> cache;
    int _capacity;
    int count = 0;
    DoublyLinkedList _list;
    void ejectIfNeeded(){

        if (count > _capacity){
            int key = _list.prune();
            cache.erase(key);
            count--;
        }
    }

};


int main(){
    LRUCache *lRUCache = new LRUCache(1);

    lRUCache->put(2, 1);
    lRUCache->get(2);
    lRUCache->put(3, 2);


}