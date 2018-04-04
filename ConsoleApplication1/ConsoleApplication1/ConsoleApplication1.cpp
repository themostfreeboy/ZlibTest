// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
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


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����:  MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  �ڴ˴�ΪӦ�ó������Ϊ��д���롣
			/* ѹ�� */
			//compress(bufStr, &bufLen, srcStr, srcLen);
			/* ��ѹ�� */
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
		// TODO:  ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����:  GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	printf("\n");
	system("pause");
	return nRetCode;
}
