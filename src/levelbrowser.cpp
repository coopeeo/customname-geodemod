#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(LevelBrowserLayer) {
    
    

    bool init(GJSearchObject* p0) {
		if(!LevelBrowserLayer::init(p0))
			return false;
        
        // auto theContent = p0;
        auto theContent3 = static_cast<cocos2d::CCNode*>(this->getChildren()->objectAtIndex(2));
        auto theContent2 = static_cast<cocos2d::CCNode*>(theContent3->getChildren()->objectAtIndex(0));
        auto theContent1 = static_cast<cocos2d::CCNode*>(theContent2->getChildren()->objectAtIndex(0));
        auto theContent = static_cast<cocos2d::CCNode*>(theContent1->getChildren()->objectAtIndex(0));
        auto theContentChildren = theContent->getChildren();
        for (size_t i = 0; i < theContent->getChildrenCount(); i++)
        {
            auto mainObj = static_cast<CCNode*>(theContentChildren->objectAtIndex(i))->getChildByID("main-layer");

            auto creatorname = mainObj->getChildByID("main-menu")->getChildByID("creator-name");
            if (creatorname != nullptr) {
                auto obj = static_cast<cocos2d::CCLabelBMFont*>(creatorname->getChildren()->objectAtIndex(0));
                std::string objString(obj->getString());
                auto accountname = static_cast<std::string>(GJAccountManager::get()->m_username);

                if(static_cast<std::string>(GJAccountManager::get()->m_username) == objString.substr(3,-1)){
                    auto value = Mod::get()->getSettingValue<std::string>("thename");

                    obj->setString(fmt::format("By {}", value).c_str());
                }

            }
            
        }
        return true;
	}
};