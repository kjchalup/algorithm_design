// Compute and display quartiles of a list of numbers.
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

typedef vector<double>::size_type vec_sz;

int main()
{
    // Read in the numbers.
    cout << "Enter numbers, then EOF. " << endl;
    double num;
    vector<double> nums;
    while(cin >> num)
        nums.push_back(num);
    vec_sz size = nums.size();

    // If no numbers, print out nothing.
    if (size < 4){
        cout << "I will need at least four numbers.";
        return 1;
    }

    // Sort.
    sort(nums.begin(), nums.end());

    // Print out each quartile.
    for (vec_sz quart = 0; quart != 4; quart++){
        cout << endl << "Quartile " << quart << ": " << endl;
        for (vec_sz num_id = quart * size / 4;
            num_id != (quart + 1) * size / 4;
            num_id++)
            cout << nums[num_id];
        cout << endl;
    }
    return 0;
}

