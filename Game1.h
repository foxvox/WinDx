#pragma once
#include "D3DApp.h"

struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw; 
	DWORD color; 
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class Game1 : public D3DApp 
{
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	Game1() {} 
	~Game1() {} 
};

