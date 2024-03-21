#include "Axis.h" 

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

Axis::Axis()
{
}

Axis::~Axis()
{
}

void Axis::OnInit(LPDIRECT3DDEVICE9 pd3dDevice)
{
	m_pd3dDevice = pd3dDevice;

	CUSTOMVERTEX vertices[] =
	{
		{-3.0f, 0.0f, 0.0f, D3DCOLOR_RGBA(255, 0, 0, 255)}, 
		{ 3.0f, 0.0f, 0.0f, D3DCOLOR_RGBA(255, 0, 0, 255)},

		{0.0f, -3.0f, 0.0f, D3DCOLOR_RGBA(0, 255, 0, 255)},
		{0.0f,  3.0f, 0.0f, D3DCOLOR_RGBA(0, 255, 0, 255)},

		{0.0f, 0.0f, -3.0f, D3DCOLOR_RGBA(0, 255, 255, 255)},
		{0.0f, 0.0f,  3.0f, D3DCOLOR_RGBA(0, 255, 255, 255)}
	}; 

	m_pd3dDevice->CreateVertexBuffer(sizeof(CUSTOMVERTEX) * 6, 0, D3DFVF_CUSTOMVERTEX,
		D3DPOOL_DEFAULT, &m_pVB, NULL);

	VOID* pVertices;
	m_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0);
	memcpy(pVertices, vertices, sizeof(vertices));
	m_pVB->Unlock();
}

void Axis::OnRender()
{
	D3DXMATRIX matWorld; 
	D3DXMatrixIdentity(&matWorld); 
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE); 
	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(CUSTOMVERTEX));
	m_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld); 
	m_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, 0, 3);
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, TRUE); 
}

void Axis::OnRelease()
{
	if (m_pVB != NULL)
		m_pVB->Release();
}
