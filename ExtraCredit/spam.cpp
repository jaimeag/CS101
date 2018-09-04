#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;


//that's a lot of prototype functions
string getFirstWord(string text);
string getLastWord(string text);
string extractWord(string &text);
string makeUppercase(string text);
bool isUppercase(string text);
bool hasMultipleExclamations(string text);
bool isGibberishWord(string text);
bool isConsanant(char letter);
bool spamCheckUppercase(string text, double textType);
int findRange(int intOne, int intTwo);
int spamCheckBadWords(string text);
int checkSubject(string text);
int checkBody(string text);
void spamCheck(int &legitMessage, int &spamMessage);

const int BADWORDS = 13;

int main(){
    int legitMessage = 0;
    int spamMessage = 0;
    cout << setprecision(2) << fixed << showpoint;
    string choice;
    for(;;){
        spamCheck(legitMessage, spamMessage);
        do{   
            cout << "Would you like to classify another email? (y or n) ";
            getline(cin, choice);
            
            //while loop breaks and the for loop restarts if "y" is pressed
            if(choice == "y"){
                ;
            }else if(choice == "n"){
                cout << endl << endl;
                cout << "Number of spam messages: " << spamMessage << endl
                        << "Number of legitimate messages: " << legitMessage << endl;
                    return 0;
            }else
                cout << "Please enter y or n." << endl;
 
        }while((choice != "y") && (choice != "n"));
    }
    
}

string getFirstWord(string text){
    int textStart = -1;
    int textEnd = -1;
    int n = text.size();
    
    for(int x = 0; x < n; x++){
        if((isalpha(text[x])) && (textStart == -1))
            textStart = x;
        else if(!isalpha(text[x]) && textStart != -1){
            textEnd = x;
            return text.substr(textStart,findRange(textStart, textEnd));
        }else if((x == n - 1) && (textStart != -1)){
            textEnd = n;
            return text.substr(textStart,findRange(textStart, textEnd));
        }
    }
    return ""; //if no alpha characters are ever found, then the function returns the empty stirng
}

string getLastWord(string text){
    
    int textStart = -1;
    int textEnd = -1;
    int n = text.size();
 
    for(int x = n-1; x >= 0; x--){
        
        if((isalpha(text[x])) && (textEnd == -1))
            textEnd = x+1;
        else if ((!isalpha(text[x])) && (textEnd != -1)){
            textStart = x+1;
            return text.substr(textStart, findRange(textStart, textEnd));
        }else if((x == 0) && (textEnd != -1)){
            textStart = 0;
            return text.substr(textStart, textEnd+1);
        }
        
    }
    return "";
    
}


string extractWord(string &text){
    
    string firstWord = getFirstWord(text);
    string firstWordExtract = "";
    int firstWordLength = firstWord.size();
    //begins the iteration of firstWordExtract if both flags are true
    bool firstLetterFound = false;
    bool wordSkipped = false;

    //makes sure that single letter words are actually stored and not empty strings
    for(int x = 0; x < text.size(); x++){
        if(!firstLetterFound){
            if(text[x] == firstWord[0])
                firstLetterFound = true;
        }
        else if(firstLetterFound && !wordSkipped){ //if the first letter is obtained and the word hasn't been skipped in the for loop
            x += firstWordLength-2;
            wordSkipped = true;
        }else if (firstLetterFound && wordSkipped) //this is when the text string is changed to everything after firstWord
            firstWordExtract += text[x];
            
    }
    
    text = firstWordExtract;
    return firstWord;
    
}

string makeUppercase(string text){
    string tempStr = text;
    for(int x = 0; x < text.length(); x++){
        if(islower(text[x]))
            tempStr[x] = toupper(tempStr[x]);
    }
    return tempStr;
}

bool isUppercase(string text){
    int totalUpper = 0;
    int totalLetters = 0;
    
    for(int x = 0; x < text.length(); x++){
        if(isalpha(text[x])){
            totalLetters++;
            if(isupper(text[x]))
                totalUpper++;
        }
    }
    if(totalLetters == 0)
        return false;
    else
        return(totalUpper == totalLetters);
}

bool hasMultipleExclamations(string text){
    //refer to line 173
    if(text.size() < 3)
        return false;
    for(int x = 0; x < (text.length()-2); x++){
        if((text[x] == '!') && (text[x+1] == '!') && (text[x+2] == '!'))
            return true;
    }
    return false;
}

