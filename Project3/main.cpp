
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate the mean of the elements in the vector
double calculateMean(vector<int>& data) {
    int sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data[i];
    }
    return static_cast<double>(sum) / data.size();
}

// Function to calculate the population standard deviation of the elements in the vector
double calculateStdDev(vector<int>& data, double mean) {
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / data.size());
}

int main() {
    ifstream inputFile("inMeanStd.dat");
    ofstream outputFile("outMeanStd.dat");

    vector<int> data;
    int num;
    while (inputFile >> num) {
        data.push_back(num);
    }

    // Computing mean and standard deviation
    double mean = calculateMean(data);
    double stdDev = calculateStdDev(data, mean);

    // Output to screen
    cout << "The mean is: " << fixed << setprecision(2) << mean << endl;
    cout << "The population standard deviation is: " << fixed << setprecision(2) << stdDev << endl;

    // Output to file
    outputFile << "The mean is: " << fixed << setprecision(2) << mean << endl;
    outputFile << "The population standard deviation is: " << fixed << setprecision(2) << stdDev << endl;

    inputFile.close();
    outputFile.close();

    return 0;