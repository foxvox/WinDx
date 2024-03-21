#pragma once
#include <d3d9.h>
#include <d3dx9.h> 
#include <d3dx9math.h> 

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class Axis
{
private:
	LPDIRECT3DDEVICE9 m_pd3dDevice; 
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 

public:
	Axis();
	~Axis(); 
	void OnInit(LPDIRECT3DDEVICE9 pd3dDevice); 
	void OnRender();
	void OnRelease(); 
};

