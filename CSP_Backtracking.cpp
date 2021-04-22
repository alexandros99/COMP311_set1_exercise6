#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include<bits/stdc++.h> 
using namespace std;

struct puzzle_t {
   string first, second, result;
};

bool allDiff(puzzle_t, string, unordered_map<char, int>, int);
bool solutionExists(puzzle_t, unordered_map<char, int>);
bool checkDigitsNotEqual(unordered_map<char, int>);


int main() {
    int base = 9; //e.g. 9, 5, 1 etc
    puzzle_t puzzle;
    string lettersLeft="";
    unordered_map<char, int> digitForLetter; //the letters are the keys

    //puzzle.first = "ab";
    //puzzle.second = "ab";
    //puzzle.result = "cd";
    // OR
    puzzle.first = "too";
    puzzle.second = "too";
    puzzle.result = "fyr";
    // OR
    // puzzle.first = "won";
    // puzzle.second = "won";
    // puzzle.result = "trr";
    // OR
    // puzzle.first = "won";
    // puzzle.second = "won";
    // puzzle.result = "too";

    //initialization of lettersLeft
    for(int i=0; i<puzzle.first.length(); i++) 
        lettersLeft += puzzle.first[puzzle.first.length()-1-i];
    for(int i=0; i<puzzle.result.length(); i++) 
        lettersLeft += puzzle.result[puzzle.result.length()-1-i];
    
    //initialization of digitsForLetter
    for(int i=0; i<lettersLeft.length(); i++) 
        digitForLetter.insert(make_pair(lettersLeft[i], lettersLeft.length()-1-i));

    if(lettersLeft.length() > base+1) {
        cout << "Too many letters to be assigned..." << endl;
        return -1;
    }

    bool solution = allDiff(puzzle, lettersLeft, digitForLetter, base);
    cout << "Solution = " << solution;
    return 1;
}



bool allDiff(puzzle_t puzzle, string lettersLeft, unordered_map<char, int> digitForLetter, int base) { //returns 2D matrix
    if(lettersLeft.empty())
        return solutionExists(puzzle, digitForLetter);
    else
        for(int digit=0; digit<=base; digit++) { //  n!

            if(checkDigitsNotEqual(digitForLetter)) {
                digitForLetter.at(lettersLeft[0]) = digit;

                if( allDiff(puzzle, lettersLeft.substr(1), digitForLetter, base) ) {//true if PuzzleSolved, false if not
                    return true;
                }
                else {
                    int temp[4];
                    int i = 0;
                    int k=digitForLetter.at(lettersLeft[0]); //the digit that is going to change now

                    for(auto dg : digitForLetter) {
                        temp[i++] = dg.second;
                    }
                    digitForLetter.at(lettersLeft[0]) = +1;
                }
            }
            else {
                int u=0;
                int temp[digitForLetter.size()];
                char str[4];
                string s;
                for(auto dg : digitForLetter) {
                    temp[u++] = dg.second;
                    s+=dg.first;
                    
                } s.copy(str,4,0);

                int k = digitForLetter.at(lettersLeft[0]) +1;
                if(k>=9) {
                    k=0;
                    digitForLetter.at(lettersLeft[0])=0;
                }
                else {
                    digitForLetter.at(lettersLeft[0])++;
                }
            }
        }
    return false; //didn't find a solution, backtrack
}

 bool solutionExists(puzzle_t puzzle, unordered_map<char, int> digitForLetter) {
    int Carry, CarryPow, tempAddents, sumOfAddents, tempResult = 0;
    string s,s1,s2,newstr="";

    // for(auto dg : digitForLetter) {
                
    //     cout << dg.first << " " << dg.second << "\n";
    // }
    // cout << "stop" << '\n';
    //sleep(0.1);

    for(auto dg : digitForLetter) { //swsth siera
            for(int i=0; i<puzzle.first.length(); i++) { // if it belongs in first or second
                 if(dg.first==puzzle.first[i]) {
                     s1 += to_string(dg.second);
                     s2 += to_string(dg.second);
                     //cout <<s1 <<endl;
                }
            }

            //for result
            int count=0;
            for(int i=0; i<puzzle.result.length(); i++) {
                if(dg.first==puzzle.result[i]) { // if it belongs in puzzle.result
                    int pos = i;
                    s += to_string(dg.second);
                    newstr.resize(s.length()); // for e.g. 2 Os. Tha prpeei na to kanw kai gia ta first,second pera apo to result.
                    newstr += to_string(dg.second);
                    
                    for(int j=0; j<pos; j++) { // s.copy(newstr, pos,0);
                        newstr[j]=s[j];
                    }
                    for(int j=pos+1; j<newstr.length()-pos-1; j++) { // s.copy(newstr, stnewstr.length()-pos-1, pos+1);
                        newstr[j]=s[j-1];
                    }
                    newstr[pos] = puzzle.result[i];
                }
        }   
    }
    //reverse(s1.begin(), s1.end());
    //reverse(s2.begin(), s2.end());
    int t1 = stoi(s1);
    int t2 = stoi(s2);
    sumOfAddents = t1+t2;
    
    //reverse(s.begin(), s.end());
    stringstream geek(s);
    geek >> tempResult;

        
    //if solved, print it before returning true !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(sumOfAddents==tempResult) { 
        cout << "Result is " << tempResult << " and the addition of the addents is also " << sumOfAddents << '\n'; 
        for(auto dg : digitForLetter) {    
            cout << dg.first << " " << dg.second << "\n";
        }
        return true;
    } 
    return false;
 }

 bool checkDigitsNotEqual(unordered_map<char, int> digitForLetter) {
    int temp[digitForLetter.size()];
    int i=0;
    string str="";
    for(auto dg : digitForLetter) {
        temp[i] = dg.second;
        str[i] = dg.first;
        //cout << temp[i] << endl;
        i++;
    }
    
    for(int i=0; i<digitForLetter.size(); i++) { //all letters must be mapped to different numbers
        for(int j=0; j<digitForLetter.size(); j++) {              
            if(temp[i] == temp[j] && str[i] != str[j] ){
                return false;
            }
        }
    }
    return true;
 }
