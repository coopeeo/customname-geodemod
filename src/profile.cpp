#include <Geode/loader/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>

static geode::Loader* get();

using namespace geode::prelude;

class $modify(ProfilePage) {
	/*static void onModify(auto& self) {
			self.setHookPriority("ProfilePage::init", -1); // try to fix with BetterInfo
	}*/

	 void loadPageFromUserInfo(GJUserScore* user) {
        // if (!ProfilePage::init(accountID, ownProfile)) return false;

			auto value = Mod::get()->getSettingValue<std::string>("thename");
    		// m_usernameLabel->setString(value.c_str());
			if (Loader::get()->isModLoaded("cvolton.betterinfo")) {
				typeinfo_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("cvolton.betterinfo/username-button")->getChildren()->objectAtIndex(0))->setString(value.c_str()); //honestly i have no clue lol
			}
		
	}
};