#pragma once
#include <d3d9.h>
#include <d3dx9.h> 
#include <d3dx9math.h> 

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

