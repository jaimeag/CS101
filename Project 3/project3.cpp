#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int enumerate(const string a[], int n, string target);
int locate(const string a[], int n, string target);
bool locateSequence(const string a[], int n, string target, int& begin, int& end);
int locationOfMin(string a[], int n);
int moveToEnd(string a[], int n, int pos);
int moveToBeginning(string a[], int n, int pos);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int eliminateDups(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max);
int divide(string a[], int n, string divider);

int main(){
    
        string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };
	    assert(enumerate(h, 7, "margaery") == 2);
	    assert(enumerate(h, 7, "") == 1);
	    assert(enumerate(h, 7, "sansa") == 0);
	    assert(enumerate(h, 0, "margaery") == 0);
	    assert(locate(h, 7, "margaery") == 2);
	    assert(locate(h, 2, "margaery") == -1);
	    int bg;
	    int en;
	    assert(locateSequence(h, 7, "daenerys", bg, en) && bg == 3 && en == 3);

	    string g[4] = { "samwell", "jon", "daenerys", "tyrion" };
	    assert(locationOfMin(g, 4) == 2);
	    assert(locateDifference(h, 4, g, 4) == 2);
	    assert(subsequence(h, 7, g, 4));
	    assert(moveToEnd(g, 4, 1) == 1 && g[1] == "daenerys" && g[3] == "jon");
	
	    string f[4] = { "daenerys", "tyrion", "margaery", "jon" };
	    assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "margaery" && f[2] == "tyrion");
	
	    string e[5] = { "daenerys", "daenerys", "daenerys", "margaery", "margaery" };
	    assert(eliminateDups(e, 5) == 2 && e[1] == "margaery");
	
	    string x[4] = { "cersei", "jon", "jon", "sansa" };
	    string y[4] = { "daenerys", "jon", "margaery", "tyrion" };
	    string z[10];
	    assert(makeMerger(x, 4, y, 4, z, 10) == 8 && z[5] == "margaery");
	
	    assert(divide(h, 7, "margaery") == 3);
	
	    cout << "All tests succeeded" << endl;
    
}

int enumerate(const string a[], int n, string target){
    
    int total = 0;
    for (int x=0;x < n; x++){
        if (a[x] == target)
            total++;
    }
    if (total >= 0)
        return total;
    else
        return -1;
}

int locate(const string a[], int n, string target){
    int location = 0;
    for (int x = 0; (x < n) && (location == 0); x++){
        if (a[x] == target){
            location = x;
        }
    }
    if (location != 0)
        return location;
    else
        return -1;
}

bool locateSequence(const string a[], int n, string target, int& begin, int& end){
    int sequence = 0; //counter used to make sure target is only tracked twice
    for (int x = 0; (x < n) && (sequence < 2); x++){
        if(sequence == 1){
            if(a[x] == target){
                sequence++;
                end = x;
            }
        }else if (a[x] == target){
            sequence++;
            begin = x;
            end = x;
        }
    }
    return((sequence == 1) || (sequence == 2));
}

int locationOfMin(string a[], int n){
    int location = -1;
    for (int x = 0; x < n-1; x++){
        if((static_cast<int>(a[x][0])) < (static_cast<int>(a[x+1][0])))
            location = x;
    }
    return location;
}

int moveToEnd(string a[], int n, int pos){
    string temp = a[pos];
    for (int x= pos; x < n-1;x++)
        a[x] = a[x+1];
    a[n-1] = temp;
    return pos;
}

int moveToBeginning(string a[], int n, int pos){
    string temp = a[pos];
    for (int x = pos; x > 0;x--)
        a[x] = a[x-1];
    a[0] = temp;
    return pos;
}

int locateDifference(const string a1[], int n1, const string a2[], int n2){
    int smallest;
    int difference = -1;
    if (n1 > n2)
        smallest = n2;
    else
        smallest = n1;
    for (int x = 0; x < smallest; x++){
        if (a1[x] != a2[x]){
            difference = x; 
            break;
        }
    }
    if (difference == -1)
        return smallest;
    else
        return difference;
}

