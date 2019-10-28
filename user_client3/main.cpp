#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include"RSA_1.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "AES.h"

#define KEY_LENGTH 2048  //��Կ�ĳ���
#define BASE 16    //������������ֽ���
using namespace std;

int main()
{

	//��rsa��Կ

	ifstream RsaFile("RSA_Key.csv", ios::in);
	string key_n,key_e;
	getline(RsaFile, key_n);
	getline(RsaFile,key_e);
	cout<<"��ȡ��Կ��d = "<<key_n<<endl;
	cout<<"��ȡ��Կ��e = "<<key_e<<endl;
	char *n ;
	const int len = key_n.length();
	n =new char[len+1];
	strcpy(n,key_n.c_str());
	int e=atoi(key_e.c_str());
	//��aes��key���м���,key�ĳ��Ȳ��ܴ���KEY_LENGTH
	//char buf[] = "13579";
	const char g_key[17] = "13579";	
	cout<<"13579..."<<endl;
	char * cipher_text = rsa_encrypt(g_key, n, e);
	cout<<"����Ϊ��"<<cipher_text<<endl;
	delete n;
	n = NULL;
	delete n;
	//�ϲ�������Ϣ����encrypy.csv
	ofstream outFile;
    outFile.open("encrypt.csv", ios::app); // ��ģʽ׷��д��
    outFile << cipher_text << endl;
	outFile.close();
	cout<<"����encrypt.vsv�ļ���ɣ�"<<endl;

    //��csv�ļ�
	cout << "��ȡ�û����ݣ�" << endl;
    ifstream inFile("data.csv", ios::in);
    string lineStr;
	getline(inFile, lineStr);
    //��ӡ�����ַ���
    cout << lineStr << endl;
    //��ɶ�ά��ṹ
    stringstream ss(lineStr);
    string str;
    //���ն��ŷָ���ȡ��Ϣ��AES����
	cout << "���ݼ��ܣ�" << endl;
    while (getline(ss, str, ','))
    {
		cout<<"------"<<str<<"------"<<endl;
		
		//AES����
    	const char g_key[17] = "13579";		
		cout << "plaintext:" << str << endl;
		string str2 = AES::EncryptionAES(str, g_key);
		cout << "encryted:" << str2 << endl;
		//д���ļ�
		ofstream outFile;
    	outFile.open("encrypt.csv", ios::app); // ��ģʽ׷��д��
    	outFile << str2 << endl;
		outFile.close();

    }
	cout << "�Ѵ����ļ�encrypt.csv" << endl;
	cout << "�ͻ����������" << endl;


    return 0;
}
