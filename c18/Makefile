CPPFLAGS=-pedantic -Wall -Werror -ggdb3 -std=gnu++98
EXEC = deduplicate
HASH_H = sha256.h md5.h
HASH_CPP = sha256.cpp md5.cpp

deduplicate: deduplication.cpp deduplication.h
	g++ $(CPPFLAGS) -o deduplicate deduplication.cpp $(HASH_CPP)