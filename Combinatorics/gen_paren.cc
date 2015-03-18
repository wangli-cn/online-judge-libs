//============================================================================
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"
//============================================================================

#include <iostream>

using namespace std;

void gen_paren(int open_stock, int close_stock, string s)
{
    if (open_stock == 0 && close_stock == 0) {
        cout << s << endl;
        return;
    }

    if (open_stock > 0) {
        gen_paren(open_stock-1, close_stock+1, s+"(");
    }

    if (close_stock > 0) {
        gen_paren(open_stock, close_stock-1, s+")");
    }
}

int main()
{
    gen_paren(3, 0, string(""));
    return 0;
}
