#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string>&names,vector<int>&scores,vector<char>&grades){
    ifstream fin(filename);
    string s;
    int a,b,c;
    char name[255];
    char format[] = "%[^:]: %d %d %d";
    while(getline(fin,s)){
    sscanf(s.c_str(),format,name,&a,&b,&c);
    names.push_back(name);
    scores.push_back(a+b+c);
    grades.push_back(score2grade(a+b+c));
}
}

void getCommand(string &command, string &key){
    cout << "Please input your command: " ;
    cin >> command;
    string commandUp = toUpperStr(command);
    if(commandUp == "NAME" || commandUp =="GRADE" || commandUp == "EXIT"){
    cin.ignore();
    getline(cin,key);
    }
}

void searchName(vector<string>names,vector<int>scores,vector<char>grades,string key){
    int j = names.size();
    bool x = false;
    cout << "---------------------------------" << endl;
    for(int i = 0; i < j; i++){
    key = toUpperStr(key);
    if(toUpperStr(names[i]) == key){
    cout << names[i] << "'s score = " << scores[i] << endl;
    cout << names[i] << "'s grade = " << grades[i] << endl;
    x = true;
    }else if(x == false && i == j-1){
    cout << "Cannot found." << endl;
}
}

    cout << "---------------------------------"<< endl;
}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    int j = names.size();
    bool x = false;
    cout << "---------------------------------" << endl;
    for(int i = 0; i < j; i++){
    if(grades[i] == *key.c_str()){
    cout << names[i] << " (" << scores[i] << ") " << endl;
    x = true;
    }else if(x == false && i == j-1){
    cout << "Cannot found." << endl;
}
}

    cout << "---------------------------------"<< endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
