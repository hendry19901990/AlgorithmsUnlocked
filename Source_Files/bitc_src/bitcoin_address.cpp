/* Copyright (c) 2017, Sumit Lahiri */

/** 

/*

All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <openssl/sha.h>
#include <openssl/ripemd.h>
 
#define COIN_VER 0
const char *coin_err;
 
typedef unsigned char byte;
 
int is_hex(const char *s) {
	int i;
	for (i = 0; i < 64; i++)
		if (!isxdigit(s[i])) return 0;
	return 1;
}
 
void str_to_byte(const char *src, byte *dst, int n) {
	while (n--) sscanf(src + n * 2, "%2hhx", dst + n);
}
 
char* base58(byte *s, char *out) {
	static const char *tmpl = "123456789"
		"ABCDEFGHJKLMNPQRSTUVWXYZ"
		"abcdefghijkmnopqrstuvwxyz";
	static char buf[40];
 
	int c, i, n;
	if (!out) out = buf;
 
	out[n = 34] = 0;
	while (n--) {
		for (c = i = 0; i < 25; i++) {
			c = c * 256 + s[i];
			s[i] = c / 58;
			c %= 58;
		}
		out[n] = tmpl[c];
	}
 
	for (n = 0; out[n] == '1'; n++);
	memmove(out, out + n, 34 - n);
 
	return out;
}
 
char *coin_encode(const char *x, const char *y, char *out) {
	byte s[65];
	byte rmd[5 + RIPEMD160_DIGEST_LENGTH];
 
	if (!is_hex(x) || !(is_hex(y))) {
		coin_err = "bad public point string";
		return 0;
	}
 
	s[0] = 4;
	str_to_byte(x, s + 1, 32);
	str_to_byte(y, s + 33, 32);
 
	rmd[0] = COIN_VER;
	RIPEMD160(SHA256(s, 65, 0), SHA256_DIGEST_LENGTH, rmd + 1);
 
	memcpy(rmd + 21, SHA256(SHA256(rmd, 21, 0), SHA256_DIGEST_LENGTH, 0), 4);
 
	return base58(rmd, out);
}
 
int main(void) {
	puts(coin_encode(
		"50863AD64A87AE8A2FE83C1AF1A8403CB53F53E486D8511DAD8A04887E5B2352",
		"2CD470243453A299FA9E77237716103ABC11A1DF38855ED6F2EE187E9C582BA6",
		0));
	return 0;
}
