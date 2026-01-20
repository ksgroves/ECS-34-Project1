#include "StringUtils.h"
#include <cctype>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // Replace code here
    return "";
}
//capitalize is template from discussion
//takes first chacter and makes upper, 
//and makes rest lower for all index >0
std::string Capitalize(const std::string &str) noexcept{
    std::string Temp = str;
    if(!Temp.empty()){
        Temp[0] = toupper(Temp[0]);
        for(size_t Index = 1; Index < Temp.length(); Index++){
            Temp[Index] = tolower(Temp[Index]);
        }
    }
    return Temp;
}

std::string Upper(const std::string &str) noexcept{
    std::string result = str;
    for(char &c : result){
        c = std::toupper(c);
    }
    return result;
}

std::string Lower(const std::string &str) noexcept{
    std::string result = str;
    for(char &c : result){
        c = std::tolower(c);
    }
    return result;
}
//strips are template from discussion
//increments an index for each space at beginning of string
//returns remaining substring from final index
std::string LStrip(const std::string &str) noexcept{
    std::string Temp = str;
    size_t Index = 0;
    size_t Length = Temp.length();
    while((Index < Length) && isspace(Temp[Index])){
        Index++;
    }

    return Temp.substr(Index);
}
//same as LStrip but deincrements from end
std::string RStrip(const std::string &str) noexcept{
    std::string Temp = str;
    if(!Temp.empty()){
        size_t Index = Temp.length()-1;
        while(isspace(Temp[Index])){
            if(!Index){
                return "";
            }
            Index--;
        }
        return Temp.substr(0,Index+1);
    }
    return "";
}
//runs both strips, gives expected result
std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str));
}
//combine LJust and RJust, do both while dividing the total padding
std::string Center(const std::string &str, int width, char fill) noexcept{
    if(str.length() >= width){
        return str;
    }
    int pad = width - str.length();
    int leftpad = pad/2;
    int rightpad = pad - leftpad;
    std::string result = str;
    result.insert(0, leftpad, fill);
    result.append(rightpad, fill);
    return result;
}
//fill space is appended in LJust and inserted at 0 in RJust
std::string LJust(const std::string &str, int width, char fill) noexcept{
    if(str.length() >= width){
        return str;
    }
    std::string result = str;
    result.append(width - str.length(), fill);
    return result;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    if(str.length() >= width){
        return str;
    }
    std::string result = str;
    result.insert(0, width - str.length(), fill);
    return result;
}
// go through each position in str to find instances of old
// the append rep to result and increment by the number of spaces old occupied
// otherwise append the current character to result and increment
std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    if (old == "") {
        return str;
    }
    std::string result;
    size_t pos = 0;
    while(pos < str.length()){
        if(str.compare(pos, old.length(), old) == 0){
            result += rep;
            pos += old.length();
        }
        else{
            result += str[pos];
            pos++;
        }
    }
    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};
