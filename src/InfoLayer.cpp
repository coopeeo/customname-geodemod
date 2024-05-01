#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/binding/InfoLayer.hpp>

using namespace geode::prelude;

class $modify(InfoLayer) {
    /*static void onModify(auto& self) {
        self.setHookPriority("LevelBrowserLayer::updateLevelsLabel", -2);
    }*/

    bool init(GJGameLevel* p0, GJUserScore* p1, GJLevelList* p2) {
        InfoLayer::init(p0,p1,p2);
        Utils* utils = Utils::get();

		if (!utils->dnInstalled()) {
            auto mainObj = static_cast<cocos2d::CCLayer*>(this->getChildren()->objectAtIndex(0));
            if (mainObj == nullptr) {log::info("Failed to move on because \"the CCLayer in InfoLayer (index 0)\" doesnt exist InfoLayer"); return true;}
            auto profilename = static_cast<CCLabelBMFont*>(mainObj->getChildByID("title-label"));
            if (profilename != nullptr) {
                std::string objString(profilename->getString());
                auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
                if(accountname == objString.substr(0,accountname.length())){

                    auto value = Mod::get()->getSettingValue<std::string>("thename");

                    profilename->setString(fmt::format("{}'s comments", value).c_str());
                }
            }
            auto menuStuff = mainObj->getChildByID("main-menu");
            if (menuStuff == nullptr) {log::info("Failed to move on because \"main-menu\" doesnt exist in \"the CCLayer in InfoLayer (index 0)\" -> InfoLayer"); return true;}
            auto creatorname = menuStuff->getChildByID("creator-button");
            if (creatorname == nullptr) {log::info("Failed to move on because \"creator-button\" doesnt exist in \"main-menu\" -> \"the CCLayer in InfoLayer (index 0)\" -> InfoLayer"); return true;}

            auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
            std::string objString(obj->getString());
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
            if(static_cast<std::string>(GJAccountManager::get()->m_username) != objString.substr(3,-1)) 
                return true;

            auto value = Mod::get()->getSettingValue<std::string>("thename");

            obj->setString(fmt::format("By {}", value).c_str());
        }
        return true;
	}
};