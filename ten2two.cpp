// ten2two.cpp : �⺻ ������Ʈ �����Դϴ�.
#pragma once
#include "stdafx.h"
#include "Form1.h"
#include "subform.h"

using namespace ten2two;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��Ʈ���� ��������� ���� Windows XP �ð� ȿ���� Ȱ��ȭ�մϴ�.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �� â�� ����� �����մϴ�.
	Application::Run(gcnew Form1());
	return 0;
}