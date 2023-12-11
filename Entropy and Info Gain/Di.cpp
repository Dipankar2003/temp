#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

vector<string> splitString(string input, char delimiter) {
   
    string temp;
    vector<string> res;
    for(int i=0;i<input.size();i++){
        if(input[i]==','){
            res.push_back(temp);
            temp.clear();
        }else{
            temp.push_back(input[i]);
        }
    }
    res.push_back(temp);
    return res;
}

void calcInfo(vector<string> outlook ,vector<string> target){
    //calculating the entropy of whole table
    map<string,double> mp;
    for(int i=0;i<target.size();i++){
        mp[target[i]]++;
    }
    double tableEntropy=0;
    for(auto i:mp){
        tableEntropy+=(-((i.second/target.size())*log2(i.second/target.size())));
    }

    //Mapping outlook value with target class and counting its count in format 
    //map[sunny][N] = value;
    //map[sunny][Y] = value;
    map<string,map<string,double>> attribute;
    for(int i=0;i<outlook.size();i++){
        attribute[outlook[i]][target[i]]++;
    }
    //calculating the entropy of atrribute
    vector<double> attributeEntropy;
    for(auto i:attribute){
        double temp=0;
        int cnt=0;
        //calculating occurence of each value such as sunny rain overcast
        for(auto j : i.second){
            cnt+=j.second;
        }
        //calculating the entropy for each value such as sunny rain overcast
        for(auto j : i.second){
            temp+=(-((j.second/cnt)*log2(j.second/cnt)));
        }
        //calculating each term used in calculating info gain such as (5/14)*(entropy of sunny)
        temp=(cnt*temp)/outlook.size();
        attributeEntropy.push_back(temp);
    }

    //calc final info gain by subtracting each term from original entropy
    double result=tableEntropy;
    for(int i=0;i<attributeEntropy.size();i++){
        result-=attributeEntropy[i];
    }
    cout<<"Information Gain is "<< result;
    
}

int main(){
    ifstream input("input.csv");
    string s;
    vector<string> outlook;
     vector<string> target;
     
    while(input>>s){
        vector<string>  temp = splitString(s , ',');
        outlook.push_back(temp[0]);
        target.push_back(temp[1]);
    }
    
    calcInfo(outlook,target);
    return 0;
}