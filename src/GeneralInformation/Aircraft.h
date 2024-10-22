
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <vector>
#include "User.h"
#include "FileMetadata.h"
#include "Config.h"
#include "References.h"

class Aircraft {
private:
    std::string name;
    User user;
    FileMetadata fileMetadata;
    Config config;

    std::string Description;

    std::vector<References> references; 
    std::string limitations;                //Nam Ho handles
    std::string notes;                      //Nam Ho handles

public:
    Aircraft();

    void setName(const std::string& name);
    std::string getName() const;

    void setUser(const User& user);
    User getUser() const;

    void setFileMetadata(const FileMetadata& fileMetaData);
    FileMetadata getFileMetadata() const;

    void setConfig(const Config& config);
    Config getConfig() const;

    void setReferences(const std::vector<References>& references);
    std::vector<References> getReferences() const;

    // void setLimitations(const std::string& limitations);
    // std::string getLimitations() const;
    void setDescription(std::string Description);
    std::string getDescription();

    void setNotes(const std::string& notes);
    std::string getNotes() const;

    bool setLimitations(std::string limitations);
    std::string getLimitations();

    bool setNotes(std::string notes);
    std::string getNotes();

    void saveToFile();
    Aircraft loadFromFile();
};

#endif // AIRCRAFT_H
