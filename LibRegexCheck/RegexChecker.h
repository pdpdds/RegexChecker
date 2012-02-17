#pragma once

class CRegexChecker
{
public:
	CRegexChecker(void);
	virtual ~CRegexChecker(void);

	BOOL IsValidCharName(TCHAR* szStr);
	BOOL IsValidResidentRegistrationNumber(TCHAR* szStr);
	BOOL IsValidURL(TCHAR* szStr);
	BOOL IsValidMacAddress(TCHAR* szStr);
	BOOL IsValidEMail(TCHAR* szStr);
	BOOL IsValidIPAddress( TCHAR* szStr );
protected:

private:
};
