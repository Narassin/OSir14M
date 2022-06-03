//PREDEFINED HEADERS
#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<string>
//CONSTANTS
#define SIZE 75
//NAMESPACE
using namespace std;

//STRUCTURE
struct hisco
{
	string name;
	int score;
};

//USER SELF DEFINED FUNCITON
void intro();
int menu();
void game();
void display_HS();
void credit();
int randomizer(int);
int category(int);
int optionscramble(int);
int display(int, int);
void highscore(int); 



//GLOBAL VARIABL AND ARRRAYS
string brand[] = {"Techware", "Armageddon", "Lenovo", "Acer", "Asus", "HP", "MSI", "Dell", "Logitech", "Apple", "Intel", "Corsair", "Alienware", "Benq", "Hyperx", "SteelSeries",
						"Razer", "Toshiba", "Samsung", "LG", "Fujitsu", "Sony", "Aorus", "Gigabytes", "Illegear", "Adidas", "Asics", "Bonia", "Canterbury", "Champion", "Diadora",
						"Fila", "H&M", "Joma", "Jordan", "Kappa", "Levis", "Line 7", "Mizuno", "New Balance", "Nike", "Puma", "Reebok", "Rip Curl", "Skechers", "The North Face",
						"Umbro", "Under armour","Vans", "Padini","Tefal","Tupperware","Ziploc","Rubber Maid","Royal Selangor","Pyrex","Kenwood","Meyer","Are/Ikan","Masahiro","Snicker",
						"Mazola","Kitkat","Kinder","Skippy","M&M","Ovaltine","Ferrero","Poptart","Pringles","Koko Krunch","Kellogs","Oreo","Doritos","Nutella","L'Oreal","Estee Lauder",
						"Maybelline","Guerlain","NARS","Laura Mercier","CHANEL","Clarins","SHISEIDO","Dior","Urban Decay","Sephora","IT Cosmetics","Yves Saint Laurent","Givenchy",
						"Bobbi Brown","MAC","Lancome","Covergirl","Clinique","e.l.f. Cosmetics","NYX","Revlon","bareMinerals","Elizabeth Arden"};

string brand_type[] = {"Tech","Clothing","Kitchenware","Food","Cosmetic"};

//MAIN FUNCTION
int main()
{
	int i = 0;
	
	while(i==0)
	{
		i = menu();
	}
	
	return 0;
}

//MENU FUNCTION
int menu()
{
	int i =0;
	string line;
	
	while(i==0)
	{
	ifstream myfile ("Database/menu.txt");
	if (myfile.is_open())
	{
    	while ( getline (myfile,line) )
      		cout << line << '\n';
 	 }
 	
    myfile.close();
	char opt;
	cout<<"\nChoose an option: ";
	cin>>opt;
	switch(opt)
	{
		case '1':game();break;
		case '2':display_HS();break;
		case '3':credit();break;
		case '4':i=1;;break;
		default:cout<<"Incorrect input\n";
	}
	system("cls");
	}
	
	
	return 1;
}

//START GAME
void game()
{
	//INITIALIZER
	int score=0,question,answer,temp,sstat=0;
	char opt,opt1,opt2,ans;
	bool lose; 
	//START A LOOP
	do
	{
		//pick random question
		system("cls");
		question = randomizer(SIZE);
		answer = category(question);
		
		srand(time(NULL));//pick random option
		temp = rand()% 2 + 1;
		if(temp == 1)
		{
			opt1 = answer;
			opt2 = optionscramble(answer);
			ans = '1';
		}
		else
		{
			opt1 = optionscramble(answer);
			opt2 = answer;
			ans = '2';
		}	
		//Display intermission
		sstat = display(sstat,score);
		system("pause");
		system("cls");
		//Display ingame
		cout<<"=========\nIN-GAME\n=========\n\nBRAND:"<<brand[question]<<"\n\nOptions:\n1-"<<brand_type[opt1]<<"\t2-"<<brand_type[opt2]<<"\n\n";
		do
		{
			cout<<"Enter your answer: ";
			cin>>opt;
			if (!(opt=='1'||opt=='2'))
			{
				cout<<"Wrong input! Re-enter";
			}
		}while(!(opt=='1'||opt=='2'));
		//Validate answer
		if(opt==ans)
		//if right update highscore
		{
			//update score
			score++;
			//sstat = display(sstat,score);	
		}
		else
		//if wrong end
		{
		 	lose = true;
		 	sstat = 2;
		 	system("cls");
			sstat = display(sstat,score);
		}
	}while(lose==false);
	system("pause");
	highscore(score);
	
}

