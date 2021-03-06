#include "TinyWindow.h"

using namespace TinyWindow;
void handleKeyPresses(unsigned int key, keyState_t keyState)
{
	if(keyState == keyState_t::down)
	{
		printf("%c \t", key);
	}
}

int main()
{
	windowManager* manager = new windowManager();
	tWindow* window = nullptr;

	window = manager->AddWindow("Example");
	window->keyEvent = handleKeyPresses;

	while (!window->shouldClose)
	{
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		manager->PollForEvents();// or WaitForEvents
		
		//manager->MakeWindowCurrentContext(window);
		window->SwapDrawBuffers();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	manager->ShutDown();
	return 0;
}
