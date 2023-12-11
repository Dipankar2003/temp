#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

void calcEquiFreq(vector<int> data,int bin){
    ofstream output("output.csv");
    int n=data.size()/bin;
    int j=0;
    int p=n;
    for(int i=0;i<bin;i++){
        output<<"Bin"<<i+1<<":";
        for(j;j<n && j<data.size();j++){
            output<<data[j]<<',';
        }
        if(data.size()/2!=0 && i==bin-2){
            n++;
        }
        
        n=n+p;
        
        output<<endl;
    }

}

void calcEquiwidth(vector<int> data, int bin){
    ofstream output("output1.csv");
    int max_val= *max_element(data.begin(),data.end());
    int min_val= *min_element(data.begin(),data.end());
    int width= (max_val-min_val)/bin;
    int j=0;
    int n=min_val+width;
    for(int i=0;i<bin;i++){
        output<<"Bin"<<i+1<<":";
        for(j;data[j]<=n && j<data.size();j++){
            output<<data[j]<<',';
        }
        n+=width;
        output<<endl;
    }
}


int main(){
    ifstream input("input.csv");
    vector<int> data;
    int value;
    while(input>>value){
        data.push_back(value);
    }
    int bin;
    cout<<"Enter No. of Bins"<<endl;
    cin>>bin;
    calcEquiFreq(data,bin);
    calcEquiwidth(data,bin);
    return 0;
}