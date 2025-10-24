#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <entityManager.hpp>

#include <map>
#include <nlohmann/json.hpp>

class Parser {
    private:
    std::vector<std::string> jsonPaths;

    std::vector<std::string> getPaths();

    public:
    bool saveFile(std::string path);
    bool delFile(std::string path);
    bool addFile(std::string path);
    std::vector<std::map<std::string,std::string>> getData(std::string path);
    bool initSession(std::vector<std::map<std::string, std::string>> data);

};

#endif