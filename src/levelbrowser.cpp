#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(LevelBrowserLayer) {
    
    

	bool init(GJGameLevel* p0, bool p1) {
		if(!LevelBrowserLayer::init(p0, p1))
			return false;
        
        
        auto theContent = this->getChildren()->objectAtIndex(2)->getChildren()->objectAtIndex(0)->getChildren()->objectAtIndex(0)->getChildren()->objectAtIndex(0);
        auto theContentChildren = theContent->getChildren();
        for (size_t i = 0; i < theContent->getChildrenCount(); i++)
        {
            auto mainObj = theContentChildren->objectAtIndex(i)->getChildByID("main-layer");

            auto obj = static_cast<cocos2d::CCLabelBMFont*>(mainObj->getChildByID("main-menu")->getChildByID("creator-name")->getChildren()->objectAtIndex(0));
            std::string objString(obj->getString());
            auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

            if(static_cast<std::string>(GJAccountManager::get()->m_username) != objString.substr(3,-1)) return;

            auto value = Mod::get()->getSettingValue<std::string>("thename");

            obj->setString(fmt::format("By {}", value).c_str());
            
        }
        
        return true;
	}
};