#include <iostream>

using namespace std;

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
    _Info = &newInfo; //Might need to put &
}

template <class T> GLRow<T>::GLRow(GLRow<T> &anotherOne) {
    //Does it copy info, next, and down?
    _Info = anotherOne._Info;
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
    return _Info;
}

template <class T> void GLRow<T>::setNext(int n)  {
    _Next = n;
}

template <class T> void GLRow<T>::setDown(int d) {
    _Down = d;
}

template <class T> void GLRow<T>::setInfo(T &x) {
    _Info = &x; //Keep an eye on this. might be wrong
}

template <class T> GLRow<T>::~GLRow() {
    delete _Info;
}

template <class T> GLRow<T> & GLRow<T>::operator=(GLRow<T> &anotherOne) {
    _Info = anotherOne._Info;
    _Down = anotherOne._Down;
    _Next = anotherOne._Next;
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

public:
    ArrayGLL();
    ArrayGLL(int size);
    ArrayGLL(ArrayGLL<T> &anotherOne);
    ArrayGLL<T> &operator=(ArrayGLL<T> &anotherOne);
    void display(); //display in parenthesis format 10% BONUS
    int find(T &key); //return the index position where you find
    // the element key; -1 if not found; use recursive search
    void findDisplayPath(T &Key); // as you travel through the tree
    // print the values of nodes encountered. If the element is
    // you will print the all the values
    int noFree(); //return the number of free locations; you need
    // to follow the _Next and get the free locations
    int size(); //return the number of elements stored
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
    firstFree = 0;
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
}

template <class T> int ArrayGLL<T>::find(T &key) {
    //todo
}

template <class T> void ArrayGLL<T>::findDisplayPath(T &Key) {
    //todo
}

template <class T> int ArrayGLL<T>::noFree() {
    //todo
}

template <class T> int ArrayGLL<T>::size() {
    //todo
}

template <class T> int ArrayGLL<T>::parentPos(T &Key) {
    //todo bonus
}

template <class T> GLRow<T>& ArrayGLL<T>::operator[](int pos) {
    //todo return the GLRow at position [i]
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
    delete[] myGLL;
}







//define all your classes here (as given above)
// write the methods after the class definition (not inside the class
// definition); You will have this main program to start. Your program must be
// able to work on other main programs as well. I HAVE NOT SYNTAX CHECKED THIS
// CODE AND IT IS YOUR REPOSIBILITY.
int main() {
    ArrayGLL<int> firstGLL(20);
    int noElements, value, next, down, parentPos;
    int pos = -1;
    int keyValue;
    int tempValue = 0;
    GLRow<int> oneRow(tempValue); //note that this statically defined
    // make sure you define all the variables
    // first line of input contains the number of segments
    cin >> noElements;
//    for (int i = 0; i < noElements; i++) {
//        cin >> value >> next >> down;
//        oneRow.setInfo(value);
//        oneRow.setNext(next);
//        oneRow.setDown(down);
//        firstGLL[i] = oneRow;
//    }
//    firstGLL.setFirstFree(noElements);
//    firstGLL.setFirstElement(0);
//    cout << firstGLL << endl;
//    firstGLL.display();
//    ArrayGLL<int> *secondGLL = new ArrayGLL<int>(firstGLL);
//    int temp600 = 600;
//    int temp700 = 700;
//    (*secondGLL)[1].setInfo(temp600);
//    (*secondGLL)[2].setInfo(temp700);
//    cout << *secondGLL << endl;
//    (*secondGLL).display();
//    keyValue = 700;
//    pos = (*secondGLL).find(keyValue);
//    if (pos /*origonally position*/ != -1) {
//        cout << (*secondGLL)[pos] << endl;
//        (*secondGLL).findDisplayPath(keyValue);
//    }
//    parentPos = (*secondGLL).parentPos(keyValue);
//    if (parentPos != -1) { cout << (*secondGLL)[parentPos] << endl; }
//    cout << (*secondGLL).size();
//    cout << (*secondGLL).noFree();
//    delete secondGLL;
//    return 0;
}