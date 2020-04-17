// TriList.h: interface for the CTriList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRILIST_H__F4D23E1D_92BF_4F04_A498_761E19114FC0__INCLUDED_)
#define AFX_TRILIST_H__F4D23E1D_92BF_4F04_A498_761E19114FC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TriObject.h"

class CTriList  
{
public:
	CTriList();
	virtual ~CTriList();

	CTriObject* getObjectByName(char* name);
	void removeAllObjects();
	void doAfterMath();
	void Init();
	int	 getNumObjects() {return numobjects;};

	void drawGL();
	BOOL add(CTriObject* _object);
	
private:
	int numobjects;
	int free;
	int maxobjects;
	CTriObject* objects[100];	


};

#endif // !defined(AFX_TRILIST_H__F4D23E1D_92BF_4F04_A498_761E19114FC0__INCLUDED_)
