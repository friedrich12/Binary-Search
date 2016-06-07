#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<locale>

void promptsort(int array[]);
int binarysearch(int array[], int size, int value, int high, int low);
using namespace std;

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main() {
	int i = 0;
	int array[10];

	while (i < 10) {
		int num;
		cout << "Enter some numbers" << endl;
		cin >> num;
		array[i] = num;
		i++;
	}
	promptsort(array);
	int v;
	cout << "Search for one of thoses values\n";
	cin >> v;
	int get = binarysearch(array, 10, v,10,0);
	cout << "This is what you searched for " << get << endl;
	system("PAUSE");
}

int binarysearch(int array[], int size, int value, int high, int low) {
	int mid = (low + high) / 2;

	if (value == array[mid]) {
		return array[mid];
	}
	else if (value > array[mid]) {
		low = mid + 1;
		binarysearch(array, size, value,high,low);
	}
	else if (value < array[mid]) {
		high = mid - 1;
		binarysearch(array, size, value,high,low);
	}
}

void promptsort(int array[]) {
	string ans;
	cout << "Are those number sorted y or n?\n";
	cin >> ans;
	if (ans == "n") {
		cout << "Alright I am sorting them\n";
		qsort(array,10,sizeof(int),compare);
	}
	else
	{
		cout << "Okay then I wont sort it.\n";
	}
}