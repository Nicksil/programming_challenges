#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main() {
    srand(time(NULL));

    string line;
    string user_input;
    vector<string> first_name_vec;
    vector<string> last_name_vec;
    int first_name_rand_index = rand() % 100;
    int last_name_rand_index = rand() % 100;

    cout << "Male or Female?" << endl;
    cin >> user_input;

    if (user_input == "Male")
    {
        ifstream male_names ("data/top_boy_names_2014.txt");
        if (male_names.is_open())
        {
            while (getline (male_names, line))
            {
                first_name_vec.push_back(line);
            }
            male_names.close();
        } else {
            cout << "Unable to open file";
        }
    } else if (user_input == "Female")
    {
        ifstream female_names ("data/top_girl_names_2014.txt");
        if (female_names.is_open())
        {
            while (getline (female_names, line))
            {
                first_name_vec.push_back(line);
            }
            female_names.close();
        } else {
            cout << "Unable to open file";
        }
    } else
    {
        cout << "Invalid input" << endl;
        return 1;
    }

    ifstream last_names ("data/common_surnames_n_america.txt");
    if (last_names.is_open())
    {
        while (getline (last_names, line))
        {
            last_name_vec.push_back(line);
        }
        last_names.close();
    } else {
        cout << "Unable to open file";
    }

    cout << first_name_vec[first_name_rand_index] << " " << last_name_vec[last_name_rand_index] << endl;

    return 0;
}
