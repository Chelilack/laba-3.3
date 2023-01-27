#pragma once
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
struct resultInt
{
	int* items;
	int count;
};
struct resultFloat
{
	float* items;
	int count;
};
struct resultComplexNumber
{
	ComplexNumber* items;
	int count;
};
struct resultCharPtr
{
	char** items;
	int count;
};
struct resultStudent
{
	Student* items;
	int count;
};
struct resultTeacher
{
	Teacher* items;
	int count;
};
resultInt InputIntArray() 
{
	int typeInput;
	int* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new int[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			cin >> items[i];
		}
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	else if (typeInput == 2)
	{
		int min, max;
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		if (count < 100) {
			cout << '[';
			for (int i = 0; i < count; i++)
			{
				items[i] = rand() % (max - min) + min;
				cout << ' ' << items[i];
			}
			cout << " ]";
		}
		else 
		{
			for (int i = 0; i < count; i++)
			{
				items[i] = rand() % (max - min) + min;
			}
		}
	}
	resultInt answer = { items, count };
	return answer;
}
resultInt InputIntArray(int count, int min, int max)
{
	int* items;

	items = new int[count];
	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % (max - min) + min;
	}
	resultInt answer = { items, count };
	return answer;
}
resultFloat InputFloatArray()
{
	int typeInput;
	float* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new float[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			cin >> items[i];
		}
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	else if (typeInput == 2)
	{
		float min, max;
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		if (count < 100) 
		{
			cout << '[';
			for (int i = 0; i < count; i++)
			{
				items[i] = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
				cout << ' ' << items[i];
			}
			cout << " ]";
		}
		else 
		{
			for (int i = 0; i < count; i++)
			{
				items[i] = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
			}
		}
	}
	
	resultFloat answer = { items, count };
	return answer;
}
resultFloat InputFloatArray(int count,float min, float max )
{
	float* items;
	items = new float[count];
	for (int i = 0; i < count; i++)
	{
		items[i] = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
	}
	resultFloat answer = { items, count };
	return answer;
}
resultComplexNumber InputComplexNumberArray() 
{
	int typeInput;
	ComplexNumber* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new ComplexNumber[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			items[i].Input();
		}
		for (int i = 0; i < count; i++)
		{
			cout << items[i];
		}
	}
	else if (typeInput == 2)
	{
		float minReal, maxReal, minIm, maxIm;
		cout << "min Real:" << endl;
		cin >> minReal;
		cout << "max Real:" << endl;
		cin >> maxReal;
		cout << "min Imaginary:" << endl;
		cin >> minIm;
		cout << "max Imaginary:" << endl;
		cin >> maxIm;
		if (count < 20)
		{
			for (int i = 0; i < count; i++)
			{
				items[i].RandomInput(minReal, maxReal, minIm, maxIm);
				cout << items[i] << endl;
			}
		}
		else 
		{
			for (int i = 0; i < count; i++)
			{
				items[i].RandomInput(minReal, maxReal, minIm, maxIm);
			}
		}
	}
	resultComplexNumber answer = { items, count };
	return answer;

};
resultComplexNumber InputComplexNumberArray(int count, float minReal, float maxReal, float  minIm, float maxIm)
{
	ComplexNumber* items;
	items = new ComplexNumber[count];
	for (int i = 0; i < count; i++)
	{
		items[i].RandomInput(minReal, maxReal, minIm, maxIm);
	}
	resultComplexNumber answer = { items, count };
	return answer;
}

resultCharPtr InputCharPtrArray()
{
	int typeInput;
	char** items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new char* [count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			char* str = new char[64];
			cin >> str;
			items[i] = str;
		}

		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}

	}
	else if (typeInput == 2)
	{
		ifstream WordFile;
		int strNow;
		int strNumber;
		if (count < 40) 
		{
			for (int i = 0; i < count; i++)
			{
				strNow = 0;
				char* str = new char[64];
				WordFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/1-1000.txt");
				strNumber = rand() % 1000 + 1;
				while (strNow != strNumber)
				{
					WordFile.getline(str, 64, '\n');
					strNow++;
				}
				WordFile.close();
				items[i] = str;
				cout << ' ' << items[i];
			}
		}
		else 
		{
			for (int i = 0; i < count; i++)
			{
				strNow = 0;
				char* str = new char[64];
				WordFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/1-1000.txt");
				strNumber = rand() % 1000 + 1;
				while (strNow != strNumber)
				{
					WordFile.getline(str, 64, '\n');
					strNow++;
				}
				WordFile.close();
				items[i] = str;
			}
		}

	}
	
	resultCharPtr answer = { items, count };
	return answer;
};
resultCharPtr InputCharPtrArray(int count)
{
	char** items;
	items = new char* [count];
	ifstream WordFile;
	int strNow;
	int strNumber;

	for (int i = 0; i < count; i++)
	{
		strNow = 0;
		char* str = new char[64];
		WordFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/1-1000.txt");
		strNumber = rand() % 1000 + 1;
		while (strNow != strNumber)
		{
			WordFile.getline(str, 64, '\n');
			strNow++;
		}
		WordFile.close();
		items[i] = str;
	}
	resultCharPtr answer = { items, count };
	return answer;
}


resultStudent InputStudentArray() {
	int typeInput;
	Student* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new Student[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			items[i].Input();
		}
		for (int i = 0; i < count; i++)
		{
			cout << items[i];
		}
	}
	else if (typeInput == 2)
	{
		if (count < 15) 
		{
			for (int i = 0; i < count; i++)
			{
				items[i].RandomInput();
				cout << items[i];
				cout << "---------------" << endl;
			}
		}
		else 
		{
			for (int i = 0; i < count; i++)
			{
				items[i].RandomInput();
			}
		}
	}
	resultStudent answer = { items, count };
	return answer;
};
resultStudent InputStudentArray(int count) 
{
	Student* items;
	items = new Student[count];
	for (int i = 0; i < count; i++)
	{
		items[i].RandomInput();
		cout << items[i];
	}
	resultStudent answer = { items, count };
	return answer;
}
resultTeacher InputTeacherArray() {
	int typeInput;
	Teacher* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new Teacher[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			items[i].Input();
		}
		for (int i = 0; i < count; i++)
		{
			cout << items[i];
		}
	}
	else if (typeInput == 2)
	{
		if (count < 10) 
		{
			for (int i = 0; i < count; i++)
			{
				items[i].RandomInput();
				cout << items[i];
				cout << "---------------" << endl;
			}
		}
		else 
		{
			for (int i = 0; i < count; i++)
			{
				items[i].RandomInput();
			}
		}
		
	}
	resultTeacher answer = { items, count };
	return answer;
};
resultTeacher InputTeacherArray(int count) 
{
	Teacher* items;
	items = new Teacher[count];
	for (int i = 0; i < count; i++)
	{
		items[i].RandomInput();
	}
	resultTeacher answer = { items, count };
	return answer;
}
