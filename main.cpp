/**
 * CS-2413
 * project3.cpp
 * Purpose: Create a generalized list data type and its corresponding methods.
 *
 * @author Hunter Darr
 * @Version 1.0 3/23/2020
 */
#include <iostream>
using namespace std;

/**
 * Description:
 * The GLRow class acts as nodes in a generalized list. It contains the info of the node, the following next node, and following down node.
 *
 *
 * Constructors:
 * - GLRow(); Default Constructor
 * - GLRow(T &newInfo); Constructor
 * - GLRow(GLRow<T> &anotherOne); Copy Constructor
 * ~GLRow(); Destructor
 *
 * Methods:
 * - int getNext(); Returns _Next
 * - int getDown(); Returns _Down
 * - T &getInfo(); Returns _Info
 * - void setNext(int n); Sets _Next
 * - void setDown(int d); Sets _Down
 * - void setInfo(T &x); Sets _Info
 */
template<class T>
class GLRow; //class prototype
template<class T>
ostream &operator<<(ostream &s, GLRow<T> &oneGLRow);

template<class T>
class GLRow {
    friend ostream &operator<<<T>(ostream &s, GLRow<T> &oneGLRow);

protected:

    T *_Info;
    int _Next;
    int _Down;

public:

    GLRow();
    GLRow(T &newInfo);
    GLRow(GLRow<T> &anotherOne); //Copy constructor
    GLRow<T> &operator=(GLRow<T> &anotherOne); //Make sure you do
    // a deep copy
    int getNext();
    int getDown();
    T &getInfo();
    void setNext(int n); //I set these to void
    void setDown(int d);
    void setInfo(T &x);
    ~GLRow(); //destructor
};

template <class T> GLRow<T>::GLRow()   {
    _Info = NULL;
    _Next = -1;
    _Down = -1;
}

template <class T> GLRow<T>::GLRow(T &newInfo)   {
    _Info = &newInfo;
}

template <class T> GLRow<T>::GLRow(GLRow<T> &anotherOne) {
    _Info = new T (anotherOne.getInfo());
    _Down = anotherOne._Down;
    _Next = anotherOne._Next;
}

template <class T> int GLRow<T>::getNext() {
    return _Next;
}

template <class T> int GLRow<T>::getDown() {
    return _Down;
}

template <class T> T & GLRow<T>::getInfo() {
    return (*_Info);
}

template <class T> void GLRow<T>::setNext(int n)  {
    _Next = n;
}

template <class T> void GLRow<T>::setDown(int d) {
    _Down = d;
}

template <class T> void GLRow<T>::setInfo(T &x) {
    _Info = &x;
}

template <class T> GLRow<T>::~GLRow() {
//    delete _Info; //todo
}

template <class T> GLRow<T> & GLRow<T>::operator=(GLRow<T> &anotherOne) {
    _Info = new T (anotherOne.getInfo());
    _Down = anotherOne._Down;
    _Next = anotherOne._Next;
    return (*this);
}
template <class T> ostream& operator << (ostream& s, GLRow<T>& row)   {
    s << "Info: " << row.getInfo() << ", Next: " << row.getNext() << ", Down: " << row.getDown() << endl;
    return s;
}

template<class T>
class ArrayGLL;//class prototype
template<class T>
ostream &operator<<(ostream &s, ArrayGLL<T> &oneGLL);

template<class T>
class ArrayGLL {
    friend ostream &operator<<<T>(ostream &s, ArrayGLL<T> &OneGLL);

protected:

    GLRow<T> *myGLL;
    int maxSize; //Maximum size of the array of GLRows
    int firstElement;
    int firstFree;
    int foundElement = -1; //I made this
    int listSize = 0;

public:
    ArrayGLL();
    ArrayGLL(int size);
    ArrayGLL(ArrayGLL<T> &anotherOne);
    ArrayGLL<T> &operator=(ArrayGLL<T> &anotherOne);
    void display(); //display in parenthesis format 10% BONUS
    int find(T &key); //return the index position where you find
    int findHelper(T &key, int startingIndex);
    // the element key; -1 if not found; use recursive search
    void findDisplayPath(T &Key); // as you travel through the tree
    // print the values of nodes encountered. If the element is
    // you will print the all the values
    bool findDisplayPathHelper(T &key, int startingIndex);
    int noFree(); //return the number of free locations; you need
    // to follow the _Next and get the free locations
    int size(); //return the number of elements stored
    int sizeHelper(int startingIndex);
    int parentPos(T &Key); // provide the location of the parent of
    // the element Key in the array 10% BONUS
    GLRow<T> &operator[](int pos);

