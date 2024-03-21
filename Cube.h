#pragma once
#include <d3d9.h> 

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

class Cube
{
private:
	LPDIRECT3DDEVICE9 m_pd3dDevice;
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 
	LPDIRECT3DINDEXBUFFER9 m_pIB; 

public:
	void OnInit(LPDIRECT3DDEVICE9 pd3dDevice); 
	void OnRender();
	void OnRelease(); 

	Cube(); 
	~Cube(); 
};

