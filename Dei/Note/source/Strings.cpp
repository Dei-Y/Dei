#include"Strings.h"
#include"Marco.h"

#include<string>
#ifdef _WIN32
#include<direct.h>
#include<Windows.h>
#include<psapi.h>
#include<iostream>
#include<corecrt_io.h>
#elif __linux__
#include<unistd.h>
#include<cstring>
#include<iomanip>
#include<iconv.h>
#endif

void String::substrReturn()
{
    std::string path = "D:/a/b.txt";
    std::string suffix = path.substr(path.find_last_of('.'), path.size());
    std::cout << suffix << std::endl; //".txt"
    std::cout << path << std::endl;  //"D:/a/b.txt"
}

int String::StringToInt(const std::string& str)
{
    try
    {
        return std::stoi(str);
    }
    catch (...)
    {
        return 0;
    }
}
double String::StringToDouble(const std::string& str)
{
    try
    {
        return std::stod(str);
    }
    catch (...)
    {
        return 0;
    }
}

bool String::MakeFolder(const std::string& str)
{
    std::string cmd{ "" };

#ifdef _WIN32
    cmd = "mkdir \"";
#else
    cmd = "mkdir -p \"";
#endif

    cmd.append(str).append("\"");
    cmd = String::ReplaceAll(cmd, "/", "\\");
    cmd = String::ReplaceAll(cmd, "\"\"", "\"");
    system(cmd.data());

    return true;
}
std::string String::ApplicationName()
{
    static std::string str{ "" };
    if (true == str.empty())
    {
#if _WIN32
        HANDLE handle = GetCurrentProcess();

        char c[1024];
        GetProcessImageFileName(handle, c, 1024);
        std::string exe{ c };
        exe = exe.substr(exe.find_last_of('\\') + 1);
        //exe = String::Replace(exe, ".exe", "");
        str = exe;
#else

#endif
    }

    return str;
}

