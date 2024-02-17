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
        log::debug("loaded!!!!!!!!!!!!!!!!!!!!!");
        
        
        auto mainObj = this->getChildByID("main-layer");

        auto creatorname = mainObj->getChildByID("main-menu")->getChildByID("creator-name");
        if (creatorname != nullptr) {
            auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
            std::string objString(obj->getString());
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

            if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString.substr(3,-1)){
                auto value = Mod::get()->getSettingValue<std::string>("thename");

                obj->setString(fmt::format("By {}", value).c_str());
            }

        }
	}
};