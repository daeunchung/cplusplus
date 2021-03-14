#ifndef _STRING_H
#define _STRING_H

namespace cppalgo{
	
	class String
	{
	public:
		// constructors (Constructor Overloading)
		
		String();							// default constructor
		String(const String& stringSrc);	// copy constructor
		String(char* lpsz);
		String(const char* lpcsz);			// c++ style native string
		String(char ch);
		String(long l);
		String(int i);
		String(double d);
		~String();
	}
}
