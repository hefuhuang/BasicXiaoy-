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
	//	MessageBox(_T("���ܶ�ȡϵͳ����"));
	}

}

void ReadSys()
{

}