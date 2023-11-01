#pragma once
#include<iostream>

class OnFile
{
	bool ReadFile(const std::string& fileName);

	static bool CanOpen(const std::string& fileName);
	static bool CanOpen(std::string fileName, std::string& msg);
	static bool Open(const std::string& fileName, std::string& msg, std::fstream& file);

	static bool CanWrite(const std::string& fileName, std::string& msg);

	static bool isEmpty(std::string fileName);
	static bool isExist(std::string fileName);
};

