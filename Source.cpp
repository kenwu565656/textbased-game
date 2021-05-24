#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string blue("\033[0;34m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");
//#include <unistd.h>
#include <windows.h>
using namespace std;
//define the information of the player
struct Player {
	int attack;
	int defense;
	int hp;
	int coin;
	string name;
	int stage;
};
int new_player(Player* a)
{
	cout << "Welcome to this game" << endl;
	cout << "Nice to meet you. What is your name ?" << endl;
	string name;
	cin >> name;
	a->name = name;
	cout << "Hello, " << a->name << endl;
	cout << "Enjoy your trip!!!" << endl;
	system("pause");
	cin.clear();
	a->attack = 10;
	a->defense = 10;
	a->hp = 50;
	a->stage = 0;
	a->coin = 0;
	return 1;
}
int read_old_record(Player* a)
{
	cout << "What is your name ?" << endl;
	string name;
	cin >> name;
	ifstream fin;
	fin.open((name + ".txt").c_str());
	if (fin.fail())
	{
		cout << "No such record" << endl;
		return 0;
	}
	cout << "Long Time No See " << name << " !!!" << endl;
	cout << "Nice To See You again" << endl;
	cout << "Let's continue your trip" << endl;
	system("pause");
	cin.clear();
	fin >> a->name >> a->attack >> a->defense >> a->hp >> a->coin >> a->stage;
	fin.close();
	return 1;
}
int ask_for_new_player_or_not(Player* a) 
{
	cout << "Are you a new player or experienced player ?" << endl;
	cout << "Please input new or experienced" << endl;
	string new_or_not;
	cin >> new_or_not;
	if (new_or_not == "new")
	{
		return new_player(a);
	}
	else if (new_or_not == "experienced")
	{
		return read_old_record(a);
	}
	cout << "You may input something wrongly" << endl;
	cout << "please try again" << endl;
	system("pause");
	return 0;
}
int store_player_record(Player* a)
{
	ofstream fout;
	fout.open((a->name + ".txt").c_str());
	if (fout.fail())
	{
		cout << "A Problem In Saving The Record" << endl;
		cout << "Please Try Again. Very Sorry To You" << endl;
		return 1;
	}
	fout << a->name << " " << a->attack << " " << a->defense << " " << a->hp << " " << a->coin << " " << a->stage << endl;
	fout.close();
	cout << "Record has been stored successfully" << endl;
	cout << "Please Do Remember Your User Name" << endl;
	cout << "Otherwise, We Cannot Get Your Record Again" << endl;
	cout << "Goodbye" << endl;
	return 1;
}
void guess_scene()
{
	cout << "+------------------Gate of the boss castle-----------------+" << endl;
	cout << "************************************************************" << endl;
	cout << "To open the gate, You have to enter a 4 digit password" << endl;
	cout << "Each digit can only be 1, 2, 3 or 4" << endl;
	cout << "Good Luck !" << endl;
	cout << "************************************************************" << endl;
	cout << "____________________________________________________________" << endl;
	cout << "|----------------------------------------------------------|" << endl;
	cout << "|----------------------------------------------------------|" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|         .....             |           .....              |" << endl;
	cout << "|        { o  o }           |          { o  o }            |" << endl;
	cout << "|         \\\\''//            |           \\\\''//             |" << endl;
	cout << "|          \\ww/            |             \\ww/              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                          o o                             |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|                           |                              |" << endl;
	cout << "|___________________________|______________________________|" << endl;
	cout << " ''..____________________..''''.._______________________..''" << endl;
}
int gate(Player* a)
{
	guess_scene();
	srand(time(NULL));
	struct fourdigit
	{
		int digit_1;
		int digit_2;
		int digit_3;
		int digit_4;
	};
	fourdigit * passwords = new fourdigit;
	passwords->digit_1 = (rand() % 4) + 1;
	passwords->digit_2 = (rand() % 4) + 1;
	passwords->digit_3 = (rand() % 4) + 1;
	passwords->digit_4 = (rand() % 4) + 1;
	int password;
	password = passwords->digit_1 * 1000 + passwords->digit_2 * 100 + passwords->digit_3 * 10 + passwords->digit_4;
	cout << password << endl;
	int guess;
	cin >> guess;

	fourdigit * guesss = new fourdigit;
	int count_bigger = 0;
	int count_equal = 0;
	int count_smaller = 0;
	int refernce;
	int guess_time = 0;
	while (guess != password)
	{
		guess_time++;
		count_bigger = 0;
		count_smaller = 0;
		count_equal = 0;
		refernce = guess;
		guesss->digit_4 = refernce % 10;
		refernce = refernce / 10;
		guesss->digit_3 = refernce % 10;
		refernce = refernce / 10;
		guesss->digit_2 = refernce % 10;
		refernce = refernce / 10;
		guesss->digit_1 = refernce % 10;
		switch (guess_time)
		{
		case 1:
			cout << "Your 1st guess: " << guesss->digit_1 << guesss->digit_2 << guesss->digit_3 << guesss->digit_4 << endl;
			break;
		case 2:
			cout << "Your 2nd guess: " << guesss->digit_1 << guesss->digit_2 << guesss->digit_3 << guesss->digit_4 << endl;
			break;
		case 3:
			cout << "Your 3rd guess: " << guesss->digit_1 << guesss->digit_2 << guesss->digit_3 << guesss->digit_4 << endl;
			break;
		default:
			cout << "Your " << guess_time << "th guess: " << guesss->digit_1 << guesss->digit_2 << guesss->digit_3 << guesss->digit_4 << endl;
			break;
		}
		if (guesss->digit_1 > passwords->digit_1)
		{
			count_bigger++;
		}
		else if (guesss->digit_1 < passwords->digit_1)
		{
			count_smaller++;
		}
		else
		{
			count_equal++;
		}
		if (guesss->digit_2 > passwords->digit_2)
		{
			count_bigger++;
		}
		else if (guesss->digit_2 < passwords->digit_2)
		{
			count_smaller++;
		}
		else
		{
			count_equal++;
		}
		if (guesss->digit_3 > passwords->digit_3)
		{
			count_bigger++;
		}
		else if (guesss->digit_3 < passwords->digit_3)
		{
			count_smaller++;
		}
		else
		{
			count_equal++;
		}
		if (guesss->digit_4 > passwords->digit_4)
		{
			count_bigger++;
		}
		else if (guesss->digit_4 < passwords->digit_4)
		{
			count_smaller++;
		}
		else
		{
			count_equal++;
		}
		if (count_equal == 4)
		{
			break;
		}
		cout << "You got " << count_equal << " digit(s) correct !" << endl;
		cout << "You got " << count_bigger << " digit(s) too big !" << endl;
		cout << "You got " << count_smaller << " digit(s) too small !" << endl;
		cout << "Try Again !" << endl;
		cin >> guess;
	}
	//system("clear");
	system("cls");
	cout << "+--------------------------Gate of the boss castle-------------------+" << endl;
	cout << "                     _______________________________________________" << endl;
	cout << "                    /|                     |-----------------------|" << endl; 
	cout << "                   / |                     |-----------------------|" << endl;
	cout << "                  /  |                     |                       |" << endl;
	cout << "                 /   |                     |                       |" << endl;
	cout << "                /    |                     |         .....         |" << endl;
	cout << "               /     |                     |        { o  o }       |" << endl;
	cout << "              /      |                     |          \\../         |" << endl;
	cout << "             /       |                     |          \\ww/         |" << endl;
	cout << "            /        |                     |                       |" << endl;
	cout << "           /         |                     |o                      |" << endl;
	cout << "          /          |                     |                       |" << endl;
	cout << "          |          |                     |                       |" << endl;
	cout << "          |          |                     |                       |" << endl;
	cout << "          |          |                     |                       |" << endl;
	cout << "          |          |                     |                       |" << endl;
	cout << "          |          |                     |                       |" << endl;
	cout << "          |          |                     |                       |" << endl;
	cout << "          |          |_____________________|_______________________|" << endl;
	cout << "          |          /                      ''.._______________..''" << endl;
	cout << "          |         /" << endl;
	cout << "          |        /" << endl;
	cout << "          |       /" << endl;
	cout << "          |      /" << endl;
	cout << "          |     /" << endl;
	cout << "          |    / " << endl;
	cout << "          |   /" << endl;
	cout << "          |  /" << endl;
	cout << "          |_/" << endl;

	
	a->stage = 3;
	a->coin = 10;
	delete passwords; 
	delete guesss;
	cout << "************************************************************" << endl;
	cout << "correct !" << endl;
	cout << "You can now enter the gate ! " << endl;
	cout << "You gain 10 coins" << endl;
	cout << "************************************************************" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
	cin.clear();
	cin.ignore();
	Sleep(5000);
	return 0;
}
void show_player_information(Player* a)
{
	cout << "+------------------------------------------------------Data Center----------------------------------------------------+" << endl;
	cout << "54390865426084352068203486234086420684568204587903271543098591075913075931275419035791304765105713904571093457130947513" << endl;
	cout << "3464908690438634065046842-60845-06843072394257628234689423762496274861730-9680135846139764845901-8539076986t43756103786" << endl;
	cout << "31485796293856309274569031278562906783187109751309753804609729075349057139057349067905471903753907513907513675203915793" << endl;
	cout << "34820975310975619037451064187109759087509357367928410781305839067251309857109235871390659307591375901709712059732157123" << endl;
	cout << "91735809137485690136521875423573519203753907412897549832547314957139067047820957329047219037541239075493247521903754190" << endl;
	cout << "59578932758023547029674189402750169710124710956981839751980610912751386513907560345670938716089537136538907515761035713" << endl;
	cout << "\n";
	cout << "Welcome! " << a->name << "Here is the data center. You can view your info\n" << endl;
	cout << "Your information: " << endl;
	cout << "Player name: " << a->name << endl;
	cout << "Attack: " << a->attack << endl;
	cout << "Defense: " << a->defense << endl;
	cout << "HP: " << a->hp << endl;
	cout << "Coin: " << a->coin << endl;
	switch (a->stage)
	{
	case 0:
		cout << "You have not completed any checkpoint yet" << endl;
		break;
	case 1:
		cout << "You have completed one checkpoint !" << endl;
		cout << "The checkpoint you have completed: checkpoint 1: Password Of The Gate" << endl;
		break;
	case 2:
		cout << "You have completed two checkpoint !" << endl;
		cout << "The checkpoint you have completed: checkpoint 1: Password Of The Gate and checkpoint 2: Questions Of The Guards" << endl;
		break;
	case 3:
		cout << "You have completed three checkpoint !" << endl;
		cout << "The checkpoint you have completed: checkpoint 1: Password Of The Gate, checkpoint 2: Questions Of The Guards and checkpoint 3: Find The Boss" << endl;
		break;
	}
	cout << endl;
	cout << "Finish Checking. Goodbye " << a->name << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
	cin.get();
	clearerr(stdin);
	//system("pause");
}
void print_shop_owner_head()
{
	cout << "+------------------------------------------------------------Shop-----------------------------------------------------+" << endl;
	cout << endl;
	cout << "                                                         ===  =====" << endl;
	cout << "                                                       =            ===" << endl;
	cout << "                                                      ==     =====    =" << endl;
	cout << "                                                    ==  =       ===    =" << endl;
	cout << "                                                  ===  =          ====    =" << endl;
	cout << "                                                   ====               ====" << endl;
	cout << "                                                  (     --         --     )" << endl;
	cout << "                                                    :   [o]-------[o]    :" << endl;
	cout << "                                                     :         :        :" << endl;
	cout << "                                                       ::     <>     :: " << endl;
	cout << "                                                          :::      :::" << endl;
	cout << "                                                             ::__::" << endl;
	cout << "                                                            |       | " << endl;
	cout << "                                                     /------         ------\\" << endl;
	cout << "                                                    /|                     |\\" << endl;
	cout << "                                                   ***************************" << endl;
	cout << "                                                   |       The Shop Owner    |" << endl;
	cout << "                                                   ***************************" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
}
void shop(Player* a)
{
	print_shop_owner_head();
	cout << red << endl;
	cout << "Owner: Hello! " << a->name << endl;
	cout << "Owner: Here is the shopping center" << endl;
	cout << "Owner: You can upgrade your attack, defense or hp with only 10coins here" << endl;
	cout << "Owner: Please choose an ablilty to upgrade" << endl;
	cout << reset << endl;
	cout << "[1] Attack" << endl;
	cout << "[2] Defense" << endl;
	cout << "[3] HP" << endl;
	cout << "(please input an integer from 1-3)\n>" << endl;
	int command;
	int shop_or_leave = 1;
	do {
		cin >> command;
		if (command == 1)
		{
			if (a->coin >= 10)
			{
				a->coin -= 10;
				a->attack += 5;
				system("cls");
				print_shop_owner_head();
				cout << red << endl; 
				cout << "Owner: Congrat ! Your attack has been increased by 5. Your attack now: " << a->attack << endl;
				cout << "Owner: Your coin now: " << a->coin << endl;
				cout << "Owner: Do you wnat to continue shopping ?" << endl; 
				cout << reset << endl;
				cout << "[1] Continue Shopping" << endl;
				cout << "[2] Leave the Shopping Center" << endl;
				cout << "(please input an integer from 1 - 2, otherwise, you will leave the shop)\n >" << endl;
				cin >> shop_or_leave;
				if (shop_or_leave == 1)
				{
					system("cls");
					print_shop_owner_head();
					cout << red << endl;
					cout << "Owner: Hello! " << a->name << endl;
					cout << "Owner: Here is the shopping center" << endl;
					cout << "Owner: You can upgrade your attack, defense or hp with only 10coins here" << endl;
					cout << "Owner: Please choose an ablilty to upgrade" << endl;
					cout << reset << endl;
					cout << "[1] Attack" << endl;
					cout << "[2] Defense" << endl;
					cout << "[3] HP" << endl;
					cout << "(please input an integer from 1-3)\n>" << endl;
				}
			}
			else
			{
				system("cls");
				print_shop_owner_head();
				cout << red << endl;
				cout << "Owner: Your coins are not enough" << endl;
				cout << "Owner: You can gain more coins by the check point!" << endl;
				cout << "Owner: Goodbye! See you again!, " << a->name <<endl;
				shop_or_leave = 2;
				cout << reset << endl;
				cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
				cin.get();
				clearerr(stdin);
			}
		}
		else if (command == 2)
		{
			if (a->coin >= 10)
			{
				a->coin -= 10;
				a->attack += 5;
				system("cls");
				print_shop_owner_head();
				cout << red << endl;
				cout << "Owner: Congrat ! Your defense has been increased by 5. Your defense now: " << a->defense << endl;
				cout << "Owner: Your coin now: " << a->coin << endl;
				cout << "Owner: Do you wnat to continue shopping ?" << endl;
				cout << reset << endl;
				cout << "[1] Continue Shopping" << endl;
				cout << "[2] Leave the Shopping Center" << endl;
				cout << "(please input an integer from 1 - 2, otherwise, you will leave the shop)\n >" << endl;
				cin >> shop_or_leave;
				if (shop_or_leave == 1)
				{
					system("cls");
					print_shop_owner_head();
					cout << red << endl;
					cout << "Owner: Hello! " << a->name << endl;
					cout << "Owner: Here is the shopping center" << endl;
					cout << "Owner: You can upgrade your attack, defense or hp with only 10coins here" << endl;
					cout << "Owner: Please choose an ablilty to upgrade" << endl;
					cout << reset << endl;
					cout << "[1] Attack" << endl;
					cout << "[2] Defense" << endl;
					cout << "[3] HP" << endl;
					cout << "(please input an integer from 1-3)\n>" << endl;
				}
			}
			else
			{
				system("cls");
				print_shop_owner_head();
				cout << red << endl;
				cout << "Owner: Your coins are not enough" << endl;
				cout << "Owner: You can gain more coins by the check point!" << endl;
				cout << "Owner: Goodbye! See you again!, " << a->name << endl;
				shop_or_leave = 2;
				cout << reset << endl;
				cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
				cin.get();
				clearerr(stdin);
			}
		}
		else if (command == 3)
		{
			if (a->coin >= 10)
			{
				a->coin -= 10;
				a->attack += 5;
				system("cls");
				print_shop_owner_head();
				cout << red << endl;
				cout << "Owner: Congrat ! Your hp has been increased by 5. Your hp now: " << a->hp << endl;
				cout << "Owner: Your coin now: " << a->coin << endl;
				cout << "Owner: Do you wnat to continue shopping ?" << endl;
				cout << reset << endl;
				cout << "[1] Continue Shopping" << endl;
				cout << "[2] Leave the Shopping Center" << endl;
				cout << "(please input an integer from 1 - 2, otherwise, you will leave the shop)\n >" << endl;
				cin >> shop_or_leave;
				if (shop_or_leave == 1)
				{
					system("cls");
					print_shop_owner_head();
					cout << red << endl;
					cout << "Owner: Hello! " << a->name << endl;
					cout << "Owner: Here is the shopping center" << endl;
					cout << "Owner: You can upgrade your attack, defense or hp with only 10coins here" << endl;
					cout << "Owner: Please choose an ablilty to upgrade" << endl;
					cout << reset << endl;
					cout << "[1] Attack" << endl;
					cout << "[2] Defense" << endl;
					cout << "[3] HP" << endl;
					cout << "(please input an integer from 1-3)\n>" << endl;
				}
			}
			else
			{
				system("cls");
				print_shop_owner_head();
				cout << red << endl;
				cout << "Owner: Your coins are not enough" << endl;
				cout << "Owner: You can gain more coins by the check point!" << endl;
				cout << "Owner: Goodbye! See you again!, " << a->name << endl;
				shop_or_leave = 2;
				cout << reset << endl;
				cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
				cin.get();
				clearerr(stdin);
			}
		}
		else
		{
			system("cls");
			print_shop_owner_head();
			cout << red << endl;
			cout << "Owner: please input a valid value" << endl;
			cout << "Owner: Hello! " << a->name << endl;
			cout << "Owner: Here is the shopping center" << endl;
			cout << "Owner: You can upgrade your attack, defense or hp with only 10coins here" << endl;
			cout << "Owner: Please choose an ablilty to upgrade" << endl;
			cout << reset << endl;
			cout << "[1] Attack" << endl;
			cout << "[2] Defense" << endl;
			cout << "[3] HP" << endl;
			cout << "(please input an integer from 1-3)\n>" << endl;
			shop_or_leave = 1;
		}
	} while (shop_or_leave == 1);
}
void fighting_scene()
{
	system("cls");
	//system("color = C");
	cout << "                                               <      >" << endl;
	cout << "                                               <      >" << endl;
	cout << "                                                -oooo-" << endl;
	cout << "                                                 oooo" << endl;
	cout << "                                                xxxxxx" << endl;
	cout << "                                               aa     aa" << endl;
	cout << "                                              aa        aa" << endl;
	cout << "                                             ^^^^^     ^^^^^" << endl;
	cout << "                                                HHHHHHH" << endl;
	cout << "                                                ()    ()" << endl;
	cout << "                                                ()    ()" << endl;
	cout << "                                                ()    ()" << endl;
	cout << "                                              ^^^^    ^^^^ " << endl;
	cout << "     aaaa" << endl;
	cout << "     aaaa" << endl;
	cout << "     aaaa" << endl;
	cout << " aaaa     aaaa   " << endl;
	cout << "  aa       aa         " << endl;
	cout << "  aa       aa   ----------------> " << endl;
	cout << "  aa       ooooo---------------->" << endl;
	cout << "                ---------------->" << endl;
	cout << "     []  []" << endl;
	cout << "     []  [] " << endl;
	cout << "     []  []" << endl;
	cout << "    ^^^  ^^^" << endl;
}
void print_HP(int x, int y)
{
	cout << "player's HP: " << x << "                               " << "boss's HP: " << y << endl;
	cout << endl;
}
void gen_mission(int x[])
{
	srand(time(NULL));
	for (int i = 0; i < 9; i++)
	{
		x[i] = rand() % 2;
	}
}
void print_mission_and_numberpad(int x[], int y[])
{
	cout << "*****************************            *****************************" << endl;
	cout << "Mission:  " << x[0] << " | " << x[1] << " | " << x[2] << "                           numberpad:  " << y[0] << " | " << y[1] << " | " << y[2] << endl;
	cout << "          " << "  +  " << " +                                           +  " << " +  " << endl;
	cout << "          " << x[3] << " | " << x[4] << " | " << x[5] << "                                       " << y[3] << " | " << y[4] << " | " << y[5] << endl;
	cout << "          " << "  +  " << " +                                           +  " << " +  " << endl;
	cout << "          " << x[6] << " | " << x[7] << " | " << x[8] << "                                       " << y[6] << " | " << y[7] << " | " << y[8] << endl;
	cout << "*****************************            *****************************" << endl;
	cout << endl;
}
void gen_number_pad(int y[])
{
	for (int i = 0; i < 9; i++)
	{
		y[i] = 0;
	}
}
void reverse(int& i)
{
	if (i == 1)
	{
		i = 0;
	}
	else
	{
		i = 1;
	}
}
void access_number_pad(int i, int y[])
{
	switch (i)
	{
	case 0:
		break;
	case 1:
		reverse(y[1]);
		reverse(y[3]);
		break;
	case 2:
		reverse(y[0]);
		reverse(y[2]);
		reverse(y[4]);
		break;
	case 3:
		reverse(y[1]);
		reverse(y[5]);
		break;
	case 4:
		reverse(y[0]);
		reverse(y[4]);
		reverse(y[6]);
		break;
	case 5:
		reverse(y[1]);
		reverse(y[3]);
		reverse(y[5]);
		reverse(y[7]);
		break;
	case 6:
		reverse(y[2]);
		reverse(y[4]);
		reverse(y[8]);
		break;
	case 7:
		reverse(y[3]);
		reverse(y[7]);
		break;
	case 8:
		reverse(y[4]);
		reverse(y[6]);
		reverse(y[8]);
		break;
	case 9:
		reverse(y[5]);
		reverse(y[7]);
		break;
	default:
		cout << "Please input an integer between 1 - 9 !!!";
	}
}
int match(int x[], int y[])
{
	int count = 0;
	for (int w = 0; w < 9; w++)
	{
		if (x[w] == y[w])
		{
			count++;
		}
	}
	return count;
}
void match_scene(int match)
{
	system("cls");
	cout << "******************************************************************************************" << endl;
	cout << "******************************************************************************************" << endl;
	cout << "******************************        " << match << " MATCHES ! ! !" << "       ******************************" << endl;
	cout << "******************************************************************************************" << endl;
	cout << "******************************************************************************************" << endl;
}
void win_scene()
{
	system("cls");
	cout << "******************************************************************************************" << endl;
	cout << "******************************************************************************************" << endl;
	cout << "******************************" << "YOU WIN ! ! !" << "******************************" << endl;
	cout << "******************************************************************************************" << endl;
	cout << "******************************************************************************************" << endl;
	system("pause");
}
void lose_scene()
{
	system("cls");
	cout << "******************************************************************************************" << endl;
	cout << "******************************************************************************************" << endl;
	cout << "******************************" << "GAME OVER" << "******************************" << endl;
	cout << "******************************************************************************************" << endl;
	cout << "******************************************************************************************" << endl;
	system("pause");
}
void reduce_HP(int& HP, int attack)
{
	HP -= attack;
}
void reduce_HP_scene(int match, int boss_attack)
{
	system("cls");
	//system("color = C");
	cout << "                                                 HP -" << match << endl;
	cout << "                                               <      >" << endl;
	cout << "                                               <      >" << endl;
	cout << "                                                -oooo-" << endl;
	cout << "                                                 oooo" << endl;
	cout << "                                                xxxxxx" << endl;
	cout << "                                               aa     aa" << endl;
	cout << "                                              aa        aa" << endl;
	cout << "                                             ^^^^^     ^^^^^" << endl;
	cout << "                                                HHHHHHH" << endl;
	cout << "                                                ()    ()" << endl;
	cout << "                                                ()    ()" << endl;
	cout << "                                                ()    ()" << endl;
	cout << "     HP -" << boss_attack << "                                   ^^^^    ^^^^ " << endl;
	cout << "     aaaa" << endl;
	cout << "     aaaa" << endl;
	cout << "     aaaa" << endl;
	cout << " aaaa     aaaa   " << endl;
	cout << "  aa       aa         " << endl;
	cout << "  aa       aa   ---------------->  " << endl;
	cout << "  aa       ooooo---------------->" << endl;
	cout << "                ---------------->" << endl;
	cout << "     []  []" << endl;
	cout << "     []  [] " << endl;
	cout << "     []  []" << endl;
	cout << "    ^^^  ^^^" << endl;
}
int boss(Player* a)
{
	int init_hp = a->hp;
	int boss_HP = 500;
	int boss_attack = (20 - a->defense);
	int * mission = new int[9];
	int * numberpad = new int [9];
	gen_number_pad(numberpad);
	while (a->hp != 0 && boss_HP != 0)
	{
		fighting_scene();
		print_HP(a->hp, boss_HP);
		gen_mission(mission);
		print_mission_and_numberpad(mission, numberpad);
		int access_key = 1;
		time_t time_now;
		time_now = time(NULL);
		time_t end_time;
		while (true)
		{

			end_time = time(NULL);
			if ((end_time - time_now) > 10 || access_key == 0)
			{
				cout << "*************TIME'S UP !!!*************" << endl;
				system("pause");
				break;
			}
			cout << " ***Please input your access key (1-9)***" << endl;
			cin >> access_key;
			access_number_pad(access_key, numberpad);
			fighting_scene();
			print_HP(a->hp, boss_HP);
			print_mission_and_numberpad(mission, numberpad);

		}
		match_scene(match(mission, numberpad));
		system("pause");
		reduce_HP(boss_HP, match(mission, numberpad) * a->attack);
		reduce_HP_scene((match(mission, numberpad) * a->attack), boss_attack);
		system("pause");
		if (boss_HP <= 0)
		{
			break;
		}
		reduce_HP(a->hp, boss_attack);
		if (a->hp <= 0)
		{
			break;
		}
	}
	if (boss_HP <= 0)
	{
		fighting_scene();
		print_HP(a->hp, boss_HP);
		system("pause");
		win_scene();
		a->stage = 4;
		return 0;
	}
	if (a->hp <= 0)
	{
		fighting_scene();
		print_HP(a->hp, boss_HP);
		system("pause");
		lose_scene();
		a->hp = init_hp;
		return 0;
	}
	delete[]numberpad;
	delete[]mission;
	return 0;
}
void walking()
{
	system("cls");
	cout << "\n\n\n\n\n\n" <<endl;
	cout << "---------------------------      Walking     ------------------------------" << endl;
	cout << "      __ ___" << endl;
	cout << "     [  |   '}" << endl;
	cout << "      '' '--'     " << endl;
	Sleep(1000);
	system("cls");
	//system("clear");
	cout << "\n\n\n\n\n\n" << endl;
	cout << "---------------------------------         Walking           -------------------------------------" << endl;
	cout << "      __ ___                                         __ ___ " << endl;
	cout << "     [  |   '}              「「「                  [  |   '}" << endl;
	cout << "      '' '--'                                        '' '--' " << endl;
	cout << "                            __ ___" << endl;
	cout << "                           [  |   '}" << endl;
	cout << "                            '' '--'     " << endl;
	Sleep(1000);
	system("cls");
	//system("clear");
	cout << "\n\n\n\n\n\n" << endl;
	cout << "-------------------------------------------               Walking           ----------------------------------------" << endl;
	cout << "      __ ___                                         __ ___                                                  __ ___ " << endl;
	cout << "     [  |   '}                  「「「              [  |   '}                                「「「         [  |   '}" << endl;
	cout << "      '' '--'                                        '' '--'                                                 '' '--'" << endl;
	cout << "                            __ ___                                               __ ___" << endl;
	cout << "                           [  |   '}                          「「「            [  |   '}" << endl;
	cout << "                            '' '--'                                              '' '--'" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
	cin.get();
	clearerr(stdin);
	system("cls");
}
void warning()
{
	system("cls");

	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "***Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!****************" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "***Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!****************" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "***Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!****************" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;	
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "***Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!*************************Warning!!!!!!!!!!!!!!!******" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "***Warning!!!!!!!*********************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!*********" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "**********************************Warning!!!!!!!***************Warning****Warning!!!!!!!!!!!!!!!***********************" << endl;
	cout << "***Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!**********************Warning!!!!!!!!!!!!!!!*********" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "***Warning!!!!!!!***********************Warning!!!!!!!!!!!!!!!!***************************Warning!!!!!!!!!!!!!!!*******" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!*************************Warning!!!!!!!!!!!!!!!****************" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "***Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***********************Warning!!!!!!!!!!!!!!!********" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	Sleep(400);

	system("cls");
	cout << reset;
	cout << "+--------------------------------------------------------Warning------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "******************************************Warning!!!!!!!***************Warning!!!!!!!!!!!!!!!!***************Warning!!!" << endl;
	cout << "*******************Warning!!!!!!!**************************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!" << endl;
	cout << "!!!!!!!!!!!!!***Warning!!!!!!!****************Warning!!!!!!!!!!!!!!!!***********Warning!!!!!!!!!!!!!!!*****************" << endl;
	cout << "***Warning!!!!!!!*****************Warning!!!!!!!!!!!!!!!!***************Warning!!!!!!!!!!!!!!!*************************" << endl;
	Sleep(400);
	cout << reset;
}
void print_master_head()
{
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << endl;
	cout << "                                                      .----------," << endl;
	cout << "                                                     //          \\\\" << endl;
	cout << "                                                     |  _       _  |" << endl;
	cout << "                                                    {|  o       o  |}" << endl;
	cout << "                                                     |      -      |" << endl;
	cout << "                                                      \\\\   ___   // " << endl;
	cout << "                                                       |\\\\_____//|" << endl;
	cout << "                                                      /           \\" << endl;
	cout << "                                             /--------             ---------\\" << endl;
	cout << "                                            /|:                            :|\\" << endl;
	cout << "                                            **********************************" << endl;
	cout << "                                            |     The Master of the Village  |" << endl;
	cout << "                                            **********************************" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
}
void introduction()
{
	print_master_head();
	cout << red << "Master: Finally......" << endl;
	cout << "Master: Are you the hero to save us ?" << endl; 
	Sleep(3000);
	system("cls");
	cout << reset;
	print_master_head();
	cout << reset << "You: What ? I have no idea." << endl;
	Sleep(3000);
	cout << red << "Master: Our village is facing a monster." << endl;
	cout << "Master: It takes the money, food from our village." << endl;
	Sleep(3000);
	cout << "Master: It even catch some of our Villagers to serve itself" << endl;
	cout << "Master: A Myth believed that there will be a hero to save our village." << endl;
	Sleep(3000);
	system("cls");
	cout << reset;
	print_master_head();
	cout << reset << "You: thinking..........." << endl; 
	Sleep(3000);
	system("cls");
	cout << reset;
	print_master_head();
	cout << reset << "You: Although I am not the hero in the story, I decided to help you." << endl;
	cout << red << "Master: That's great. You must be the hero." << endl;
	cout << "Master: Come in my village first !!!" << endl;
	cout << reset;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
	cin.get();
	clearerr(stdin);
	system("cls");
}
void start()
{
	cout << green << endl;
	cout << "                       /\\                            / /     ----    \\ \\" << endl;
	cout << "                    / / \\ \\                         / /  -----------  \\ \\" << endl;
	cout << "                   / / --\\ \\                       / /     --------    \\ \\" << endl;
	cout << "                  / /  ---\\ \\                     / /   -------------   \\ \\" << endl;
	cout << "                 / /  ---- \\ \\                   / /---    -----------   \\ \\" << endl;
	cout << "                / /  -----  \\ \\                 / /   -----------------   \\ \\" << endl;
	cout << "               / /  -------- \\ \\               / / ----------------------- \\ \\" << endl;
	cout << "              / / ----------- \\ \\             / / ----------  ------------- \\ \\" << endl;
	cout << "             / / --------------\\ \\           / / -----  -------------------- \\ \\" << endl;
	cout << "            / /-----------------\\ \\         / /----------------------  -------\\ \\" << endl;
	cout << "           / /-------------------\\ \\       / /-------------------------   -----\\ \\                 " << endl;
	cout << "          / /                     \\ \\     / /                                   \\ \\                 " << endl;
	cout << "         / /---------------------- \\ \\   / /-------------------------------------\\ \\             " << endl;
	cout << red;
	cout << "***********************************************************************************************************************" << endl;
	cout << "      /_/         ___       ______    __     __      ___        ___     ____     _______     _______" << endl;
	cout << "     /_/       / /   \\ \\    | |  \\ \\  \\ \\   / /   / /   \\ \\     | |   / /| |    | |   |_|   | |    |_|" << endl;
	cout << "    /_/       / /-----\\ \\   | |   \\ \\  \\ \\ / /   / /-----\\ \\    | |  / / | |    | |         | |____" << endl;
	cout << "   /_/       / /       \\ \\  | |   / /   \\ \\//   / /       \\ \\   | | / /  | |    | |   |-|   | |____| " << endl;
	cout << "  /_/       /_/         \\_\\ | |__/ /     \\_/   /_/         \\_\\  |_|/_/   |_|    |_|___|_|   | |____|-|" << endl;
	cout << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout << green;
	cout << "/_/________________________________/_/___\\_\\_____________________________________________\\_\\                               " << endl;
	cout << blue;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << reset;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
	cin.get();
	clearerr(stdin);
}
void village()
{
	cout << "+--------------------------------------------------------Village------------------------------------------------------+" << endl;
	cout << "                  _________________________________________________________________________     ||\\" << endl;
	cout << "                  ||\\                                                                      \\    || \\\\" << endl;
	cout << "                  || \\                                                                      \\   ||___\\\\" << endl;
	cout << "                  ||  \\                                                                      \\  || " << endl;
	cout << "                  ||   \\                                                                      \\ ||" << endl;
	cout << "                  ||    \\______________________________________________________________________\\||" << endl;
	cout << "                  ||       ^^^^^^                         ^^^^^^                           ^^^^^^" << endl;
	cout << "                  ||      |------|-----------------------|------|-------------------------|------|" << endl;
	cout << "                  ||      |oooooo|                       |oooooo|                         |oooooo|" << endl;
	cout << "                  \\       |------|-----------------------|------|-------------------------|------|" << endl;
	cout << "                   \\      |oooooo|                       |oooooo|                         |oooooo|" << endl;
	cout << "                    \\     |------|--------------------|-------------|---------------------|------|" << endl;
	cout << "                     \\    |oooooo|                    |             |                     |oooooo|" << endl;
	cout << "                      \\   |------|--------------------|     ''      |---------------------|------|" << endl;
	cout << "                       \\  |oooooo|                    |             |                     |oooooo|" << endl;
	cout << "                        \\ |------|--------------------|             |---------------------|------|" << endl;
	cout << "                         \\|oooooo|____________________|_____________|_____________________|oooooo|" << endl;
	cout << "                          '.____.'                                                        '.____.'" << endl;
	cout << "                                                        \\           \\" << endl;
	cout << "                                                         \\           \\" << endl; 
	cout << "                                                          \\           \\  " << endl;
	cout << "                                                           \\           \\" << endl;
	cout << "                                                            \\           \\" << endl;
	cout << "                                                             ~~~~~~~~~~~~" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << red << endl;
	cout << "You are in the village. Please decide where to go.(Please input an integer from 1-5)" << endl;
	cout << "[1] continue your trip to fight the boss" << endl;
	cout << "[2] visit the shop to upgrade attack, defense or hp" << endl;
	cout << "[3] go to the data center to view your player information" << endl;
	cout << "[4] save your record" << endl;
	cout << "[5] leave the game(please make sure you have saved the record)" << endl;
	cout << reset << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+\n>" << endl;
}

