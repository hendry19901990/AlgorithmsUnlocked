#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include "sha256.c"
#include "sha256.h"
using namespace std;

class GenericException : public std::exception {
	const char *cmessage;
public:
	explicit GenericException(const char *message) : cmessage(message) {}
	~GenericException() override = default;
	const char *what() const noexcept override {
		return this->cmessage;
	}
};

class Hash {
	bool valid;
	unsigned char digest[32];
public:
	Hash();
	explicit Hash(const std::string &type_string);
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
		for (const auto& c : this->digest) {
			stream << std::hex << std::setw(2) << std::setfill('0') << (unsigned)(c);
}
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

