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
class GLRow;
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
    GLRow<T> &operator=(GLRow<T> &anotherOne);
    int getNext();
    int getDown();
    T &getInfo();
    void setNext(int n);
    void setDown(int d);
    void setInfo(T &x);
    ~GLRow(); //destructor
};

template <class T> GLRow<T>::GLRow()   {
//    _Info = NULL;
int inf = 999; //todo revert to above
setInfo(inf);
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

template <class T> GLRow<T>::~GLRow() { // todo Maybe turn info to 999, next to -1 and down to -1
    int info = 998;
    setInfo(info);
    _Next = -1;
    _Down = -1;
//    if ( _Info != NULL)   {
//        delete _Info;
//    }
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
/**
 * Description:
 * The ArrayGLL class combines the GLRow nodes together into a generalized list.
 * This is achieved using an array.
 *
 *
 * Constructors:
 * - ArrayGLL(); Default Constructor
 * - ArrayGLL(int size); Constructor
 * - ArrayGLL(ArrayGLL<T> &anotherOne); Copy Constructor
 * - ~ArrayGLL(); Destructor
 *
 * Methods:
 * - void display(); display in parenthesis format 10% BONUS
 * - int find(T &key); return the index position where you find the element key; -1 if not found; use recursive search
 * - int findHelper(T &key, int startingIndex); Helps find. Does most of the calculations
 * - void findDisplayPath(T &Key); as you travel through the tree print the values of nodes encountered. If the element is not in the tree you will print the all the values
 * - bool findDisplayPathHelper(T &key, int startingIndex); Helps findDisplayPath(T &Key). Does most of the calculations.
 * - int noFree(); Counts the number of free nodes in the generalized linked list.
 * - int size(); Returns the number of nodes used in the generalized linked list.
 * - int sizeHelper(int startingIndex); Helps size(), does most of the calculations.
 * - int parentPos(T &Key); Finds the parent of the given _Info.
 * - int parentPosHelper(T &Key, int startingPoint, int parentPos); Helps parentPos(T &Key), does most of the calculations.
 * - int getFirstFree(); Getter method for firstFree.
 * - int getFirstElement(); Getter method for firstElement.
 * - void setFirstFree(int pos); Setter method for setFirstFree.
 * - void setFirstElement(int pos); Setter method for setFirstElement.
 */
template<class T>
class ArrayGLL;
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
    int foundElement = -1;
    int listSize = 0;
    int deletedNumber = 999;
    int deleteDownNext = -1;

public:
    ArrayGLL();
    ArrayGLL(int size);
    ArrayGLL(ArrayGLL<T> &anotherOne);
    ArrayGLL<T> &operator=(ArrayGLL<T> &anotherOne);
    void display(); //display in parenthesis format 10% BONUS
    void displayHelper(int root);
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
    int parentPosHelper(T &Key, int startingPoint, int parentPos);
    GLRow<T> &operator[](int pos);
    //return the GLRow that is in
    // in the position pos in the array
    int getFirstFree();
    int getFirstElement();
    void setFirstFree(int pos);
    void setFirstElement(int pos);
    void insertAChild(T& parent, T& child); //todo New method for project 4
    int findFree();
    void removeANode (T& node); //todo New method for project 4
    void removeHelper(int index);
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
    firstElement = -1;
    firstFree = -1;
}

template <class T> ArrayGLL<T>::ArrayGLL(ArrayGLL<T> &anotherOne) {
    myGLL = new GLRow<T>[anotherOne.maxSize];
    for( int i = 0; i < anotherOne.size() + anotherOne.noFree(); ++i){
        myGLL[i] = anotherOne.myGLL[i];
    }
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree;
    maxSize = anotherOne.maxSize;

}

template <class T> ArrayGLL<T>& ArrayGLL<T>::operator=(ArrayGLL<T> &anotherOne) {
    myGLL = new GLRow<T>[anotherOne.maxSize];
    for( int i = 0; i < anotherOne.size() + anotherOne.noFree(); ++i){
        myGLL[i] = anotherOne.myGLL[i];
    }
    firstElement = anotherOne.firstElement;
    firstFree = anotherOne.firstFree;
    maxSize = anotherOne.maxSize;
    return (*this);

}

template <class T> void ArrayGLL<T>::display() {
    cout << "(display bonus not completed)\n" << endl;
    displayHelper(firstElement);

}

template <class T> void ArrayGLL<T>::displayHelper(int root) {
    if (root == -1) return;
    if (myGLL[root].getInfo() == 999) return;
    cout << myGLL[root].getInfo();

    if ((myGLL[root].getNext() != -1 && myGLL[root].getDown() != -1))   {

        cout << " (";
        displayHelper(myGLL[root].getDown());
        cout << " ) ";
        displayHelper(myGLL[root].getNext());
    }
    else if (myGLL[root].getDown() != -1)   {
        int tempRoot = myGLL[root].getDown();
        cout << " (";
        displayHelper(tempRoot);
        cout << " )";
    }
    else if(myGLL[root].getNext() != -1)   {
        int tempRoot = myGLL[root].getNext();
        cout << " ";
        displayHelper(tempRoot);
    }

    return;

}

template <class T> int ArrayGLL<T>::find(T &key) {
    int answer = findHelper(key, firstElement);
    foundElement = -1;
    return answer;
}

template <class T> int ArrayGLL<T>::findHelper(T &key, int startingIndex) {
    if ( myGLL[startingIndex].getInfo() == 999)   { //was NULL
        foundElement = -1; //if this happens something is probably wrong.... very wrong...
    }

    if (key == myGLL[startingIndex].getInfo())   {
        foundElement = startingIndex; //If found set found element.
    }
    //makes it so that if both next and down are not -1 it can handle it.
    else if ( (myGLL[startingIndex].getNext() != -1) && (myGLL[startingIndex].getDown() != -1))   {
        findHelper(key, myGLL[startingIndex].getDown());
        if ( foundElement == -1)   {
            findHelper(key, myGLL[startingIndex].getNext());
        }
    }
    else if ( (myGLL[startingIndex].getNext() == -1) && (myGLL[startingIndex].getDown() == -1))   {
        foundElement = -1; //Returns -1 if the key is not in the generalized linked list
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

template <class T> bool ArrayGLL<T>::findDisplayPathHelper(T &key, int startingIndex) {
    if (startingIndex == -1 )   {
        return false;
    }
    if (key == myGLL[startingIndex].getInfo())   {
        cout << myGLL[startingIndex] << endl;
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
    int numberFree = 1;
    int nextValue = myGLL[firstFree].getNext();
    while (nextValue != -1)   {
        numberFree = numberFree + 1;
        nextValue = myGLL[nextValue].getNext();
    }
    return numberFree;
}

template <class T> int ArrayGLL<T>::size() {
    int size = sizeHelper(firstElement);
    listSize = 0;
    return size;

}

template <class T> int ArrayGLL<T>::sizeHelper(int startingIndex) {
    listSize = listSize + 1;
    if ( myGLL[startingIndex].getInfo() == NULL)   {
        listSize = -123;
    }
        //makes it so that if both next and down are not -1 it can handle it.
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
    int parentPos = parentPosHelper(Key, firstElement, -1);
    return parentPos;

}

template <class T> int ArrayGLL<T>::parentPosHelper(T &Key, int startingPoint, int parentPos) {
    if (startingPoint == -1)   {
        return -1;
    }
    else if (myGLL[startingPoint].getInfo() == Key)   {
        return parentPos;
    }

    int next = parentPosHelper(Key, myGLL[startingPoint].getNext(), parentPos);
    int down = parentPosHelper(Key, myGLL[startingPoint].getDown(), startingPoint);

    if (next != -1)   {
        return next;
    }
    else if ( down != -1)   {
        return down;
    }
    else   {
        return -1;
    }
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
    if ( myGLL != NULL) {
//        delete[] myGLL;
    }
}

template <class T> int ArrayGLL<T>::findFree() { //todo test this
    int firstFreeReturn = firstFree;
    firstFree = myGLL[firstFreeReturn].getNext();
    return firstFreeReturn;
}

template <class T> void ArrayGLL<T>::insertAChild(T &parent, T &child) { //todo test this
    GLRow<T> childElement(child);
    int indexOfParent = find(parent);
    int freeIndex = findFree();
    int tempDown = myGLL[indexOfParent].getDown();
    myGLL[indexOfParent].setDown(freeIndex);
    childElement.setNext(tempDown);
    childElement.setDown(-1);
    myGLL[freeIndex] = childElement;
}

template <class T> void ArrayGLL<T>::removeANode(T &node) { //Maybe reset
    //todo not done
    int L = find(node);
    int deletedNode = -1;
    if (myGLL[L].getDown() == -1)   {
        if ( myGLL[L].getNext() == -1)   {
            deletedNode = L;
            cout << "This1: " << myGLL[L] << endl;
            cout << "node to be removed:" << L << endl;

            removeHelper(L);
            cout << "This2: " << myGLL[L] << endl;
            cout << "remove called--------------------------------1" << endl;

//            delete& myGLL[L]; //todo Get nathan to help
        }
    }
    else {
        int nodeKeeper = L;
        while (myGLL[nodeKeeper].getDown() != -1)   {
            nodeKeeper = myGLL[nodeKeeper].getDown();
        }
//        cout << "HIT";
        myGLL[L] = myGLL[nodeKeeper];
        deletedNode = nodeKeeper;
        int info = 998;
        int deleter = -1;
        cout <<"NODE TO BE REMEMBER NOT LEAF: " << nodeKeeper << endl;
        removeHelper(nodeKeeper);
        cout << "remove called--------------------------------2" << endl;
//        myGLL[nodeKeeper].setInfo(info);
//        myGLL[nodeKeeper].setNext(deleter);
//        myGLL[nodeKeeper].setDown(deleter);
//        delete& myGLL[nodeKeeper]; //todo get nathan to help
    }
//    int freeIndex = firstFree;
//    while (myGLL[freeIndex].getNext() != -1)   {
//        freeIndex = myGLL[freeIndex].getNext();
//    }
//    if (deletedNode != -1)   {
//        myGLL[freeIndex].setNext(deletedNode);
//    }
    cout << "ThisOutside: " << myGLL[L] << endl;

}

template <class T> void ArrayGLL<T>::removeHelper(int index) {
    myGLL[index].setInfo(deletedNumber);
    myGLL[index].setNext(deleteDownNext);
    myGLL[index].setDown(deleteDownNext);
}

template <class T> ostream& operator << (ostream& s, ArrayGLL<T>& array)   {
    int i = 0;
    while ( i < (array.size() + array.noFree()))   {
        s << array[i];
        i = i + 1;
    }
    return s;
}




/**
 * Description:
 * The Main class is used to run the entire program. It calls upon other classes and their methods.
 */
int main() {

    ArrayGLL<int> firstGLL (20);  //Creates new ArrayGLL
    int noElements, value, next, down, parentPos;
    int pos = -1;
    int keyValue;
    int tempValue = 0;
    GLRow<int> oneRow (tempValue); //note that this statically defined
//    GLRow<int>* oneRow = (GLRow<int>*)malloc(sizeof(GLRow<int>));
//    oneRow->setInfo(tempValue);

    cin >> noElements;
    for (int i = 0; i < noElements; i++) {  //Taking inputs and setting them to values and adding them to firstGLL
        cin >> value >> next >> down;
//        GLRow<int>* oneRow = (GLRow<int>*)malloc(sizeof(GLRow<int>));

        oneRow.setInfo(value);
        oneRow.setNext(next);
        oneRow.setDown(down);
        firstGLL[i] = oneRow;

    }
    firstGLL.setFirstFree (8); //Setting FirstFree
    firstGLL.setFirstElement (2); //Setting FirstElement
    cout << firstGLL << endl;
    firstGLL.display();
    ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);  //Creating a second arrayGLL and copying the contents of firstGLL

//    int tempValue600 = 600;
//    (*secondGLL)[1].setInfo(tempValue600); //Replaceing the info of [1]
//    int tempValue700 = 700;
//    (*secondGLL)[2].setInfo(tempValue700); //Replacing the info of [2]

    cout << *secondGLL << endl;
    (*secondGLL).display();

    keyValue = 700;
    pos = (*secondGLL).find(keyValue);
    if (pos != -1)   {
        cout << "Finding Info of 700 with find(700), setting it to pos...\npos = the index of "; //Cout explains
        cout << (*secondGLL)[pos] << endl;
        cout << "Printing the value of nodes up to pos(700 as found with find()) with findDisplayPath(pos): " << endl;
        (*secondGLL).findDisplayPath(keyValue);
    }

    cout << "Printing out the Parent Position of 700: " << endl; //Cout explains
    parentPos = (*secondGLL).parentPos(keyValue);
    if (parentPos != -1)   {
        cout << (*secondGLL)[parentPos] << endl;
    }
    else {
        cout << "There is no parent position\n" << endl; //Cout explains
    }
    cout << "Size of secondGLL: " << (*secondGLL).size() << endl;
    cout << "Number free in secondGLL: " << (*secondGLL).noFree() << endl;

    cout << "insert test: " << endl;
    int parent = 80;
    int child = 100;
    (*secondGLL).insertAChild(parent, child); //todo finish
    cout << (*secondGLL) << endl;

    cout << "\nremove node test: " << endl;
    int nodeToRemove = 10;
    cout << "This is the test for [13]: " <<(*secondGLL)[13] << endl;
    (*secondGLL).removeANode(nodeToRemove);
    cout << "This is the test for [13]: " <<(*secondGLL)[13] << endl;
    (*secondGLL).display();

//    int test = 988;
//    (*secondGLL)[13].setInfo(test);


//    cout << (*secondGLL) << endl;

    delete secondGLL;
    return 0;
}