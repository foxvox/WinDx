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

	m_Eye.x = 10.0f; 
	m_Eye.y = 5.0f;
	m_Eye.z = -10.0f; 

	m_At.x = 0.0f; 
	m_At.y = 0.0f; 
	m_At.z = 0.0f;

	m_Up.x = 0.0f;
	m_Up.y = 1.0f;
	m_Up.z = 0.0f; 

	D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
	m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 1.0f, -8.0f, 8.0f); 
	m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj); 
	m_pd3dDevice->SetViewport(&vp); 

	m_Axis.OnInit(m_pd3dDevice);
	D3DXCreateTeapot(m_pd3dDevice, &m_pTeapotMesh, NULL);  	

	m_fScale = 1.0f; 
} 

void Game1::OnUpdate()
{
	if (GetAsyncKeyState('A') < 0)
		m_fScale += 0.1f; 

	if (GetAsyncKeyState('D') < 0)
		m_fScale -= 0.1f; 
}

void Game1::OnRender()
{
	D3DXMATRIX matTranslation; 

	m_Axis.OnRender(); 	

	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	D3DXMatrixTranslation(&matTranslation, 2.5f, 0.0f, 2.0f); 
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matTranslation);
	m_pTeapotMesh->DrawSubset(0); 	
}

void Game1::OnRelease()
{
	m_pTeapotMesh->Release();	
	m_Axis.OnRelease(); 	
}

Game1::Game1()
{
	m_pVB = NULL;
	m_pBoxMesh = NULL;
	m_pSphereMesh = NULL;
	m_pTeapotMesh = NULL;
	m_pCylinderMesh = NULL; 
	m_fScale = 1.0f; 
}

Game1::~Game1()
{
}

