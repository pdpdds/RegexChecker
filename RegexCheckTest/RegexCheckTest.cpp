// RegexCheckTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RegexChecker.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
	CRegexChecker Checker;

//주민등록번호
	assert(FALSE == Checker.IsValidResidentRegistrationNumber(L"801234-798999"));
	assert(TRUE == Checker.IsValidResidentRegistrationNumber(L"801234-7989990"));
	assert(FALSE == Checker.IsValidResidentRegistrationNumber(L"801234-79899909"));

//URL
	assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver.org/444/"));
	assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver.org/444"));
	assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver.org"));
	assert(TRUE == Checker.IsValidURL(L"http://onlinegameserver"));
	assert(FALSE == Checker.IsValidURL(L"http://"));
	assert(FALSE == Checker.IsValidURL(L"http://["));

//이메일
	assert(FALSE == Checker.IsValidEMail(L"email"));
	assert(FALSE == Checker.IsValidEMail(L"email@"));
	assert(FALSE == Checker.IsValidEMail(L"email@daum"));
	assert(FALSE == Checker.IsValidEMail(L"email@daum."));
	assert(TRUE == Checker.IsValidEMail(L"a@daum.net"));
	assert(TRUE == Checker.IsValidEMail(L"email-A@DAUM.Net"));
	assert(FALSE == Checker.IsValidEMail(L"email-A@DAUM.Neta"));
	assert(TRUE == Checker.IsValidEMail(L"email-A@DAUM.Ne"));
	assert(FALSE == Checker.IsValidEMail(L"email-A@DAUM.N"));
	assert(FALSE == Checker.IsValidEMail(L"email--A@DAUM.NET"));

//IP Address
	assert(FALSE == Checker.IsValidIPAddress(L"333"));
	assert(FALSE == Checker.IsValidIPAddress(L"333."));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333"));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333."));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333.333"));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333.333."));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333.333.333"));
	assert(TRUE == Checker.IsValidIPAddress(L"133.133.133.133"));
	assert(TRUE == Checker.IsValidIPAddress(L"255.255.255.255"));
	assert(FALSE == Checker.IsValidIPAddress(L"255.255.255.256"));
	assert(TRUE == Checker.IsValidIPAddress(L"56.255.255.255"));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333.333.333."));
	assert(FALSE == Checker.IsValidIPAddress(L"333.333.333.333.333"));

//캐릭터이름
	assert(FALSE == Checker.IsValidCharName(L"★가나다abc-][(){}_AB194"));
	assert(TRUE == Checker.IsValidCharName(L"가나다abc-][(){}_AB194"));
	assert(FALSE == Checker.IsValidCharName(L"ㅁ가나다abc-][(){}_AB194"));

	return 0;
}