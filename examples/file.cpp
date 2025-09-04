#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream File("hello_with_file.cpp");

    File << "#include <iostream>\n\n"
         << "int main() {" << endl
         << "\tstd::cout << \"Hello File\" << std::endl;" << endl
         << "\treturn 0;" << endl
         << "}";

    File.close();

    return 0;
}
