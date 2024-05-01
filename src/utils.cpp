#include "utils.hpp"
#include <Geode/loader/Loader.hpp>
#include <Geode/loader/Mod.hpp>

using namespace geode::prelude;

Utils* Utils::sharedutils = nullptr;

Utils* Utils::get() {
    if (sharedutils == nullptr) {
        sharedutils = new (std::nothrow) Utils();
    }

    return sharedutils;
}

bool Utils::dnInstalled() {return geode::Loader::get()->isModLoaded(displayNameModID.c_str());}
bool Utils::nameTransferred() {return geode::Loader::get()->isModLoaded(displayNameModID.c_str()) && geode::Loader::get()->getLoadedMod(displayNameModID.c_str())->hasSavedValue("nametransferred");}
bool Utils::nameTransfered() {return geode::Loader::get()->isModLoaded(displayNameModID.c_str()) && geode::Loader::get()->getLoadedMod(displayNameModID.c_str())->hasSavedValue("nametransferred");}

std::vector<std::string> Utils::splitString(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end;
    while ((end = s.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

Utils::Utils() {
    gamelaunch = true;
    displayNameModID = "coopeeo.displaynames";
}