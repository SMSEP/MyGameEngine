#include "BaseApplication.hpp"

int My::BaseApplication::Initialize()
{
	m_bQuit = false;
	return 0;
}

int My::BaseApplication::Finalize()
{
	
}

void My::BaseApplication::Tick()
{
	
}

bool My::BaseApplication::IsQuit()
{
	return m_bQuit;
}
