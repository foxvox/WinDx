#pragma once
#include "D3DApp.h"
#include "Axis.h" 
#include "Cube.h" 

class Game1 : public D3DApp 
{
private:
	D3DXMATRIX m_matView; 
	D3DXMATRIX m_matProj; 
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 
	
	D3DXVECTOR3 m_Eye, m_At, m_Up; 
	Axis m_Axis; 	
	Cube m_Cube; 

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	Game1();
	~Game1();
};

