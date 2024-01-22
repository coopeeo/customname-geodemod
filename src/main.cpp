#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if(!MenuLayer::init())
			return false;

		auto value = Mod::get()->getSettingValue<std::string>("thename");
    		static_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("player-username"))->setString(value.c_str());
		
		
		return true;
	}
};
