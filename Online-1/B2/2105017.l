%option noyywrap

%x TOKENIZER

%{
    #include <bits/stdc++.h>
    using namespace std;

    ofstream tokenFile("2105017_token.txt");
    ofstream logFile("2105017_log.txt");

    stack<string> st;

    void logError(const string &message)
    {
        logFile << "Error: " << message << endl;
    }
%}

BOLD    "\\textbf"
ITALIC    "\\textit"
SECTION    "\\section"
LATEX    ({BOLD}|{ITALIC}|{SECTION})
LCURL    "{"
RCURL    "}"

%%

{LATEX}    {
    BEGIN(TOKENIZER);
}

<TOKENIZER>{
    {LCURL} {
        st.push(yytext);
    }
    {RCURL} {
        if (st.empty()) {
            logError("unmatched }");
            BEGIN(INITIAL);
        } else {
            st.pop();
            if (st.empty()) {
                logFile << "Valid LaTeX syntax" << endl;
                BEGIN(INITIAL);
            }
        }
    }
    {LATEX} {
        // Do nothing, just continue in TOKENIZER state
    }
    [^{}]+ {
        if (st.empty()) {
            logError("command not followed by brace block");
            BEGIN(INITIAL);
        }
    }
    <<EOF>> {
        if (!st.empty()) {
            logError("unmatched {");
            BEGIN(INITIAL);
        }
    }
}

[^{LATEX}] {
    logError("unsupported command");
    return 0;
}

%%

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // ./2105017.l <input_file>
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    FILE *file = fopen(inputFile.c_str(), "r");
    if (!file)
    {
        cout << "Error opening file: " << inputFile << endl;
        return 1;
    }

    yyin = file;

    yylex();

    fclose(file);
    tokenFile.close();
    logFile.close();

    cout << "Lexical analysis completed. Check 2105017_token.txt and 2105017_log.txt for results." << endl;

    return 0;
}