bool isGibberishWord(string text){
    //used to prevent segmentation fault
    if(text.size() < 3)
      return false;
        
    for(int x = 0; x < (text.length()-2); x++){
        if((isConsanant(text[x])) && (isConsanant(text[x+1])) && (isConsanant(text[x+2])))
            return true;
    }
    return false;
}

//This is to check if a letter is a a consanant because I don't want to write out all the booleans for isGibberishWord
bool isConsanant(char letter){
    
    if(isalpha(letter)){ //to filter out non alphabetic characters
        letter = tolower(letter);
        return (letter != 'a') && (letter != 'e') && (letter != 'i') && (letter != 'o') && (letter != 'u'); //return if the letter is not a vowel
    }
    else
        return false;
    
}

//returns the range of two numbers depending on which is bigger (this could replaced with abs())
int findRange(int intOne, int intTwo){
    if(intOne > intTwo)
        return intOne - intTwo;
    else if(intOne < intTwo)
        return intTwo - intOne;
    else //if both numbers are equal
        return intOne;
}

bool spamCheckUppercase(string text, double textType){
    string temp = text;
    string wordCheck = extractWord(temp);
    int wordCheckLen = wordCheck.length();
    double totalWords = 0;
    double totalWordsCaps = 0;

    while(wordCheck != ""){
        int totalCaps = 0;

//for every letter that is uppercase in wordCheck, totalCaps is incremented      
        for(int x = 0; x < wordCheckLen; x++){
            if(isupper(wordCheck[x]))
                totalCaps++;
        }
//the total words in a string will only increase if every letter is capital
        if (totalCaps == wordCheckLen)
            totalWordsCaps++;

        totalWords++; //total words is always increased to get the percentage of capital words
        wordCheck = extractWord(temp); //the next word is obtained after the previous word is checked
        wordCheckLen = wordCheck.length();
    }
    
    return((totalWordsCaps / totalWords) > textType);

}

int spamCheckBadWords(string text){
    string temp = text;    
    string wordCheck;
    int wordCheckLen = 0;
    int spamScore = 0;
    
    string badWords[BADWORDS] = {"BUY", "CHEAP", "CLICK", "DIPLOMA", "ENLARGE", "FREE", "LONELY", "MONEY", "NOW", "OFFER", "ONLY", "PILLS", "SEX"}; 

    do{
        wordCheck = extractWord(temp);
        wordCheck = makeUppercase(wordCheck);

        for (int x=0; x < BADWORDS; x++){
            if (wordCheck == badWords[x])
                spamScore += 5;
        }

    }while(temp != "");

    return spamScore;
}

int checkSubject(string text){
    int spamScore = 0;
    
    if(spamCheckUppercase(text, .90))
        spamScore += 30;
    
    if(isGibberishWord(getLastWord(text))) //gibberishWord only needs to check the last word so getLastWord is called
        spamScore += 40;
    
    if(hasMultipleExclamations(text))
        spamScore += 20;
    
    return spamScore;
}

int checkBody(string text){
    int spamScore = 0;
    
    if(spamCheckUppercase(text, .50))
        spamScore += 40;

    spamScore += spamCheckBadWords(text);
    //spam word filter returns an interger so I only need to increase spamScore
    
    return spamScore;
}

void spamCheck(int &legitMessage, int &spamMessage){
    string emailSubject;
    string emailBodyAppend = " ";
    string emailBody = " ";
    
    int spamScoreSubject = 0;
    int spamScoreBody = 0;
    
    cout << "Enter the subject line of the email: ";
    getline(cin, emailSubject);
    cout << "Enter the body of the email.  Press enter on an empty line to finish" << endl;
    //while the input isn't an empty string (blank line), the user can input as many lines as they want which are seperated by space
    while(emailBodyAppend != ""){
        getline(cin, emailBodyAppend);
        emailBody += emailBodyAppend;
        emailBody += ' ';
    }
    
    spamScoreSubject = checkSubject(emailSubject);
    spamScoreBody = checkBody(emailBody);
    
    if((spamScoreBody + spamScoreSubject) > 100){
        cout << "This email is classified as spam, because its spam score is " << spamScoreBody + spamScoreSubject << ".";
        spamMessage++;
    }
    else{
        cout << "This email is classified as legitimate, because its spam score is " << spamScoreBody + spamScoreSubject << ".";
        legitMessage++;
    }
    
    cout <<endl;
}
