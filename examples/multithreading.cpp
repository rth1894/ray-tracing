#include <iostream>
#include <thread>
#include <vector>

// thread 1: [0 to n/4)
// thread 2: [n/4 to n/2)
// thread 3: [n/2 to 3n/4)
// thread 4: [3n/4 to n)

std::vector<int> nums(1000000, 1);
int partial_sums[4] = {0, 0, 0, 0};

void t1() {
    for (int i=0; i<250000; i++) {
        partial_sums[0] += nums[i];
    }
}
void t2() {
    for (int i=250000; i<500000; i++) {
        partial_sums[1] += nums[i];
    }
}
void t3() {
    for (int i=500000; i<750000; i++) {
        partial_sums[2] += nums[i];
    }
}
void t4() {
    for (int i=750000; i<1000000; i++) {
        partial_sums[3] += nums[i];
    }
}

int main() {
    std::thread task1(t1);
    std::thread task2(t2);
    std::thread task3(t3);
    std::thread task4(t4);

    std::cout << "MAIN: t1 ID: " << task1.get_id() << std::endl;
    std::cout << "MAIN: t2 ID: " << task2.get_id() << std::endl;
    std::cout << "MAIN: t3 ID: " << task3.get_id() << std::endl;
    std::cout << "MAIN: t4 ID: " << task4.get_id() << std::endl;

    if (task1.joinable()) { task1.join(); }
    if (task2.joinable()) { task2.join(); }
    if (task3.joinable()) { task3.join(); }
    if (task4.joinable()) { task4.join(); }

    std::cout << "Total: " << (partial_sums[0] + partial_sums[1] + partial_sums[2] + partial_sums[3]) << std::endl;
    std::cout << "Total should be: " << "1000000" << std::endl;

    return 0;
}
