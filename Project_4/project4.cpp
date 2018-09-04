#include <iostream>
#include <string>
//for ACTUAL random numbers
#include <cstdlib>
#include <ctime>

using namespace std;

void inverseString(string &a, int n);
void reverseString(string &a, int n);
void toUpper(string &a, int n);
void jumbleString(string a, int n);
void countWords(string a, int n);
void countConsonants(string a, int n);

int main(){
    
    srand(time(NULL));
    
    char choice = 'N';
    string inString;
    int stringLength;
    
    cout << "Enter a string: ";
    getline(cin, inString);
    stringLength = inString.length();
    while(inString == ""){
        cout << "Please enter a valid string: ";
        getline(cin, inString);
    }
    
    do{
        cout << "USE THIS MENU TO MANIPULATE YOUR STRING" << endl
            << "---------------------------------------" << endl
            << "1)  Inverse String" << endl
            << "2)  Reverse String" << endl
            << "3)  To Uppercase" << endl
            << "4)  Jumble String" << endl
            << "5)  Count Number Words" << endl
            << "6)  Count Consonants" << endl
            << "7)  Enter a Different String" << endl
            << "8)  Print the String" << endl
            << "Q)  Quit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case '1':
                inverseString(inString, stringLength);
                break;
            case '2':
                reverseString(inString, stringLength);
                break;
            case '3':
                toUpper(inString, stringLength);
                break;
            case '4':
                jumbleString(inString, stringLength);
                break;
            case '5':
                countWords(inString, stringLength);
                break;
            case '6':
                countConsonants(inString, stringLength);
                break;
            case '7':
                cout << "Please enter your new string: ";
                getline(cin, inString);
                stringLength = inString.length();
                while(inString == ""){
                    cout << "Please enter a valid string";
                    getline(cin, inString);
                }
                break;
            case '8':
                cout << inString << endl;
                break;
            case 'q':
            case 'Q':
                return 0;
                break;
            default:
                cout << "That is not a valid choice." << endl;
                break;
        }
        
    }while(true);


}

void inverseString(string &a, int n){
    
    for (int i = 0; i < n; i++){
        
        if(isupper(a[i]))
            a[i] = tolower(a[i]);
        else if(islower(a[i]))
            a[i] = toupper(a[i]);
    }
    
}

void reverseString(string &a, int n){
    
    string temp = a;
    int count = n - 1;
    
    for (int i = 0; i < n; i++){
        a[i] = temp[count];
        count--;
    }
    
}

void toUpper(string &a, int n){
    char temp;
    for (int i = 0; i < n; i++){
        temp = a[i];
        if(islower(a[i]))
            a[i] = toupper(a[i]);
    }
    
}

void jumbleString(string a, int n){
  
    string tempString = a;
    char tempChar;
    int randInt;

    for(int x = 0; x < n; x++){
        randInt = rand() % n;
        tempChar = tempString[randInt];
        tempString[randInt] = tempString[x];
        tempString[x] = tempChar;
    }
    cout << tempString << endl;
}

void countWords(string a, int n){
    
    int total = 0;
    
    for(int x = 0; x < n; x++){
        
        if((isalpha(a[x])) && (a[x] != '\t')){
         
            total++;
            
            while((a[x] != ' ') && (a[x] != '\t') && (x < n)) //skips all the spaces until the next letter/number is reached isblank(a[x])
                x++;
            
        }

    }

/*
    if((total == 0) && (a != "") && (a[0] != ' '))
        total = 1;
*/    
    cout << "The string: " << a << " has " << total << " words." << endl;
}

void countConsonants(string a, int n){
    
    int total = 0;
    string temp = a;
    
    for(int x = 0; x < n; x++){ //gets rid of case sensitivty
        if ((temp[x] >= 65) && (temp[x] <= 90))
            temp[x] = tolower(temp[x]);
    }
    
    for (int x = 0; x < n; x++){
        
        if((temp[x] != 'a') && (temp[x] != 'e') && (temp[x] != 'i') && (temp[x] != 'o') && (temp[x] != 'u') && (isalpha(temp[x])))
            total++;
        
    }
    
    cout << "The string: " << a << " has " << total << " consonants." << endl;
    
}
