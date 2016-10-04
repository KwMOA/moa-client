//
//  main.cpp
//  moa
//
//  Created by kimyongchan on 2016. 9. 23..
//  Copyright © 2016년 kimyongchan. All rights reserved.
//

#include "GameManager.hpp"
#include "JsonReader.hpp"
#include "TaskManagerImpl.h"
#include "IProcessBuilding_1.hpp"
#include <map>

int main(int argc, const char * argv[]) {
    
//    GameManager::GetInstance();
    
//    GameManager::GetInstance()->init();
    
//    GameManager::GetInstance()->run();
	/*const int BufferLength = 1024;
	std::string config_doc;
	int fileSize;
	char readBuffer[BufferLength] = { 0, };
	FILE* r = fopen("object_Info.json", "rb");
	if (NULL == r) return 0;
	int i = 0; 
	while (!feof(r)){
		i = 0;
		fileSize = fread(readBuffer, 1, BufferLength, r);
		for (i = 0; i < fileSize; i++) {
			config_doc += readBuffer[i];
		}
	}

	fclose(r);*/
	JsonReader jr = JsonReader();
	Json::Value root;
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(jr.config_doc, root);
	if (!parsingSuccessful)
	{
		std::cout << "Failed to parse configuration\n"
			<< reader.getFormatedErrorMessages();
		return 0;
	}
	
	const Json::Value tribe = root["tribe"]["1"]["object"]["building_1"];
	
		std::cout << tribe["name"].asString() << std::endl;

		TaskManagerImpl task = TaskManagerImpl();
		
		std::map<int, Process*>::iterator it = task.map.find(1);
		std::cout << it->first;
		return 0;
}
