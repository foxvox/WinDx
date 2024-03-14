#pragma once
#include "D3DApp.h"
#include "Triangle.h" 

class Game1 : public D3DApp 
{
private:
	Triangle m_Triangle; 
	LPDIRECT3DVERTEXBUFFER9 m_pVB; 

	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	Game1() {} 
	~Game1() {} 
};

