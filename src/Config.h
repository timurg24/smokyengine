#pragma once
#include <pugixml.hpp>
#include <string>
#include <iostream>

struct Config {
    std::string author;
    std::string gameName;
    std::string version;
    std::string startScene;

    void Load() {
        pugi::xml_document doc;
        pugi::xml_parse_result result = doc.load_file("config.xml");
        if(!result) {
            std::cout << "Error: Failed to load configuration file! " << result.description() << "\n";
        }

        pugi::xml_node root = doc.child("Config");
        author = root.attribute("author").as_string();
        gameName = root.attribute("gameName").as_string();
        version = root.attribute("version").as_string();
        startScene = root.attribute("startScene").as_string();
    }
};