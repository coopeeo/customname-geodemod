#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/binding/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(PauseLayer) {
    static void onModify(auto& self) {
        self.setHookPriority("PauseLayer::create", -100);
    }

    void create(bool p0) {
        PauseLayer::create(p0);
        // log::debug("loadFromComment() function called! Running Custom Name!");
        
        if (!Loader::get()->isModLoaded("tpdea.betterpause-Better")) return true;

        auto mainObj = this->getChildByID("better-pause-node");
        if (mainObj == nullptr) {log::info("Failed to move on because \"better-pause-node\" doesnt exist PauseLayer"); return true;}
        auto creatorname = mainObj->getChildByID("creator-name");
        if (creatorname == nullptr) {log::info("Failed to move on because \"creator-name\" doesnt exist in \"better-pause-node\" -> PauseLayer"); return true;}

        auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
        std::string objString(obj->getString());
        auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
        if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString.substr(3,-1)){
            auto value = Mod::get()->getSettingValue<std::string>("thename");

            obj->setString(fmt::format("By {}", value).c_str());
        }
        return true;
	}
};