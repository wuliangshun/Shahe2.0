#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <iostream>
//#include <gmp.h>
#include "../gmp-5.0.1/gmp.h"

struct key_pair
{
	char * n;
	char * d;
	int e;
};
//生成两个大素数
mpz_t * gen_primes();
//生成密钥对
key_pair * gen_key_pair();
//加密函数
char * rsa_encrypt(const char * plain_text, const char * key_n, int key_e);
//解密函数
char * rsa_decrypt(const char * cipher_text, const char * key_n, const char * key_d);
