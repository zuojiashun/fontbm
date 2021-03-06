﻿#pragma once

#include <cstdint>
#include <map>
#include <vector>

class FntInfo
{
public:

    struct Character
    {
        int x;
        int y;
        int w;
        int h;
        int xoffset;
        int yoffset;
        int xadvance;
        int page;
    };

    std::map<uint32_t, Character> characters;
    std::map<int, std::string> pages;

    static FntInfo loadFromFile(const std::string& fileName);

private:
	static std::string getValueString(const std::string& line, const std::string& key);
	static std::string getQuotedValueString(const std::string& line, const std::string& key);
	static int getValueInt(const std::string& line, const std::string& key, int defaultVal = -1);
};
