#include <iostream>
using namespace std;


void clear() {
	system("cls");
}


void inputInt(int& value) {

	cout << "Введите значение INT: ";
	cin >> value;
}


void printInt(int value) {

	int bitArray[32]{};

	for (int i = 0; i < 32; i++) {
		bitArray[i] = (value >> (31 - i)) & 1;
	}

	cout << "INT: " << value << "\n";

	cout << "BIN: ";

	for (int bit : bitArray) {
		cout << bit;
	}

	cout << "\n";
}



void inputDouble(double& value) {

	cout << "Введите значение DOUBLE: ";
	cin >> value;
}


void printDouble(double value) {

	union {
		double doubleValue;
		unsigned int parts[2];
	} doubleUnion;

	doubleUnion.doubleValue = value;

	int bitArray[64]{};

	for (int i = 0; i < 32; i++) {
		bitArray[i] = (doubleUnion.parts[1] >> (31 - i)) & 1;
	}

	for (int i = 0; i < 32; i++) {
		bitArray[i + 32] = (doubleUnion.parts[0] >> (31 - i)) & 1;
	}

	cout << "DOUBLE: " << value << "\n";

	cout << "BIN: ";

	for (int i = 0; i < 64; i++) {

		cout << bitArray[i];

		
		if (i == 0) {
			cout << " ";
		}

		
		if (i == 11) {
			cout << " ";
		}
	}

	cout << "\n";
}


void printDoubleParts(double value, int bitArray[64]) {

	union {
		double doubleValue;
		unsigned int parts[2];
	} doubleUnion;

	doubleUnion.doubleValue = value;

	

	for (int i = 0; i < 32; i++) {
		bitArray[i] = (doubleUnion.parts[1] >> (31 - i)) & 1;
	}

	for (int i = 0; i < 32; i++) {
		bitArray[i + 32] = (doubleUnion.parts[0] >> (31 - i)) & 1;
	}

	cout << "\nСтруктура DOUBLE:\n";

	cout << "Знак: ";

	for (int i = 0; i < 1; i++) {
		cout << bitArray[i];
	}

	cout << "\nПорядок: ";

	for (int i = 1; i < 12; i++) {
		cout << bitArray[i];
	}

	cout << "\nМантисса: ";

	for (int i = 12; i < 64; i++) {
		cout << bitArray[i];
	}

	cout << "\n";
}

int binToInt(int bitArray[32]) {
	unsigned int bits = 0;

	for (int i = 0; i < 32; i++) {
		bits = bits * 2 + bitArray[i];
	}

	int value = static_cast<int>(bits);

	return value;
}

double binToDouble(int bitArray[64]) {
	union {
		double doubleValue;
		unsigned int parts[2];
	} doubleUnion;

	doubleUnion.parts[0] = 0;
	doubleUnion.parts[1] = 0;

	for (int i = 0; i < 32; i++) {
		doubleUnion.parts[1] = (doubleUnion.parts[1] << 1) | bitArray[i];
	}

	for (int i = 32; i < 64; i++) {
		doubleUnion.parts[0] = (doubleUnion.parts[0] << 1) | bitArray[i];
	}
	
	return doubleUnion.doubleValue;
}

/*=========================================================================*/

void setIntBits(int bitArray[32]) {
	int count;
	int bitIndex;
	int bitValue;

	cout << "\nСколько разрядов установить: ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "Номер разряда: ";
		cin >> bitIndex;
		cout << "Значение разряда (0 или 1): ";
		cin >> bitValue;
		bitArray[31 - bitIndex] = bitValue;
	}
}

void setDoubleBits(int bitArray[64]) {
	int count;
	int bitIndex;
	int bitValue;

	cout << "\nСколько разрядов установить: ";
	cin >> count;

	for (int i = 0; i < count; i++) {

		cout << "Номер разряда: ";
		cin >> bitIndex;

		cout << "Значение разряда (0 или 1): ";
		cin >> bitValue;

		bitArray[63 - bitIndex] = bitValue;
	}
}

