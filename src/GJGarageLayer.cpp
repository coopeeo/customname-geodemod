#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(GJGarageLayer) {
	bool init() {
	    if(!GJGarageLayer::init())
            return false;

		Utils* utils = Utils::get();

		if (!utils->dnInstalled()) {
			auto value = Mod::get()->getSettingValue<std::string>("thename");
			static_cast<cocos2d::CCTextFieldTTF*>(this->getChildByID("username-label")->getChildren()->objectAtIndex(0))->setString(value.c_str());
		}
		return true;
	}
};