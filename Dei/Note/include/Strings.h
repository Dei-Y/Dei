#pragma once
#include<iostream>

class String
{
public:
	int StringToInt(const std::string& str);
	double StringToDouble(const std::string& str);

	bool MakeFolder(const std::string& str);
	std::string ApplicationName();

	static std::string& ReplaceAll(std::string& source, const std::string& beReplaced, const std::string& replacer);

	static bool ToUpper(std::string& str);
	static bool ToLower(std::string& str);

	static std::string GetCurrentPath();
private:
	// 函数substr的返回值，是否修改值本身--不修改
	void substrReturn();
};