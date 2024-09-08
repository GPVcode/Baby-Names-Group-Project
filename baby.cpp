#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if the percentage is valid
bool is_valid_percentage(double percent) {
    return (percent >= 0 && percent <= 100);
}

/**
   Reads name information, prints the name if total >= 0, and adjusts the total.
   @param in_file the input stream
   @param total the total percentage that should still be processed
*/
void process_name(ifstream& in_file, double& total) {
    string name;
    int count;
    double percent;
    in_file >> name >> count >> percent;

    if (in_file.fail()) { 
        cerr << "Error: Failed to read from file." << endl;
        return; 
    }

    // Validate percentage
    if (!is_valid_percentage(percent)) {
        cerr << "Error: Invalid percentage encountered." << endl;
        return;
    }

    if (total > 0) { 
        cout << name << " "; 
    }
    total -= percent;
}

int main() {
    ifstream in_file;
    in_file.open("babynames_with_percentages_final2.txt");
    if (in_file.fail()) { 
        cerr << "Error: Unable to open file." << endl;
        return 1; 
    }

    double boy_total = 50;
    double girl_total = 50;

    while (boy_total > 0 || girl_total > 0) {
        int rank;
        in_file >> rank;
        if (in_file.fail()) { 
            cerr << "Error: Failed to read rank from file." << endl;
            return 1; 
        }

        cout << rank << " ";

        process_name(in_file, boy_total);
        process_name(in_file, girl_total);

        cout << endl;
    }

    // Close the file when done
    in_file.close();

    return 0;
}