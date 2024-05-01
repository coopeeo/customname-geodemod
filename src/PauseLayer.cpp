#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/binding/PauseLayer.hpp>
#include <Geode/binding/GJAccountManager.hpp>

using namespace geode::prelude;

class $modify(PauseLayer) {
    static void onModify(auto& self) {
        self.setHookPriority("PauseLayer::create", -110);
    }

    static PauseLayer* create(bool p0) {
        auto dathing = PauseLayer::create(p0);
        
        if (!Loader::get()->isModLoaded("tpdea.betterpause-Better")) return dathing;

        Mod* betterpause = Loader::get()->getLoadedMod("tpdea.betterpause-Better");
        bool ratingtextsetting = !betterpause->getSettingValue<bool>("disable-rating-plus-label");
        bool ratingiconsetting = !betterpause->getSettingValue<bool>("disable-icon-rating-plus-label");

        auto mainObj = dathing->getChildByID("better-pause-node");
        if (mainObj == nullptr) {log::info("Failed to move on because \"better-pause-node\" doesnt exist PauseLayer"); return dathing;}
        
        auto creatorname = mainObj->getChildByID("creator-name");
        if (creatorname == nullptr) {log::info("Failed to move on because \"creator-name\" doesnt exist in \"better-pause-node\" -> PauseLayer"); return dathing;}

        auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname);

        std::string objString(obj->getString());

        auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

        Utils* utils = Utils::get();

        if(!utils->dnInstalled() && accountname == objString.substr(3,accountname.size())){
            auto value = Mod::get()->getSettingValue<std::string>("thename");
            if (ratingtextsetting) {
                auto split = utils->splitString(objString, " | ");
                obj->setString(fmt::format("By {} | {}", value, split[1]).c_str());
                if (ratingiconsetting) {
                    static_cast<CCNode*>(mainObj->getChildren()->objectAtIndex(5))->setPosition({ 87.f + obj->getContentSize().width * obj->getScale() + 10.f, cocos2d::CCDirector::sharedDirector()->getWinSize().height - 18.f });
                }
            } else {
                obj->setString(fmt::format("By {}", value).c_str());
            }
        }
        return dathing;
	}
};
