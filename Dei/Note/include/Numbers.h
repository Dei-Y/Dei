#pragma once
#include<iostream>

class Numbers
{
private:
	// 随机数 -- 随着时间的改变而改变 
	static bool RandomNum(int& num);

	// 是否为数值，包括科学计数法
	static bool isNumber(std::string str);
};