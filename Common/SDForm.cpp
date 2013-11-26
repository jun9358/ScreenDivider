#include "../ScreenDivider/stdafx.h"
#include "../ScreenDividerHk/stdafx.h"
#include "SDForm.h"

IMPLEMENT_SERIAL(CSDForm, CObject, 1)

CSDForm::CSDForm(void)
{
	// Get desktop handle
	HWND hWnd = NULL;
	hWnd = GetDesktopWindow();

	// Get desktop size
	CSDWindow screen;
	GetWindowRect(hWnd, &screen);

	// Add screen rect to m_lstSDWindow's first item
	m_lstSDWindow.AddHead(screen);
}

CSDForm::CSDForm(CSDWindow screen)
{
	m_lstSDWindow.AddHead(screen);
}

CSDForm::~CSDForm(void)
{
	// Remove all sdwindows
	m_lstSDWindow.RemoveAll();
}

void CSDForm::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	m_lstSDWindow.Serialize(ar);
}

BOOL CSDForm::LoadFromFile(TCHAR strSDFormPath[MAX_PATH])
{
	BOOL isSuccess = TRUE;
	BOOL ret;

	// Before load data, remove all data
	m_lstSDWindow.RemoveAll();

	// Open file
	CFile fileSDForm;
	ret = fileSDForm.Open(strSDFormPath, CFile::modeRead);
	if (ret == 0)
	{
		isSuccess = FALSE;
		return isSuccess;
	}

	// Create archive object
	CArchive arSDForm(&fileSDForm, CArchive::load);

	// Serialization
	Serialize(arSDForm);

	// Close the archive and file
	arSDForm.Close();
	fileSDForm.Close();

	return isSuccess;
}

BOOL CSDForm::SaveToFile(TCHAR strSDFormPath[MAX_PATH])
{
	BOOL isSuccess = TRUE;
	BOOL ret;

	// Open file
	CFile fileSDForm;
	ret = fileSDForm.Open(strSDFormPath, CFile::modeCreate | CFile::modeWrite);
	if (ret == 0)
	{
		isSuccess = FALSE;
		return isSuccess;
	}

	// Create archive object
	CArchive arSDForm(&fileSDForm, CArchive::store);

	// Serialization
	Serialize(arSDForm);

	// Close the archive and file
	arSDForm.Close();
	fileSDForm.Close();

	return isSuccess;
}

POSITION CSDForm::AddSDWindow(CSDWindow &newSDWindow)
{
	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

POSITION CSDForm::AddSDWindow(int l, int t, int r, int b)
{
	CSDWindow newSDWindow(l, t, r, b);

	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

POSITION CSDForm::AddSDWindow(POINT topLeft, POINT bottomRight)
{
	CSDWindow newSDWindow(topLeft, bottomRight);

	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

POSITION CSDForm::AddSDWindow(POINT point, SIZE size)
{
	CSDWindow newSDWindow(point, size);

	POSITION posAdded;
	posAdded = m_lstSDWindow.AddTail(newSDWindow);

	return posAdded;
}

VOID CSDForm::RemoveSDWindow(POSITION pos)
{
	// Check valid pos
	ASSERT(m_lstSDWindow.GetAt(pos));

	// Remove sdwindow from pos
	m_lstSDWindow.RemoveAt(pos);
}

CSDWindow CSDForm::GetSDWindow(const CPoint& cursor)
{
	CSDWindow curSDWindow;

	// Loop all sdwindow
	int i;
	for (i=0 ; i<m_lstSDWindow.GetCount() ; i++)
	{
		POSITION pos;
		pos = m_lstSDWindow.FindIndex(i);

		CSDWindow curSDWindow;
		curSDWindow = m_lstSDWindow.GetAt(pos);
		if (curSDWindow.IsCursorInTitlebar(cursor))
		{
			return curSDWindow;
		}
	}

	return curSDWindow;
}

CSDWindow CSDForm::GetSDWindow(POSITION pos)
{
	CSDWindow curSDWindow;

	// Check valid pos
	ASSERT(m_lstSDWindow.GetAt(pos));

	// Get sdwindow from pos
	curSDWindow = m_lstSDWindow.GetAt(pos);

	return curSDWindow;
}

CSDWindow CSDForm::GetSDWindow(int idx)
{
	CSDWindow curSDWindow;

	if (m_lstSDWindow.GetCount() <= idx)
	{
		return curSDWindow;
	}

	// Set current position to head
	POSITION pos = m_lstSDWindow.FindIndex(idx);
	curSDWindow = m_lstSDWindow.GetAt(pos);

	return curSDWindow;
}