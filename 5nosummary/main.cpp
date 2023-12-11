#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;


double median(vector<double> data){
    double ans=0;
    int n=data.size();
    n=n+1;
    if(n%2!=0){
        n=n/2;
        ans= (data[n-1]+data[n])/2.0;
        
    }else{
        n=n/2;
        ans=data[n-1];
    }
    return ans;
}

double Quartile1(vector<double> data){
    double ans=0;
    int n=data.size();
    n=n+1;
    if(n%4!=0){
        n=n/4;
        ans= (data[n-1]+data[n])/2.0;

    }else{
        n=n/4;
        ans=data[n-1];
    }
    return ans;
}

double Quartile3(vector<double> data){
    double ans=0;
    int n=data.size();
    n=n+1;
    if(n%4!=0){
        n=n/4;
        n=n*3;
        ans= (data[n-1]+data[n])/2.0;

    }else{
        n=n/4;
        n=n*3;
        ans=data[n-1];
    }
    return ans;
}

int main(){
    ifstream input("input.csv");
    vector<double> data;
    int value;
    while(input>>value){
        data.push_back(value);
    }
    sort(data.begin(),data.end());
    ofstream output("output.csv",ios::app);
    double x=0;
    output<<"Min = "<< data[0] <<endl;
    x=median(data);
    output<<"Median = "<< x <<endl;
    x=Quartile1(data);
    output<<"Quartile1(Q1) = "<< x <<endl;
    x=Quartile3(data);
    output<<"Quartile3(Q3) = "<< x <<endl;
    output<<"Max = "<< data[data.size()-1] <<endl;
    return 0;
}