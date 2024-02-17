#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(LevelBrowserLayer) {
    
    

	void loadLevelsFinished(cocos2d::CCArray* p0,const char* p1, int p2) {
	    LevelBrowserLayer::loadLevelsFinished(p0, p1, p2);
        
        auto theContent = p0;
        // auto theContent3 = static_cast<cocos2d::CCNode*>(this->getChildren()->objectAtIndex(2));
        // auto theContent2 = static_cast<cocos2d::CCNode*>(theContent3->getChildren()->objectAtIndex(0));
        // auto theContent1 = static_cast<cocos2d::CCNode*>(theContent2->getChildren()->objectAtIndex(0));
        // auto theContent = static_cast<cocos2d::CCNode*>(theContent1->getChildren()->objectAtIndex(0));
        auto theContentChildren = p0;
        for (size_t i = 0; i < theContentChildren->count(); i++)
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
	}
};