void taskInt() {
	clear();

	int value;
	int bitArray[32]{};

	cout << "Работа с типом INT\n";
	cout << "---------------------\n\n";

	inputInt(value);

	cout << "\nВнутреннее представление:\n";
	printInt(value);


	for (int i = 0; i < 32; i++) {
		bitArray[i] = (value >> (31 - i)) & 1;
	}

	
	int result = binToInt(bitArray);

	cout << "\nОбратно из BIN: " << result << "\n";

	cout << "\nНажмите Enter чтобы продолжить";
	cin.ignore();
	cin.get();
}

void taskTenInt() {
	clear();

	int value;
	int bitArray[32]{};

	cout << "Работа с типом INT\n";
	cout << "---------------------\n\n";

	inputInt(value);

	cout << "\nВнутреннее представление:\n";
	printInt(value);

	for (int i = 0; i < 32; i++) {
		bitArray[i] = (value >> (31 - i)) & 1;
	}

	setIntBits(bitArray);

	cout << "\nИзменённое представление:\n";
	for (int i = 0; i < 32; i++) {
		cout << bitArray[i];
	}
	cout << "\n";

	int result = binToInt(bitArray);

	cout << "\nОбратно из BIN: " << result << "\n";

	cout << "\nНажмите Enter чтобы продолжить";
	cin.ignore();
	cin.get();
}



void taskDouble() {
	clear();

	double value;
	int bitArray[64]{};

	cout << "Работа с типом DOUBLE\n";
	cout << "---------------------\n\n";

	inputDouble(value);

	cout << "\nВнутреннее представление:\n";

	printDouble(value);

	printDoubleParts(value, bitArray);

	cout << "\n";

	double result = binToDouble(bitArray);

	cout << "Обратно из BIN: " << result << "\n";

	cout << "\nРазмер DOUBLE: " << sizeof(double) << " байт\n";

	cout << "\nНажмите Enter чтобы продолжить";
	cin.ignore();
	cin.get();
}

void taskTenDouble() {
	clear();

	double value;
	int bitArray[64]{};

	cout << "Работа с типом DOUBLE\n";
	cout << "---------------------\n\n";

	inputDouble(value);

	cout << "\nВнутреннее представление:\n";
	printDouble(value);

	printDoubleParts(value, bitArray);

	setDoubleBits(bitArray);

	cout << "\nИзменённое представление:\n";

	for (int i = 0; i < 64; i++) {
		cout << bitArray[i];

		if (i == 0) cout << " ";
		if (i == 11) cout << " ";
	}

	cout << "\n";

	double result = binToDouble(bitArray);

	cout << "\nОбратно из BIN: " << result << "\n";

	cout << "\nНажмите Enter чтобы продолжить";
	cin.ignore();
	cin.get();
}

int main() {

	setlocale(LC_ALL, "Russian");

	int mode;
	int modeTen;

	while (true) {

		clear();

		cout << "Лабораторная работа №1\n";
		cout << "Вариант 10\n";
		cout << "Исследование внутреннего представления различных форматов данных\n\n";

		cout << "Выберите режим работы:\n";
		cout << "1. INT\n";
		cout << "2. DOUBLE\n";

		cout << "3. Задание 10\n";
		

		cout << "0. Выход\n";

		cout << "Выбор: ";
		cin >> mode;


		if (mode == 0) {
			break;
		}


		if (mode == 1) {
			taskInt();
		}


		else if (mode == 2) {
			taskDouble();
		}

		else if (mode == 3) {
			clear();
			cout << "Задание 10\n";
			cout << "Установить в заданные пользователем значения некоторые разряды, количество которых и номера разрядов задаются с клавиатуры.\n\n";

			cout << "Выберите режим работы:\n";
			cout << "1. INT\n";
			cout << "2. DOUBLE\n";



			cout << "0. Выход\n";

			cout << "Выбор: ";
			cin >> modeTen;

			if (modeTen == 0) {
				break;
			}


			if (modeTen == 1) {
				taskTenInt();
			}


			else if (modeTen == 2) {
				taskTenDouble();
			}
		}
	}

	return 0;
}
