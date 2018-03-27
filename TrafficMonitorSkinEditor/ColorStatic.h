#pragma once


// CColorStatic
#define WM_STATIC_CLICKED (WM_USER + 1001)

class CColorStatic : public CStatic
{
	DECLARE_DYNAMIC(CColorStatic)

public:
	CColorStatic();
	virtual ~CColorStatic();

	void SetFillColor(COLORREF fill_color);		//����Ҫ���ı���ɫ
	void SetLinkCursor(bool link_cursor = true);		//����ָ��ؼ�ʱ����ɳ�������״

protected:
	COLORREF m_fill_color{ RGB(255, 255,255) };
	bool m_hover{ false };		//�����ָ��ؼ�ʱΪtrue
	bool m_link_cursor{ false };	//�Ƿ����ó�������״�Ĺ��

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual void PreSubclassWindow();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

