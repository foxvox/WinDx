#include "Ground.h" 

struct GROUNDVERTEX
{
	D3DXVECTOR3 vPos; 
	DWORD		dwDiffuse; 
};

#define D3DFVF_GROUNDVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE) 

void Ground::Create(LPDIRECT3DDEVICE9 pd3dDevice, int nRow = 20, int nCol = 20, float fSize = 0.5f)
{
	m_nCol = nCol; 
	m_nRow = nRow; 

	m_dwNumVertices = (m_nCol + 1) * (m_nRow + 1); 
	m_dwNumIndices = m_nCol * m_nRow * 6; 
	m_pd3dDevice = pd3dDevice; 

	GROUNDVERTEX* pGroundVertex = new GROUNDVERTEX[m_dwNumVertices]; 

	int nIndex = 0; 
	D3DXVECTOR3 vPos0(-1.0f * m_nCol * fSize * 0.5f, 0.0f, m_nRow * fSize * 0.5f); 
	for (int z = 0; z <= m_nRow; z++)
	{
		for (int x = 0; x <= m_nCol; x++)
		{
			pGroundVertex[nIndex].vPos.x = vPos0.x + fSize * x; 
			pGroundVertex[nIndex].vPos.y = 0.0f; 
			pGroundVertex[nIndex].vPos.z = vPos0.z + (-1.0f) * (fSize * z); 
			pGroundVertex[nIndex].dwDiffuse = D3DCOLOR_RGBA(255, 255, 255, 255); 
			nIndex++; 
		}
	}

	if (m_pd3dDevice->CreateVertexBuffer(m_dwNumVertices * sizeof(GROUNDVERTEX), 0,
		D3DFVF_GROUNDVERTEX, D3DPOOL_DEFAULT, &m_pVB, NULL) != D3D_OK)
	{
		MessageBox(NULL, L"정점버퍼 생성 Error", L"Error", MB_OK); 
		return; 
	}

	void* pVertices; 
	if (m_pVB->Lock(0, 0, &pVertices, NULL) != D3D_OK)
	{
		MessageBox(NULL, L"정점버퍼 Lock Error", L"Error", MB_OK); 
		return; 
	}

	memcpy(pVertices, pGroundVertex, m_dwNumVertices * sizeof(GROUNDVERTEX)); 
	m_pVB->Unlock(); 

	WORD* pIndex = new WORD[m_dwNumIndices];

	nIndex = 0; 
	for (int z = 0; z < m_nRow; z++)
	{
		for (int x = 0; x < m_nCol; x++)
		{
			pIndex[nIndex++] = WORD(z * (m_nCol + 1) + x);
			pIndex[nIndex++] = WORD((z + 1) * (m_nCol + 1) + x + 1); 
			pIndex[nIndex++] = WORD((z + 1) * (m_nCol + 1) + x); 

			pIndex[nIndex++] = WORD(z * (m_nCol + 1) + x);
			pIndex[nIndex++] = WORD(z * (m_nCol + 1) + x + 1);
			pIndex[nIndex++] = WORD((z + 1) * (m_nCol + 1) + x + 1);
		}		
	}

	void* pIndices; 
	m_pd3dDevice->CreateIndexBuffer(m_dwNumIndices * sizeof(WORD), 0, D3DFMT_INDEX16, 
		D3DPOOL_DEFAULT, &m_pIB, NULL); 

	m_pIB->Lock(0, 0, (void**)&pIndices, 0);
	memcpy(pIndices, pIndex, sizeof(WORD) * m_dwNumIndices);
	m_pIB->Unlock();

	delete[] pIndex; 
	delete[] pGroundVertex; 
}

void Ground::OnRender()
{
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);

	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(GROUNDVERTEX));
	m_pd3dDevice->SetIndices(m_pIB); 
	m_pd3dDevice->SetFVF(D3DFVF_GROUNDVERTEX);	
	m_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_dwNumVertices, 0, m_dwNumIndices);
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}

void Ground::OnRelease()
{
}

Ground::Ground()
{
	m_dwNumVertices = 0; 
	m_dwNumIndices = 0; 
	m_pIB = NULL;
	m_pVB = NULL;
	m_pd3dDevice = NULL;
	m_nCol = 0; 
	m_nRow = 0;
}

Ground::~Ground()
{
}
