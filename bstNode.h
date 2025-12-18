#ifndef BST_H
#define BST_H

#define NIL NULL
#include <iostream>
using namespace std;

// bstNode.h: address menyimpan alamat node
typedef struct Node *address;

// bstNode.h: struktur dari node
struct Node {
    int x, y;
    string nama;
    bool tembus;
    string pesan;
    address left, right;
};

// bstNode.h: Membuat node baru
address createNode(int objectX, int objectY, 
    string namaObject, string pesanObject, 
    bool statusDilewati);

// bstNode.h: Memasukkan data baru ke bst
address insert(address root, int x, int y, 
    string namaObj, string pesanObj, 
    bool statusDilewati);

// bstNode.h: mencari node khsusus
address cariNode(address root, int x, int y);

#endif