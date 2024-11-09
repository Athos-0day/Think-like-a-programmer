#include <iostream>

typedef char * arrayString ; 
//In this approach a string is an array of char 
//the first element of the array is the length of the string 

int length(arrayString s) ;
//return the length of s 
char characterAt(arrayString s, int position) ;
//the function return s[position] if it exist
void append(arrayString& s, char elt) ;
//add elt to the string 
void concatenate(arrayString& s1, arrayString s2) ;
//concatenate two string
void subString(arrayString& s, int pos_start, int length_sub) ;
//take a substring of the string which start at pos_start and with length_sub
void replaceText(arrayString& s, arrayString source, arrayString change) ;
//replace the source element that there are in s by change 


//length 
int length(arrayString s) {
    if (s==0) {
        return 0 ;
    }
    else {
        return int(s[0]) ;
    }
}

void test_length() {
    arrayString s = new char[4] ;
    s[0] = 4 , s[1] = 't' , s[2] = 'e' , s[3]='s' , s[4] = 't' ;
    std::cout << length(s) << std::endl ;

}


//characterat
//return $ if error with exception message
char characterAt(arrayString s, int position) {
    if (s==0) {
        std::cout << "the array is empty" << std::endl ;
        return '$' ;
    } 

    if (position+1>length(s)) {
        std::cout << "this position doesn't exist" << std::endl ;
        return '$' ;
    }
    else {
        return s[position+1] ;
    }
}

void test_characterAt() {
    arrayString s = new char[4] ;
    s[0] = 4 , s[1] = 't' , s[2] = 'e' , s[3]='s' , s[4] = 't' ;
    std::cout << characterAt(s,10) << std::endl ;
    std::cout << characterAt(s,2) << std::endl ;
    delete[] s ;
    return ;

}

//append 
void append(arrayString& s, char elt) {
    int lgth = length(s) ;
    arrayString news = new char[lgth+2] ;
    for (int i = 1; i<=lgth ; i++) {
        news[i] = s[i] ;
    }
    news[lgth+1] = elt ;
    news[0] = length(s) + 1 ;
    delete[] s ;
    s = news ;
}

void test_append() {
    arrayString s = new char[4] ;
    s[0] = 4 , s[1] = 't' , s[2] = 'e' , s[3]='s' , s[4] = 't' ;
    std::cout << length(s) << std::endl ;
    append(s,'s') ;
    std::cout << s << std::endl ;
    std::cout << length(s) << std::endl ;
    delete[] s ; 
}


//concatenate 
void concatenate(arrayString& s1, arrayString s2) {
    int lgths1 = length(s1) ;
    int lgths2 = length(s2) ;
    int new_length = lgths1 + lgths2 ;
    arrayString newS = new char[new_length+1] ;

    for (int i = 1 ; i<=lgths1 ; i++) {
        newS[i] = s1[i] ;
    }
    for (int j = 1 ; j<=lgths2 ; j++) {
        newS[lgths1+j] = s2[j] ;
    }
    newS[0] = new_length + 1 ;
    delete[] s1 ;
    s1 = newS ; 

}

void test_concatenate() {
    arrayString s = new char[4] ;
    s[0] = 4 , s[1] = 't' , s[2] = 'e' , s[3]='s' , s[4] = 't' ;
    arrayString s2 = new char[4] ;
    s2[0] = 4 , s2[1] = ' ' , s2[2] = 'y' , s2[3]='e' , s2[4] = 's' ;
    concatenate(s,s2) ;
    std::cout << s << std::endl ;
    delete[] s ;
    delete[] s2 ;

}


//subString
void subString(arrayString& s, int pos_start, int length_sub) {
    int old_length = length(s) ;
    if ((pos_start+length_sub)>=old_length) {
        std::cout << "s is not long enough" << std::endl ;
    } else {
        arrayString s2 = new char[length_sub+1] ;
        for (int i=1 ; i<=length_sub ; i++) {
            s2[i] = s[pos_start+i] ;
        }
        delete[] s ;
        s2[0] = length_sub+2 ;
        s = s2 ;
    }
    return ;
}

void subString_test() {
    arrayString s = new char[4] ;
    s[0] = 4 , s[1] = 't' , s[2] = 'e' , s[3]='s' , s[4] = 't' ;
    arrayString s2 = new char[4] ;
    s2[0] = 4 , s2[1] = 't' , s2[2] = 'e' , s2[3]='s' , s2[4] = 't' ;
    subString(s,1,2) ;
    subString(s2,1,5) ;
    std::cout << s << std::endl ;
    std::cout << s2 << std::endl ; //we notice that s doesn't change
    delete[] s ;
    delete[] s2 ;
    
}


int main() {
    test_length() ;
    test_characterAt() ;
    test_append() ;
    test_concatenate() ;
    subString_test() ;
    return 0 ;
}