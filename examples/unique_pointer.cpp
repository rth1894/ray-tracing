#include <iostream>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> next; Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    private:
        std::unique_ptr<Node> head;

    public:
        void push_node(int value) {
            auto new_node = std::make_unique<Node>(value);
            new_node->next = std::move(head);
            head = std::move(new_node);
        }

        void pop_front() {
            if (head) { head = std::move(head->next); }
        }

        void print() const {
            Node* current = head.get();
            while (current) {
                std::cout << current->data << " ";
                current = current->next.get();
            }
            std::cout << "\n";
        }
};

int main() {
    LinkedList ll;

    ll.push_node(12);
    ll.push_node(10);
    ll.pop_front();
    ll.print();
    ll.push_node(90);
    ll.print();
}
