#include <iostream>
#include <memory>
#include <string>

class Node {
    public:
        std::string name;
        std::weak_ptr<Node> next;

        Node(std::string n) : name(n) {};
        ~Node() { std::cout << "Destructor called for " << name << std::endl; }
};

int main() {
    auto a = std::make_shared<Node>("A");
    auto b = std::make_shared<Node>("B");

    a->next = b;
    b->next = a;

    if (auto nextA = a->next.lock()) {
        std::cout << "a->next is " << nextA->name << std::endl;
    }

    if (auto nextB = b->next.lock()) {
        std::cout << "b->next is " << nextB->name << std::endl;
    }

    return 0;
}
