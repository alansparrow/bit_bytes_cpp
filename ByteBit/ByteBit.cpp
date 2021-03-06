// ByteBit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<limits>
#include<bitset>
#include<string>

using namespace std;

void f1() {
	for (int i; cin >> i; ) {
		cout << dec << i << "=="
			<< hex << "0x" << i << "=="
			<< bitset<8 * sizeof(int)>{unsigned(i)} << endl;
	}
}

void f2() {
	bitset<128> dword_bits{ string{"10101010101010"} };
	cout << dword_bits << endl;
}

// reverse order
void f3() {
	constexpr int max = 10;
	for (bitset<max> b; cin >> b;) {
		cout << b << endl;
		for (int i = 0; i < max; i++)
			cout << b[i];
		cout << endl;
	}
}

// overflow
void f4() {
	static_assert(sizeof(long long) > sizeof(int), "");

	int si = 0;
	unsigned ui = 0;
	long long sum = 0;

	while (++si) sum++;
	cout << "signed int loop: " << sum << endl;

	sum = 0;
	while (++ui) sum++;
	cout << "unsigned int loop: " << sum << endl;
}

void tmp() {
	bitset<32> a{129};
	bitset<8> b{ 129 };

	cout << a << endl;
	cout << b << endl;
}

void f5() {
	cout << "sizeof(unsigned short): " << sizeof(unsigned short) << endl;

	unsigned short val = 423;
	cout << bitset<8 * sizeof(unsigned short)>{val} << endl;

	unsigned char right = val & 0xff;
	unsigned char right1 = val;

	cout << bitset<8 * sizeof(unsigned char)>{right} << endl;
	cout << bitset<8 * sizeof(unsigned char)>{right1} << endl;

	unsigned char left = val >> 8;
	cout << bitset<8 * sizeof(unsigned char)>{left} << endl;
}

// flags
enum Printer_flags {
	acknowledge = 1,
	paper_empty = 1 << 1,
	busy		= 1 << 2,
	out_of_black= 1 << 3,
	out_of_color= 1 << 4
};

void f6() {
	Printer_flags flg = Printer_flags(out_of_color | out_of_black);
	cout << flg << endl;;
}

// bitfields
struct PPN {
	//unsigned int PFN : 22; // 8 * 3 = 24 (3 bytes)
	//int : 3; // 4 bytes
	//unsigned int CCA : 3; // 4 bytes
	
	//bool nonreachable : 1;
	//bool dirty : 1;
	//bool valid : 1;
	//bool global : 1;
	
	//int c : 1;
	//int a : 6;
	//unsigned int filler : 23;
	//bool dirty : 1;

	int test_a : 1;
	bool test_b : 1;
	int test_c : 1;
	bool test_d : 1;
	int test_e : 1;
	bool test_f : 1;
	int test_g : 1;
	bool test_h : 1;
};

struct S {
	// three-bit unsigned field,
	// allowed values are 0...7
	unsigned int b : 3;
};

struct S1 {
	// will usually occupy 2 bytes:
	// 3 bits: value of b1
	// 2 bits: unused
	// 6 bits: value of b2
	// 2 bits: value of b3
	// 3 bits: unused
	unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
};

void f7() {
	cout << "sizeof(unsigned int): " << sizeof(unsigned int) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(bool): " << sizeof(bool) << endl;
	cout << "sizeof(PPN): " << sizeof(PPN) << endl;

	S s = { 7 };
	++s.b; // unsigned overflow (guaranteed wrap-around)
	std::cout << s.b << '\n'; // output: 0
}

int main()
{
	static_assert(4 <= sizeof(int), "");
	static_assert(numeric_limits<char>::is_signed, "");
	
	f7();
	//f6();
	//f5();

	//tmp();
	//f4();
	//f3();
	//f2();
	//f1();

    return 0;
}

