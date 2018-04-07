#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <array>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <future>
#include <initializer_list>
#include <mutex>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <exception>
#include "sha256.h"
#include "sha256.c"

#define print(vec) for(const auto& i : vec) cout << i << endl;
#define input(ss, inputbuffer) while(cin.good()) { getline(cin, inputbuffer); ss << inputbuffer << endl; }
#define sz(a) int((a).size())
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
std::stringstream stream, input, rawinput;
std::string dump, temp;
/*Code Here*/

class GenericException : public std::exception {
	const char *cmessage;
public:
	GenericException(const char *message = "Unhandled Exception Occured") : cmessage(message) {}
	virtual ~GenericException() {}
	virtual const char *what() const noexcept {
		return this->cmessage;
	}
};
class Hash {
	bool valid;
	unsigned char digest[32];
public:
	Hash();
	Hash(const std::string &type_string);
	bool operator!() const {
		return !this->valid;
	}
	int cmp(const Hash &b) const {
		return memcmp(this->digest, b.digest, 32);
	}
	bool operator<(const Hash &b) const {
		return this->cmp(b) < 0;
	}
	bool operator==(const Hash &b) const {
		return this->cmp(b) == 0;
	}
	bool operator!=(const Hash &b) const {
		return this->cmp(b) != 0;
	}
	std::string stringize() const {
		std::stringstream stream;
		stream << "0x";
		for (const auto& c : this->digest)
			stream << std::hex << std::setw(2) << std::setfill('0') << (unsigned)c;
		return stream.str();
	}
	std::string double_sha256(const std::string &type_string) {
		SHA256_CTX tx;
		sha256_init(&tx);
		sha256_update(&tx, (const BYTE *)type_string.c_str(), type_string.size());
		sha256_final(&tx, this->digest);
		sha256_final(&tx, this->digest);
		std::stringstream stream;
		stream << "0x";
		for (const auto& c : this->digest)
			stream << std::hex << std::setw(2) << std::setfill('0') << (unsigned)c;
		return stream.str();
	}
	std::string once_sha256(const std::string &type_string) {
		SHA256_CTX ptx;
		sha256_init(&ptx);
		sha256_update(&ptx, (const BYTE *)type_string.c_str(), type_string.size());
		sha256_final(&ptx, this->digest);
		std::stringstream stream;
		stream << "0x";
		for (const auto& c : this->digest)
			stream << std::hex << std::setw(2) << std::setfill('0') << (unsigned)c;
		return stream.str();
	}
};
Hash::Hash() {
	this->valid = false;
	memset(this->digest, 0, sizeof(this->digest));
}

Hash::Hash(const std::string &type_string) {
	this->valid = true;
	SHA256_CTX ctx;
	sha256_init(&ctx);
	sha256_update(&ctx, (const BYTE *)type_string.c_str(), type_string.size());
	sha256_final(&ctx, this->digest);
}

int main()
{
	freopen("inputstring.cpp", "r", stdin);
	freopen("out.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	while (cin.good())
	{
		getline(cin, dump);
		temp += dump;
	}
	Hash sha256(temp);
	cout << sha256.once_sha256(temp) << endl;
	cout << sha256.double_sha256(temp) << endl;
	cerr << clock() << " ms." << endl;
	return 0;
}