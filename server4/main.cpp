#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include"RSA_1.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "AES.h"
#include<ctime>
#include "HbApi.h"

#define KEY_LENGTH 2048  //公钥的长度
#define BASE 16    //输入输出的数字进制
using namespace std;

int main()
{
	int flag = 0;
	key_pair * p;
	while(1)
	{
		int choice;
		cout << "-------------------沙盒程序-------------------" << endl;
		cout << "------请先生成密钥，加密数据后再调用API------" << endl;
		cout << "按数字1生成RSA密钥..." << endl;
		cout << "按数字2调用API进行评估..." << endl;
		cout << "按数字0退出程序..." << endl;
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			p = gen_key_pair();
			cout << "生成密钥对：" << endl;
			cout<<"n = "<<p->n<<endl;
			cout<<"d = "<<p->d<<endl;
			cout<<"e = "<<p->e<<endl;
			//公钥写入文件
			cout << "公钥n,e写入文件发送给客户端" << endl;
			ofstream outFile;
			outFile.open("RSA_Key.csv", ios::out | ios::trunc); // 截断文件后写入
			outFile << p->n << endl;
			outFile << p->e << endl;
			outFile.close();
			flag = 1;
		}
		else if (choice == 2)
		{
			if (flag == 0)
			{
				cout << "请先按1生成密钥！" << endl;
			}
			else
			{
				//私钥解出AES的key
				cout << "读取E(aes_k)：" << endl;

				ifstream inFile2("encrypt.csv", ios::in);

				string aes_key;
				getline(inFile2, aes_key);
				cout<< "E(aes_k): "<< aes_key <<endl;

				char *ak;
				const int len_ak = aes_key.length();
				ak =new char[len_ak+1];
				strcpy(ak,aes_key.c_str());

				char * plain_text = rsa_decrypt(ak, p->n, p->d);
				cout<<"aes解码："<<plain_text<<endl;
				//用key解出data
				string par;
				int i = 0;
				vector< string > api;
				while(getline(inFile2, par))
				{
					cout<<"第"<<i+1<<"个加密参数："<< par << endl;
					string decrypted = AES::DecryptionAES(par, plain_text);
					api.push_back(decrypted.c_str());
					cout << "第"<<i+1<<"个参数解密："<< api[i] << endl;
					i = i+1;
				}
				//调用风控API
				HbApi *htapi = new HbApi;
				/*
				const char* custNo = "007";
				tint custType = 0;
				const char* custName = "张三";
				int cardType = 1;
				const char* cardNo = "240988198009309287";
				const char* ruleTime = "2018-05-25 08:58:00";
				const char* reqFlow = "123456";
				const char* groupCode = "GROUP_CODE_11";
				const char* healthStatus = "1";
				const char* isHaveShop = "1";
				const char* shopYear = "5";
				const char* assetsHouse = "1";
				const char* assetsCar = "1";
				*/
				cout << "调用接口："<< endl;
				//调用准入API
				rtAdmit* rtadm = htapi->admitGroupRule(api[0].c_str(), atoi(api[1].c_str()), api[2].c_str(), atoi(api[3].c_str()),
					api[4].c_str(), api[5].c_str(), api[6].c_str(), api[7].c_str(),
					api[8].c_str(), api[9].c_str(), api[10].c_str());
				//调用评级API
				rtAdmit2* rtadm2 = htapi->RatingRule(api[0].c_str(), atoi(api[1].c_str()), api[2].c_str(), api[4].c_str(),
					api[11].c_str(), api[12].c_str(), api[5].c_str(), api[6].c_str(), api[7].c_str());
				//打印结果`
				char str[1024] = { 0 };
				sprintf(str, "success:%d\nerrorCode:%d\nresult:%s\nmsg:%s\n",
					rtadm->success, rtadm->errorCode, rtadm->msg, rtadm->data.result);
				printf("%s\n", str);
				//打印结果
				char str2[1024] = { 0 };
				sprintf(str2, "success:%d\nerrorCode:%d\nresult:%s\nmsg:%s\nrate:%s\n",
					rtadm2->success, rtadm2->errorCode, rtadm2->msg, rtadm2->data.result, rtadm2->rate);
				printf("%s\n", str2);
				//内存回收
				htapi = NULL;
				delete htapi;
				flag = 0;
			}
		}
		else
		{
			cout << "无效的输入！" << endl;
		}


	}
    return 0;
}
