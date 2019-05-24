#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

#ifdef _DEBUG		
#include <stdio.h>
#define	DebugPrint	printf
#else
#define	DebugPrint __noop
#endif

#ifdef _DEBUG
#pragma comment(lib, "..\\Debug\\tinyxml2.lib")
#else
#pragma comment(lib, "..\\Release\\tinyxml2.lib")
#endif

void ReadXML2Data(const char* pXmlBuf);
void ReadXML2File(const char* pXmlFileName);

void ParseXML2(XMLElement *pElement);
void PrintTree(int c);

void ReadXML2Data(const char* pXmlBuf)
{

	XMLDocument *pMyDocument = new XMLDocument();

	pMyDocument->Parse(pXmlBuf);
	XMLElement *rootElement = pMyDocument->RootElement();

	DebugPrint("----------------start-----------------\n");
	while (rootElement)
	{
		ParseXML2(rootElement);
		rootElement = rootElement->NextSiblingElement();
	}

	delete pMyDocument;
	pMyDocument = NULL;
	DebugPrint("----------------END-----------------\n\n");

}

void ReadXML2File(const char* pXmlFileName)
{

	XMLDocument *pMyDocument = new XMLDocument();

	if (pMyDocument->LoadFile(pXmlFileName))
	{
		return;
	}

	XMLElement *rootElement = pMyDocument->RootElement();

	DebugPrint("----------------start-----------------\n");
	while (rootElement)
	{
		ParseXML2(rootElement);
		rootElement = rootElement->NextSiblingElement();
	}

	delete pMyDocument;
	pMyDocument = NULL;
	DebugPrint("----------------END-----------------\n\n");

}

void ParseXML2(XMLElement *pElement)
{
	static int i = 0;
	PrintTree(i);
	DebugPrint("%s ", pElement->Value());
	const char * str = NULL;
	if (str = pElement->GetText())
	{
		DebugPrint(": %s\n", str);
		//此处对文本操作 比如用容器进行存储

	}
	else
	{
		DebugPrint("\n");
	}

	const XMLAttribute* attributeOfStudent = pElement->FirstAttribute();
	while (attributeOfStudent)
	{
		PrintTree(i);
		DebugPrint("%s : %s\n", attributeOfStudent->Name(), attributeOfStudent->Value());
		//此处对属性以及属性值操作 比如用容器进行存储


		attributeOfStudent = attributeOfStudent->Next();
	}
	XMLElement* ChildElement = pElement->FirstChildElement();
	while (NULL != ChildElement)
	{
		i++;
		ParseXML2(ChildElement);
		i--;
		ChildElement = ChildElement->NextSiblingElement();
	}

}

void PrintTree(int c)
{
	if (c <= 0)
		return;
	while (c)
	{
		DebugPrint(" ");
		--c;
	}
	return;
}


