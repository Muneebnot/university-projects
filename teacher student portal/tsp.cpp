#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class teacher
{
private:
	char name[50];
	char password[50];
public:
	void user_register()
	{
		ofstream fwrite("userdata.txt", ios::app);
		cout << "enter your name: " << endl;
		cin >> name;
		cout << "enter your password: " << endl;
		cin >> password;
		fwrite << name << " " << password << endl;
	}
	char* gettname()
	{
		return name;
	}
	char* gettpass()
	{
		return password;
	}
};


class student
{
private:
	char name[50];
	char password[50];
	int rollno;
	int marks[5];
	char grade[6];
	int attendence = 0;
public:
	void user_register()
	{
		ofstream fwrite1("studentdata.txt", ios::app);
		cout << "enter name: " << endl;
		cin >> name;
		cout << "enter password: " << endl;
		cin >> password;
		cout << "enter roll no: " << endl;
		cin >> rollno;
		fwrite1 << name << " " << password << " " << rollno << endl;
	}
	void user_marks()
	{
		cout << "****ENTER STUDENT MARKS OF 5 SUBJECTS****" << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << "marks of subject " << i + 1 << " : " << endl;
			cin >> marks[i];
		}
	}
	void user_grades()
	{
		cout << "****ENTER STUDENT GRADES OF 5 SUBJECTS****" << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << "grade of subject " << i + 1 << " : " << endl;
			cin >> grade[i];
		}
	}
	void mark_attendence()
	{
		attendence++;
	}

	char* getsname()
	{
		return name;
	}
	char* getspass()
	{
		return password;
	}
	int getrollno()
	{
		return rollno;
	}

	void report()
	{
		ofstream fwrites("report.txt", ios::app);
		cout << "NAME: " << name << "\nROLLNO: " << rollno <<"\nATTENDENCE:  "<<attendence<<"MARKS: " << endl;
		fwrites <<name<<" " << rollno<<" "<< attendence << " ";
		for (int i = 0;i < 5;i++)
		{
			cout << marks[i] << endl;
			fwrites<< marks[i] << " ";
		}
		cout << "grades: " << endl;
		for (int i = 0;i < 5;i++)
		{
			cout << grade[i] << endl;
			fwrites << grade[i];
		}
		cout << endl;
	}
};

template<class type>

type* grow(type* oldarr, int& size)
{
	int newsize = size + 1;
	type* newarr = new type[newsize];
	for (int i = 0;i < size;i++)
	{
		newarr[i] = oldarr[i];
	}
	delete[]oldarr;
	size = newsize;
	return newarr;
}


template<class type>
type* shrink(type* oldarr, int& size,int targetroll)
{
	int newsize = size - 1;
	type* newarr = new type[newsize];
	int k = 0;
	for (int i = 0;i < size;i++)
	{
		if (targetroll != oldarr[i].getrollno())
		{
			newarr[k] = oldarr[i];
			k++;
		}
	}
	delete[]oldarr;
	size = newsize;
	return newarr;
}






