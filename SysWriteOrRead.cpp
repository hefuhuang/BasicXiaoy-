#include "stdafx.h"
#include "SysWriteOrRead.h"


SysWriteOrRead::SysWriteOrRead()
{
}


SysWriteOrRead::~SysWriteOrRead()
{

}

void WriteSys()
{
	char buffer[256];
	ifstream myfile("..\\sys\\sys.txt");
	ofstream outfile("..\\sys\\sys.txt");
	if (!myfile){
	//	MessageBox(_T("不能读取系统参数"));
	}

}

void ReadSys()
{

}