/*==============================
 HEADER FILE FOR COMPOSER CLASS
 ===============================*/

#ifndef Composer_h
#define Composer_h
#include <iostream>
using namespace std;

class Composer
{
private:
    string name;
    int date;
    
public:
    Composer();                        
    Composer(string, int);
    ~Composer();
    string getName()const;
    int getDate()const;
    void setName(string);
    void setDate(int);
    bool operator==(const Composer&);
    bool operator<(const Composer&);
    bool operator!=(const Composer&);
    friend ostream& operator<<(ostream&, const Composer&);
    
};
#endif
