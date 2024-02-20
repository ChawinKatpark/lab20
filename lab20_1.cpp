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

void importDataFromFile(string filename,vector<string>& names,vector<int>& scores,vector<char>& grades){
    ifstream dest;
    dest.open(filename);
    string text0;
    while(getline(dest,text0)){
         const char *text1 = text0.c_str();
         char format[] = "%[^:]: %d %d %d";
         char name[100];
         int a,b,c;
      sscanf(text1,format,name,&a,&b,&c);
            names.push_back(name);
            scores.push_back((a+b+c));
            grades.push_back(score2grade(a+b+c));
    }
    return;
}

void getCommand(string &command, string &key){
    cout << "Please input your command: ";
    string text0;
    getline(cin,text0);
    const char *text1 = text0.c_str();
     char format[] = "%[^ ] %[abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ. ] ";
     char Command[100];
     char Key[100];
     sscanf(text1,format,Command,Key);
    command = Command;
    key = Key;
}

void searchName(vector<string>& names, vector<int>& scores, vector<char>& grades, string  key){
        cout << "---------------------------------\n";
        for(unsigned int i = 0 ; i < names.size();i++){
        if(toUpperStr(names[i]) == key){
            cout << names[i] << "'s score = " << scores[i] << endl;
            cout << names[i] << "'s grade = " << grades[i] << endl;
            cout << "---------------------------------\n";
            return;
        } 
        }
        cout << "Cannot found." << endl;
    cout << "---------------------------------\n";
    


}
void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    cout << "---------------------------------\n";
    bool find = 0;
    for(unsigned int i = 0 ; i < names.size();i++){
        if(grades[i] == key.c_str()[0]){
            cout << names[i] << " (" << scores[i] << ")" << endl;
            find = 1;
        }
    }
    if(find == 0){
        cout << "Cannot found." << endl;    
    }
    cout << "---------------------------------\n";
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
