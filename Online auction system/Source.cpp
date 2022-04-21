#include<iostream>
#include <string>
using namespace std;
#define NUM_OF_MEMBER 20
#define NUM_OF_CATEGORY 5
string category[NUM_OF_CATEGORY] = { "car","book","shose","house","painting" };
int  size_of_array_member = 2; // global variable storage number of member sign up in my system  
struct Date
{
	int day;
	int month;
	int year;
};
struct List
{
	int numOfItems;
	string Category;
	int startBidPrice;
	Date StartDate;
	Date EndDate;
	string Status;
};
struct BuyingRequist
{
	string status;
	int id;
	int price;
	int numOfItem;
};
struct Member
{
	int ID;
	string E_mail;
	string Password;
	string Name;
	string Address;
	string Phone_Number;
	List ItemsList[100];
	BuyingRequist requist[100];
	char tybe; // tybe buyer(B) or seller(S) 	
	int point;
	int numOfItem;
	int numofRequest;
	int numofComment;
	string comment[100];

} member[NUM_OF_MEMBER] = { 0 };
bool checkcategory(string x)
{
	bool isFound = 0;
	for (int i = 0; i < NUM_OF_CATEGORY; i++)
	{
		if (category[i] == x)
		{
			isFound = 1;
			break;
		}
	}
	if (isFound)
		return 1;
	else
		return 0;
}
int returnnumofcate(string x)
{
	int i;
	for (i = 0; i < NUM_OF_CATEGORY; i++)
	{
		if (x == category[i])
			break;
	}
	return i;
}
long long calcdate(Date x)
{
	long long sum = 0;
	sum = x.day;
	sum += x.month * 30;
	sum += x.year * 30 * 12;
	return sum;
}
int check(string email, string pass)
{
	bool isCorrectdata = 0;
	int i;
	for (i = 1; i <= size_of_array_member; i++)
	{
		if (email == member[i].E_mail && pass == member[i].Password)
		{
			isCorrectdata = 1;
			break;
		}
	}
	if (isCorrectdata)
		return i;
	else
		return -1;
}
void sign_up(int x) // this function to sign up new account 
{
	cout << "Enter your Email , please  as ( yourname@gmail.com ) :   ";
	cin >> member[x].E_mail;
	cout << "please Enter your password ( Least 8 digits ) :  ";
	while (1) {
		string s;
		cin >> s;
		if (s.size() >= 8)
		{
			member[x].Password = s;
			break;
		}
		else
		{
			cout << "Invalid password ,please enter valid password :  ";
		}

	}
	cout << "Please Enter your name : ";
	cin >> member[x].Name;
	cout << "Enter your address , please : ";
	cin.clear();
	getline(cin, (member[x].Address));
	cin.ignore(1000, '\n');
	cout << "Enter your phone num (11 digit) : ";
	while (1) {
		string s;
		cin >> s;
		if (s.size() == 11)
		{
			member[x].Phone_Number = s;
			break;
		}
		else
		{
			cout << "Invalid phone number ,please enter valid phone number :  ";
		}

	}
	cout << "please enter your tybe (buyer (B) , seller (S)) : ";
	while (1)
	{
		char s;
		cin >> s;
		if (s == 'S' || s == 'B')
		{
			member[x].tybe = s;
			break;
		}
		else
			cout << "invaled tybe , please enter ( B or S ) :  ";
	}
	member[x].ID = size_of_array_member + 1;
	return;
}
void insertitems(int x) // to insert new item in market placse 
{
	int placs = member[x].numOfItem;
	member[x].numOfItem++;
	cout << "Item num : ";
	cin >> member[x].ItemsList[placs].numOfItems;
	cout << "Enter category : ";
	cout << "(car , book , shoes , house , painting)";
	while (1)
	{
		string temp;
		cin >> temp;
		if (checkcategory(temp))
		{
			member[x].ItemsList[placs].Category = temp;
			break;
		}
		else {
			cout << "Invalid category enter again : ";
		}
	}
	cout << "start bid price : ";
	cin >> member[x].ItemsList[placs].startBidPrice;
	cout << "Enter date of the day : ";
	cin >> member[x].ItemsList[placs].StartDate.day;
	cin >> member[x].ItemsList[placs].StartDate.month;
	cin >> member[x].ItemsList[placs].StartDate.year;
	member[x].ItemsList[placs].Status = "avilable";
	cout << "insert sucssesfly " << endl << "------------------------------" << endl;
	return;
}
void marketplace(int x) // to see all items in market place
{
	cout << "############################################" << endl << "market placse " << endl << "-------" << endl;
	bool isFound = 0;
	for (int i = 1; i <= size_of_array_member; i++)
	{
		int sizelist = member[i].numOfItem;
		for (int j = 0; j < sizelist; j++)
		{
			if (member[i].ItemsList[j].Status == "avilable")
			{
				cout << member[i].Name << "\t" << member[i].ID << "\t" << member[i].Phone_Number << endl;
				cout << member[i].ItemsList[j].numOfItems << "\t" << member[i].ItemsList[j].Category << "\t" << member[i].ItemsList[j].startBidPrice << endl;
				isFound = 1;

				cout << "-------------------------------- \n";
				cout << "To buy this item and agree on bid price    ,  press 1 : \n";
				cout << "To buy this item and do not agree on price ,  press 2 :  \n";
				cout << "To skip this item and show the next        ,  press 3 : \n ";
				int num, price, numofitem;
				Date temp;

				cin >> num;
				if (num == 1)
				{
					cout << "enter num of item  : ";
					cin >> numofitem;
					member[i].requist[member[i].numofRequest].price = 0;
					member[i].requist[member[i].numofRequest].numOfItem = numofitem;
					member[i].requist[member[i].numofRequest].id = member[x].ID;
					member[i].numofRequest++;
					member[i].ItemsList[j].Status = "sold";
					cout << "please Enter the date of day : ";
					cin >> temp.day >> temp.month >> temp.year;
					member[i].ItemsList[j].EndDate.day = temp.day;
					member[i].ItemsList[j].EndDate.month = temp.month;
					member[i].ItemsList[j].EndDate.year = temp.year;


				}
				if (num == 2)
				{

					cout << "enter num of item  : ";
					cin >> numofitem;
					cout << "enter price you suggest : ";
					cin >> price;
					member[i].requist[member[i].numofRequest].price = price;
					member[i].requist[member[i].numofRequest].numOfItem = numofitem;
					member[i].requist[member[i].numofRequest].id = member[x].ID;

					member[i].numofRequest++;
				}

				cout << "-----------------------" << endl;

			}
		}
	}
	if (isFound == 0)
		cout << endl << "not found items to show " << endl << "------------------------" << endl;

	cout << "###########################################" << endl;
	return;
}
void marketplace(int x, string category) // to search about one category in market place
{
	cout << "############################################" << endl << "market placse " << endl << "-------" << endl;
	bool isFound = 0;
	for (int i = 1; i <= size_of_array_member; i++)
	{
		int sizelist = member[i].numOfItem;
		for (int j = 0; j < sizelist; j++)
		{
			if ((member[i].ItemsList[j].Status == "avilable") && (member[i].ItemsList[j].Category == category))
			{
				cout << member[i].Name << "\t" << member[i].ID << "\t" << member[i].Phone_Number << endl;
				cout << member[i].ItemsList[j].numOfItems << "\t" << member[i].ItemsList[j].Category << "\t" << member[i].ItemsList[j].startBidPrice << endl;
				isFound = 1;
				cout << "-------------------------------- \n";
				cout << "To buy this item and agree on bid price    ,  press 1 : \n";
				cout << "To buy this item and do not agree on price ,  press 2 :  \n";
				cout << "To skip this item and show the next        ,  press 3 : \n ";
				int num, price, numofitem;
				Date temp;
				cin >> num;
				if (num == 1)
				{
					cout << "enter num of item  : ";
					cin >> numofitem;
					member[i].requist[member[i].numofRequest].price = 0;
					member[i].requist[member[i].numofRequest].numOfItem = numofitem;
					member[i].requist[member[i].numofRequest].id = member[x].ID;

					member[i].numofRequest++;

					member[i].ItemsList[j].Status = "sold";
					cout << "please Enter the date of day : ";
					cin >> temp.day >> temp.month >> temp.year;
					member[i].ItemsList[j].EndDate.day = temp.day;
					member[i].ItemsList[j].EndDate.month = temp.month;
					member[i].ItemsList[j].EndDate.year = temp.year;
				}
				if (num == 2)
				{

					cout << "enter num of item  : ";
					cin >> numofitem;
					cout << "enter price you suggest : ";
					cin >> price;
					member[i].requist[member[i].numofRequest].price = price;
					member[i].requist[member[i].numofRequest].numOfItem = numofitem;
					member[i].requist[member[i].numofRequest].id = member[x].ID;

					member[i].numofRequest++;
				}

				cout << "-----------------------" << endl;

			}
		}
	}
	if (isFound == 0)
		cout << endl << "not found items to show " << endl << "------------------------" << endl;

	cout << "###########################################" << endl;
	return;
}
void marketplace(int x, string category, int price) //to search via category and price  
{
	cout << "############################################" << endl << "market placse " << endl << "-------" << endl;
	bool isFound = 0;
	for (int i = 1; i <= size_of_array_member; i++)
	{
		int sizelist = member[i].numOfItem;
		for (int j = 0; j < sizelist; j++)
		{
			if ((member[i].ItemsList[j].Status == "avilable") && (member[i].ItemsList[j].Category == category) && (member[i].ItemsList[j].startBidPrice == price))
			{
				cout << member[i].Name << "\t" << member[i].ID << "\t" << member[i].Phone_Number << endl;
				cout << member[i].ItemsList[j].numOfItems << "\t" << member[i].ItemsList[j].Category << "\t" << member[i].ItemsList[j].startBidPrice << endl;
				isFound = 1;
				cout << "-------------------------------- \n";
				cout << "To buy this item and agree on bid price    ,  press 1 : \n";
				cout << "To buy this item and do not agree on price ,  press 2 :  \n";
				cout << "To skip this item and show the next        ,  press 3 : \n ";
				int num, price, numofitem;
				Date temp;
				cin >> num;
				if (num == 1)
				{
					cout << "enter num of item  : ";
					cin >> numofitem;
					member[i].requist[member[i].numofRequest].price = 0;
					member[i].requist[member[i].numofRequest].numOfItem = numofitem;
					member[i].requist[member[i].numofRequest].id = member[x].ID;
					member[i].numofRequest++;
					member[i].ItemsList[j].Status = "sold";
					cout << "please Enter the date of day : ";
					cin >> temp.day >> temp.month >> temp.year;
					member[i].ItemsList[j].EndDate.day = temp.day;
					member[i].ItemsList[j].EndDate.month = temp.month;
					member[i].ItemsList[j].EndDate.year = temp.year;

				}
				if (num == 2)
				{

					cout << "enter num of item  : ";
					cin >> numofitem;
					cout << "enter price you suggest : ";
					cin >> price;
					member[i].requist[member[i].numofRequest].price = price;
					member[i].requist[member[i].numofRequest].numOfItem = numofitem;
					member[i].requist[member[i].numofRequest].id = member[x].ID;

					member[i].numofRequest++;
				}

				cout << "-----------------------" << endl;

			}
		}
	}
	if (isFound == 0)
		cout << endl << "not found items to show " << endl << "------------------------" << endl;

	cout << "###########################################" << endl;
	return;
}
void buyingrequest(int x) // to buy item 
{
	bool isFound = 0;
	for (int i = 0; i < member[x].numofRequest; i++)
	{
		int s;
		if (member[x].requist[i].status == "done")
			continue;
		if (member[x].requist[i].price != 0)
		{
			cout << "the user is Id :  " << member[x].requist[i].id << " requist to buy your item have num " << member[x].requist[i].numOfItem << endl;
			cout << "if you agree on price : " << member[x].requist[i].price << "  enter 1  or 2 if you dont agree " << endl;
			cin >> s;
			Date temp;
			if (s == 1)
			{
				for (int j = 0; j < member[x].numOfItem; j++)
				{
					if (member[x].requist[i].numOfItem == member[x].ItemsList[j].numOfItems)
					{
						member[x].ItemsList[j].Status = "sold";
						cout << "please Enter the date of day : ";
						cin >> temp.day >> temp.month >> temp.year;
						member[x].ItemsList[j].EndDate.day = temp.day;
						member[x].ItemsList[j].EndDate.month = temp.month;
						member[x].ItemsList[j].EndDate.year = temp.year;
					}
				}
				member[x].requist[i].status = "done";
			}
			else if (s == 2)
			{
				member[x].requist[i].status = "done";
			}
			isFound = 1;
		}
		else if (member[x].requist[i].price == 0)
		{
			cout << "The customer whose ID " << member[x].requist[i].id << " has purchased your product whose ID " << member[x].requist[i].numOfItem << endl;
			cout << "press 1 to continue  : ";
			cin >> s;
			if (s == 1)
				member[x].requist[i].status = "done";
			isFound = 1;
		}
	}
	if (isFound == 1)
	{
		cout << endl << "you have no other requests  " << endl << "######################################" << endl;

	}
	else
	{
		cout << endl << "you have no requests  " << endl << "######################################" << endl;
	}
	return;
}
void topcategory(Date x) // to show top category
{
	bool isFound = 0;
	int arrofcategory[NUM_OF_CATEGORY] = { 0 };
	for (int i = 0; i < size_of_array_member; i++)
	{
		int sizelist = member[i].numOfItem;
		for (int j = 0; j < sizelist; j++)
		{
			if (member[i].ItemsList[j].Status == "sold")
			{
				int sum = calcdate(x) - calcdate(member[i].ItemsList[j].EndDate);
				cout << "sum is : " << sum;
				if (sum <= 30)
				{
					isFound = 1;
					string temp = member[i].ItemsList[j].Category;
					arrofcategory[returnnumofcate(temp)]++;
				}
			}
		}
	}
	if (isFound == 0)
	{
		cout << "################################\n" << "No products were sold  ------" << endl;
		return;
	}

	cout << "###################################" << endl << "max category sold in month later is : " << endl;
	for (int i = 0; i < NUM_OF_CATEGORY; i++)
	{
		int mx = 0, mxindex = -1;
		for (int j = 0; j < NUM_OF_CATEGORY; j++)
		{
			if (arrofcategory[j] > mx)
			{
				mx = arrofcategory[j];
				mxindex = j;
			}
		}
		if (arrofcategory[mxindex] != 0 && mxindex != -1)
		{
			cout << "#num " << i + 1 << " : " << category[mxindex] << " sold out " << arrofcategory[mxindex] << " times " << endl;
			arrofcategory[mxindex] = 0;
		}

	}
	return;
}
void feedback() // to make feedback
{
	int id, rate;
	cout << "Enter ID of the other member participating in the transaction : ";
	cin >> id;
	cout << "Enter a rating (1 to 5 ) : ";
	while (1)
	{
		cin >> rate;
		if (rate >= 1 && rate <= 5)
		{
			break;
		}
		cout << "Invalid rate please enter valid rate : ";
	}
	cout << "Enter your comment (withoutspace) \n";
	cin >> member[id].comment[member[id].numofComment];



	cout << "Thanks for your feedback \n" << "-----------------------------------\n";

	if (rate >= 3)
	{
		member[id].point++;
	}

	member[id].numofComment++;
	return;
}
void showcomment(int x) // to display all comments that other write to user use this function
{
	cout << "your comments : \n";
	for (int i = 0; i < member[x].numofComment; i++)
	{
		cout << "#num " << i + 1 << " :  " << member[x].comment[i] << endl;
	}
	if (member[x].numofComment != 0)
		cout << endl << "No anouther comment" << endl << "##########################################\n";
	else
		cout << "Not found comments \n" << "############################### \n";
	return;
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
int main()
{
	// set data to user num 1  
	member[1].ID = 1;
	member[1].E_mail = "s";
	member[1].Address = "street1 in cairo";
	member[1].Name = "user1";
	member[1].Password = "12345678";
	member[1].Phone_Number = "123456789";
	member[1].tybe = 'S';
	member[2].ID = 2;
	member[2].E_mail = "b";
	member[2].Address = "street1 in cairo";
	member[2].Name = "user2";
	member[2].Password = "123456789";
	member[2].Phone_Number = "123456789";
	member[2].tybe = 'B';
	while (true)
	{
		cout << "press 1 to sign in         : \n";
		cout << "press 2 to sign up         : \n";
		cout << "press 3 to close program : \n";
		int x;
		bool isClose = 0;
		string email, pass;
		int checkresult = -111;
		while (1)
		{
			cin >> x;
			if (x >= 1 && x <= 3)
				break;
			cout << "invalid number , enter again : ";
		}
		switch (x)
		{
		case 1:
			cout << "please enter email : ";
			cin >> email;
			cout << "please enter password : ";
			cin >> pass;
			checkresult = check(email, pass);
			if (checkresult == -1)
			{
				cout << "invalid email or password \n";
				continue;
			}
			else
			{
				Date temp;
				cout << endl << "#########################################################" << endl << endl;
				cout << "Welcom : " << member[checkresult].Name << endl;
				cout << "Your point is : " << member[checkresult].point << endl;
				cout << "------------------------------------ \n";
				if (member[checkresult].tybe == 'S')
				{
					while (1)
					{
						cout << "to insert new item into market plase press 1 :  \n";
						cout << "to show buying requist press 2 : \n";
						cout << "to show top category was sold in sepsific mounth press 3 : \n";
						cout << "to give feedback press 4 : \n";
						cout << "to show your comments press 5  : \n";
						cout << "press 6 to sign out : \n";

						cin >> x;
						switch (x)
						{
						case 1:
							insertitems(checkresult);
							break;
						case 2:
							buyingrequest(checkresult);
							break;
						case 3:
							cout << "enter date of day  : ";
							cin >> temp.day >> temp.month >> temp.year;
							topcategory(temp);
							cout << "################################################" << endl;
							break;

						case 4:
							feedback();
							break;
						case 5:
							showcomment(checkresult);
							break;
						}
						if (x == 6)
							break;

					}
					continue;
				}
				else
				{
					while (1)
					{
						int x, price;
						string category;
						cout << "to show market place press 1 :" << endl;
						cout << "to show top category was sold in sepsific mounth press 2 : \n";
						cout << "to give feedback press 3 : \n";
						cout << "to show your comments press 4 : \n";
						cout << "to sign out press 5 " << endl;
						cin >> x;
						switch (x)
						{
						case 1:
							cout << "-------------------------\n";
							cout << "show marketplacse press 1         :   \n";
							cout << "to search via category press 2    : \n";
							cout << "to search via category and price press 3 : \n";
							cin >> x;
							while (x != 1 && x != 2 && x != 3)
							{
								cout << "invalid num , please enter valid num :";
								cin >> x;
							}
							switch (x) {
							case 1:
								marketplace(checkresult);
								break;
							case 2:
								cout << endl << "-----------------------------------" << endl << "enter category you search about : ";
								cin >> category;
								marketplace(checkresult, category);
								break;
							case 3:
								cout << endl << "-----------------------------------" << endl << "enter category you search about : ";
								cin >> category;
								cout << "enter price you search about : ";
								cin >> price;
								marketplace(checkresult, category, price);
								break;

							}
							break;
						case 2:
							cout << "enter date of day  : ";
							cin >> temp.day >> temp.month >> temp.year;
							topcategory(temp);
							cout << "################################################" << endl;
							break;
						case 3:
							feedback();
							break;
						case 4:
							showcomment(checkresult);
							break;
						}
						if (x == 5)
							break;
					}
				}
			}
			break;
		case 2:
			sign_up(size_of_array_member + 1);
			size_of_array_member++;
			cout << "logup succesfuly , your ID : " << size_of_array_member << endl;
			continue;
			break;
		case 3:
			isClose = 1;
			break;
		default:
			cout << "invalid num please enter (1 or 2 or 3 ) \n";
			continue;
			break;
		}
		if (isClose)
			break;
	}
	return 0;
}