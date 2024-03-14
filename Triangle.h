#pragma once 

// #include <d3dx9.h> 
#include <d3d9.h> 

struct CUSTOMVERTEX
{
	FLOAT x, y, z, rhw;
	DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class Triangle
{
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 
	LPDIRECT3DDEVICE9 m_pd3dDevice; 

public:
	void OnInit(LPDIRECT3DDEVICE9 pd3dDevice);
	void OnUpdate();
	void OnRender();
	void OnRelease();
};

