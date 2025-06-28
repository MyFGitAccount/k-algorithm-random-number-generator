#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <string>

using namespace std;

unsigned long long int_pow(unsigned long long base, int exp) {
    unsigned long long result = 1;
    while (exp) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

using StepFunction = function<void(size_t&)>;

unsigned int Random_num(size_t X) {
    if (X < int_pow(10, 9)) {
        cerr << "Input too small. Must be at least 10 digits.\n";
        return X;
    }

    unsigned int y = X / int_pow(10, 9);
    int Y = (y >> (to_string(y).size() ))%100;

    // Define steps K3 to K12
    vector<StepFunction> steps = {
        // K3
        [](size_t& x) {
            if (x < 5000000000) x += 5000000000;
            cout << "K3: " << x << endl;
        },
        // K4
        [](size_t& x) {
            x = (int_pow(x, 2) / int_pow(10, 5)) % int_pow(10, 10);
            cout << "K4: " << x << endl;
        },
        // K5
        [](size_t& x) {
            x = (1001001001 * x) % 1010;
            cout << "K5: " << x << endl;
        },
        // K6
        [](size_t& x) {
            x = (x < 100000000) ? (x + 9814055677) : (int_pow(10, 10) - x);
            cout << "K6: " << x << endl;
        },
        // K7
        [](size_t& x) {
            x = int_pow(10, 5) * (x % int_pow(10, 5)) + x / int_pow(10, 5);
            cout << "K7: " << x << endl;
        },
        // K8
        [](size_t& x) {
            x = (1001001001 * x) % 1010;
            cout << "K8: " << x << endl;
        },
        // K9
        [](size_t& x) {
            string s = to_string(x);
            for (size_t i = 0; i < s.size(); ++i) {
                if (x >= int_pow(10, i)) {
                    x -= int_pow(10, i);
                }
            }
            cout << "K9: " << x << endl;
        },
        // K10
        [](size_t& x) {
            x = (x < int_pow(10, 5)) ? int_pow(x, 2) + 99999 : int_pow(x, 2) - 99999;
            cout << "K10: " << x << endl;
        },
        // K11
        [](size_t& x) {
            if (x < int_pow(10, 9)) {
                x *= 100;
            }
            else if (x > int_pow(10, 9)) {
                x/=100;
            }
            cout << "K11: " << x << endl;
        },
        // K12
        [](size_t& x) {
            x = (x * (x - 1) / int_pow(10, 5)) % int_pow(10, 10);
            cout << "K12: " << x << endl;
        }
    };

    while (Y-- > 0) {
        int Z = (X / int_pow(10, 8)) % 10;
        int startIndex = max(0, Z - 3); // K3 = index 0

        for (int i = startIndex; i < steps.size(); ++i) {
            steps[i](X);
        }
        cout<<"Y: "<<Y<<endl;
    }
    cout << "Final Output: " <<X<<endl;
    return X;
}

int main() {
    Random_num(int_pow(65,10));
    return 0;
}