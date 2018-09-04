#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    
    cout << setprecision(2) << fixed;
    
    double initOdometer;
    double finOdometer;
    double totalOdometer;
    string customerName;
    double total;
    int dayNumber;

    cout << "Initial odometer reading: ";
    cin >> initOdometer;
    
    cout << "Final odometer reading: ";
    cin >> finOdometer;

    cin.ignore();
    
    cout << "Customer Name: ";
    getline(cin, customerName);
    
    
    cout << "Day number (1=sun, 2=Mon, etc.): ";
    cin >> dayNumber;
    
    cout << "---" << endl;
    
    totalOdometer = finOdometer - initOdometer;
    
    //this will check to see if dayNumber is in the range of Monday through thursday
    bool boolPremium = (dayNumber == 2) || (dayNumber == 3) || (dayNumber == 4) || (dayNumber == 5); 

    if(initOdometer < 0){
        cout << "The initial odometer reading must be nonnegative." << endl;
    }
    else if(initOdometer > finOdometer){
        cout << "The final reading must be at least as large as the initial reading";
    }
    else if (customerName.length() == 0){
        cout << "You must enter a customer name";
    }
    else if (dayNumber > 7 || dayNumber < 0){
        cout << "The day number must be in the range 1 through 7." << endl;
    }
    else{
        if (boolPremium){
            //non premium days mon-thurs (2, 3, 4, 5)
            if (totalOdometer <= 48){
                //regular price for all hours
                total = 3.12 * totalOdometer;
            }
            else{
                //regular price for first 48 hours THEN higher price for the rest
                total = (3.12 * 48) + (6.55 * (totalOdometer - 48));
            }
        }
        else{
            if (totalOdometer <= 30){
                //regular price for all hours
                total = 4.28 * totalOdometer;
            }
            else{
                //regular price for first 30 hours THEN higher price for the rest
                total = (4.28 * 30) + (6.55 * (totalOdometer - 30));
            }
        }
        cout << "The bill for " << customerName << " is $" << total << "\n";
    }
    
}