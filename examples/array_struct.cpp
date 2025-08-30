#include <iostream>

using namespace std;

struct arr {
    int a[3];
};

int main() {
    arr arr1 = {{1, 2, 3}};
    arr arr2 = {{4, 5, 6}};
    
    cout << "arr1: ";
    for(int i = 0; i < 3; i++) {
        cout << arr1.a[i] << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for(int i = 0; i < 3; i++) {
        cout << arr2.a[i] << " ";
    }
    cout << endl;

    return 0;
}
