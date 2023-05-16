#pragma once
#include <unordered_map>

class c_globals {
public:
	bool active = true;
	bool activeStatistics = false;
	char user_name[32] = "Album";
	char pass_word[32] = "Artist";
};

inline c_globals globals;