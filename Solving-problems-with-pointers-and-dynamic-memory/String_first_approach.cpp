#include <iostream>

typedef char * arrayString ; 
//In this approach a string is an array of char 
//To detect the end of the array we place a 0 at the last place 

int length(arrayString s) ;
//return the length of the string s
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
    int i = 0 ;
    while (s[i]!=0) {
        i++;
    }
    return i ;
}

void length_test() {
    arrayString s = new char[4] ;
    s[0] = 't' , s[1] = 'e' , s[2] = 's' , s[3]='t' , s[4] = 0 ;
    std::cout << length(s) << std::endl ;
    delete[] s ;
    return ;
}


//characterat
//return $ if error with exception message
char characterAt(arrayString s, int position) {
    int lgth = length(s) ;
    if (position>=lgth) {
        std::cout << "this position doesn't exist" << std::endl ;
        return '$' ;
    }
    else {
        return s[position] ;
    }
}

void test_characterAt() {
    arrayString s = new char[4] ;
    s[0] = 't' , s[1] = 'e' , s[2] = 's' , s[3]='t' , s[4] = 0 ;
    std::cout << characterAt(s,10) << std::endl ;
    std::cout << characterAt(s,2) << std::endl ;
    delete[] s ;
    return ;

}

//append 
void append(arrayString& s, char elt) {
    int lgth = length(s) ;
    arrayString news = new char[lgth+2] ;
    for (int i = 0; i<lgth ; i++) {
        news[i] = s[i] ;
    }
    news[lgth] = elt ;
    news[lgth+1] = 0 ;
    delete[] s ;
    s = news ;
}

void test_append() {
    arrayString s = new char[4] ;
    s[0] = 't' , s[1] = 'e' , s[2] = 's' , s[3]='t' , s[4] = 0 ;
    append(s,'s') ;
    std::cout << s << std::endl ;
    delete[] s ; 
}

//concatenate
void concatenate(arrayString& s1, arrayString s2) {
    int lgths1 = length(s1) ;
    int lgths2 = length(s2) ;
    int new_length = lgths1 + lgths2 ;
    arrayString newS = new char[new_length+1] ;

    for (int i = 0 ; i<lgths1 ; i++) {
        newS[i] = s1[i] ;
    }
    for (int j = 0 ; j<lgths2 ; j++) {
        newS[lgths1+j] = s2[j] ;
    }
    newS[lgths1+lgths2] = 0 ;
    delete[] s1 ;
    s1 = newS ; 

}

void test_concatenate() {
    arrayString s = new char[4] ;
    s[0] = 't' , s[1] = 'e' , s[2] = 's' , s[3]='t' , s[4] = 0 ;
    arrayString s2 = new char[4] ;
    s2[0] = ' ' , s2[1] = 'y' , s2[2] = 'e' , s2[3]='s' , s[4] = 0 ;
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
        for (int i=0 ; i<length_sub ; i++) {
            s2[i] = s[pos_start+i] ;
        }
        delete[] s ;
        s2[length_sub] = 0 ;
        s = s2 ;
    }
    return ;
}

void subString_test() {
    arrayString s = new char[4] ;
    s[0] = 't' , s[1] = 'e' , s[2] = 's' , s[3]='t' , s[4] = 0 ;
    arrayString s2 = new char[4] ;
    s2[0] = 't' , s2[1] = 'e' , s2[2] = 's' , s2[3]='t' , s2[4] = 0 ;
    subString(s,1,2) ;
    subString(s2,1,5) ;
    std::cout << s << std::endl ;
    std::cout << s2 << std::endl ; //we notice that s doesn't change
    delete[] s ;
    delete[] s2 ;
    
}

//replaceText 
void replaceText(arrayString& s, arrayString source, arrayString change) {
    int lgth = length(s) ;
    int length_source = length(source) ;
    //we will determine how many time the pattern appears 

    int count = 0 ;
    for (int i = 0 ; i<=(lgth-length_source) ; i++) {
        int j = 0 ;
        while (j<length_source && s[j+i]==source[j]) {
            j++ ;
        }
        if (j==length_source) {
            count++ ;
        }
    }
    int lgth_change  = length(change) ;
    int lgth_final = count*lgth_change + lgth - count*length_source ;
    arrayString finalS = new char[lgth_final+1] ;

    int k = 0 ;
    int i = 0 ;
    for (int i = 0 ; i<=(lgth-length_source) ; i++) {
        int j = 0 ;
        while (j<length_source && s[j+i]==source[j]) {
            j++ ;
        }
        if (j==length_source) {
            concatenate(finalS,change) ;
            k+=lgth_change ;
            i+= (length_source-1) ;
        } else {
            finalS[k] = s[i] ;
            k++ ;
        }
    }
    delete[] s ;
    s = finalS ;

}

void replaceText_test() {
    arrayString s = new char[8] ;
    s[0] = 'a' , s[1] = 'b' , s[2] = 'o' , s[3] = 'i' , s[4] = 'a' , s[5] = 'b' , s[6] = 'a' , s[7] = 'b' , s[8] = 0 ;
    arrayString source = new char[3] ;
    source[0] = 'a' , source[1] = 'b' , source[2] = 0 ;
    arrayString replace = new char[4] ;
    replace[0] = 'x' , replace[1] = 'y' , replace[2] = 'z' , replace[3] = 0 ;
    std::cout << "input: " << s << " source: " << source << " replace: " << replace << std::endl ; 
    replaceText(s,source,replace) ;
    std::cout << s << std::endl ;
    delete[] s;
    delete[] source ;
    delete[] replace ;
    
}





int main() {
    length_test() ;
    test_characterAt() ;
    test_append() ;
    test_concatenate() ;
    subString_test() ;
    replaceText_test() ;
    return 0 ;
}

