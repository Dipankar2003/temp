// 2020BTEIT00059	Ankur Singh	DM LAB Journal

#include<bits/stdc++.h>
using namespace std;

map<string, double> classProbability;
map<string, map<string, double>> featureProbability;

void train(vector<vector<string>> &trainingData) {
    // Calculating Class Probability.
    for(auto itr:trainingData) {
        string label = itr.back(); // Last element is class label (Yes  or No).
        classProbability[label]++;
    }

    // Calculate Feature Probability.
    for(auto itr:trainingData) {
        string label = itr.back();
        for(int i=0;i<itr.size()-1;i++) {
            string feature = itr[i];
            featureProbability[label][feature]++;
        }
    }

    // Normalize Probabilities.
    for(auto& classFeatureProb:featureProbability) {
        for(auto& featureProb:classFeatureProb.second) {

            featureProb.second = double(featureProb.second) / classProbability[classFeatureProb.first];
        }
    }
    cout<<endl;

    for(auto& itr:classProbability) {
        itr.second /= trainingData.size();
    }
}

string predict(vector<string> features) {
    string predictedClass;
    double maxProbability = 0.0;

    for(auto classProb:classProbability) {
        double prob = classProb.second;

        for(int i=0;i<features.size();i++) {
            prob *= featureProbability[classProb.first][features[i]];

            // cout<<prob<<" "<<featureProbability[classProb.first][features[i]]<<endl;;
        }

        if(prob > maxProbability) {
            maxProbability = prob;
            predictedClass = classProb.first;
        }
        cout<<prob<<" "<<classProb.first<<endl;
    }

    cout<<maxProbability<<" "<<predictedClass<<endl;

    return predictedClass;
}

int main() {

    ifstream file("input.csv");
    string line, point;
    vector<vector<string>> trainingData;
    
    // Skipping Headers.
    getline(file, line);

    while(getline(file, line)) {
        stringstream str(line);

        vector<string> temp;
        while(getline(str, point, ',')) {
            temp.push_back(point);
        }
        trainingData.push_back(temp);
    }

    train(trainingData);

    vector<string> newExample = {"sunny", "hot", "high", "weak"};
    string pred = predict(newExample);

    return 0;
}
