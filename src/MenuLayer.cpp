#include "utils.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/binding/FLAlertLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	static void onModify(auto& self) {
        self.setHookPriority("MenuLayer::init", -2); // fix with BetterMenu
    }
    
	bool init() {
		if(!MenuLayer::init())
			return false;

		Utils* utils = Utils::get();

		if (utils->dnInstalled()) {
			if (utils->getLaunch() && utils->nameTransfered()) {
				FLAlertLayer::create(
					"Custom Name Notice",
					"Your name has already transferred to the Display Names mod. The Display Names mod is replacing Custom Name (this mod will still function if Display Names is disabled/not installed).",
					"OK"
				)->show();
				utils->afterLaunch();
			}
		} else {
			auto value = Mod::get()->getSettingValue<std::string>("thename");
    		static_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("player-username"))->setString(value.c_str());
		}
		
		return true;
	}
};
