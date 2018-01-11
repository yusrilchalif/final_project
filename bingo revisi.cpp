#include<iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>

/*  Game ini bernama bingo
	pada game ini pemain akan 
	berusaha menebak posisi angka 
	dimana jika pemain dapat menebak 
	posisi angka sebanyak satu kolom atau baris
	maka pemain akan dinyatakan menang
	pemain akan diberikan kesempatan sebanyak 15x 
	percobaan untuk menebak posisi angka
	angka yang ditebak adalah angka dari 1 sampai 25.
*/
using namespace std;

string logo[7][42] = {
{" _______  ___   __    _  _______  _______ "}, 
{"|  _    ||   | |  |  | ||       ||       |"},
{"| |_|   ||   | |   |_| ||    ___||   _   |"},
{"|       ||   | |       ||   | __ |  | |  |"},
{"|  _   | |   | |  _    ||   ||  ||  |_|  |"},
{"| |_|   ||   | | | |   ||   |_| ||       |"},
{"|_______||___| |_|  |__||_______||_______|"},                                
};



int angka[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
};
char area[11][17]={
	{"<==t==t==t==t==>"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"a==+==+==+==+==b"},
	{"|  |  |  |  |  |"},
	{"[==-==-==-==-==]"},
	
};
int jumlah = 0;

bool wincheck()
{
	/*int count = 0;
	
	for(int k=0; k<5; k++){
		count = 0;
		
		for(int l=0; l<5; l++){
			if (angka[k][l] != 0)
				++count;
		}
		
		if (count == 5)
			return true;
	}
	
	return false;*/
	
	bool win = false;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(area[i*2+1][j*3+1] == ' ')
				break;
			else if(j == 4)
				win = true;
		}
	}
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(area[j*2+1][i*3+1] == ' ')
				break;
			else if(j == 4)
				win = true;
		}
	}
	
	return win;
}
void RandomNumber() {
	int temp;
	bool status = true;
	
	srand((unsigned)time(0));
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			while(status) {
				temp = rand() % 25 + 1;
				status = false;
			
				for(int k = 0; k < 5; k++) {
					for(int l = 0; l < 5; l++) {
						if(temp == angka[k][l]) {
							status = true;
							break;
						}
					}
				}	
			}
			
			angka[i][j] = temp;
			status = true;
		}
	}
}

void printBingo(){
	for (int i=0; i<7; i++){
		for (int j=0; j<42; j++){
			string t= logo[i][j];
			cout<<t;
		}
			cout<<endl;
	}
			cout<<endl;		
}

void printMap() {
	for (int i=0;i<11;i++){
			for (int j=0;j<16;j++){
				char t = area[i][j];
				if(t == '|') {
					cout<<char(186);
				}
				else if(t == '='){
					cout<<char(205);
				}
				else if(t == '+'){
					cout<<char(206);
				}
				else if(t == 't'){
					cout<<char(203);
				}
				else if(t == 'a'){
					cout<<char(204);
				}
				else if(t == 'b'){
					cout<<char(185);
				}			
				else if(t == '<'){
					cout<<char(201);
				}
				else if(t == '>'){
					cout<<char(187);
				}
				else if(t == '['){
					cout<<char(200);
				}
				else if(t == ']'){
					cout<<char(188);
				}
				else if(t == '-'){
					cout<<char(202);
				}
				else {
					cout<<t;
					//cout<<angka[y][x];
					//if(angka[y][x] < 10)
					//	cout<<' ';
					//x++;
				}
				
			}
			
				
			cout<<endl;
		}
}

int main()
{
	
	string hasil="5341253412534125341253412";
	//stringstream ss;
	//srand((unsigned)time(0));
	
	/*while(hasil.length()<=10){
		int r=rand()%5+1;
		
		ss<<r;
		
		if(hasil.find(ss.str())== -1){
			hasil.append(ss.str());
		}
		ss.str("");
	}
	
	cout<<hasil;*/
	
//=(205),|(186),+(206),t(203),a(204),b(185),<(201),>(187),[(200),](188),-(202)

	RandomNumber();
	

	while(!wincheck()) {
		system ("cls");
		printBingo();
		printMap();
		
		stringstream temp;
		int n;
		cout<<"Masukkan Angka(1-25): ";
		cin>>n;
		
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(angka[i][j] == n) {
					temp<<n;
					string s = temp.str();
					
					area[i*2+1][j*3+1] = s[0];
					area[i*2+1][j*3+2] = s[1];
					
					temp.clear();
				}
			}
		}
		
		++jumlah;
		
		if (jumlah == 15)
		break;
	}
	
	system("cls");
	printMap();
	
	if (wincheck()) {
		cout<<"MENANG!!";	
	} else {
		cout << "KALAH!!";
	}
}

