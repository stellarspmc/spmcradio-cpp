#pragma once
#include <string>  

struct AudioTrackInfo {
    std::string title;
    std::string author;
    long length;
    std::string identifier;
    bool is_stream;
    std::string uri;
    std::string artwork_url;
    std::string isrc;
};
