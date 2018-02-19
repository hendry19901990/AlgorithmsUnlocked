/* Copyright (c) 2017, Sumit Lahiri */

/** 
 * The implementation here is only dummy but it shows how to overload operators
 * in case of classes defined with a template typename. Hope this will clarify the 
 * basics of how to write such kinds of code and will also help in better understanding of 
 * Functors, overloading & Constructors along with operator oveloading
 **/
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
#include <openssl/sha.h>
 
const char *coin_err;
#define bail(s) { coin_err = s; return 0; }
 
int unbase58(const char *s, unsigned char *out) {
	static const char *tmpl = "123456789"
		"ABCDEFGHJKLMNPQRSTUVWXYZ"
		"abcdefghijkmnopqrstuvwxyz";
	int i, j, c;
	const char *p;
 
	memset(out, 0, 25);
	for (i = 0; s[i]; i++) {
		if (!(p = strchr(tmpl, s[i])))
			bail("bad char");
 
		c = p - tmpl;
		for (j = 25; j--; ) {
			c += 58 * out[j];
			out[j] = c % 256;
			c /= 256;
		}
 
		if (c) bail("address too long");
	}
 
	return 1;
}
 
int valid(const char *s) {
	unsigned char dec[32], d1[SHA256_DIGEST_LENGTH], d2[SHA256_DIGEST_LENGTH];
 
	coin_err = "";
	if (!unbase58(s, dec)) return 0;
 
	SHA256(SHA256(dec, 21, d1), SHA256_DIGEST_LENGTH, d2);
 
	if (memcmp(dec + 21, d2, 4))
		bail("bad digest");
 
	return 1;
}
 
int main (void) {
	const char *s[] = {
		"1Q1pE5vPGEEMqRcVRMbtBK842Y6Pzo6nK9",
		"1AGNa15ZQXAZUgFiqJ2i7Z2DPU2J6hW62i",
		"1Q1pE5vPGEEMqRcVRMbtBK842Y6Pzo6nJ9",
		"1AGNa15ZQXAZUgFiqJ2i7Z2DPU2J6hW62I",
		0 };
	int i;
	for (i = 0; s[i]; i++) {
		int status = valid(s[i]);
		printf("%s: %s\n", s[i], status ? "Ok" : coin_err);
	}
 
	return 0;
}