    //return the GLRow that is in
    // in the position pos in the array
    int getFirstFree();
    int getFirstElement();
    void setFirstFree(int pos);
    void setFirstElement(int pos);
    ~ArrayGLL(); //destructor
};

template <class T> ArrayGLL<T>::ArrayGLL()   {
    myGLL = NULL;
    maxSize = -1;
    firstElement = -1;
    firstFree = -1;
}

template <class T> ArrayGLL<T>::ArrayGLL(int size) {
    myGLL = new GLRow<T> [size];
    maxSize = size;
    firstElement = -1; //TODO know if these values are correct
    firstFree = -1;
}

template <class T> ArrayGLL<T>::ArrayGLL(ArrayGLL<T> &anotherOne) {
    myGLL = anotherOne.myGLL;
    maxSize = anotherOne.maxSize;
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree;
}

template <class T> ArrayGLL<T>& ArrayGLL<T>::operator=(ArrayGLL<T> &anotherOne) {
    myGLL = anotherOne.myGLL;
    maxSize = anotherOne.maxSize;
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree;
}

template <class T> void ArrayGLL<T>::display() {
    //TODO Fill in for bonus
    cout << "(display bonus not completed)" << endl;
}

template <class T> int ArrayGLL<T>::find(T &key) {
    //todo
    int answer = findHelper(key, firstElement);
    foundElement = -1;
    return answer;
}

template <class T> int ArrayGLL<T>::findHelper(T &key, int startingIndex) {
    if ( myGLL[startingIndex].getInfo() == NULL)   {
        foundElement = -1;
    }

    if (key == myGLL[startingIndex].getInfo())   {
        foundElement = startingIndex; //Test
    }
    //makes it so that if both next and down are not -1 it can handle it.
    else if ( (myGLL[startingIndex].getNext() != -1) && (myGLL[startingIndex].getDown() != -1))   {
        findHelper(key, myGLL[startingIndex].getDown());
        if ( foundElement == -1)   {
            findHelper(key, myGLL[startingIndex].getNext());
        }
    }
    else if ( (myGLL[startingIndex].getNext() == -1) && (myGLL[startingIndex].getDown() == -1))   {
        foundElement = -1;
    }
    else if (myGLL[startingIndex].getNext() == -1)   {
        findHelper(key, myGLL[startingIndex].getDown());
    }
    else if (myGLL[startingIndex].getNext() != -1)   {
        findHelper(key, myGLL[startingIndex].getNext());
    }
    else if (myGLL[startingIndex].getDown() == -1 )   {
        findHelper(key, myGLL[startingIndex].getNext());
    }
    else if (myGLL[startingIndex].getDown() != -1)   {
        findHelper(key, myGLL[startingIndex].getDown());
    }
    return foundElement;

}

template <class T> void ArrayGLL<T>::findDisplayPath(T &Key) {
    findDisplayPathHelper(Key, firstElement);
}

template <class T> bool ArrayGLL<T>::findDisplayPathHelper(T &key, int startingIndex) { //TODO not done
    if (startingIndex == -1 )   {
        return false;
    }
    if (key == myGLL[startingIndex].getInfo())   {
        cout << myGLL[startingIndex] << endl;  //Might want to remove
        return true;
    }

    if (findDisplayPathHelper(key, myGLL[startingIndex].getNext()))   {
        return true;
    }
    if (findDisplayPathHelper(key, myGLL[startingIndex].getDown()))   {
        cout << myGLL[startingIndex] << endl;
        return true;
    }
}

template <class T> int ArrayGLL<T>::noFree() {
    //todo
    int numberFree = 1;
    int nextValue = myGLL[firstFree].getNext();
    while (nextValue != -1)   {
        numberFree = numberFree + 1;
        nextValue = myGLL[nextValue].getNext();
    }
    return numberFree;
}

template <class T> int ArrayGLL<T>::size() {
    //todo
    int size = sizeHelper(firstElement);
    listSize = 0;
    return size;

}

