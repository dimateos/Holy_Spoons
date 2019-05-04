#include "BulletHittable.h"
#include "LogSystem.h"

#include "MessageSystem.h"

//at some point move to json
std::map<string, int> BulletHittable::bulletDamages_ = { {"bBullets0", 10}, {"pBullets0", 50} };

void BulletHittable::setUp() {
	maxHitPoints_ = hitPoints_ = FINDnRETURN(cfg_, "hp", int, 0);
	valuePoints_ = FINDnRETURN(cfg_, "points", int, 50);
}

void BulletHittable::onCollision(ID * other) {
	//find the damage value of the impacted bullet
	if (bulletDamages_.find(other->group_) != bulletDamages_.end())
		if (owner_->isActive() && hitPoints_ > 0) {
			hitPoints_ -= bulletDamages_.at(other->group_);
			MessageSystem::getSingleton()->sendMessageGroup(&Message(ENEMY_DAMAGE), "manage_gameObjects");
		}

	//check death
	if (hitPoints_ <= 0) {
		owner_->setActive(false);
		MessageSystem::getSingleton()->sendMessageGroup(&Msg_ADD_SCORE(valuePoints_), "manage_gameObjects");
	}
}

void BulletHittable::configActive()
{
	hitPoints_ = maxHitPoints_;
}

#include "GOFactory.h"
REGISTER_TYPE(BulletHittable);
