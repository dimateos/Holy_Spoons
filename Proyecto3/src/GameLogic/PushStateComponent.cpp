#include "PushStateComponent.h"

#include "GameStateMachine.h"
#include <RenderSystemInterface.h>
#include "OverlayComponent.h"
#include <PhysicsSystemManager.h>

void PushStateComponent::setUp()
{
	if (isInited()) return;
	setInited();

	string keycode = this->getCfg()["key"];

	if (keycode == "esc") {
		key = SDLK_ESCAPE; //cant read special chars
	}
	else {
		key = SDL_Keycode(keycode[0]);
	}

	state = this->getCfg()["state"];
	json = this->getCfg()["json"];
}

bool PushStateComponent::handleEvents(GameObject * o, const SDL_Event & evt)
{
	if (evt.type == SDL_KEYDOWN) {
		if (evt.key.keysym.sym == key) {
			//cambio de rendering target
			static_cast<OverlayComponent*>(this->getOwner()->getComponent("canvas"))->hideOverlay();
			RenderSystemInterface::getSingleton()->setRenderingScene(state);

			//pause/unpause physics
			PhysicsSystemManager::getSingleton()->pausePhysics(state != mainGameState);

			//cambio de estado
			GameState* s = GameStateMachine::getSingleton()->loadLevel(json); //CANT BE READ IT IN CONSTRUCTOR, POPSTATE DELETES IT
			//GameState* s = new GameState(new nap_transform(nap_vector3(10, 0, 10)));
			GameStateMachine::getSingleton()->pushState(s);

			//agregarle objetos
			//...
			return true;
		}
	}

	return false;
}

#include "GOFactory.h"
REGISTER_TYPE(PushStateComponent);