/*
* �滻 Replace��ReplaceAll ֮��Ĳ���
*/
/*
* ************************ NOTE ************************ *
* 1. ������������Ϊ����ʱ�����ǿ��������������ܣ�Ҳ��������ͨ���������ܡ�
*    ���������������ܷ�������Ϊ��ͨ����������ʱ��eg��int& c = ��ʱ����;������
*    ��ԭ�򣺵����Ƿ�������Ϊ��ͨ����ʱ����������������ʱ���豣֤������ݲ�����ʧ�����¢٢ڣ���Ȼ�������ʱ���󷵻ظ�����������
*      ���� ����һ����ʱ����Ȼ��return�����ݿ����������ʱ���󣨵���������ִ�������Ӧջ�ռ�ͻᱻ�ͷţ����ܱ����·��䣬���������������ʧ�����ԲŻ��������һ����ʱ�������洢Ҫ���ص����ݣ���
*        �� �ŵ��Ĵ����ж��ݴ洢������
* ************* ************* ************* *************
* 2. String::ReplaceAll() �����Ǿ�̬��Ա�����ĵ��÷�����������������������ʱ�� ����ǰ��Ҫ��static
*    ����������ַ������ã�����Ҫ��ʵ����һ��������ȥ���÷���
*    ���� String strOpertaer;
*	      path = strOpertaer.ReplaceAll(path, "\\", "/");
*    ���Ǿ�̬��Ա������ʱ��Ҳ���Բ�������ʵ�����ķ�ʽ����
* ************* ************* ************* *************
* 3. ��̬��Ա�������
* https://blog.csdn.net/weixin_41783335/article/details/92784826
* https://zhuanlan.zhihu.com/p/530183592#:~:text=%E4%BA%8C%E3%80%81C%2B%2B%E8%AF%AD%E8%A8%80%E4%B8%AD%E7%9A%84static%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E7%9A%84%E4%BD%9C%E7%94%A8%EF%BC%9A%201.%E5%9C%A8%E7%B1%BB%E4%B8%AD%EF%BC%8Cstatic%20%E9%99%A4%E4%BA%86%E5%8F%AF%E4%BB%A5%E5%A3%B0%E6%98%8E%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%8F%98%E9%87%8F%EF%BC%8C%E8%BF%98%E5%8F%AF%E4%BB%A5%E5%A3%B0%E6%98%8E%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E3%80%82%20%E6%99%AE%E9%80%9A%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E5%8F%AF%E4%BB%A5%E8%AE%BF%E9%97%AE%E6%89%80%E6%9C%89%E6%88%90%E5%91%98%EF%BC%88%E5%8C%85%E6%8B%AC%E6%88%90%E5%91%98%E5%8F%98%E9%87%8F%E5%92%8C%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%EF%BC%89%EF%BC%8C%E4%BD%86%E6%98%AF%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E5%8F%AA%E8%83%BD%E8%AE%BF%E9%97%AE%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E3%80%82%202.%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E4%B8%8E%E6%99%AE%E9%80%9A%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E7%9A%84%E6%A0%B9%E6%9C%AC%E5%8C%BA%E5%88%AB%E5%9C%A8%E4%BA%8E%EF%BC%9A%E6%99%AE%E9%80%9A%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E6%9C%89%20this%20%E6%8C%87%E9%92%88%EF%BC%8C%E5%8F%AF%E4%BB%A5%E8%AE%BF%E9%97%AE%E7%B1%BB%E4%B8%AD%E7%9A%84%E4%BB%BB%E6%84%8F%E6%88%90%E5%91%98%EF%BC%9B%E8%80%8C%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E6%B2%A1%E6%9C%89%20this,%E6%8C%87%E9%92%88%EF%BC%8C%E5%8F%AA%E8%83%BD%E8%AE%BF%E9%97%AE%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%EF%BC%88%E5%8C%85%E6%8B%AC%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%8F%98%E9%87%8F%E5%92%8C%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%EF%BC%89%E3%80%82%203.%E5%9C%A8C%2B%2B%E4%B8%AD%EF%BC%8C%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E7%9A%84%E4%B8%BB%E8%A6%81%E7%9B%AE%E7%9A%84%E6%98%AF%E8%AE%BF%E9%97%AE%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E3%80%82%20%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E4%B9%9F%E5%8F%AF%E4%BB%A5%E5%A3%B0%E6%98%8E%E4%B8%BA%E6%99%AE%E9%80%9A%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%EF%BC%8C%E4%BD%86%E6%98%AF%E5%AE%83%E4%BB%AC%E9%83%BD%E5%8F%AA%E5%AF%B9%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E8%BF%9B%E8%A1%8C%E6%93%8D%E4%BD%9C%EF%BC%8C%E5%8A%A0%E4%B8%8A%20static%20%E8%AF%AD%E4%B9%89%E6%9B%B4%E5%8A%A0%E6%98%8E%E7%A1%AE%E3%80%82%204.%E5%92%8C%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%8F%98%E9%87%8F%E7%B1%BB%E4%BC%BC%EF%BC%8C%E9%9D%99%E6%80%81%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0%E5%9C%A8%E5%A3%B0%E6%98%8E%E6%97%B6%E8%A6%81%E5%8A%A0%20static%EF%BC%8C%E5%9C%A8%E5%AE%9A%E4%B9%89%E6%97%B6%E4%B8%8D%E8%83%BD%E5%8A%A0%20static%E3%80%82
* 
*/
std::string& String::ReplaceAll(std::string& source, const std::string& beReplaced, const std::string& replacer)
{
    // check string empty
    if (source.empty() || 0 == beReplaced.compare(replacer))
    {
        return source;
    }

    int bsize = beReplaced.size();
    int rsize = replacer.size();
    while (true)
    {
        int begin = 0;
        bool work = false;
        size_t index(0);
        while (std::string::npos != (index = source.find(beReplaced, begin)))
        {
            source = source.replace(index, bsize, replacer);
            begin = index + rsize;
            work = true;
        }

        EQUL_BREAK(false, work);
    }
    return source;
}


bool String::ToUpper(std::string& str)
{
    int len = (int)str.size();
    for (int i = 0; i < len; i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return true;
}
bool String::ToLower(std::string& str)
{
    int len = (int)str.size();
    for (int i = 0; i < len; i++)
    {
        str[i] = std::tolower(str[i]);
    }
    return true;
}

std::string String::GetCurrentPath()
{
    static std::string path;
    if (path.empty())
    {
        char* cwdp = getcwd(NULL, 0);
        std::string cwd(cwdp);

        free(cwdp);

        path = String::ReplaceAll(cwd, "\\", "/");
    }
    return path;
}