#ifndef ARRAY_H
#define ARRAY_H
#include"Library.h"

//Khoi tao mang voi 
void InitArray(int** a, int sl);

//Them 1 gia tri vao cuoi mang
void InsertArray(int** a, int data);

//Hien Thi mang
void InMang(int* a);

//Kiem tra mang co rong khong 
bool IsEmpty(int* a);

//Kiem tra xem mang day khong 
bool IsFull(int* a);

//Xoa gia tri tai cuoi mang
void DeleteLast(int** a);

#endif // !ARRAY_H

