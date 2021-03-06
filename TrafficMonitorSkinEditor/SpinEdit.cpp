// SpinEdit.cpp: 实现文件
//

#include "stdafx.h"
#include "TrafficMonitorSkinEditor.h"
#include "SpinEdit.h"


// CSpinEdit

IMPLEMENT_DYNAMIC(CSpinEdit, CEdit)

CSpinEdit::CSpinEdit()
{

}

CSpinEdit::~CSpinEdit()
{
}

void CSpinEdit::SetRange(short lower, short upper)
{
	if (m_spin.GetSafeHwnd() != NULL)
		m_spin.SetRange(lower, upper);
}

void CSpinEdit::SetValue(int value)
{
	if (m_spin.GetSafeHwnd() != NULL)
		m_spin.SetPos(value);
}

int CSpinEdit::GetValue()
{
	if (m_spin.GetSafeHwnd() != NULL)
		return m_spin.GetPos();
	else
		return 0;
}


BEGIN_MESSAGE_MAP(CSpinEdit, CEdit)
END_MESSAGE_MAP()



// CSpinEdit 消息处理程序

void CSpinEdit::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	CWnd* pParent = GetParent();		//获取控件的父窗口
	m_spin.Create(UDS_ALIGNRIGHT | UDS_ARROWKEYS | UDS_HOTTRACK | UDS_SETBUDDYINT | WS_VISIBLE, CRect(), pParent, SPIN_ID);	//创建微调控件
	m_spin.SetBuddy(this);			//设置Edit控件为关联控件
	m_spin.SetRange(0, 999);		//设置默认范围

	CEdit::PreSubclassWindow();
}
