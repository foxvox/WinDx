#include "Cube.h"

void Cube::OnInit(LPDIRECT3DDEVICE9 pd3dDevice)
{
	m_pd3dDevice = pd3dDevice;

	CUSTOMVERTEX vertices[] =
	{
		{D3DXVECTOR3(-1.0f, 1.0f,  1.0f), D3DCOLOR_RGBA(255, 0, 255, 255)},
		{D3DXVECTOR3( 1.0f, 1.0f,  1.0f), D3DCOLOR_RGBA(0, 255, 0, 255)},
		{D3DXVECTOR3( 1.0f, 1.0f, -1.0f), D3DCOLOR_RGBA(0, 0, 255, 255)},
		{D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DCOLOR_RGBA(255, 255, 0, 255)},

		{D3DXVECTOR3(-1.0f, -1.0f,  1.0f), D3DCOLOR_RGBA(255, 0, 255, 255)},
		{D3DXVECTOR3( 1.0f, -1.0f,  1.0f), D3DCOLOR_RGBA(0, 255, 0, 255)},
		{D3DXVECTOR3( 1.0f, -1.0f, -1.0f), D3DCOLOR_RGBA(0, 0, 255, 255)},
		{D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DCOLOR_RGBA(255, 255, 0, 255)}
	};

	WORD Indices[] =
	{
		0, 1, 2,
		1, 2, 3,
		4, 6, 5,
		4, 7, 6,
		0, 3, 7,
		0, 7, 4,
		1, 5, 6,
		1, 6, 2,
		3, 2, 6,
		3, 6, 7,
		0, 4, 5,
		0, 5, 1
	}; 

	m_pd3dDevice->CreateVertexBuffer(sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX,
		D3DPOOL_DEFAULT, &m_pVB, NULL);

	VOID* pVertices;
	m_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0);
	memcpy(pVertices, vertices, sizeof(vertices));
	m_pVB->Unlock();
}

void Cube::OnRender()
{
}

void Cube::OnRelease()
{
}

Cube::Cube() 	 
{
	m_pd3dDevice = NULL;
	m_pVB = NULL;
	m_pIB = NULL; 
}

Cube::~Cube()
{
}
