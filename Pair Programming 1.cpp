#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
	cout << fixed << setprecision(2);
/* 
	//1-1	
		cout << "STUDENT INFORMATION" << endl
		<< "----------------------" << endl
		<< "COMPUTER LANGUAGES: Javascript, HTML, CSS, C++, Python" << endl
		<< "FAVORITE VIDEO GAME: Resident Evil 7" << endl
		<< "Im taking this class for my major and for the sake of learning more about CPU Science" << endl;
*/


/*
	//1-2
	double num1, num2, num3;
	
	//trial 1
	cout << "please enter your values for num1 and num2 in their respective order." << endl;
	cin >> num1 >> num2;
	cout << setw(8) << num1 << endl
		<< "*" << setw(7) << num2 << endl
		<< string(8, '-') << endl
		<< setw(8) << num1 * num2 << endl;
	
	//trial 2
	cout << "please enter your values for num1, num2 and num3 in their respective order." << endl;
	cin >> num1 >> num2 >> num3;
	cout << setw(8) << num1 << endl
		<< "*" << setw(7) << num2 << endl
		<< '-' << setw(7) << num3 << endl
		<< string(8, '-') << endl
		<< setw(8) << num1 * num2 - num3 << endl;

	//trial 3
	cout << "please enter your values for num1, num2 and num3 in their respective order." << endl;
	cin >> num1 >> num2 >> num3;	
	cout << setw(8) << num1 << endl
		<< "/" << "(" << num2 << "*" << num3 << ")" << endl
		<< string(12, '-') << endl
		<< setw(8) << num1 / (num2 * num3) << endl;



*/
/*
	//1-3
	cout << "Welcome to Lost Fortune!\nPlease answer the following questions for your personalized adventure : " << endl;
	int partyMembers;
	int partyMembersLost;

	cout << "Enter the number of explorers:" << endl;
	cin >> partyMembers;
	cout << endl << "Enter the number of Explorers lost in battle:" << endl;
	cin >> partyMembersLost;

    int partyMembersLeft = partyMembers - partyMembersLost;
	int dividedGold = 750 / partyMembersLeft;
	double bonusGold = 750 % partyMembersLeft;

	cout << "You bravely led " << partyMembers << " adventurers on a quest for gold." << endl
		<< "The group fought a band of ogres and lost " << partyMembersLost << " members." << endl
		<< "Only " << partyMembersLeft << " survived." << endl
		<< "The party was about to give up when they stumbled upon the buried fortune of 750 gold pieces." << endl
		<< "The group split the loot evenly";
	if (bonusGold > 0) {
		cout << " and as the quest leader you kept the extra "
			<< bonusGold << " gold pieces";
	}
	cout << "." << endl;
*/

/*
	//1-4
	double length;
	double height;
	double area;
	double volume;

	cout << "Enter the length of the pyramid's base:" << endl;
	cin >> length;
	cout << endl << "Enter the height of the pyramid:" << endl;
	cin >> height;

	area = pow(length, 2);
	volume = (area * height) / 3;

	cout << "The area of the base is: " << area << endl
		 << "The volume of the pyramid is: " << volume << endl;

*/

/*
	//1-5
	double appleCost = .65;
	double orangeCost = .90;
	double bananaCost = .70;

	int appleBought;
	int orangeBought;
	int bananaBought;


	cout << endl << "How many apples would you like to buy?" << endl;
	cin >> appleBought;
	cout << endl << "How many bananas would you like to buy?" << endl;
	cin >> bananaBought;
	cout << endl << "How many oranges would you like to buy?" << endl;
	cin >> orangeBought;

	double appleTotal = appleCost * appleBought;
	double orangeTotal = orangeCost * orangeBought;
	double bananaTotal = bananaCost * bananaBought;

	cout << "Bob's Fruits Groccery Invoice" << endl
		<< string(40, '-') << endl
		<< setw(3) << appleBought << " Apples  @ 0.65 each" << setw(7) << "= $ " << appleTotal << endl
		<< setw(3) << orangeBought << " Oranges @ 0.90 each" << setw(7) << "= $ " << orangeTotal << endl
		<< setw(3) << bananaBought << " Bananas @ 0.70 each" << setw(7) << "= $ " << bananaTotal << endl
		<< setw(36) << string(10, '-') << endl
		<< setw(30) << "TOTAL = $ " << appleTotal + bananaTotal + orangeTotal << endl;
	
*/

/*
	//1-6
	char ASCII;
	cout << "Please enter a custom character:" << endl;
	cin >> ASCII;
	cout << endl << "The ASCII code for the character " << ASCII << " is " << int(ASCII) << endl;
*/
	system("pause");
}