//DISPLAY HIGHSCORE
void display_HS()
{
	int i = 0;
	system("cls");
	string line;
	ifstream myfile ("Database/highscore.txt");
	
	cout<<"===========\nHIGHSCORE\n===========\nNAME\tSCORE\n====\t=====\n";
	
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
			cout << line << '\n';
	myfile.close();
 	}
 	system("pause");
}


void credit()
{
		
	string line;
	ifstream myfile ("Database/credit.txt");
	system("cls");
	
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
			cout << line << '\n';
	myfile.close();
 	}
 	system("pause");
}

int randomizer(int size)
{
	int x;
	srand(time(NULL));
	
	x=rand() % size + 1;
	
	return x;
}

int category(int x)
{
	int y;
	
	if (x<=24)
		return 0;
	else if(x<=49)
		return 1;
	else if(x<=59)
		return 2;
	else if(x<74)
		return 3;
	else
		return 4;
}

int optionscramble(int a)
{
	int i;
	do
	{
		srand(time(NULL));
		i = rand() % 5 + 0;
	}while(i==a);
	return i;
}

int display(int o, int score)
{
	cout<<"Score: "<<score;
	if(o == 0)
	{
		string line;
		ifstream myfile ("Database/displayonce.txt");
		
		
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
				cout << line << '\n';
			myfile.close();
	 	}
	 	return 1;
	}
	else if(o == 1)
	{
		string line;
		ifstream myfile ("Database/displaywin.txt");
		
		
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
				cout << line << '\n';
			myfile.close();
	 	}
	 	return 1;
	}
	else if(o == 2)
	{
		string line;
		ifstream myfile ("Database/displaylost.txt");
		
		
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
				cout << line << '\n';
			myfile.close();
	 	}
	 	return 2;
	}
	
}

void highscore(int x)
{
	hisco tscore[3], temp;
	
	string nama;
	
	ofstream sco;
	ifstream hs;
	hs.open("Database/highscore.txt");
	if(!hs)
	{
		cout<<"Unable to open file\n";
		exit(1);
	}
		for(int i=0;i<3;i++)
		hs>>tscore[i].name>>tscore[i].score;
	hs.close();
	if(x>=tscore[2].score)
	{
		if(x>=tscore[1].score)
		{
			if(x>=tscore[0].score)
			{
				temp.name = tscore[1].name;
				temp.score = tscore[1].score;
				tscore[2].name = temp.name;
				tscore[2].score = temp.score;
				temp.name = tscore[0].name;
				temp.score = tscore[0].score;
				tscore[1].name = temp.name;
				tscore[1].score = temp.score;
				do{
					cout<<"Enter your name[3 character long]: ";
					cin >> tscore[0].name;
					if(tscore[0].name.size() > 3)
						cout<<"Incorrect Input, RE-ENTER!!\n";
				}while (tscore[0].name.size() > 3);
				tscore[0].score = x;
			}
			else
			{
				temp.name = tscore[1].name;
				temp.score = tscore[1].score;
				tscore[2].name = temp.name;
				tscore[2].score = temp.score;
				do{
					cout<<"Enter your name[3 character long]: ";
					cin >> tscore[1].name;
					if(tscore[0].name.size() > 3)
					cout<<"Incorrect Input, RE-ENTER!!\n";
				}while (tscore[1].name.size() > 3);
				tscore[1].score = x;
				
			}
		}
		else
		{
			do{
				cout<<"Enter your name[3 character long]: ";
				cin >> tscore[2].name;
				if(tscore[0].name.size() > 3)
				cout<<"Incorrect Input, RE-ENTER!!\n";		
			}while (tscore[0].name.size() > 3);
			tscore[2].score = x;
				
		}
	}
	sco.open("Database/highscore.txt");
	if (!sco)
	{
		cout<<"Unable to open file\n";
		exit(1);
	}
	for(int k=0;k<3;k++ )
		sco<<tscore[k].name<<'\t'<<tscore[k].score<<'\n';
	
}

