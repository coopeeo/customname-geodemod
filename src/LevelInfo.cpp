#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/binding/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LevelInfoLayer) {

	bool init(GJGameLevel* p0, bool p1) {
		if(!LevelInfoLayer::init(p0, p1))
			return false;

        Utils* utils = Utils::get();

		if (!utils->dnInstalled()) {
            auto obj = static_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("creator-info-menu")->getChildByID("creator-name")->getChildren()->objectAtIndex(0));
            
            std::string objString(obj->getString());
            
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

            if(static_cast<std::string>(GJAccountManager::get()->m_username) != objString.substr(3,-1)) {
                return true;
            }

            auto value = Mod::get()->getSettingValue<std::string>("thename");

            obj->setString(fmt::format("By {}", value).c_str());
            }
		return true;
	}
};