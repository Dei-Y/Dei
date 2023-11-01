#include<fstream>
#include<filesystem>

#include"Files.h"
#include"Marco.h"
#include"Strings.h"


/*
* 1. "std::string msg;"��ʼ��ʱ����Ҫ��Ĭ��ֵ��
* 2. "file.close();" Ӧ���ȹ��ļ����� deleteָ���������FILE*�йص�ָ�룩������delete������ļ����ɾ�ˣ�ɾ����close�򲻶�
	���ȹرվ������ delete����
*/
bool OnFile::ReadFile(const std::string& fileName)
{
	FILE* fp = fopen(fileName.c_str(), "rb");
	EQUL_RETURN_FALSE(nullptr, fp);
	// xxx������������Varient * pFile = new Varient(fp, "file");��
	fclose(fp);
	// ���ͷź�fp��ص�ָ�������������SAFE_DELETE(pFile);��

	return true;
}

bool OnFile::CanOpen(const std::string& fileName)
{
	std::string msg;
	return OnFile::CanOpen(fileName, msg);
}
bool OnFile::CanOpen(std::string fileName, std::string& msg)
{
	std::fstream file;
	return OnFile::Open(fileName, msg, file);
}
bool OnFile::Open(const std::string& fileName, std::string& msg, std::fstream& file)
{
	file.open(fileName, std::ios::in);
	bool opend = file.is_open();

	if (false == opend)
	{
		msg = "file not exist or internal breakdown.";
		return false;
	}

	if (EOF == file.peek())
	{
		msg = "file is empty.";
		file.close();

		return false;
	}
	return true;
}

bool OnFile::CanWrite(const std::string& fileName, std::string& msg)
{
	std::string path = fileName;
	path = String::ReplaceAll(path, "\\", "/");
	path = String::ReplaceAll(path, "//", "/");

	int idx = path.find_last_of('/');

	if (-1 == idx)
	{
		msg = "Path not exist.";
		return false;
	}

	path.resize(idx);

	if (false == std::filesystem::is_directory(path))
	{
		msg = "Path not exist.";
		return false;
	}

	return true;
}

bool OnFile::isEmpty(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);

	if (EOF == file.peek())
	{
		file.close();
		return false;
	}
	file.close();

	return true;
}
bool OnFile::isExist(std::string fileName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	bool opend = file.is_open();

	if (false == opend)
	{
		return false;
	}
	file.close();

	return true;
}

