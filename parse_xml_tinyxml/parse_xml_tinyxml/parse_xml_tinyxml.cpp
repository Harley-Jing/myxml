// parse_xml_tinyxml.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "myxml.h"

int main()
{
	std::string strPostDate;
	strPostDate += "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
	strPostDate += "<config version=\"1.0\" xmlns=\"http://www.ipc.com/ver10\">";
	strPostDate += "<search>";
	strPostDate += "<recTypes type=\"list\"><itemType type=\"recType\">string</itemType>";
	strPostDate += "<item>manual</item>";
	strPostDate += "<item>schedule</item>";
	strPostDate += "<item>motion</item>";
	strPostDate += "<item>sensor</item>";
	strPostDate += "</recTypes>";
	strPostDate += "<starttime type=\"string\">2019-04-03 00:00:00</starttime>";
	strPostDate += "<endtime type=\"string\">2019-04-03 23:59:59</endtime>";
	strPostDate += "</search>";
	strPostDate += "</config>";

	ReadXML2Data(strPostDate.c_str());

	ReadXML2File("test.xml");

	getchar();
    return 0;
}


