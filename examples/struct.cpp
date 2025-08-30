#include <iostream>
#include <vector>

struct vec3 {
    std::vector<float> data[3];
};

void display(vec3 v);

int main() {
    vec3 v;
    for (int i = 0; i < 3; ++i) {
        float value;
        std::cout << "Enter value for data[" << i << "]: ";
        std::cin >> value;
        v.data[i].push_back(value);
    }
    display(v);

    v.data[2].pop_back();
    if (v.data[2].empty()) {
        std::cout << "YAYYY\n";
    }

    std::cout << "After:\n";
    display(v);

    return 0;
}

void display(vec3 v) {
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i) {
        if (v.data[i].empty()) {
            std::cout << "data[" << i << "] is empty." << std::endl;
            continue;
        }
        std::cout << "data[" << i << "]: " << v.data[i][0];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
