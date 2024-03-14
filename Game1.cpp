#include "Game1.h"

void Game1::OnInit()
{
	m_Triangle.OnInit(m_pd3dDevice); 
}

void Game1::OnUpdate()
{
}

void Game1::OnRender()
{
	m_Triangle.OnRender(); 
}

void Game1::OnRelease()
{
	m_Triangle.OnRelease(); 
}

