#ifndef __JSON_READER_HPP__
#define __JSON_READER_HPP__

#include <json/json.h>
#include <string.h>
class JsonReader {
private:
	const int BufferLength = 1024;
	int i;
	int fileSize;
	char* readBuffer;
	Json::Value root;
	Json::Reader reader;
	FILE* file;
public:
	std::string config_doc;
	JsonReader();
};
#endif