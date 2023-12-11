#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

vector<int> splitstring(string s){
    string temp;
    vector<int> ans;
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            int x=stoi(temp);
            ans.push_back(x);
            temp.clear();
        }else{
            temp.push_back(s[i]);
        }
    }
    int x=stoi(temp);
    ans.push_back(x);
    return ans;
}

double mean(vector<int> arr){
    double sum=0;
    double n=arr.size();
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    return (sum/n);
}

void calcCorrelation(vector<int> age,vector<int> height){
    double age_mean=mean(age);
    double height_mean=mean(height);
    double numerator=0;
    for(int i=0;i<age.size();i++){
        numerator+=((age[i]-age_mean)*(height[i]-height_mean));
    }
    double age_sqr=0,height_sqr=0;
    for(int i=0;i<age.size();i++){
        age_sqr+=pow((age[i]-age_mean),2);
    }

    for(int i=0;i<age.size();i++){
        height_sqr+=pow((height[i]-height_mean),2);
    }

    double demoninator= sqrt(height_sqr*age_sqr);

    cout<<"Correlation is = "<< (numerator/demoninator);
}


int main(){
    ifstream input("input.csv");
    vector<int> age,height;
    string s;
    input>>s;
    while(input>>s){
        vector<int> temp=splitstring(s);
        age.push_back(temp[0]);
        height.push_back(temp[1]);
    }
    calcCorrelation(age,height);
}