#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/binding/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	/*static void onModify(auto& self) {
        self.setHookPriority("MenuLayer::init", -2); // try to fix with BetterMenu
    }*/
    // creator info menu
    // creator name
    // then in that is a CCLabelBMFont
    
    

	bool init(GJGameLevel* p0, bool p1) {
        log::info("init called!");
		if(!LevelInfoLayer::init(p0, p1))
			return false;
        
        auto obj = static_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("creator-info-menu")->getChildByID("creator-name")->getChildren()->objectAtIndex(0));
        std::string objString(obj->getString());
        auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);
        // log for debug
        log::info("Username of Level Creator is: [start]{}[end]", objString.substr(3,-1));
        log::info("Username of Current Account is: [start]{}[end]", accountname);

        if(static_cast<std::string>(GJAccountManager::get()->m_username) != objString.substr(0,3)) 
            log::info("didnt pass username check");
            return true;

		auto value = Mod::get()->getSettingValue<std::string>("thename");
        
    	log::info("passed username check!");
		
		return true;
	}
};