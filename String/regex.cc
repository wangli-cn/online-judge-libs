//============================================================================
// Regular Expression Matching
// Implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true
//============================================================================

#include <iostream>

bool is_match(const char *s, const char *p)
{
    if (*s == '\0') {
        return *p == '\0';
    } else {
        if (*p == '\0') return false;
        else {
            if (*(p+1) != '*') {
                return ((*p == *s) || (*p == '.')) && is_match(s+1, p+1);
            } else {
                while ((*p == *s) || (*p == '.')) {
                    if (is_match(s, p+2)) return true;
                    s += 1;
                }

                return is_match(s, p+2);
            }
        }
    }
}

//bool is_match(const char *s, const char *p)
//{
    //if (*p == '\0') {
        //return *s == '\0';
    //} else if (*(p+1) != '*') {
        //return ((*p == *s) || (*p == '.' && *s != '\0')) && is_match(s+1, p+1);
    //} else {
        //while ((*p == *s) || (*p == '.' && *s != '\0')) {
            //if (is_match(s, p+2)) return true;
            //s++;
        //}

        //return is_match(s, p+2);
    //}
//}

int main(void)
{
    std::cout << std::boolalpha << is_match("aaaaabc", "a*b.") << std::endl;
    std::cout << std::boolalpha << is_match("aaaaabc", "a*b") << std::endl;
    std::cout << std::boolalpha << is_match("aaaaabc", ".*bc") << std::endl;
    return 0;
}
