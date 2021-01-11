/*======================================
 11/26/2019
 This assignment is a multi-file project
 in which a templated linked list is
 implemented to create a list of composers.
 =======================================*/

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Composer.h"
using namespace std;

int main()
{
    LinkedList<Composer> list;
    string name, dateS;
    int date;
    char input;
    
    ifstream infile;
    infile.open("composers.txt");
    if(!infile)
    {
        cout <<"File not found!;" << endl;
        exit(1);
    }
        
    while(getline(infile,name, ',' ))
    {
        getline (infile, dateS);
        date = stoi(dateS);
        Composer composer(name, date);
        list.insert(composer);
    }
    
    Composer check;
    
    do
    {
        cout << "Enter 's' to search, 'r' to remove, 'd'"
        <<"to display, or 'e' to exit: ";
        cin >> input;
        cin.ignore();
        
        switch(input)
        {
            case's':
            {
                string name;
                cout <<"Enter a composer's name to search for: ";
                getline (cin, name);
                check.setName(name);
                if (list.find(check))
                {
                    cout << endl;
                    cout <<"\t"<<check.getName() <<" was found in "
                    "the list" <<endl <<endl;
                }
                else
                {
                    cout <<endl;
                    cout <<"\t"<<check.getName() <<" was not found in the "
                    "list" <<endl << endl;
                }
                break;
            }
            case'r':
            {
                string name;
                cout <<"Enter a composer's name to remove: ";
                getline (cin, name);
                check.setName(name);
                if(list.remove(check))
                {
                    cout << endl;
                    cout <<"\t"<<check.getName() <<" was successfully removed "
                    "from the list" << endl <<endl;
                }
                else
                {
                    cout << endl;
                    cout <<"\t"<<check.getName() <<" was not found in the "
                    "list when attempting to remove" << endl <<endl;
                }
                break;
            }
            case'd':
            {
                list.printList();
                cout << endl;
                break;
            }
            case'e':
                break;
            default:
                cout <<"Please enter a valid choice! " << endl;
            
        }
        
    }while (input != 'e');

}

/*================================
            SAMPLE RUN
 =================================*/
/*
 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: d
 Claudio Monteverdi - 1643
 Henry Purcell - 1695
 Antonio Vivaldi - 1741
 Johann Sebastian Bach - 1750
 George Frideric Handel - 1759
 Wolfgang Amadeus Mozart - 1791
 Joseph Haydn - 1809
 Ludwig van Beethoven - 1827
 Franz Schubert - 1828
 Felix Mendelssohn - 1847
 Frederic Chopin - 1849
 Robert Schumann - 1856
 Hector Berlioz - 1869
 Richard Wagner - 1883
 Franz Liszt - 1886
 Pyotr Ilyich Tchaikovsky - 1893
 Johannes Brahms - 1897
 Giuseppe Verdi - 1901
 Antonin Dvorak - 1904
 Edvard Grieg - 1907
 Gustav Mahler - 1911
 Claude Debussy - 1918
 Camille Saint-Saens - 1921
 Giacomo Puccini - 1924
 George Gershwin - 1937
 Maurice Ravel - 1937
 Sergei Rachmaninoff - 1943
 Bela Bartok - 1945
 Arnold Schoenberg - 1951
 Sergei Prokofiev - 1953
 Igor Stravinsky - 1971
 Dmitri Shostakovich - 1975
 Leonard Bernstein - 1990
 Aaron Copland - 1990

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: s
 Enter a composer's name to search for: Franz Liszt

     Franz Liszt was found in the list

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: r
 Enter a composer's name to remove: Franz Liszt

     Franz Liszt was successfully removed from the list

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: r
 Enter a composer's name to remove: Claudio Monteverdi

     Claudio Monteverdi was successfully removed from the list

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: d
 Henry Purcell - 1695
 Antonio Vivaldi - 1741
 Johann Sebastian Bach - 1750
 George Frideric Handel - 1759
 Wolfgang Amadeus Mozart - 1791
 Joseph Haydn - 1809
 Ludwig van Beethoven - 1827
 Franz Schubert - 1828
 Felix Mendelssohn - 1847
 Frederic Chopin - 1849
 Robert Schumann - 1856
 Hector Berlioz - 1869
 Richard Wagner - 1883
 Pyotr Ilyich Tchaikovsky - 1893
 Johannes Brahms - 1897
 Giuseppe Verdi - 1901
 Antonin Dvorak - 1904
 Edvard Grieg - 1907
 Gustav Mahler - 1911
 Claude Debussy - 1918
 Camille Saint-Saens - 1921
 Giacomo Puccini - 1924
 George Gershwin - 1937
 Maurice Ravel - 1937
 Sergei Rachmaninoff - 1943
 Bela Bartok - 1945
 Arnold Schoenberg - 1951
 Sergei Prokofiev - 1953
 Igor Stravinsky - 1971
 Dmitri Shostakovich - 1975
 Leonard Bernstein - 1990
 Aaron Copland - 1990

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: s
 Enter a composer's name to search for: Aaron Copland

     Aaron Copland was found in the list

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: z
 Please enter a valid choice!
 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: a
 Please enter a valid choice!
 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: r
 Enter a composer's name to remove: Aaron Copland

     Aaron Copland was successfully removed from the list

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: d
 Henry Purcell - 1695
 Antonio Vivaldi - 1741
 Johann Sebastian Bach - 1750
 George Frideric Handel - 1759
 Wolfgang Amadeus Mozart - 1791
 Joseph Haydn - 1809
 Ludwig van Beethoven - 1827
 Franz Schubert - 1828
 Felix Mendelssohn - 1847
 Frederic Chopin - 1849
 Robert Schumann - 1856
 Hector Berlioz - 1869
 Richard Wagner - 1883
 Pyotr Ilyich Tchaikovsky - 1893
 Johannes Brahms - 1897
 Giuseppe Verdi - 1901
 Antonin Dvorak - 1904
 Edvard Grieg - 1907
 Gustav Mahler - 1911
 Claude Debussy - 1918
 Camille Saint-Saens - 1921
 Giacomo Puccini - 1924
 George Gershwin - 1937
 Maurice Ravel - 1937
 Sergei Rachmaninoff - 1943
 Bela Bartok - 1945
 Arnold Schoenberg - 1951
 Sergei Prokofiev - 1953
 Igor Stravinsky - 1971
 Dmitri Shostakovich - 1975
 Leonard Bernstein - 1990

 Enter 's' to search, 'r' to remove, 'd'to display, or 'e' to exit: e
 Program ended with exit code: 0
 */
