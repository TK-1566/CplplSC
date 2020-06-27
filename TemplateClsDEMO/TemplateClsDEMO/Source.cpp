#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<sstream>
#include "Facebook.h"

using namespace std;

//function prototypes
void firstFriend(Facebook instance);
void removeFriend(Facebook instance);
void printFriendsF(Facebook instance);
void printFriendsR(Facebook instance);
void resetFriends(Facebook instance);
void menuSelect(Facebook instance);



int main()
{

	//variables
	fstream inputStream;
	string name, date, state;

	//create instance of Facebook class
	Facebook newFB;

	//open file
	inputStream.open("PresidentHomeState.txt");

	if (inputStream.is_open())
	{
		getline(inputStream, name, '(');

		while (inputStream)
		{
			Profile newUser;
			newUser.name = name;

			getline(inputStream, date, ')');
			{
				newUser.years = date;
				getline(inputStream, state);
				{
					newUser.state = state;

					getline(inputStream, name, '(');
					newFB.addFriend(newUser);
				}
			}
		}
		inputStream.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.";
	}
	menuSelect(newFB);
	return 0;
}

void menuSelect(Facebook newFB)
{
	char option;

	do
	{
		cout << "\nEnter an option:" << endl;
		cout << "a. Display first friend." << endl;
		cout << "b. Remove first friend." << endl;
		cout << "c. Print friends list (ascending)." << endl;
		cout << "d. Print friends list (descending)." << endl;
		cout << "e. Reset/Clear friends list." << endl;
		cout << "f. Check status of friends list." << endl;
		cout << "q. Quit program." << endl;
		cin >> option;
		cout << endl;
		if (option == 'a')
			firstFriend(newFB);
		else if (option == 'b')
			removeFriend(newFB);
		else if (option == 'c')
			printFriendsF(newFB);
		else if (option == 'd')
			printFriendsR(newFB);
		else if (option == 'e')
			resetFriends(newFB);
		else if (option == 'f')
			newFB.checkList();
		cout << endl;
	} while (option != 'q');

}

void firstFriend(Facebook instance)
{
	instance.firstFriend();
}

void removeFriend(Facebook instance)
{
	instance.removeFriend();
}

void printFriendsF(Facebook instance)
{
	instance.printFriends();
}

void printFriendsR(Facebook instance)
{
	instance.printFriendsR();
}

void resetFriends(Facebook instance)
{
	instance.resetFriends();
}