int main()
{
	int ssize = 0;
	int tsize = 0;
	teacher* tarr = new teacher[tsize];
	student* sarr = new student[ssize];
	int domain;
	do
	{


		cout << "PLEASE SELECT ON OF THESE:\n1.TEACHER\n2.STUDENT\n3.EXIT" << endl;
		cin >> domain;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "invalid choice entered!" << endl;
		}
		int choice;
		if (domain == 1)
		{
			char opinion[50];
			cout << "ARE YOU REGISTERED: (y or n)" << endl;
			cin >> opinion;
			
			if (strcmp(opinion, "y")==0)
			{
				char username[50];
				char userpass[50];
				cout << "enter name: " << endl;
				cin >> username;
				cout << "enter password: " << endl;
				cin >> userpass;
				char filename[50];
				char filepass[50];
				bool login = false;
				ifstream fread("userdata.txt");
				while (fread >> filename>>filepass)
				{
					if (strcmp(username, filename) == 0 && strcmp(userpass, filepass) == 0)
					{

						cout << "login successfully!" << endl;
						login = true;
					}
				}
				fread.close();
				
					if (login)
					{


						do
						{
							cout << "----TEACHER MENU----" << endl;
							cout << "1.ADD STUDENT:\n2.DELETE STUDENT:\n3.SHOW STUDENTS: \n4.MARK ATTENDENCE\n5.ENTER MARKS:\n6.ENTER GRADES:\n7.EXIT: " << endl;
							cin >> choice;
							if (cin.fail())
							{
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "invalid choice entered!" << endl;
							}
							switch (choice)
							{
							case 1:
							{
								sarr = grow(sarr, ssize);
								sarr[ssize - 1].user_register();
								break;
							}
							case 2:
							{
								int r;
								cout << "enter student roll no to delete: " << endl;
								cin >> r;
								sarr = shrink(sarr, ssize, r);
								break;
							}
							case 3:
							{
								for (int i = 0;i < ssize;i++)
								{
									cout << "NAME: " << sarr[i].getsname() << "\nROLL NO: " << sarr[i].getrollno() << endl;
								}
								break;
							}
							case 4:
							{
								int r;
								cout << "enter student roll no to mark attendence: " << endl;
								cin >> r;
								bool found = false;
								for (int i = 0;i < ssize;i++)
								{
									if (r == sarr[i].getrollno())
									{
										sarr[i].mark_attendence();
										found = true;
									}
								}
								if (!found)
								{
									cout << "wrong roll number added!" << endl;
								}
								break;
							}

							case 5:
							{
								int r;
								cout << "enter roll no to add marks: " << endl;
								cin >> r;
								bool found = false;
								for (int i = 0;i < ssize;i++)
								{
									if (r == sarr[i].getrollno())
									{
										sarr[i].user_marks();
										found = true;
									}
								}
								if (!found)
								{
									cout << "wrong roll number added!" << endl;
								}
								break;
							}

							case 6:
							{
								int r;
								cout << "enter roll no to add grades: " << endl;
								cin >> r;
								bool found = false;
								for (int i = 0;i < ssize;i++)
								{
									if (r == sarr[i].getrollno())
									{
										sarr[i].user_grades();
										found = true;
									}
								}
								if (!found)
								{
									cout << "wrong roll number added!" << endl;
								}
								break;
							}
							case 7:
							{
								break;
							}

							default:
							{
								break;
							}

							}



						} while (choice != 7);


					}
			}
			else if(strcmp(opinion,"n")==0)
			{
				tarr = grow(tarr, tsize);
				tarr[tsize - 1].user_register();
			}
			else
			{
				cout << "wrong choice entered!" << endl;
			}

		}
		else if (domain == 2)
		{
			ifstream fread1("studentdata.txt");
			char username[50];
			char userpassword[50];
			char filename[50];
			char filepass[50];
			cout << "enter user name: " << endl;
			cin >> username;
			cout << "enter password: " << endl;
			cin >> userpassword;
			bool login = false;
			int fileroll;
			while(fread1>>filename>>filepass>>fileroll)
			{
				if (strcmp(username, filename) == 0 && strcmp(userpassword, filepass) == 0)
				{
					cout << "login successfully!" << endl;
					login = true;
					break;
				}
			}
			if (login)
			{
				int choice;
				do
				{
					
					cout << "--STUDENT MAINMENU--" << endl;
					cout << "1.VIEW REPORT: " << endl;
					cout << "2.EXIT: " << endl;
					cin >> choice;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "invalid choice entered!" << endl;
					}
					switch (choice)
					{
					case 1:
					{
						int r;
						cout << "enter roll number to see report: " << endl;
						cin >> r;
						bool found = false;
						int k = 0;
						for (int i = 0;i < ssize;i++)
						{
							if (r == sarr[i].getrollno())
							{
								found = true;
								k = i;
							}
						}
						if (found)
						{
	
							sarr[k].report();
							break;
						}
						if (!found)
						{
							cout << "wrong roll number added!" << endl;
						}
						break;
					}
					case 2:
					{
						break;
					}
					default:
					{
						break;
					}
					}
				} while (choice != 2);
			}
		}
		else if (domain == 3)
		{
			break;
			}
	}while (domain != 3);
}