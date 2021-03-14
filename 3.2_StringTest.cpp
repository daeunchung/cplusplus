#include "3.2_AString.h"
using namespace cppalgo;

void main(void)
{
	// constructor test
	String str1;					// default constructor 호출
	String str2("String Test");		// constructor : const char*
	String str3('A');				// constructor : char
	String str4 = str2;				// copy constructor 
	String str5(156);				// constructor : int, long
	String str6(1.1);				// constructor : double
	
	// basic functions
	str1.Empty();
	
	str1 = "CompareNoCase";
	n = str1.Find("No", 0);
	n = str1.FindNoCase("No", 0);
	n = str1.ReverseFind('C');	// StringX 문자한개만가능 
	str1.Replace("e", "EEE");
	
	str1 = "0123456789";
	str2 = str1.Left(3);
	str2 = str1.Right(3);
	str2 = str1.Mid(3,3);
	
	str1 = "	\ttrim	test	\r\n";
	str1.TrimLeft();
	str1.TrimRight();
	
	str1.Format("Format %s %d", "test", 555);
	
	str1 = "This is[Token]Test.";
	n=0;
	while(n>=0) str2 = str1.GetToken(" []", n);
	// " "공백, "[", "]" 를 분리자로 주고, n은 reference값. Token분리끝나면 -1 return 
	str2 = (const char*)str1; 

}
