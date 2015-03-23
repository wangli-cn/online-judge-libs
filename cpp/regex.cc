#include <iostream>
#include <regex>
#include <string>

typedef std::match_results<const char*> cmatch;

int main()
{
    std::string str("Hello world");
    std::regex rx("ello");

    bool bMatch = regex_match(str.begin(), str.end(), rx);
    bool bSearch = regex_search(str.begin(), str.end(), rx);

    std::cout << bMatch << " " << bSearch << std::endl;

    std::string replacement = "planet";
    std::string str2 = std::regex_replace(str, rx, replacement);
    std::cout << str2 << std::endl;

    cmatch res;
    str = "<h2>Egg prices</h2>";
    std::regex rxx("<h(.)>([^<]+)");
    std::regex_search(str.c_str(), res, rxx);
    std::cout << res[1] << ". " << res[2] << std::endl;
    return 0;
}
