
/*
Functionality:
- nxt(): reads the next string
- cxt(): reads the next character
- lxt(): reads the whole line
*/
constexpr int BUFSIZE = 2e6 + 1;
char buf[BUFSIZE];
class Reader {
    string nxt() {
        scanf("%s", buf);
        return buf;
    }
    char cxt() {
        scanf("%s", buf);
        return buf[0];
    }
    string lxt() {
        char c;
        string sb;
        while (c = getchar()) {
            if (c == '\n' || c == EOF) {
                break;
            }
            sb += c;
        }
        return sb;
    }
} fs;
