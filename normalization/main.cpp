#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

void calcMinMax(vector<int> data, double new_min, double new_max) {
    ofstream output("output.csv", ios::app);
    double min_val = *min_element(data.begin(), data.end());
    double max_val = *max_element(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++) {
        double value = (((data[i] - min_val) * (new_max - new_min)) / (max_val - min_val)) + new_min;
        output << value << ",";
    }
    output << endl;  
}

void calcZscore(vector<int> data) {
    ofstream output("output1.csv", ios::app);
    double means=0;
    double sd=0;
    for (int i = 0; i < data.size(); i++) {
        means+=data[i];
    }
    means=means/data.size();
    for (int i = 0; i < data.size(); i++) {
        sd+=pow((data[i]-means),2);
    }

    sd= sqrt(sd/data.size());
     for (int i = 0; i < data.size(); i++) {
       double value= (data[i]-means)/sd;
       output<<value;
       output<<endl;
    }   
}

int main() {
    string File;
    File = "input.csv";
    ifstream input(File);
    vector<int> data;
    int val;
    while (input >> val) {
        data.push_back(val);
    }

    double new_min, new_max;
    cout << "Enter min and max value" << endl;
    cin >> new_min >> new_max;
    calcMinMax(data, new_min, new_max);
    calcZscore(data);
    return 0;  // Add a return statement
}
