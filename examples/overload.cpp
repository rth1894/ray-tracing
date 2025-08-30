#include <iostream>
using namespace std;

class Complex {
    private:
        float real = 0, img = 0;

    public:
        Complex(float r = 0, float i = 0) : real(r), img(i) {}
        Complex operator+(const Complex& other) { return Complex(real + other.real, img + other.img); }
        Complex operator-(const Complex& other) { return Complex(real - other.real, img - other.img); }
        Complex operator*(const Complex& other) { return Complex(real * other.real, img * other.img); }
        void display() { cout << real << " + " << img << "i\n"; }
};

int main() {
    float real, img;
    int choice;
    Complex result;

    cout << "First number:\n";
    cout << "> ";
    cin >> real;
    cout << "> ";
    cin >> img;
    Complex c1(real, img);

    cout << "Second number:\n";
    cout << "> ";
    cin >> real;
    cout << "> ";
    cin >> img;
    Complex c2(real, img);


    while (true) {
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Exit\n> ";
        cin >> choice;
        switch(choice) {
            case 1:
                result = c1 + c2;
                cout << "SUM: ";
                result.display();
                break;
            case 2:
                result = c1 - c2;
                cout << "DIFF: ";
                result.display();
                break;
            case 3:
                result = c1 * c2;
                cout << "PRD: ";
                result.display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