int main()
{
		start();
		Player* a = new Player;  // use pointer to store the information for memory management

		system("cls"); // for windows
		//system("clear"); //for linux

		introduction();
		//cout << "Welcome to the Game" << endl;      // add a game name later
		//cout << "indroduction : " << endl;   //add some intro also, just sentences, ez
		/*cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
		cin.get();
		clearerr(stdin); */
		do {

			system("cls"); // for windows
			//system("clear"); //for linux	
			cout << "+---------------------------------------------Record and login System--------------------------------------------+" << endl;
			Sleep(2000);
		} while (!(ask_for_new_player_or_not(a))); // ask the player is new or not. if new, create a new record. if old, read past record. if wrong type in, ask again
		string whole_instruction;
		char game_instruction;
		do
		{

			system("cls"); // for windows
			//system("clear"); //for linux
			cin.clear();
			village();
			getline(cin, whole_instruction);
			game_instruction = whole_instruction[0];
			switch (game_instruction)
			{
			case '1':
				walking();
				switch (a->stage)
				{
				case 0:
					warning();
					cout << "***********************************************************************************************************************" << endl;
					cout << "+------------------------------------------Check Point 1: Password of the gate----------------------------------------+" << endl;
					cout << "***********************************************************************************************************************" << endl;
					cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
					cin.clear();
					cin.ignore();
					gate(a);
					walking();
					break;
				/*case 1:
					warning();
					cout << "***********************************************************************************************************************" << endl;
					cout << "+-----------------------------------------Check Point 2: Questions of the guards--------------------------------------+" << endl;
					cout << "***********************************************************************************************************************" << endl;
					cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
					cin.clear();
					cin.ignore();
					question(a);
					walking();
					break;
				case 2:
					warning();
					cout << "***********************************************************************************************************************" << endl;
					cout << "+---------------------------------------------Check Point 3: Find the boss--------------------------------------------+" << endl;
					cout << "***********************************************************************************************************************" << endl;
					cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
					cin.clear();
					cin.ignore();
					findboss(a);
					walking();
					break;*/
				case 3:
					warning();
					cout << "***********************************************************************************************************************" << endl;
					cout << "+---------------------------------------------------Final Battle: Boss------------------------------------------------+" << endl;
					cout << "***********************************************************************************************************************" << endl;
					cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
					cin.clear();
					cin.ignore();
					boss(a);
					walking();
					break;
				}
				break;
			case '2':
				walking();
				shop(a);
				walking();
				break;
			case '4':
				walking();
				cout << "+--------------------------------------------------Record and login System---------------------------------------------+" << endl;
				store_player_record(a);
				walking();
				break;
			case '3':
				walking();
				//system("clear");
				system("cls");
				show_player_information(a);
				walking();
				break;
			case '5':
				walking();
				break;
			default:
				cout << "+--------------------------------------------------------System-------------------------------------------------------+" << endl;
				cout << "**********************************************please enter a valid number**********************************************" << endl;
				cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+---------------------------------------------Please press enter to continue...---------------------------------------+\n>" << endl;
				Sleep(3000);
				walking();
			}
		} while ((game_instruction != '5') && (a->stage < 4));


		system("cls"); // for windows
		//system("clear"); //for linux
		if (a->stage == 4)
		{
			print_master_head();
			cout << red << endl;
			cout << "Master: You did it! you beat the boss!" << endl;
			cout << "Master: You are the hero!!!, " << a->name << endl;
			cout << reset << endl;
			cout << "+-----------------------------------------------------The End-------------------------------------------------------+" << endl;
		}
		cout << "Hope you enjoy the game" << endl;
		cout << "Goodbye and have a nice day" << endl;
		delete a; //release the memory
		return 0;
	}

