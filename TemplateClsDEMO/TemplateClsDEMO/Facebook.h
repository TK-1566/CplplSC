#pragma once
#include<iostream>
#include<string>
#include "Queue.h"

using namespace std;

class Profile
{
public:
	string name;
	string years;
	string state;


	friend ostream& operator<<(ostream& os, const Profile& pt);


};

ostream& operator<<(ostream& os, const Profile& pt)
{
	if (addressof(pt) != NULL && pt.name != "" && pt.state != "")
		os << pt.name << " " << pt.state;
	return os;
}

class Facebook
{
private:
	int numofFriends;
	Profile User;
	Queue<Profile>* FriendLists;
public:
	void addFriend(Profile newfriend);
	void removeFriend();
	void printFriends();
	void printFriendsR();
	void firstFriend();
	void resetFriends();
	void checkList();
};

void Facebook::addFriend(Profile newfriend)
{
	if (FriendLists == NULL)
		FriendLists = new Queue<Profile>;
	FriendLists->enqueue(newfriend);
}

void Facebook::removeFriend()
{
	Profile removedFriend = FriendLists->dequeue();
	cout << "Removed: " << removedFriend << "\n\n";
}

void Facebook::printFriends()
{
	if (FriendLists->isEmpty())
	{
		cout << "There are no friends to display...how sad...\n\n";
	}
	else
		FriendLists->print();
}

void Facebook::printFriendsR()
{
	if (FriendLists->isEmpty())
	{
		cout << "There are no friends to display...how sad...\n\n";
	}
	else
		FriendLists->reversePrint();
}

void Facebook::firstFriend()
{
	Profile firstFriend = FriendLists->peek();


	cout << "First Friend is: " << firstFriend << "\n\n";
}

void Facebook::resetFriends()
{
	FriendLists->makeEmpty();

	cout << "Your friends list has been purged.";
}

void Facebook::checkList()
{
	if (FriendLists->isEmpty())
	{
		cout << "Your friends list is empty.\n\n";
	}
	else
		cout << "Friends remain waiting in your list...beware...\n\n";
}