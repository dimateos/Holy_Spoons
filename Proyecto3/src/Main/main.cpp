#include <iostream>
#include <RenderSystemManager.h>

int main(int argc, char *argv[])
{
	RenderSystemManager* renderInterface = RenderSystemManager::getSingleton();
	renderInterface->shutdown();
	return 0;
}
