#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelCell.hpp>
#include <Geode/binding/LevelCell.hpp>

using namespace geode::prelude;

class $modify(LevelCell) {
    /*static void onModify(auto& self) {
        self.setHookPriority("LevelBrowserLayer::updateLevelsLabel", -2);
    }*/

    void loadCustomLevelCell() {
        LevelCell::loadCustomLevelCell();
        
        Utils* utils = Utils::get();
        
        auto mainObj = this->getChildByID("main-layer");
        if (mainObj == nullptr) {log::warn("Failed to move on because \"main-layer\" doesnt exist LevelCell"); return;}
        auto menuStuff = mainObj->getChildByID("main-menu");
        if (menuStuff == nullptr) {log::warn("Failed to move on because \"main-menu\" doesnt exist in \"main-layer\" -> LevelCell"); return;}
        auto creatorname = menuStuff->getChildByID("creator-name");
        if (creatorname == nullptr) {log::warn("Failed to move on because \"creator-name\" doesnt exist in \"main-menu\" -> \"main-layer\" -> LevelCell"); return;}
        if (!utils->dnInstalled()) {
            auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
            std::string objString(obj->getString());
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
            if (this->m_compactView) {
                if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString){
                    auto value = Mod::get()->getSettingValue<std::string>("thename");

                    obj->setString(value.c_str());
                }
            } else {
                if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString.substr(3,-1)){
                    auto value = Mod::get()->getSettingValue<std::string>("thename");

                    obj->setString(fmt::format("By {}", value).c_str());
                }
            }
        }
	}
};