/**
*Name: Amirul Azim bin Amran
*Matric no: 2017425
*Lecturer: Dr Norlia Yusof
*/ 
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct info{
	string name;
	string description;
	double rate;
	double hours;
	double payment;
};

void read_data(info arr[], int size)
{
	ifstream customerFile;
	customerFile.open("customer_data.txt");
	if (customerFile.fail()) {
        cout << "File open failed!";
	}
	
	for (int i = 0; i < size; ++i) {
        customerFile >> arr[i].name >> arr[i].description >> arr[i].rate >> arr[i].hours;
    }
    customerFile.close();
    cout << "The customers data have been read succesfully." << endl << endl;
    
    ofstream outcustomerFile;
    outcustomerFile.open("customer_data.txt");

    if (outcustomerFile.fail()) {
        cout << "File open failed!" << endl;
    }

    for (int i = 0; i < size; ++i) {
        outcustomerFile << arr[i].name << " " << arr[i].description << " " << arr[i].rate << " " << arr[i].hours << endl;
    }
}
void calcPay(info arr[], int size)
{
	
	for (int i = 0; i < size; ++i) {
        arr[i].payment=(arr[i].rate*arr[i].hours);
    }
}
void print_data(info arr[], int size)
{
	cout << "Name\t\t" << "Description\t" << "Rate/Hour\t" << "Hours\t" << "Payment" << endl;
	cout << "-------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i].name << "\t\t" << arr[i].description << "\t" << arr[i].rate << "\t\t" << arr[i].hours << "\t" << arr[i].payment << endl;
    }
}

int main()
{
	info arr[10];
	int size=10;
	info *ptr1 = &arr[0], *ptr2 = &arr[1], *ptr3 = &arr[2], *ptr4 = &arr[3], *ptr5 = &arr[4];
	info *ptr6 = &arr[5], *ptr7 = &arr[6], *ptr8 = &arr[7], *ptr9 = &arr[8], *ptr10 = &arr[9];
	cout << "The customers' data being read........" << endl << endl;
	read_data(arr, size);
	calcPay(arr, size);
	cout << "Below is the customer's details report including the payment...'" << endl << endl;
	print_data(arr, size);
    
	
	return 0;
}
