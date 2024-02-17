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
    
    

	bool init(GJGameLevel* level, bool* p1) {
		if(!LevelInfoLayer::init(level, p1))
			return false;
        
        auto obj = static_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("player-username")->getChildByID("player-username")->getChildren()->objectAtIndex(0));
        std::string objString(obj->getString());
        
        // log for debug
        log::info("Username of Level Creator is: {}", objString.substr(0,3));

        if(static_cast<std::string>(GJAccountManager::get()->m_username) != objString.substr(0,3)) 
            return true;

		auto value = Mod::get()->getSettingValue<std::string>("thename");
        
    	log::info("passed username check!");
		
		return true;
	}
};