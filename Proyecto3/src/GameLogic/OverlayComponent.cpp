#include "OverlayComponent.h"
#include <OgreOverlayManager.h>
#include <OgreOverlayContainer.h>
#include <OgreOverlay.h>

void OverlayComponent::setUp()
{
	overlay = Ogre::OverlayManager::getSingleton().getByName(cfg_["overlay_name"]);
	panel = overlay->getChild(cfg_["panel_container"]);

	// Show the overlay
	showOverlay();
}

void OverlayComponent::setDown()
{
	Ogre::OverlayManager::getSingletonPtr()->destroyOverlayElement(panel);
	Ogre::OverlayManager::getSingletonPtr()->destroy(overlay);
}

void OverlayComponent::hideOverlay()
{
	overlay->hide();
}

void OverlayComponent::showOverlay()
{
	overlay->show();
}