#ifndef STRING_H
#define STRING_H


class String
{
public:
    String(int count, char **src);

    bool operator == (const char *src);

    char *getString();

private:
    char **mString;

    int mCount;
};

#endif // STRING_H
