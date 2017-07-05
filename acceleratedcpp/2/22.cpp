// Variable-size string padding.
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    // Record the name.
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // Prepare the message to print.
    const string msg = "Hello " + name + "!";

    // Padding amount.
    const int pad_col = 10;
    const int pad_row = 1;

    // Number of rows and columns to write.
    const int rows = pad_row * 2 + 3;
    const string::size_type cols = msg.size() + pad_col * 2 + 2;

    // Write out the message!
    cout << endl;

    for (int row_id = 0; row_id != rows; ++row_id)
    {
        string::size_type col_id = 0;

        while (col_id != cols)
        {
            if (row_id == pad_row + 1 && col_id == pad_col + 1) {
                cout << msg;
                col_id += msg.size();
            }
            else {
                if (row_id == 0 || row_id == rows - 1 ||
                    col_id == 0 || col_id == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                col_id++;
            }
        }
    cout << endl;
    }
    return 0;
}




