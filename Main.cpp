// **************************
// Chancellor Griffin
// COSC 1437.S02
// Lab #2: Classes
// Fall 2016
// **************************

#include <iostream>
#include "Class.h"

using namespace std;

void main()
{
	String		Str1("The Quick Brown Fox ");
	String		Str2;
	String		Str3(Str1); //cpy
	String		Str4("Jumps Over The Lazy Dog.");
	int			i;

	cout << "\nWelcome\n" << endl;

	cout << "String 1 was initialized with this sentence: ";
	Str1.DisplayLine();
	cout << "String 2 is empty. We can copy String 1 into string 2 by using Copy command." << endl;
	Str2.Copy(Str1);
	cout << "Copied String 1 into String 2: ";
	Str2.DisplayLine();
	
	cout << "\nString 3 was initialized by copying String 1, so we will have the same statement in it." << endl;
	cout << "We can compare String 3 with String 4, which contains the rest of the Sentence..." << endl;
	cout << "\nString 4 currently has this: ";
	Str4.DisplayLine();
	i = Str4.Len();
	cout << "We also know from Len() method that it has " << i << " Characters." << endl;
	cout << "Therefore when we use the compare command with Str3, it should say it comes afterward, becaause J comes before T" << endl;
	Str3.Compare(Str4);
	
	cout << "\nWe can now complete the sentence using Concat command." << endl;
	Str3.Concat(Str4);
	cout << "Now that they are combined, it finishes the statement: ";
	Str3.DisplayLine();
	i = Str3.Len();
	cout << "Which has " << i << " characters.";
	cout << "\n\n";

	// ** Lab 2 Testing **
	// ** Operator Examples **

	Str1.Copy(Str3);
	if (Str1 == Str3)
		cout << "This Works" << endl;
	else
		cout << "This doesn't work" << endl;

	if (Str1 > Str3)
		cout << "This failed" << endl;
	else
		cout << "This passed" << endl;

	Str2 = "Not String 3";
	Str3 = "Not String 2";
	if (Str3 != Str2)
		cout << "This passed" << endl;
	else
		cout << "This failed" << endl;

	if (Str2 < Str3)
		cout << "String 2 is smaller" << endl;
	else
		cout << "Error" << endl;

	String PleaseWork;
	String String1("This should");
	String String2(" Display Properly");

	PleaseWork = String1 + String2;
	cout << PleaseWork << endl;

	String1 = "Hello";
	PleaseWork = String1 + " World";
	cout << PleaseWork << endl;

	cout << "Please Enter User Input: ";
	cin >> PleaseWork;
	cout << "You Entered: " << PleaseWork  << endl;

	cout << "Enter two Identical Strings: ";
	cin >> String1;
	cout << "\n>> ";
	cin >> String2;

	if (String1 == String2)
		cout << "\nThanks For following Directions!" << endl;
	else if (String1 < String2)
		cout << "\nYour first string was smaller.... you think you wouldnt get caught?" << endl;
	else if (String1 > String2)
		cout << "\nYour first string was bigger... common now.." << endl;
	else
		cout << "INTERNAL ERROR" << endl;


	cout << "\nGoodbye" << endl;
}