#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

vector<int> splitstring(string s){
    vector<int> ans;
    string temp;
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

double distance(int x1,int y1,int x2,int y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}


void lowerMatrix(vector<int> x,vector<int> y,int x_center,int y_center){

  vector<vector<double>> ans(x.size(),vector<double>(x.size(),0));
  ofstream output("output.csv",ios::app);

    for(int i=0;i<x.size();i++){
        for(int j=i+1;j<y.size();j++){
            
            ans[i][j]= distance(x[i],y[i],x[j],y[j]);
        }
    }

     for(int i=0;i<x.size();i++){
        for(int j=0;j<y.size();j++){
            if(ans[i][j]!=0){
            output<<ans[i][j]<<",";
            }
        }
        output<<endl;
    }
}



int main(){
    ifstream input("input.csv");
    string s;
    input>>s;
    vector<int> x;
    vector<int> y;
    while(input>>s){
        vector<int> temp=splitstring(s);
        x.push_back(temp[0]);
        y.push_back(temp[1]);
    }

    int x_center=0,y_center=0;
    for(int i=0;i<x.size();i++){
        x_center+=x[i];
    }
    x_center=x_center/x.size();

    for(int i=0;i<x.size();i++){
        y_center+=y[i];
    }
    y_center=y_center/y.size();

    lowerMatrix(x,y,x_center,y_center);


    return 0;
}