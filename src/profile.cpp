#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
	 bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

		if (ownProfile)
		{
			auto value = Mod::get()->getSettingValue<std::string>("thename");
    		m_usernameLabel->setString(value.c_str());
		}
		
		return true;
	}
};