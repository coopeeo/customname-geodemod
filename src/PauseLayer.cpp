#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/binding/PauseLayer.hpp>

using namespace geode::prelude;

vector<string> splitString(const string& s, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end;
    while ((end = s.find(delimiter, start)) != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

class $modify(PauseLayer) {
    static void onModify(auto& self) {
        self.setHookPriority("PauseLayer::create", -110);
    }

    static PauseLayer* create(bool p0) {
        auto dathing = PauseLayer::create(p0);
        
        if (!Loader::get()->isModLoaded("tpdea.betterpause-Better")) return dathing;

        auto mainObj = dathing->getChildByID("better-pause-node");
        if (mainObj == nullptr) {log::info("Failed to move on because \"better-pause-node\" doesnt exist PauseLayer"); return dathing;}
        
        auto creatorname = mainObj->getChildByID("creator-name");
        if (creatorname == nullptr) {log::info("Failed to move on because \"creator-name\" doesnt exist in \"better-pause-node\" -> PauseLayer"); return dathing;}

        auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname);

        std::string objString(obj->getString());

        auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

        Utils* utils = Utils::get();

        if(utils->dnInstalled() && static_cast<std::string>(GJAccountManager::get()->m_username) == objString.substr(3,-1)){
            auto value = Mod::get()->getSettingValue<std::string>("thename");

            obj->setString(fmt::format("By {}", value).c_str());
        }
        return dathing;
	}
};