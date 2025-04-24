#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip> // Include this for std::setw

using namespace std;

int main()
{
    string hashFunctions[] = {"sdbm", "djb2", "fnv"}; // Replaced vector<string> with string array
    int hashFunctionCount = sizeof(hashFunctions) / sizeof(hashFunctions[0]); // Get the size of the array
    string reportFile = "report.txt";

    ofstream report(reportFile);
    if (!report.is_open())
    {
        cerr << "Failed to open report file.\n";
        return 1;
    }

    report << "\t\tHash Function Performance Report\n";
    report << "\t\t--------------------------------\n";
    report << "Hash Function\tTotal Collisions\tCollision Ratio\n";
    report << "-------------\t----------------\t---------------\n";

    for (int i = 0; i < hashFunctionCount; i++) // Iterate over the string array
    {
        string hash = hashFunctions[i];
        string command = "main.exe " + hash + " < input.txt > output.txt";
        system(command.c_str());

        ifstream tempOut("collision.txt");
        if (!tempOut.is_open())
        {
            cerr << "Failed to open collision.txt for " << hash << "\n";
            continue;
        }

        string line;
        int totalCollisions = -1;
        double collisionRatio = -1;

        while (getline(tempOut, line))
        {
            if (line.find("Total Collisions:") != string::npos)
            {
                totalCollisions = stoi(line.substr(line.find(":") + 1));
            }
            else if (line.find("Collision Ratio:") != string::npos)
            {
                collisionRatio = stod(line.substr(line.find(":") + 1));
            }
        }

        tempOut.close();

        report << left << setw(20) << hash // Fixed width for hash function
               << setw(20) << totalCollisions // Fixed width for total collisions
               << setw(20) << collisionRatio // Fixed width for collision ratio
               << "\n";
        report << "-------------\t----------------\t---------------\n";
    }

    report.close();
    return 0;
}
