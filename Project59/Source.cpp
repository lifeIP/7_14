#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void findANDreplace(char* str, char* resault);
void convert(float y, float z, char* str);

int main()
{
	setlocale(LC_ALL, "RUS");
	float y, z;
	cout << "Ââåäèòå y: ";
	cin >> y;
	cout << "Ââåäèòå z: ";
	cin >> z;
	char res[100];
	convert(y, z, res);
	cout << res << endl;
	char* str1 = new char[100];
	char* str2 = new char[110];
	strcpy(str1, "OLEG BALDA");
	findANDreplace(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	delete[]str1;
	delete[]str2;
}
void convert(float y, float z, char* str)
{
	double x = y + 3 * exp(z);
	sprintf(str, "%05.5f = %05.5f + 3*exp(%05.5f)", x, y, z);
}

void findANDreplace(char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 100);

	char exchange[] = " A-A-A ";
	int counter = 0;

	char str[250] = {};
	for (short i = 0; i < strlen(str_l); i++) {
		str[i] = str_l[i];
	}

	int i = 0;

	int address = strcspn(str, "@");
	char str1[250] = {};
	char str2[250] = {};

	for (int i = 0; i < address; i++) {
		str1[i] = str[i];
	}

	for (int i = address + 1, ia = 0; i < strlen(str); i++, ia++) {
		str2[ia] = str[i];
	}

	memset(str, 0, sizeof(char) * 250);

	int iii = 0;
	char str_t[100] = {};
	char str_t2[100] = {};
	int pass = 0;
	int sz = 0;

	for (; i < strlen(str1); ) {
		strncpy(str, i + str1, 50);
		iii = strcspn(str, "A");
		strncpy(str_t, i + str, iii);
		i = i + iii + 1;
		strncpy(sz + str_t2, str, iii);
		if (str1[i - 1] == 'A') {
			strcat(str_t2, exchange);
			counter++;
		}
		sz = strlen(str_t2);
	}
	for (int i = 0; i < strlen(str_t2); i++) {
		resault_l[i] = str_t2[i];
	}
}