#include <iostream>
#include <cmath>

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

Vec3 operator/(const Vec3& a, float scalar) {
    return { (a.x / scalar), (a.y / scalar), (a.z / scalar) };
}

Vec3 operator*(const Vec3& a, float num) {
    return { (a.x * num), (a.y * num), (a.z * num) };
}


Vec3 cross(const Vec3& a, const Vec3& b) {
    return { (a.y*b.z - a.z*b.y), (a.z*b.x - a.x*b.z), (a.x*b.y - a.y*b.x) };
}

float dot(const Vec3& a, const Vec3& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float length(const Vec3& a) {
    float squared = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
    return sqrt(squared);
}

Vec3 normalize(const Vec3& a) {
    float len = length(a);
    if (len == 0) return {0, 0, 0};
    return {(a.x / len), (a.y / len), (a.z / len)};
}

int main() { 
    int choice;
    Vec3 a, b, result;

    while (true) {
        cout << "1. Input\n2. Add\n3. Subtract\n4. Scalar Product\n5. Scalar Division\n6. Cross\n"
             << "7. Dot Product\n8. Display vectors\n9. Length of Vectors\n10. Normalize the vector\n11. Exit\n>";
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
                cout << "Vector b:\n";
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
                cout << "Scalar product with a:\n";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << endl;
                result = b * num;
                cout << "Scalar product with b:\n";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 5:
                float scalar;
                cout << "Enter number to divide with: ";
                cin >> scalar;
                result = a / scalar;
                cout << "Scalar division with b:\n";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                result = b / scalar;
                cout << "Scalar division with b:\n";
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 6:
                result = cross(a,b);
                cout << "(x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 7:
                float dot_prod;
                dot_prod = dot(a, b);
                cout << "Result: " << dot_prod << "\n\n";
                break;

            case 8:
                cout << "A is ";
                cout << "(x,y,z): " << "(" << a.x << " " << a.y << " " << a.z << ")\n\n";
                cout << "B is ";
                cout << "(x,y,z): " << "(" << b.x << " " << b.y << " " << b.z << ")\n\n";
                break;

            case 9:
                cout << "Length of A: " << length(a) << endl;
                cout << "Length of B: " << length(b) << endl;
                break;

            case 10:
                result = normalize(a);
                cout << "Normalized A (x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                result = normalize(b);
                cout << "Normalized B (x,y,z): " << "(" << result.x << " " << result.y << " " << result.z << ")\n\n";
                break;

            case 11:
                cout << "Exiting\n\n";
                return 0;
            
            default:
                cout << "INVALID CHOICE!\n\n";
        }
    }

    return 0;
}