int eliminateDups(string a[], int n){
    string target;
    string temp[n];
    int tempCount = 0;
    
    for (int x = 0; x < n; x++) //clones the list
        temp[x] = a[x];
   
    for (int x = 0; x < n; x++){
        target = a[x];
        for (int y = x + 1; y < n; y++){
            if (a[y] != target)
                break;
            temp[y] = "!DUPLICATE"; //I used this string because it's least likely to be used as an input value
        }
    }
    
    for (int x = 0; x < n; x++){
        if (temp[x] != "!DUPLICATE"){
            a[tempCount] = temp[x];
            tempCount+=1;
        }
        
    }
    
    for (int x = tempCount; x < n; x++)
        a[x] = "DUPLICATE"; //the rest of the list is replaced with the string DUPLICATE

    return tempCount;
}

bool subsequence(const string a1[], int n1, const string a2[], int n2){
    int matches = 0;
    int lastMatch = 0;
    for (int x = 0; x < n2; x++){
        for (int y = lastMatch; y < n1; y++){
            if (a2[x] == a1[y]){
                matches++;
                lastMatch = y + 1;
                break; //makes sure that two values from a2 aren't matched with one a1 value
            }
        }
    }
    return (matches == n2);
}

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max){
    int n1Pos = 0;
    int n2Pos = 0;
    int maxPos = 0;
    for (int x = 0; x < (n1 - 1); x++){
        if((static_cast<int>(a1[x][0])) > (static_cast<int>(a1[x+1][0])))
            return -1;
    }
    
    for (int x = 0; x < (n2 - 1); x++){
        if((static_cast<int>(a2[x][0])) > (static_cast<int>(a2[x+1][0])))
            return -1;
    }

    if((n1+n2 > max))
        return -1;
        
    while ((n1Pos < n1) && (n2Pos < n2)){ //this part of my program makes sure that if one of the arrays hits its limit, it can still continue the longer list
        if ((static_cast<int>(a1[n1Pos][0])) < static_cast<int>(a2[n2Pos][0])){
            result[maxPos] = a1[n1Pos];
            maxPos++;
            n1Pos++;
        }else if (((static_cast<int>(a1[n1Pos][0])) > static_cast<int>(a2[n2Pos][0]))){
            result[maxPos] = a2[n2Pos];
            maxPos++;
            n2Pos++;
        }else{
            result[maxPos] = a1[n1Pos];
            n1Pos++;
            maxPos++;
            result[maxPos] = a2[n2Pos];
            n2Pos++;
            maxPos++;
        }
            
    }
    
    //this is the part that continues the iteration of the longer array
    if (n1Pos == n1){
        for (int x = n2Pos; x < n2; x++){
            result[maxPos] = a2[x];
            maxPos++;
        }
    }else if (n2Pos == n2){
        for (int x = n1Pos; x < n1; x++){
            result[maxPos] = a1[x];
            maxPos++;
        }
    }
    return maxPos;
}

int divide(string a[], int n, string divider){
    string temp[n];
    int counter = 0; //used to continue the list after the > values are complete
    int dividingPoint = n;
    bool firstGreaterFlag = true; //true until a value that is > than divider is found
    
    for (int x = 0; x < n; x++){ //ONLY finds values less than the divider
        if((static_cast<int>(a[x][0])) < (static_cast<int>(divider[0]))){
            temp[counter] = a[x];
            counter++;
        }
    }
    for (int x = 0; x < n; x++){
        if((static_cast<int>(a[x][0])) >= (static_cast<int>(divider[0]))){ //ONLY finds values greater than divider
            temp[counter] = a[x];
            if(firstGreaterFlag){
                dividingPoint = counter;
                firstGreaterFlag = false;
            }
            counter++;
        }
    }
    for (int x = 0; x < n; x++){
        a[x] = temp[x];
    }
    return dividingPoint;
}