#include "utils.hpp"
#include <Geode/loader/Loader.hpp>

Utils* Utils::sharedutils = nullptr;

Utils* Utils::get() {
    if (sharedutils == nullptr) {
        sharedutils = new (std::nothrow) Utils();
    }

    return sharedutils;
}

Utils::dnInstalled() {return geode::Loader::get()->isModLoaded(displayNameModID.c_str());}
Utils::nameTransferred() {return geode::Loader::get()->isModLoaded(displayNameModID.c_str()) && geode::Loader::get()->getLoadedMod(displayNameModID.c_str())->hasSavedValue("nametransferred");}
Utils::nameTransfered() {return geode::Loader::get()->isModLoaded(displayNameModID.c_str()) && geode::Loader::get()->getLoadedMod(displayNameModID.c_str())->hasSavedValue("nametransferred");}

Utils::Utils() {
    gamelaunch = true;
    displayNameModID = "coopeeo.displaynames";
}