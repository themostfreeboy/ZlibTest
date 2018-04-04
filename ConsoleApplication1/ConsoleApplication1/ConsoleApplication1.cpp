// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ConsoleApplication1.h"

#include "zlib.h"
#pragma comment(lib, "ZLib.lib")

#include "iostream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  更改错误代码以符合您的需要
			_tprintf(_T("错误:  MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  在此处为应用程序的行为编写代码。
			/* 压缩 */
			//compress(bufStr, &bufLen, srcStr, srcLen);
			/* 解压缩 */
			//uncompress(bufStr, &bufLen, srcStr, srcLen);
			int err;

			Byte compr[200], uncompr[200];    // big enough

			uLong comprLen, uncomprLen;

			const char* hello = "12345678901234567890123456789012345678901234567890";



			uLong len = strlen(hello) + 1;

			comprLen = sizeof(compr) / sizeof(compr[0]);



			err = compress(compr, &comprLen, (const Bytef*)hello, len);



			if (err != Z_OK) {

				cerr << "compess error: " << err << '\n';

				exit(1);

			}

			cout << "orignal size: " << len

				<< " , compressed size : " << comprLen << '\n';



			strcpy_s((char*)uncompr, 8, "garbage");



			err = uncompress(uncompr, &uncomprLen, compr, comprLen);



			if (err != Z_OK) {

				cerr << "uncompess error: " << err << '\n';

				exit(1);

			}

			cout << "orignal size: " << len

				<< " , uncompressed size : " << uncomprLen << '\n';



			if (strcmp((char*)uncompr, hello)) {

				cerr << "BAD uncompress!!!\n";

				exit(1);

			}
			else {

				cout << "uncompress() succeed: \n" << (char *)uncompr;

			}

		}
	}
	else
	{
		// TODO:  更改错误代码以符合您的需要
		_tprintf(_T("错误:  GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	printf("\n");
	system("pause");
	return nRetCode;
}
