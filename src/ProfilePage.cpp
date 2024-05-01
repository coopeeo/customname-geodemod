#include "utils.hpp"
#include <Geode/loader/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>
#include <Geode/binding/GJAccountManager.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
    static void onModify(auto& self) {
        self.setHookPriority("ProfilePage::loadPageFromUserInfo", -1);

        if (Loader::get()->isModLoaded("cvolton.betterinfo"))
            self.setHookPriority("ProfilePage::init", -1);
    }

    // Non-BetterInfo way
    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

        auto isOwnProfile = ownProfile || (GJAccountManager::get()->m_username.c_str() == m_usernameLabel->getString());
        
        Utils* utils = Utils::get();

        if (!utils->dnInstalled() && isOwnProfile) {
            auto value = Mod::get()->getSettingValue<std::string>("thename");
            m_usernameLabel->setString(value.c_str());
        }

        return true;
    }
    
    // BetterInfo way
    void loadPageFromUserInfo(GJUserScore* user) {
        ProfilePage::loadPageFromUserInfo(user);

        auto isOwnProfile = m_ownProfile || (GJAccountManager::get()->m_username.c_str() == m_usernameLabel->getString());

        Utils* utils = Utils::get();

        auto value = Mod::get()->getSettingValue<std::string>("thename");

		if (!utils->dnInstalled() && Loader::get()->isModLoaded("cvolton.betterinfo") && isOwnProfile) {
			static_cast<cocos2d::CCLabelBMFont*>(this->getChildByIDRecursive("main-menu")->getChildByID("cvolton.betterinfo/username-button")->getChildren()->objectAtIndex(0))->setString(value.c_str());
		};
    };
};
