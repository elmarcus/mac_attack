#include <iostream>
#include <string>
#include "SHA1.h"
#include <cstring>
#include <stdint.h>
#include <fstream>
#include <sstream>

#pragma once

using namespace std;

void print_file(unsigned char msg[], string mac, int cppisdumb);

static unsigned char Data[] = { 
	0x4e, 0x6f, 0x20, 0x6f, 0x6e, 0x65, 0x20, 0x68, 0x61, 0x73, 0x20, 0x63, 0x6f, 0x6d, 0x70, 0x6c,
	0x65, 0x74, 0x65, 0x64, 0x20, 0x6c, 0x61, 0x62, 0x20, 0x32, 0x20, 0x73, 0x6f, 0x20, 0x67, 0x69,
	0x76, 0x65, 0x20, 0x74, 0x68, 0x65, 0x6d, 0x20, 0x61, 0x6c, 0x6c, 0x20, 0x61, 0x20, 0x30
};

	/*uint32_t digest[5];
	digest[0] = 0x67452301;
	digest[1] = 0xefcdab89;
	digest[2] = 0x98badcfe;
	digest[3] = 0x10325476;
	digest[4] = 0xc3d2e1f0;*/


static uint32_t mac1[] = {0xf4b645e8, 0x9faaec2f, 0xf8e443c5, 0x95009c16, 0xdbdfba4b}; 

int main(int argc, char* argv)
{
	const int MY_MESSAGE_SIZE = 24;
	const int KEY_SIZE = 16;
	const int BLOCK_SIZE = 64;

	SHA1 sha;
	string my_message = "Give Marcus Blatter An A";
	string mac2;
	int place = 0;
	//unsigned char final_message[BLOCK_SIZE * 2 + MY_MESSAGE_SIZE] = {};
	stringstream agg_message;

	for(; place < KEY_SIZE; place++)
	{
		agg_message << (char)0xff;
	}

	for(int i = place; i < sizeof(Data)+place; i++)
	{
		final_message[i] = Data[i];
	}

	place += sizeof(Data);

	final_message[place] = 0x80;

	place = BLOCK_SIZE*2;

	final_message[place-2] = 0x01;
	final_message[place-1] = 0xf8;

	for(int i = 0; i < my_message.size(); i++)
	{
		final_message[place] = (char)my_message[i];
		place++;
	}

	sha.setDigest(mac1);
	sha.update(my_message);
	mac2 = sha.final();

	ofstream myfile;

	//print to file
	myfile.open("C:\\Users\\Marcus\\Desktop\\temp.txt");

	myfile << mac2 << '\n' << endl;

	for(int i = 0; i < BLOCK_SIZE*2+MY_MESSAGE_SIZE; i++)
	{
		cout << hex << (int)final_message[i] << endl;
		if(final_message[i] == 0)
			myfile << "00";
		else
			myfile << hex << (unsigned int)final_message[i];
	}

	myfile.close();

	system("notepad C:\\Users\\Marcus\\Desktop\\temp.txt");
	return 0;
}

void print_file(unsigned char msg[], string mac, int cppisdumb)
{
	ofstream myfile;

	//print to file
	myfile.open("C:\\Users\\Marcus\\Desktop\\temp.txt");

	myfile << mac << '\n' << endl;

	for(int i = 0; i < cppisdumb; i++)
	{
		cout << "msg length " << cppisdumb << endl;
		if((int)msg[i] == 0)
			myfile << "00";
		else
			myfile << hex << msg[i];
	}

	myfile.close();
}