template <class T> int ArrayGLL<T>::sizeHelper(int startingIndex) {  //todo FINISH
    listSize = listSize + 1;
    if ( myGLL[startingIndex].getInfo() == NULL)   {
        listSize = -123;
    }
        //todo make it so that if both next and down are not -1 it can handle it.
    else if ( (myGLL[startingIndex].getNext() != -1) && (myGLL[startingIndex].getDown() != -1))   {
        sizeHelper(myGLL[startingIndex].getDown());
        sizeHelper(myGLL[startingIndex].getNext());
    }
    else if ( (myGLL[startingIndex].getNext() == -1) && (myGLL[startingIndex].getDown() == -1))   {
    }
    else if (myGLL[startingIndex].getNext() == -1)   {
        sizeHelper(myGLL[startingIndex].getDown());
    }
    else if (myGLL[startingIndex].getNext() != -1)   {
        sizeHelper(myGLL[startingIndex].getNext());
    }
    else if (myGLL[startingIndex].getDown() == -1 )   {
        sizeHelper(myGLL[startingIndex].getNext());
    }
    else if (myGLL[startingIndex].getDown() != -1)   {
        sizeHelper(myGLL[startingIndex].getDown());
    }
    return listSize;
}

template <class T> int ArrayGLL<T>::parentPos(T &Key) {
    //todo bonus
}

template <class T> GLRow<T>& ArrayGLL<T>::operator[](int pos) {
    return myGLL[pos];
}

template <class T> int ArrayGLL<T>::getFirstFree() {
    return firstFree;
}

template <class T> int ArrayGLL<T>::getFirstElement() {
    return firstElement;
}

template <class T> void ArrayGLL<T>::setFirstFree(int pos) {
    firstFree = pos;
}

template <class T> void ArrayGLL<T>::setFirstElement(int pos) {
    firstElement = pos;
}

template <class T> ArrayGLL<T>::~ArrayGLL() {
//    delete[] myGLL;
}

template <class T> ostream& operator << (ostream& s, ArrayGLL<T>& array)   {
    int i = 0;
    while ( i < (array.size() + array.noFree()))   {
        s << array[i];
        i = i + 1;
    }
    return s;
}

//define all your classes here (as given above)
// write the methods after the class definition (not inside the class
// definition); You will have this main program to start. Your program must be
// able to work on other main programs as well. I HAVE NOT SYNTAX CHECKED THIS
// CODE AND IT IS YOUR REPOSIBILITY.
int main() {

    ArrayGLL<int> firstGLL (20);
    int noElements, value, next, down, parentPos;
    int pos = -1;
    int keyValue;
    int tempValue = 0;
    GLRow<int> oneRow (tempValue); //note that this statically defined

    //make sure you define all the variables

    //first line of input contains the number of segments
    cin >> noElements;
    for (int i = 0; i < noElements; i++) {
        cin >> value >> next >> down;
        oneRow.setInfo(value);
        oneRow.setNext(next);
        oneRow.setDown(down);
        firstGLL[i] = oneRow;

    }
    firstGLL.setFirstFree (8);
    firstGLL.setFirstElement (2);
    cout << firstGLL << endl;
    firstGLL.display();
    ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);

    int tempValue600 = 600;
    (*secondGLL)[1].setInfo(tempValue600);
    int tempValue700 = 700;
    (*secondGLL)[2].setInfo(tempValue700);

    cout << *secondGLL << endl;
    (*secondGLL).display();

    keyValue = 700;
    pos = (*secondGLL).find(keyValue); //todo make sure find can spit out -1 if its not in the list
    if (pos != -1)   {
        cout << "Finding Info of 700 with find(700), setting it to pos...\npos = the index of ";
        cout << (*secondGLL)[pos] << endl;
        cout << "Printing the value of nodes up to pos(700 as found with find()) with findDisplayPath(pos): " << endl;
        (*secondGLL).findDisplayPath(keyValue);
    }
//    parentPos = (*secondGLL).parentPos(keyValue);
//    if (parentPos != -1)   {
//        cout << (*secondGLL)[parentPos] << endl;
//    }
    cout << "Size of secondGLL: " << (*secondGLL).size() << endl;
    cout << "Number free in secondGLL: " << (*secondGLL).noFree() << endl;

    delete secondGLL;

    return 0;
}