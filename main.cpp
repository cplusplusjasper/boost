#include <boost/program_options/options_description.hpp>
#include <boost/program_options/option.hpp>
using namespace std;
#include <iostream>

namespace po = boost::program_options;

int a_add_b(int a, int b) {
    return a + b;
}

int a_minus_b(int a, int b) {
    return a - b;
}

int func(int a, int b, int(*cb)(int, int)) {
    return (cb)(a, b);
}

int main(int argc, char** argv) {

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ;

    auto a_mod_b = [](int a, int b) {
        return a % b;
    };

    int a = 10;
    int b = 3;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Sum:        " << func(a, b, a_add_b) << endl;

    cout << "Difference: " << func(a, b, a_minus_b) << endl;

    cout << "mod:        " << func(a, b, a_mod_b) << endl;

    return 0;
}
