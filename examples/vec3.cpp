#include <iostream>
using namespace std;

struct Vec3 {
    float x = 0, y = 0, z = 0;
};

Vec3 operator+(const Vec3& a, const Vec3& b) {
    return { (a.x + b.x), (a.y + b.y), (a.z + b.z) };
}

Vec3 operator-(const Vec3& a, const Vec3& b) {
    return { (a.x - b.x), (a.y - b.y), (a.z - b.z) };
}

Vec3 operator*(const Vec3& a, float num) {
    return { (a.x * num), (a.y * num), (a.z * num) };
}

float dot(const Vec3& a, const Vec3& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vec3 cross(const Vec3& a, const Vec3& b) {
    return { (a.y*b.z - a.z*b.y), (a.z*b.x - a.x*b.z), (a.x*b.y - a.y*b.x) };
}

int main() { 
    int choice;
    Vec3 a, b, result;

    while (true) {
        cout << "1. Input\n2. Add\n3. Subtract\n4. Scalar\n5. Dot\n6. Cross\n7. Display vectors\n8. Exit\n>";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Vector a:\n";
                cout << "x: ";
                cin >> a.x;
                cout << "y: ";
                cin >> a.y;
                cout << "z: ";
                cin >> a.z;
                             ;
                cout << "Vect;or b:\n";
                cout << "x: ";
                cin >> b.x;
                cout << "y: ";
                cin >> b.y;
                cout << "z: ";
                cin >> b.z;

                cout << "\n\n";

                break;

            case 2:
                result = a + b;
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 3:
                result = a - b;
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 4:
                float num;

                cout << "Enter number to multiply with: ";
                cin >> num;
                result = a * num;
                cout << "Scalar with a:\n";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << endl;
                result = b * num;
                cout << "Scalar with b:\n";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 5:
                float dot_prod;
                dot_prod = dot(a, b);
                cout << "Result: " << dot_prod << "\n\n";
                break;

            case 6:
                result = cross(a,b);
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 7:
                cout << "A is ";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                cout << "B is ";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 8:
                cout << "Exiting\n\n";
                return 0;
            
            default:
                cout << "INVALID CHOICE!\n\n";
        }
    }

    return 0;
}
