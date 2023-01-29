
#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
int x = 1;
#define random(a,b) a+rand()%(b-a+1)

string GetLine(int x, string url) {
	string str;
	ifstream file(url);
	int index = 1;
	while (getline(file, str)) {
		if (index == x) {
			break;
		}
		index++;
	}
	file.close();
	return str;
}


class Npc
{
	string gender;
	string hair;
	string lips_and_eyelashes;
	string torso;
	string closes;
	string shoes;
	string color_skin;
	string color_closes;
	string color_shoes;
	int count = x;
public:
	Npc() {
		this->gender = getGender();
		this->hair = getHair();
		this->lips_and_eyelashes = getLips();
		this->torso = gender;
		this->closes = getCloses();
		this->shoes = getShoes();
		this->color_skin = getColorSkin();
		this->color_closes = getColorAnother();
		this->color_shoes = getColorAnother();
		x++;
	};


	//void SaveNPC() {

	//	//string path= ("Npc\\")+ ("NPC") + x + (".txt");


	//}

	void showNPC() {


		cout << "\nNpc "<< count << "\n���: " << gender << "\n������: " << hair << "\n����������� ���� � �������: "
			<< lips_and_eyelashes << "\n����: " << torso << "\n������: " << closes << "\n�����: " << shoes << "\n���� ����: " << color_skin
			<< "\n���� ������: " << color_closes << "\n���� �����: " << color_shoes << endl;

	}

	string getGender() {
		string line = GetLine(random(2, 3), "files\\gender.csv");
		return line;
		
	};
	string getHair() {
		// ������� = ������� � ������� ��������, ������� = ������� � ������� ��������
		string line;
		int x;
		if (gender == "�������") {
			x = random(2, 6);
			line = GetLine(x, "files\\hair.csv");
		}
		else {
			x = random(5, 8);
			line = GetLine(x, "files\\hair.csv");
		}
		return line;
	};
	string getLips() {
		//���� ��� �������, �� ����������� ���� � ������� ����, � ���� �������, �� ���
		string line;
		if (gender == "�������") {
			line = GetLine(2, "files\\lips.csv");
		}
		else {
			line = GetLine(3, "files\\lips.csv");
		}
		return line;
	};
	string getTorso() {
		return gender;
	};
	string getCloses() {
		//���� ������� ���, �� ������ � ��� � ������ �� �����
		int x = random(2, 8);
		if (gender == "�������") {
			while (x == 2 || x == 4) {

				x = random(2, 8);
			}

		}
		string line = GetLine(x, "files\\clothes.csv");

		return line;

	};
	string getShoes() {
		// ���� ������ = ������ � ���, �� ��������� �� �����
		string line;
		if (closes == "������ � ���") {
			line = GetLine(random(3, 4), "files\\shoes.csv");
		}
		else {
			line = GetLine(random(2, 4), "files\\shoes.csv");
		}
		return line;
	};
	string getColorSkin() {

		string line = GetLine(random(2, 4), "files\\color_skin.csv");
		return line;
	};
	string getColorAnother() {
		string line = GetLine(random(2, 8), "files\\color_another.csv");
		return line;
	};

};


//class SaveNPC {
//public:
//	SaveNPC(Npc npc1) {
//
//
//
//	}
//};



int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <Npc> array;
	for (int i = 0; i < 30; i++) {
		array.push_back(Npc());
	}
	for (int i = 0; i < 30; i++) {
		array[i].showNPC();
	}
}

