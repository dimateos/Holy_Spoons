#ifndef BASICPOSTPROCESSINGCOMPONENT_H_
#define BASICPOSTPROCESSINGCOMPONENT_H_

#include "Component.h"

class BasicPostProcessingComponent: public Component
{
private:
	std::string compositorName;

public:
	virtual ~BasicPostProcessingComponent() {};
	BasicPostProcessingComponent(nap_json const & cfg, GameObject* owner) : Component(cfg, owner) {};

	virtual void setUp();

	void setPostProcessingEnabled(bool enabled);

	std::string getCompositorName();

	void setCompositorName(std::string name);

	//this will probably need a "receive" method -> set enabled/disabled the compositor
};

#endif //BASICPOSTPROCESSINGCOMPONENT_H_