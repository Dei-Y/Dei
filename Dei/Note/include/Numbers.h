#pragma once
#include<iostream>

class Numbers
{
private:
	// ����� -- ����ʱ��ĸı���ı� 
	static bool RandomNum(int& num);

	// �Ƿ�Ϊ��ֵ��������ѧ������
	static bool isNumber(std::string str);
};