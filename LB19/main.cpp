#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void task1()
{
    string values;
    string basic_string;

    getline(cin, values);
    getline(cin, basic_string);
    int index_of_divider = 0;
    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] == ',')
        {
            string temp = values.substr(index_of_divider, i - index_of_divider);
            string key = temp.substr(0, temp.find('='));
            index_of_divider = i + 1;
            size_t in_template_key_index = 0;
            while ((in_template_key_index = basic_string.find("[" + key + "]", in_template_key_index)) != string::npos)
            {
                basic_string.replace(in_template_key_index, key.length() + 2,
                                     temp.substr(temp.find('=') + 1, temp.length() - temp.find('=') - 1));
                in_template_key_index += temp.length() - temp.find('=') - 1;
            }
        }
    }
    string temp = values.substr(index_of_divider, values.length() - index_of_divider);
    string key = temp.substr(0, temp.find('='));
    size_t in_template_key_index = 0;
    while ((in_template_key_index = basic_string.find("[" + key + "]", in_template_key_index)) != string::npos)
    {
        basic_string.replace(in_template_key_index, key.length() + 2,
                             temp.substr(temp.find('=') + 1, temp.length() - temp.find('=') - 1));
        in_template_key_index += temp.length() - temp.find('=') - 1;
    }
    cout << basic_string << "\n";
}

void task2()
{
    string password;
    bool is_valid_password = false;

    while (!is_valid_password)
    {
        cout << "Enter password: ";
        cin >> password;
        is_valid_password = true;
        string temp = password;

        if (password.length() < 8)
        {
            // cout << password.length() << endl;
            is_valid_password = false;
            cout << "Password must be 8 characters long!" << endl;
        }
        transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return tolower(c); });
        if (password == temp)
        {
            is_valid_password = false;
            cout << "The password must have at least one upper case letter" << endl;
        }
        temp = password;
        transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return toupper(c); });
        if (password == temp)
        {
            is_valid_password = false;
            cout << "The password must have at least one lower case letter" << endl;
        }
        bool contains_digits = false;
        bool contains_only_alnums = true;
        for (int i = 0; i < password.length(); i++)
        {
            if (isdigit(password[i]))
            {
                contains_digits = true;
            }
            if (!isalpha(password[i]))
            {
                contains_only_alnums = false;
            }
            if (contains_digits and not contains_only_alnums) break;
        }
        if (contains_only_alnums)
        {
            is_valid_password = false;
            cout << "The password must have at least one special symbol" << endl;
        }
        if (!contains_digits)
        {
            is_valid_password = false;
            cout << "The password must have at least one digit" << endl;
        }
        if (is_valid_password)
        {
            cout << "The password is valid" << endl;
        }
    }
}

int main()
{
    task1();
    // task2();
}
