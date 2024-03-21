#include "Game1.h"

void Game1::OnInit()
{
	RECT rect;
	D3DVIEWPORT9 vp;
	GetClientRect(m_hWnd, &rect); 

	vp.X		= 0; 
	vp.Y		= 0; 
	vp.Width	= rect.right - rect.left; 
	vp.Height	= rect.bottom - rect.top; 
	vp.MinZ		= 0.0f; 
	vp.MaxZ		= 1.0f; 

	m_Eye.x = 5.0f; 
	m_Eye.y = 8.0f;
	m_Eye.z = -10.0f; 

	m_At.x = 0.0f; 
	m_At.y = 0.0f; 
	m_At.z = 0.0f;

	m_Up.x = 0.0f;
	m_Up.y = 1.0f;
	m_Up.z = 0.0f; 

	D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
	m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 1.0f, 1.0f, 3.5f); 
	m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj); 
	m_pd3dDevice->SetViewport(&vp); 

	m_Axis.OnInit(m_pd3dDevice);
}

void Game1::OnUpdate()
{
}

void Game1::OnRender()
{
	m_Axis.OnRender(); 
	 
}

void Game1::OnRelease()
{
	m_Axis.OnRelease(); 
}

Game1::Game1()
{	 
}

Game1::~Game1()
{
}

