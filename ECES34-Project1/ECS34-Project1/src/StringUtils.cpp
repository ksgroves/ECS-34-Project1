namespace StringUtils{
// ifs handle negatives and zeroes as inputs
// otherwise just returns the substring from start to end
std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    ssize_t len = str.length();
    if(start < 0){
        start += len;
    }
    if(end == 0){
        end = len;
    }
    if(end < 0){
        end += len;
    }
    if(start < 0){
        start = 0;
    }
    if (start >= end){
        return "";
    }
    return str.substr(start, (end - start));
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
// two cases, either white space or given splitter
// ignore leading and trailing space, treat multiple as one
// for given splitter find each instance divide by them
std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector< std::string > result;
    if(splt == ""){
        size_t i = 0;
        size_t n = str.length();

        while(i < n){
            while(i < n && std::isspace(static_cast<unsigned char>(str[i]))){
                i++;
            }

            if(i >= n){
                break;
            }

            size_t start = i;
            while(i < n && !std::isspace(static_cast<unsigned char>(str[i]))){
                i++;
            }

            result.push_back(str.substr(start, i - start));
        }
        return result;
    }
    size_t pos = 0;
    size_t spltterlen = splt.length();

    while(true){
        size_t found = str.find(splt, pos);

        if(found == std::string::npos){
            result.push_back(str.substr(pos));
            break;
        }

        result.push_back(str.substr(pos, found - pos));
        pos = found + spltterlen;
    }
    return result;
}
// appends each string in vector to result with seperator in between
std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    if(vect.empty()){
        return "";
    }
    std::string result = vect[0];
    for(size_t i = 1; i < vect.size(); i++){
        result += str;
        result += vect[i];
    }
    return result;
}
// get column position, when encountering tab
//calculate spaces to next tab stop and append that many spaces
// newline rests column count
std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string result;
    int col = 0;

    for(char c : str){
        if(c == '\t'){
            int spaces = tabsize - (col % tabsize);
            result.append(spaces, ' ');
            col += spaces;
        }
        else{
            result += c;
            if(c == '\n' || c == '\r'){
                col = 0;
            }
            else{
                col++;
            }
        }
    }
    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};
