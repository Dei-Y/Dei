#include<fstream>
#include<filesystem>

#include"Files.h"
#include"Marco.h"
#include"Strings.h"


/*
* 1. "std::string msg;"初始化时，需要给默认值吗？
* 2. "file.close();" 应该先关文件，再 delete指针变量（和FILE*有关的指针）；避免delete里面把文件句柄删了，删了再close则不对
	【先关闭句柄，再 delete】。
*/
bool OnFile::ReadFile(const std::string& fileName)
{
	FILE* fp = fopen(fileName.c_str(), "rb");
	EQUL_RETURN_FALSE(nullptr, fp);
	// xxx操作，【例：Varient * pFile = new Varient(fp, "file");】
	fclose(fp);
	// 再释放和fp相关的指针变量，【例：SAFE_DELETE(pFile);】

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

