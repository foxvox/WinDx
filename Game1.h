#pragma once
#include "D3DApp.h"
#include "Axis.h" 

class Game1 : public D3DApp 
{
private:
	D3DXMATRIX m_matView; 
	D3DXMATRIX m_matProj; 
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 
	
	D3DXVECTOR3 m_Eye, m_At, m_Up; 
	Axis m_Axis; 	
	
	LPD3DXMESH m_pBoxMesh; 
	LPD3DXMESH m_pSphereMesh; 
	LPD3DXMESH m_pTeapotMesh;
	LPD3DXMESH m_pCylinderMesh;

	float m_fScale; 

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	Game1();
	~Game1();
};

