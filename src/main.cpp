#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if(!MenuLayer::init())
			return false;
    
    		static_cast<cocos2d::CCLabelBMFont>(this->getChildByID("player-username"))->setString();
		
		
		return true;
	}
};
