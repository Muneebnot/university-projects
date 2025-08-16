#include<iostream>
#include<cstring>

using namespace std;






class user
{
private:
	char name[50];
	char password[50];

public:
	void userregister()
	{
		cout << "enter name: " << endl;
		cin >> name;
		cout << "enter your password: " << endl;
		cin >> password;
	}

	char* getname()
	{
		return name;
	}

	char* getpassword()
	{
		return password;
	}
	void showusers(user*arr,int size)
	{
		for (int i = 0;i < size;i++)
		{
			cout << "NAME: " << arr[i].name << endl;
		}
	}
	
};
void copyarray(user* oldarr, int size, user* newarr)
{
	for (int i = 0;i < size;i++)
	{
		newarr[i] = oldarr[i];
	}
}

user* shrink(user* oldarr, int& size, char* target)
{
	int newsize = size - 1;
	user* newarr = new user[newsize];
	int k = 0;
	for (int i = 0;i < size;i++)
	{
		if (strcmp(target, oldarr[i].getname()) != 0)
		{
			newarr[k] = oldarr[i];
			k++;
		}
	}
	delete[]oldarr;
	size = newsize;
	return newarr;

}

user* grow(user* oldarr, int& size)
{
	int newsize = size + 1;
	user* newarr = new user[newsize];
	copyarray(oldarr, size, newarr);
	delete[]oldarr;
	size = newsize;
	return newarr;

}
int main()
{
	int choice;
	int size = 0;
	user* arr = new user[size];

	do
	{
		cout << "---MAIN MENU---" << endl;
		cout << "1.REGISTER USER: " << endl;
		cout << "2.LOGIN USER: " << endl;
		cout << "3.SHOW USER LIST: " << endl;
		cout << "4.SEARCH USER: " << endl;
		cout << "5.DELETE USER: " << endl;
		cout << "6.EXIT: " << endl;

		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "invalid choice entered!\n ENTER CHOICE AGAIN: " << endl;
		}
		switch (choice)
		{
		case 1:
		{
			arr = grow(arr, size);
			arr[size - 1].userregister();
			break;
		}
		case 2:
		{
			char name[50];
			char password[50];
			cout << "enter user name: " << endl;
			cin >> name;
			cout << "enter password: " << endl;
			cin >> password;
			bool login = false;
			for (int i = 0;i < size;i++)
			{
				if (strcmp(name, arr[i].getname()) == 0 && strcmp(password, arr[i].getpassword()) == 0)
				{
					cout << "login succesfully!" << endl;
					login = true;
					break;
				}
			}
			if (!login)
			{
				cout << "wrong info added" << endl;
			}
			break;
		}

		case 3:
		{
			for (int i = 0;i < size;i++)
			{
				cout << arr[i].getname() << endl;
			}
			break;
		}
		case 4:
		{
			char n[50];
			cout << "enter name to search: " << endl;
			cin >> n;
			bool found = false;
			for (int i = 0;i < size;i++)
			{
				if (strcmp(n, arr[i].getname()) == 0)
				{
					cout << "NAME FOUND!" << endl;
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << "no such person exits!" << endl;
			}
			break;
		}
		case 5:
		{
			char n[50];
			cout << "enter username to delete: " << endl;
			cin >> n;
			arr = shrink(arr, size, n);
			break;
		}

		case 6:
		{
			break;
		}
		default:
		{
			break;
		}



		}






	} while (choice != 6);
}