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

#define KEY_LENGTH 2048  //公钥的长度
#define BASE 16    //输入输出的数字进制
using namespace std;

int main()
{

	//读rsa公钥

	ifstream RsaFile("RSA_Key.csv", ios::in);
	string key_n,key_e;
	getline(RsaFile, key_n);
	getline(RsaFile,key_e);
	cout<<"读取密钥，d = "<<key_n<<endl;
	cout<<"读取密钥，e = "<<key_e<<endl;
	char *n ;
	const int len = key_n.length();
	n =new char[len+1];
	strcpy(n,key_n.c_str());
	int e=atoi(key_e.c_str());
	//对aes的key进行加密,key的长度不能大于KEY_LENGTH
	//char buf[] = "13579";
	const char g_key[17] = "13579";	
	cout<<"13579..."<<endl;
	char * cipher_text = rsa_encrypt(g_key, n, e);
	cout<<"密文为："<<cipher_text<<endl;
	delete n;
	n = NULL;
	delete n;
	//合并加密信息存入encrypy.csv
	ofstream outFile;
    outFile.open("encrypt.csv", ios::app); // 打开模式追加写入
    outFile << cipher_text << endl;
	outFile.close();
	cout<<"存入encrypt.vsv文件完成！"<<endl;

    //读csv文件
	cout << "读取用户数据：" << endl;
    ifstream inFile("data.csv", ios::in);
    string lineStr;
	getline(inFile, lineStr);
    //打印整行字符串
    cout << lineStr << endl;
    //存成二维表结构
    stringstream ss(lineStr);
    string str;
    //按照逗号分隔读取信息，AES加密
	cout << "数据加密：" << endl;
    while (getline(ss, str, ','))
    {
		cout<<"------"<<str<<"------"<<endl;
		
		//AES加密
    	const char g_key[17] = "13579";		
		cout << "plaintext:" << str << endl;
		string str2 = AES::EncryptionAES(str, g_key);
		cout << "encryted:" << str2 << endl;
		//写入文件
		ofstream outFile;
    	outFile.open("encrypt.csv", ios::app); // 打开模式追加写入
    	outFile << str2 << endl;
		outFile.close();

    }
	cout << "已存入文件encrypt.csv" << endl;
	cout << "客户端任务完成" << endl;


    return 0;
}
