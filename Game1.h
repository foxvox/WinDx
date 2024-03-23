#pragma once
#include "D3DApp.h"

class Game1 : public D3DApp 
{
private:
	D3DXMATRIX				m_matView; 
	D3DXMATRIX				m_matProj; 
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 	
	D3DXVECTOR3				m_Eye, m_At, m_Up; 

	LPD3DXFONT				m_pFont;
	DWORD					m_dwElapsedTime; 
	unsigned int			m_nFPS, m_nFPSCount; 

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	Game1();
	~Game1();
};

