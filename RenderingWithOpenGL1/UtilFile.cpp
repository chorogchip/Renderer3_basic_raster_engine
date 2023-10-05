
//#include "UtilFile.h"

//#include <iostream>
//#include <string>

namespace pop {
    /*
    std::string ReadFullText(const char* filename, bool* succeed) {
        std::string ret;
        
        FILE* fp = nullptr;
        fopen_s(&fp, filename, "r");
        if (fp == nullptr)
            goto FAILED;
        
        {
            fseek(fp, 0, SEEK_END);
            const auto len = ftell(fp);
            ret.resize(len);
            fread(ret.data(), sizeof(char), len, fp);
            fclose(fp);
        }
    SUCCEED:
        if (succeed != nullptr) {
            *succeed = true;
            goto RET;
        }
    FAILED:
        if (succeed != nullptr) {
            *succeed = false;
            goto RET;
        }
    RET:
        return ret;
    }
    */
}
