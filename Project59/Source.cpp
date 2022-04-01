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
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	char res[250];
	convert(y, z, res);
	cout << res << endl;
	char* str1 = new char[250];
	char* str2 = new char[250];
	strcpy(str1, "Этому миру не хватает героя, но это не ты!");
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
	memset(resault_l, 0, sizeof(char) * 250);
	char str1[250] = {};
	char str[250] = {};

	for (short i = 0; i < strlen(str_l); i++) {
		str[i] = str_l[i];
	}
	char str2[5] = {};
	int iii = 0;
	int was_iii = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < strlen(str_l); i++) {
		strncpy(str, i + str_l, 50);
		iii = strcspn(str, " ");
		i = i + iii +1;
		if (was_iii==0){
			start = 0;
			end = i;
		}
		else {
			start = was_iii;
			end = i;
		}
		was_iii = i;
		int size_word = 0;
		size_word = end - start;
		sprintf(str2, "%d ", size_word-1);
		strncpy(strlen(str1) + str1, start+str_l, size_word);
		strcat(str1, str2);
	}
	cout << str1 << endl;
	for (int i = 0; i < strlen(str1); i++) {
		resault_l[i] = str1[i];
	}
}